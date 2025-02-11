#include <stdio.h>
#include <stdlib.h>
#include "utils.h"
#include <pl_ini.h>
#include <md5.h>
#include <errno.h>
#include <stdlib.h>

StoreOptions set,
            *get;



void* __stack_chk_guard = (void*)0xdeadbeef;

void __stack_chk_fail(void)
{
    log_info("Stack smashing detected.");
    msgok(FATAL, "Stack Smashing has been Detected");
}

extern item_t* all_apps; // Installed_Apps

bool sceAppInst_done = false;
int Lastlogcheck = 0;
static const char     *sizes[] = { "EiB", "PiB", "TiB", "GiB", "MiB", "KiB", "B" };
static const uint64_t  exbibytes = 1024ULL * 1024ULL * 1024ULL *
1024ULL * 1024ULL * 1024ULL;

int copyFile(char* sourcefile, char* destfile)
{
    int src = sceKernelOpen(sourcefile, 0x0000, 0);
    if (src > 0)
    {
        
        int out = sceKernelOpen(destfile, 0x0001 | 0x0200 | 0x0400, 0777);
        if (out > 0)
        {
            size_t bytes;
            char* buffer = (char*)malloc(65536);
            if (buffer != NULL)
            {
                while (0 < (bytes = sceKernelRead(src, buffer, 65536)))
                    sceKernelWrite(out, buffer, bytes);
                free(buffer);
            }
        }
        else
        {
            log_error("Could copy file: %s Reason: %x", destfile, out);
            sceKernelClose(src);
            return -1;
        }

        sceKernelClose(src);
        sceKernelClose(out);
        return 0;
    }
    else
    {
        log_error("Could copy file: %s Reason: %x", destfile, src);
        return -1;
    }
}

int64_t sys_dynlib_load_prx(char* prxPath, int* moduleID)
{
    return (int64_t)syscall4(594, prxPath, 0, moduleID, 0);
}

int64_t sys_dynlib_unload_prx(int64_t prxID)
{
    return (int64_t)syscall1(595, (void*)prxID);
}


int64_t sys_dynlib_dlsym(int64_t moduleHandle, const char* functionName, void* destFuncOffset)
{
    return (int64_t)syscall3(591, (void*)moduleHandle, (void*)functionName, destFuncOffset);
}

void ProgSetMessagewText(int prog, const char* fmt, ...)
{

        char buff[300];
        memset(&buff[0], 0, sizeof(buff));

        va_list args;
        va_start(args, fmt);
        vsnprintf(&buff[0], 299, fmt, args);
        va_end(args);

        sceMsgDialogProgressBarSetValue(0, prog);
        sceMsgDialogProgressBarSetMsg(0, buff);
}

static bool touch_file(char* destfile)
{
    int fd = open(destfile, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd > 0) {
        close(fd);
        return true; 
    }
    else
        return false;
}

char* usbpath()
{
    static char usbbuf[100];
    usbbuf[0] = '\0';
    for(int x = 0; x <= 7; x++)
    {
        snprintf(usbbuf, sizeof(usbbuf), "/mnt/usb%i/.dirtest", x);
        if(touch_file(usbbuf))
        {
            snprintf(usbbuf, 100, "/mnt/usb%i", x);

            log_info("found usb = %s", usbbuf);
            return usbbuf;
        }
    }
    log_warn( "FOUND NO USB");

    return "";
}

int MD5_hash_compare(const char* file1, const char* hash)
{
    unsigned char c[MD5_HASH_LENGTH];
    FILE* f1 = fopen(file1, "rb");
    MD5_CTX mdContext;

    int bytes = 0;
    unsigned char data[1024];

    MD5_Init(&mdContext);
    while ((bytes = fread(data, 1, 1024, f1)) != 0)
        MD5_Update(&mdContext, data, bytes);
    MD5_Final(c, &mdContext);

    char md5_string[33] = {0};

    for(int i = 0; i < 16; ++i) {
        snprintf(&md5_string[i*2], 32, "%02x", (unsigned int)c[i]);
    }
    log_info( "FILE HASH: %s", md5_string);
    md5_string[32] = 0;

    if (strcmp(md5_string, hash) != 0) {
        return DIFFERENT_HASH;
    }

    log_info( "Input HASH: %s", hash);
    fclose(f1);

    return SAME_HASH;
}


bool is_apputil_init()
{
    int ret = sceAppInstUtilInitialize();
    if (ret) {
        log_error( "sceAppInstUtilInitialize failed: 0x%08X", ret);
        return false;
    }
    else
        sceAppInst_done = true;

    return true;
}


bool app_inst_util_uninstall_patch(const char* title_id, int* error) {
    int ret;

    if(!is_apputil_init())
    {
        bool res = is_apputil_init();
        if (!res)
        {  *error = 0xDEADBEEF;
           return false;
        }
    }
    if (!title_id) {
        ret = 0x80020016;
        if (error) {
            *error = ret;
        }
        goto err;
    }

    ret = sceAppInstUtilAppUnInstallPat(title_id);
    if (ret)
    {
        if (error) {
            *error = ret;
        }
        log_error( "sceAppInstUtilAppUnInstallPat failed: 0x%08X", ret);
        goto err;
    }

    return true;

err:
    return false;
}


bool app_inst_util_uninstall_game(const char *title_id, int *error)
{
    int ret;

    if (strlen(title_id) != 9)
    {
        *error = 0xBADBAD;
        return false;
    }
    if(!is_apputil_init())
    {
        bool res = is_apputil_init();
        if (!res)
        {  *error = 0xDEADBEEF;
           return false;
        }    
    }

    if (!title_id)
    {
        ret = 0x80020016;
        if (error)
        {
            *error = ret;
        }
        goto err;
    }

    ret = sceAppInstUtilAppUnInstall(title_id);
    if (ret)
    {
        if (error)
        {
            *error = ret;
        }
        log_error( "sceAppInstUtilAppUnInstall failed: 0x%08X", ret);
        goto err;
    }

    return true;

err:
    return false;
}


int LoadOptions(StoreOptions *set)
{
    for(int i=0; i< NUM_OF_STRINGS; i++)
    {   // dynalloc and zerofill
        set->opt[ i ] = calloc(256, sizeof(char));
    }

    /* Initialize INI structure */
    pl_ini_file file;
    char buff[257];
    if (strstr(usbpath(), "/mnt/usb"))
    {
        snprintf(buff, 256, "%s/settings.ini", usbpath());

        if (!if_exists(buff))
        {
            log_warn( "No INI on USB");
            if (if_exists("/user/app/NPXS39041/settings.ini"))
                snprintf(set->opt[INI_PATH], 255, "%s", "/user/app/NPXS39041/settings.ini");
        } else {
            pl_ini_load(&file, buff);
            log_info( "Loading ini from USB");
            snprintf(set->opt[INI_PATH], 255, "%s", buff);
        }
    }
    else
    if (!if_exists("/user/app/NPXS39041/settings.ini"))
    {
        log_error( "CANT FIND INI"); return -1;
    } else {
        pl_ini_load( &file, "/user/app/NPXS39041/settings.ini");
        log_info( "Loading ini from APP DIR");
        snprintf(set->opt[INI_PATH], 255, "%s", "/user/app/NPXS39041/settings.ini");
    }

    /* Read the file */
    pl_ini_load(&file, set->opt[INI_PATH]);
    /* Load values */
    if(strstr(usbpath(), "/mnt/usb"))
        snprintf(set->opt[USB_PATH], 255, "%s", usbpath());

    pl_ini_get_string(&file, "Settings", "CDN",      "http://api.pkg-zone.com",
                                 set->opt[CDN_URL],  256);
    pl_ini_get_string(&file, "Settings", "temppath", "/user/app/",
                                 set->opt[TMP_PATH], 256);
    pl_ini_get_string(&file, "Settings", "TTF_Font", "/system_ex/app/NPXS20113/bdjstack/lib/fonts/SCE-PS3-RD-R-LATIN.TTF",
                                 set->opt[FNT_PATH], 256);
#if BETA==1
    pl_ini_get_string(&file, "Settings", "BETA_KEY", "00000000000000000000000", set->opt[BETA_KEY], 256);
    log_info("set->opt[BETA_KEY]: %s", set->opt[BETA_KEY]);
#endif
    // get an ints
    set->Legacy     = pl_ini_get_int(&file, "Settings", "Legacy", 0);
    set->StoreOnUSB = pl_ini_get_int(&file, "Settings", "StoreOnUSB", 0);
    set->HomeMenu_Redirection = pl_ini_get_int(&file, "Settings", "Home_Redirection", 0);
    set->Daemon_on_start = pl_ini_get_int(&file, "Settings", "Daemon_on_start", 1);

    log_info( "set->opt[INI_PATH]: %s", set->opt[INI_PATH]);
    log_info( "set->opt[USB_PATH]: %s", set->opt[USB_PATH]);
    log_info( "set->opt[FNT_PATH]: %s", set->opt[FNT_PATH]);
    log_info( "set->opt[TMP_PATH]: %s", set->opt[TMP_PATH]);
    log_info( "set->opt[CDN_URL ]: %s", set->opt[CDN_URL]);
    log_info( "set->legacy       : %i", set->Legacy);
    log_info( "set->Daemon_...   : %s", set->Daemon_on_start ? "ON" : "OFF");
    log_info(" set->HomeMen...   : %s", set->HomeMenu_Redirection ? "ItemzFlow (ON)" : "Orbis (OFF)");
    log_info( "set->StoreOnUSB   : %i", set->StoreOnUSB);

    /* Clean up */
    pl_ini_destroy(&file);

    return 1;
}


char* cutoff(const char* str, int from, int to)
{
    if (from >= to)
        return  NULL;

    char* cut = calloc(sizeof(char), (to - from) + 1);
    char* begin = cut;
    if (!cut)
        return  NULL;

    const char* fromit = str + from;
    const char* toit = str + to;
    (void)toit;
    memcpy(cut, fromit, to);
    return begin;
}

int SaveOptions(StoreOptions *set)
{
    /* Initialize INI structure */
    pl_ini_file file;

    /* Read the file */
    if (!if_exists(set->opt[INI_PATH])) {
        pl_ini_create(&file);
        log_info("INI NOT AVAIL Creating... ");
    }
    else
       pl_ini_load(&file, set->opt[INI_PATH]);

    log_info( "set->opt[INI_PATH]  %s", set->opt[INI_PATH]);
    log_info( "set->opt[USB_PATH]: %s", set->opt[USB_PATH]);
    log_info( "set->opt[TMP_PATH]: %s", set->opt[TMP_PATH]);
    log_info( "set->opt[FNT_PATH]: %.20s...", set->opt[FNT_PATH]);
    log_info( "set->opt[CDN_URL ]: %s", set->opt[CDN_URL ]);
    log_info( "set->StoreOnUSB   : %i", set->StoreOnUSB);
    log_info( "set->HomeMen...   : %s", set->HomeMenu_Redirection ? "ItemzFlow (ON)" : "Orbis (OFF)");

    /* Load values */
    pl_ini_set_string(&file, "Settings", "CDN",        set->opt[CDN_URL ]);
    pl_ini_set_string(&file, "Settings", "temppath",   set->opt[TMP_PATH]);
    pl_ini_set_string(&file, "Settings", "TTF_Font",   set->opt[FNT_PATH]);
    pl_ini_set_int   (&file, "Settings", "StoreOnUSB", set->StoreOnUSB);
    pl_ini_set_int   (&file, "Settings", "Home_Redirection", set->HomeMenu_Redirection);

    int ret = pl_ini_save(&file, set->opt[INI_PATH]);
    chmod(set->opt[INI_PATH], 0777);

    /* Clean up */
    pl_ini_destroy(&file);

    return ret;
}


uint32_t SysctlByName_get_sdk_version(void)
{
    uint32_t sdkVersion = -1;
    size_t   len = 4;
    sysctlbyname("kern.sdk_version", &sdkVersion, &len, NULL, 0);

    return sdkVersion;
}

char *calculateSize(uint64_t size)
{
    char     *result = (char *)malloc(sizeof(char) * 32);
    uint64_t  multiplier = exbibytes;
    int i;

    for (i = 0; i < DIM(sizes); i++, multiplier /= 1024)
    {
        if (size < multiplier)
            continue;
        if (size % multiplier == 0)
            snprintf(result, sizeof(char) * 31, "%" PRIu64 " %s", size / multiplier, sizes[i]);
        else
            snprintf(result, sizeof(char) * 31, "%.1f %s", (float)size / multiplier, sizes[i]);
        return result;
    }
    strcpy(result, "0");
    return result;
}


static char *checkedsize = NULL;

long CalcAppsize(char *path)
{
    FILE *fp = NULL;
    long off;

    fp = fopen(path, "r");
    if (fp == NULL) return 0;
            
    if (fseek(fp, 0, SEEK_END) == -1) goto cleanup;
            
    off = ftell(fp);
    if (off == (long)-1) goto cleanup;

    if (fclose(fp) != 0) goto cleanup;
    
    if(off) { checkedsize = calculateSize(off); return off; }
    else    { checkedsize = NULL; return 0; }

cleanup:
    if (fp != NULL)
        fclose(fp);

    return 0;

}
//////////////////////////////////////////////////////




void CheckLogSize()
{
    CalcAppsize(STORE_LOG);

    log_info("[LOG CHECK] Size  = %s", checkedsize);

    if (strstr(checkedsize, "GiB") != NULL)
        unlink(STORE_LOG);
    else
        log_info("[LOG CHECK] File Is NOT 1 => GiB, Skipping Deletion");

    if(checkedsize) free(checkedsize), checkedsize = NULL;
}




void die(char* message)
{
    log_fatal( message);
    sceSystemServiceLoadExec("INVALID", 0);
}

void msgok(enum MSG_DIALOG level, char* format, ...)
{
    if(strlen(format) > 301) return;

    int ret = 0;
    sceSysmoduleLoadModule(ORBIS_SYSMODULE_MESSAGE_DIALOG);

    sceMsgDialogTerminate();


    char buff[300];
    char buffer[300];
    memset(&buff[0], 0,  sizeof(buff));


    va_list args;
    va_start(args, format);
    vsnprintf(buff, 299, format, args);
    va_end(args);



    switch (level)
    {
    case NORMAL:
        log_info(buff);
        strcpy(buffer, buff);
        break;
    case FATAL:
        log_fatal( buff);
        snprintf(buffer, 299, "Fatal Error %s\n\n  Please Close the Program  after Pressing 'OK'", buff);
        break;
    case WARNING:
        log_warn( buff);
        snprintf(buffer, 299, "Warning %s", &buff[0]);
        break;
    }


    sceMsgDialogInitialize();
    OrbisMsgDialogParam param;
    OrbisMsgDialogParamInitialize(&param);
    param.mode = ORBIS_MSG_DIALOG_MODE_USER_MSG;

    OrbisMsgDialogUserMessageParam userMsgParam;
    memset(&userMsgParam, 0, sizeof(userMsgParam));
    userMsgParam.msg        = buffer;
    userMsgParam.buttonType = ORBIS_MSG_DIALOG_BUTTON_TYPE_OK;
    param.userMsgParam      = &userMsgParam;

    if (sceMsgDialogOpen(&param) < 0)
           log_fatal( "MsgD failed");
    
        
    

    OrbisCommonDialogStatus stat;

    while (1)
    {
        stat = sceMsgDialogUpdateStatus();
        if (stat == ORBIS_COMMON_DIALOG_STATUS_FINISHED)
        {
            OrbisMsgDialogResult result;
            memset(&result, 0, sizeof(result));

            if (0 > sceMsgDialogGetResult(&result))
                         log_fatal( "MsgD failed"); 

            sceMsgDialogTerminate();
            break;
        }
    }


    switch (level)
    {
    case FATAL:
        die(&buff[0]);
        break;

    default:
        break;
    }

    return;
}

void loadmsg(char* format, ...)
{
    if(strlen(format) > 1024) return;

    sceSysmoduleLoadModule(ORBIS_SYSMODULE_MESSAGE_DIALOG);

    sceMsgDialogInitialize();

    char buff[1024];
    memset(&buff[0], 0, sizeof(buff));

    va_list args;
    va_start(args, format);
    vsnprintf(&buff[0], 1023, format, args);
    va_end(args);

    // int32_t  ret = 0;_sceCommonDialogBaseParamInit

    OrbisMsgDialogButtonsParam buttonsParam;
    OrbisMsgDialogUserMessageParam messageParam;
    OrbisMsgDialogParam dialogParam;

    OrbisMsgDialogParamInitialize(&dialogParam);

    memset(&buttonsParam, 0x00, sizeof(buttonsParam));
    memset(&messageParam, 0x00, sizeof(messageParam));

    dialogParam.userMsgParam = &messageParam;
    dialogParam.mode = ORBIS_MSG_DIALOG_MODE_USER_MSG;

    messageParam.buttonType = ORBIS_MSG_DIALOG_BUTTON_TYPE_WAIT;
    messageParam.msg        = &buff[0];

    sceMsgDialogOpen(&dialogParam);

    OrbisCommonDialogStatus stat;

    while (1)
    {
        stat = sceMsgDialogUpdateStatus();
        if (stat == ORBIS_COMMON_DIALOG_STATUS_RUNNING) 
             break;
        
    }

    return;
}

//
int check_download_counter(StoreOptions* set, char* title_id)
{

    char  http_req[300];
    char* result;
    int count;

#if LOCALHOST_WINDOWS
    snprintf(http_req, 300, "%s/00/download.php?tid=%s&check", set->opt[CDN_URL], title_id);
#else
    snprintf(http_req, 300, "%s/download.php?tid=%s&check", set->opt[CDN_URL], title_id);
#endif

    result = check_from_url(http_req, DL_COUNTER);

    if (result != NULL)
        count = atoi(result);
    else
        msgok(FATAL, "Dev Error 6066");

    free(result);

    log_debug( "%s Number_of_DL:%d", __FUNCTION__, count);

    return count;
}



// 
int check_store_from_url(int page_number, char* cdn, enum CHECK_OPTS opt)
{
    char  http_req[300];
    char  dst_path[300];
    char *result;

    switch(opt)
    {
        case MD5_HASH:
        {
            snprintf(http_req, 300, "%s/api.php?page=%i&check_hash=true", cdn, page_number);
            snprintf(dst_path, 300, "/user/app/NPXS39041/homebrew-page%i.json", page_number);

            result = check_from_url(http_req, MD5_HASH);

            if (MD5_hash_compare(dst_path, result) == SAME_HASH)
            {
                free(result); return 1;
            }
            else
            {
                free(result); return 0;
            }
        } break;

        case COUNT:
        {
            snprintf(http_req, 300, "%s/api.php?count=true", cdn);

            result = check_from_url(http_req, COUNT);


            int pages = -1;
            if (result != NULL)
            {
                
                log_info("result %s", result);
                if (atoi(result) < 20000)
                   pages = atoi(result) / 15;
                else
                  msgok(FATAL, "Number of pages Exceeds the Stores Limits!");
            }
            else
                msgok(FATAL, "Dev Error 6066");
          

            if (pages % 15 != 0) pages++;

            free(result); 
            log_debug( "%s counted pages:%d", __FUNCTION__, pages);

            return pages;
        } break;

#if BETA==1 //http://api.pkg-zone.com/beta_check.php?id_check=KEY
     
        case BETA_CHECK: {
            char url[255];
            snprintf(url, 254, "http://api.pkg-zone.com/beta/beta_check.php?id_check=%s", get->opt[BETA_KEY]);
            log_info("FULL URL: %s", url); 
            return check_from_url(url, BETA_CHECK); 
            break;
        }
#endif

        default: break;
    }
    return 0;   
}

int getjson(int Pagenumb, char* cdn, bool legacy)
{
    char http_req[300];
    char destbuf [300];

    snprintf(destbuf, 300, "/user/app/NPXS39041/homebrew-page%i.json", Pagenumb);

    if(legacy == true)
        snprintf(http_req, 300, "%s/homebrew-page%i.json", cdn, Pagenumb);
    else
    {
        snprintf(http_req, 300, "%s/api.php?page=%i", cdn, Pagenumb);
        if (if_exists(destbuf))
        {
            log_info("page %i exists", Pagenumb);
            if (!check_store_from_url(Pagenumb, get->opt[CDN_URL], MD5_HASH))
            {
                unlink(destbuf);
                if( dl_from_url(http_req, destbuf, false) )
                {
                    msgok(FATAL, "Could not Download Page: %i From: %s", Pagenumb, get->opt[CDN_URL]);
                    return -1;
                }
            }
            else
            {
                log_info("HASH IS THE SAME"); return 0;
            }
        }
        else
        {
            if( dl_from_url(http_req, destbuf, false) )
            {
                msgok(FATAL, "Could not Download Page: %i From: %s", Pagenumb, get->opt[CDN_URL]);
                return -1;
            }
        }
    }   
    log_info("%s %s", __FUNCTION__, http_req);

    return dl_from_url(http_req, destbuf, false);
}


bool rmtree(const char path[]) {

    struct dirent* de;
    char fname[300];
    DIR* dr = opendir(path);
    if (dr == NULL)
    {
        log_debug("No file or directory found: %s", path);
        return false;
    }
    while ((de = readdir(dr)) != NULL)
    {
        int ret = -1;
        struct stat statbuf;
        snprintf(fname,299, "%s/%s", path, de->d_name);
        if (!strcmp(de->d_name, ".") || !strcmp(de->d_name, ".."))
            continue;
        if (!stat(fname, &statbuf))
        {
            if (S_ISDIR(statbuf.st_mode))
            {
                log_debug("removing dir: %s Err: %d", fname, ret = unlinkat(dirfd(dr), fname, AT_REMOVEDIR));
                if (ret != 0)
                {
                    rmtree(fname);
                    log_debug("Err: %d", ret = unlinkat(dirfd(dr), fname, AT_REMOVEDIR));
                }
            }
            else
            {
                log_debug("Removing file: %s, Err: %d", fname, unlink(fname));
            }
        }
    }
    closedir(dr);

    return true;
}

const char* Store_Asset_Paths[] = { "/user/app/NPXS39041/storedata/aaa.png", "/user/app/NPXS39041/storedata/btn_X.png"};
const char* Store_Asset_Links[] = { "/assets/cover.png", "/assets/btn_X.png" };


void setup_store_assets(StoreOptions* get)
{
    //Operated by the Dev Team
    log_info("Checking for Store Assets ...");
    if (!if_exists("/mnt/sandbox/NPXS39041_000/app0/assets/aaa.png"))
    {
        char CDN_Buf[255];
        log_info("This is not the New PKG check if Assets are Downloaded # of assets: %d", sizeof Store_Asset_Paths / sizeof Store_Asset_Paths[0]);
        for (int i = 0; i <= sizeof Store_Asset_Paths / sizeof Store_Asset_Paths[0] - 1; i++)
        {
            log_debug("On i: %i", i);
            snprintf(CDN_Buf, 254, "%s/%s", get->opt[CDN_URL], Store_Asset_Links[i]);
            if (!if_exists(CDN_Buf))
            {
                log_info("Downloading Asset: %s ...", Store_Asset_Paths[i]);

                int ret = dl_from_url(CDN_Buf, Store_Asset_Paths[i], false);
                if (ret != 0) {
                    msgok(FATAL, "Could NOT Download Asset: %s\nFrom %s\nError Code %i", Store_Asset_Paths[i], CDN_Buf, ret);
                }
                else if (ret == 0)
                    log_info("Downloaded Asset: %s Successfully", Store_Asset_Paths[i]);


            }
            else
                log_info("Assets: %s already exists Download NOT needed", Store_Asset_Paths[i]);
        }
    }
    else
        log_info("This is the New PKG Assets are already on PS4");
}

bool IS_ERROR(uint32_t a1)
{
    return a1 & 0x80000000;
}

//            sceSystemServiceKillApp();



uint32_t Launch_App(char* TITLE_ID, bool silent) {

    uint32_t sys_res = -1;

    int libcmi = sceKernelLoadStartModule("/system/common/lib/libSceSystemService.sprx", 0, NULL, 0, 0, 0);
    if (libcmi > 0)
    {
        log_info("Starting action Launch_Game_opt");


        OrbisUserServiceLoginUserIdList userIdList;

        log_info("ret %x", sceUserServiceGetLoginUserIdList(&userIdList));

        for (int i = 0; i < 4; i++)
        {
            if (userIdList.userId[i] != 0xFF)
            {
                log_info("[%i] User ID 0x%x", i, userIdList.userId[i]);
            }
        }


        LncAppParam param;
        param.sz = sizeof(LncAppParam);

        if (userIdList.userId[0] != 0xFF)
            param.user_id = userIdList.userId[0];
        else if (userIdList.userId[1] != 0xFF)
            param.user_id = userIdList.userId[1];

        param.app_opt = 0;
        param.crash_report = 0;
        param.check_flag = SkipSystemUpdateCheck;

        log_info("l1 %x", sceLncUtilInitialize());


        sys_res = sceLncUtilLaunchApp(TITLE_ID, 0, &param);
        if (IS_ERROR(sys_res))
        {
            if (!silent) {
                log_info("Switch 0x%x", sys_res);
                switch (sys_res) {
                case SCE_LNC_ERROR_APP_NOT_FOUND: {
                    msgok(WARNING, "App is NOT Found ref: SCE_LNC_ERROR_APP_NOT_FOUND");
                    break;
                }
                case SCE_LNC_UTIL_ERROR_ALREADY_RUNNING: {
                    msgok(WARNING, "App is already running ref: SCE_LNC_UTIL_ERROR_ALREADY_RUNNING");
                    break;
                }
                case SCE_LNC_UTIL_ERROR_ALREADY_RUNNING_KILL_NEEDED: {
                    log_debug("ALREADY RUNNING KILL NEEDED");
                    break;
                }
                case SCE_LNC_UTIL_ERROR_ALREADY_RUNNING_SUSPEND_NEEDED: {
                    log_debug("ALREADY RUNNING SUSPEND NEEDED");
                    break;
                }
                case SCE_LNC_UTIL_ERROR_SETUP_FS_SANDBOX: {
                    msgok(WARNING, "App is NOT Launchable ref: SCE_LNC_UTIL_ERROR_SETUP_FS_SANDBOX");
                    break;
                }
                case SCE_LNC_UTIL_ERROR_INVALID_TITLE_ID: {
                    msgok(WARNING, "TITLE_ID IS NOT VAILED ref: SCE_LNC_UTIL_ERROR_SETUP_FS_SANDBOX");
                    break;
                }

                default: {
                    msgok(WARNING, "App Launch has failed with error code: 0x%x", sys_res);
                    break;
                }
                }
            }
        }

        log_info("launch ret 0x%x", sys_res);

    }
    else {
        if(!silent)
            msgok(WARNING, "Game Launch has failed with 0x%X", libcmi);
    }

    return sys_res;
}

extern struct retry_t* cf_tex;

extern int total_pages;
    
void refresh_apps_for_cf(void)
{

#if STANDALONE_APP==0
    int before = all_apps[0].token_c;
    loadmsg("Reloading the Installed Apps List ...");
    log_debug("Reloading Installed Apps before: %i", before);
    if (all_apps)
        free(all_apps);
    all_apps = index_items_from_dir("/user/app", "/mnt/ext0/user/app"); 
    InitScene_5(ATTR_ORBISGL_WIDTH, ATTR_ORBISGL_HEIGHT);
    InitScene_4(ATTR_ORBISGL_WIDTH, ATTR_ORBISGL_HEIGHT);
    for (int i = 1; i < all_apps[0].token_c + 1; i++) {
        check_tex_for_reload(i);
        check_n_load_textures(i);
    }

    sceMsgDialogTerminate();
    log_debug("Done reloading # of App: %i, # of Apps added/removed: %i", all_apps[0].token_c,  all_apps[0].token_c - before);
    
#else

char page_buf[100];
snprintf(page_buf, sizeof(total_pages), "%i", total_pages);
char* new_argv[11] = { "--reload_games", page_buf };

log_info("reloading the App");
unlink("/data/self/eboot.bin");
copyFile("/user/app/NPXS39041/homebrew.elf", "/data/self/eboot.bin");
sceSystemServiceLoadExec("/data/self/eboot.bin", &new_argv);

#endif



}


void build_iovec(struct iovec** iov, int* iovlen, const char* name, const void* val, size_t len) {
    int i;

    if (*iovlen < 0)
        return;

    i = *iovlen;
    *iov = (struct iovec*)realloc((void*)(*iov), sizeof(struct iovec) * (i + 2));
    if (*iov == NULL) {
        *iovlen = -1;
        return;
    }

    (*iov)[i].iov_base = strdup(name);
    (*iov)[i].iov_len = strlen(name) + 1;
    ++i;

    (*iov)[i].iov_base = (void*)val;
    if (len == (size_t)-1) {
        if (val != NULL)
            len = strlen((const char*)val) + 1;
        else
            len = 0;
    }
    (*iov)[i].iov_len = (int)len;

    *iovlen = ++i;
}


int mountfs(const char* device, const char* mountpoint, const char* fstype, const char* mode, uint64_t flags)
{
    struct iovec* iov = NULL;
    int iovlen = 0;
    int ret;

    build_iovec(&iov, &iovlen, "fstype", fstype, -1);
    build_iovec(&iov, &iovlen, "fspath", mountpoint, -1);
    build_iovec(&iov, &iovlen, "from", device, -1);
    build_iovec(&iov, &iovlen, "large", "yes", -1);
    build_iovec(&iov, &iovlen, "timezone", "static", -1);
    build_iovec(&iov, &iovlen, "async", "", -1);
    build_iovec(&iov, &iovlen, "ignoreacl", "", -1);

    if (mode) {
        build_iovec(&iov, &iovlen, "dirmask", mode, -1);
        build_iovec(&iov, &iovlen, "mask", mode, -1);
    }

    log_info("##^  [I] Mounting %s \"%s\" to \"%s\" \n", fstype, device, mountpoint);
    ret = nmount(iov, iovlen, flags);
    if (ret < 0) {
        log_info("##^  [E] Failed: %d (errno: %d).\n", ret, errno);
        goto error;
    }
    else {
        log_info("##^  [I] Success.\n");
    }

error:
    return ret;
}


void print_memory()
{
    SceLibcMallocManagedSize ManagedSize;
    SCE_LIBC_INIT_MALLOC_MANAGED_SIZE(ManagedSize);
    malloc_stats_fast(&ManagedSize);

    log_info("PS4 Memory Stats: CurrentSystemSize: %s, CurrentInUseSize: %s, MaxSystemSize: %s, MaxInUseSize: %s", calculateSize(ManagedSize.currentSystemSize), calculateSize(ManagedSize.currentInuseSize), calculateSize(ManagedSize.maxSystemSize), calculateSize(ManagedSize.maxInuseSize));
}