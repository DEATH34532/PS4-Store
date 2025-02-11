/*
    edited ps_signs.frag glsl fragment shader code

    original work from: https://www.shadertoy.com/view/WdV3DW

    2020-21, masterzorag
*/
static unsigned char ps_signs_shader[] = {
  0x2f, 0x2a, 0x0a, 0x20, 0x2a, 0x20, 0x4f, 0x72, 0x69, 0x67, 0x69, 0x6e,
  0x61, 0x6c, 0x20, 0x73, 0x68, 0x61, 0x64, 0x65, 0x72, 0x20, 0x66, 0x72,
  0x6f, 0x6d, 0x3a, 0x20, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f,
  0x77, 0x77, 0x77, 0x2e, 0x73, 0x68, 0x61, 0x64, 0x65, 0x72, 0x74, 0x6f,
  0x79, 0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x76, 0x69, 0x65, 0x77, 0x2f, 0x57,
  0x64, 0x56, 0x33, 0x44, 0x57, 0x0a, 0x20, 0x2a, 0x2f, 0x0a, 0x0a, 0x23,
  0x69, 0x66, 0x64, 0x65, 0x66, 0x20, 0x47, 0x4c, 0x5f, 0x45, 0x53, 0x0a,
  0x70, 0x72, 0x65, 0x63, 0x69, 0x73, 0x69, 0x6f, 0x6e, 0x20, 0x6d, 0x65,
  0x64, 0x69, 0x75, 0x6d, 0x70, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x3b,
  0x0a, 0x23, 0x65, 0x6e, 0x64, 0x69, 0x66, 0x0a, 0x0a, 0x2f, 0x2f, 0x20,
  0x67, 0x6c, 0x73, 0x6c, 0x73, 0x61, 0x6e, 0x64, 0x62, 0x6f, 0x78, 0x20,
  0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d, 0x73, 0x0a, 0x75, 0x6e, 0x69,
  0x66, 0x6f, 0x72, 0x6d, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x74,
  0x69, 0x6d, 0x65, 0x3b, 0x0a, 0x75, 0x6e, 0x69, 0x66, 0x6f, 0x72, 0x6d,
  0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x72, 0x65, 0x73, 0x6f, 0x6c, 0x75,
  0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x0a, 0x2f, 0x2f, 0x20, 0x73, 0x68,
  0x61, 0x64, 0x65, 0x72, 0x74, 0x6f, 0x79, 0x20, 0x65, 0x6d, 0x75, 0x6c,
  0x61, 0x74, 0x69, 0x6f, 0x6e, 0x0a, 0x23, 0x64, 0x65, 0x66, 0x69, 0x6e,
  0x65, 0x20, 0x69, 0x54, 0x69, 0x6d, 0x65, 0x20, 0x74, 0x69, 0x6d, 0x65,
  0x0a, 0x23, 0x64, 0x65, 0x66, 0x69, 0x6e, 0x65, 0x20, 0x69, 0x52, 0x65,
  0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x72, 0x65, 0x73,
  0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x0a, 0x0a, 0x2f, 0x2f, 0x20,
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x5b, 0x20, 0x4f, 0x72,
  0x69, 0x67, 0x69, 0x6e, 0x61, 0x6c, 0x20, 0x53, 0x68, 0x61, 0x64, 0x65,
  0x72, 0x54, 0x6f, 0x79, 0x20, 0x62, 0x65, 0x67, 0x69, 0x6e, 0x73, 0x20,
  0x68, 0x65, 0x72, 0x65, 0x20, 0x5d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d,
  0x2d, 0x2d, 0x2d, 0x2d, 0x20, 0x2f, 0x2f, 0x0a, 0x2f, 0x2f, 0x42, 0x61,
  0x73, 0x65, 0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x73, 0x20, 0x6d, 0x6f,
  0x64, 0x69, 0x66, 0x69, 0x65, 0x64, 0x20, 0x77, 0x69, 0x74, 0x68, 0x20,
  0x64, 0x65, 0x70, 0x74, 0x68, 0x20, 0x6c, 0x61, 0x74, 0x65, 0x72, 0x0a,
  0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x6e, 0x73,
  0x69, 0x74, 0x79, 0x20, 0x3d, 0x20, 0x31, 0x2e, 0x30, 0x3b, 0x0a, 0x66,
  0x6c, 0x6f, 0x61, 0x74, 0x20, 0x72, 0x61, 0x64, 0x69, 0x75, 0x73, 0x20,
  0x3d, 0x20, 0x30, 0x2e, 0x31, 0x3b, 0x0a, 0x0a, 0x2f, 0x2f, 0x44, 0x69,
  0x73, 0x74, 0x61, 0x6e, 0x63, 0x65, 0x20, 0x66, 0x75, 0x6e, 0x63, 0x74,
  0x69, 0x6f, 0x6e, 0x73, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20, 0x0a, 0x2f,
  0x2f, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x77, 0x77, 0x77,
  0x2e, 0x69, 0x71, 0x75, 0x69, 0x6c, 0x65, 0x7a, 0x6c, 0x65, 0x73, 0x2e,
  0x6f, 0x72, 0x67, 0x2f, 0x77, 0x77, 0x77, 0x2f, 0x61, 0x72, 0x74, 0x69,
  0x63, 0x6c, 0x65, 0x73, 0x2f, 0x64, 0x69, 0x73, 0x74, 0x66, 0x75, 0x6e,
  0x63, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x32, 0x64, 0x2f, 0x64, 0x69, 0x73,
  0x74, 0x66, 0x75, 0x6e, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x32, 0x64,
  0x2e, 0x68, 0x74, 0x6d, 0x0a, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x74,
  0x72, 0x69, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x44, 0x69, 0x73, 0x74, 0x28,
  0x76, 0x65, 0x63, 0x32, 0x20, 0x70, 0x29, 0x7b, 0x20, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x20, 0x66, 0x6c, 0x6f, 0x61,
  0x74, 0x20, 0x6b, 0x20, 0x3d, 0x20, 0x73, 0x71, 0x72, 0x74, 0x28, 0x33,
  0x2e, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x70, 0x2e, 0x78,
  0x20, 0x3d, 0x20, 0x61, 0x62, 0x73, 0x28, 0x70, 0x2e, 0x78, 0x29, 0x20,
  0x2d, 0x20, 0x31, 0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x70,
  0x2e, 0x79, 0x20, 0x3d, 0x20, 0x70, 0x2e, 0x79, 0x20, 0x2b, 0x20, 0x31,
  0x2e, 0x30, 0x2f, 0x6b, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66,
  0x28, 0x20, 0x70, 0x2e, 0x78, 0x2b, 0x6b, 0x2a, 0x70, 0x2e, 0x79, 0x3e,
  0x30, 0x2e, 0x30, 0x20, 0x29, 0x20, 0x70, 0x3d, 0x76, 0x65, 0x63, 0x32,
  0x28, 0x70, 0x2e, 0x78, 0x2d, 0x6b, 0x2a, 0x70, 0x2e, 0x79, 0x2c, 0x2d,
  0x6b, 0x2a, 0x70, 0x2e, 0x78, 0x2d, 0x70, 0x2e, 0x79, 0x29, 0x2f, 0x32,
  0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x70, 0x2e, 0x78, 0x20,
  0x2d, 0x3d, 0x20, 0x63, 0x6c, 0x61, 0x6d, 0x70, 0x28, 0x20, 0x70, 0x2e,
  0x78, 0x2c, 0x20, 0x2d, 0x32, 0x2e, 0x30, 0x2c, 0x20, 0x30, 0x2e, 0x30,
  0x20, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75,
  0x72, 0x6e, 0x20, 0x2d, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x28, 0x70,
  0x29, 0x2a, 0x73, 0x69, 0x67, 0x6e, 0x28, 0x70, 0x2e, 0x79, 0x29, 0x3b,
  0x0a, 0x7d, 0x0a, 0x0a, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x62, 0x6f,
  0x78, 0x44, 0x69, 0x73, 0x74, 0x28, 0x76, 0x65, 0x63, 0x32, 0x20, 0x70,
  0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20,
  0x64, 0x20, 0x3d, 0x20, 0x61, 0x62, 0x73, 0x28, 0x70, 0x29, 0x2d, 0x31,
  0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75,
  0x72, 0x6e, 0x20, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x28, 0x6d, 0x61,
  0x78, 0x28, 0x64, 0x2c, 0x76, 0x65, 0x63, 0x32, 0x28, 0x30, 0x29, 0x29,
  0x29, 0x20, 0x2b, 0x20, 0x6d, 0x69, 0x6e, 0x28, 0x6d, 0x61, 0x78, 0x28,
  0x64, 0x2e, 0x78, 0x2c, 0x64, 0x2e, 0x79, 0x29, 0x2c, 0x30, 0x2e, 0x30,
  0x29, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x2f, 0x2f, 0x20, 0x50, 0x6c, 0x6f,
  0x74, 0x20, 0x61, 0x6e, 0x20, 0x58, 0x3a, 0x20, 0x74, 0x68, 0x65, 0x20,
  0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x20, 0x3d, 0x20, 0x6d, 0x61, 0x78,
  0x20, 0x63, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x20, 0x72, 0x61, 0x64, 0x69,
  0x75, 0x73, 0x0a, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x63, 0x72, 0x6f,
  0x73, 0x73, 0x44, 0x69, 0x73, 0x74, 0x28, 0x76, 0x65, 0x63, 0x32, 0x20,
  0x70, 0x29, 0x20, 0x7b, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76,
  0x65, 0x63, 0x32, 0x20, 0x20, 0x64, 0x20, 0x3d, 0x20, 0x61, 0x62, 0x73,
  0x28, 0x70, 0x29, 0x2d, 0x31, 0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x78, 0x20, 0x3d, 0x20, 0x6c,
  0x65, 0x6e, 0x67, 0x74, 0x68, 0x28, 0x70, 0x29, 0x20, 0x2d, 0x20, 0x31,
  0x2e, 0x3b, 0x20, 0x2f, 0x2f, 0x20, 0x72, 0x61, 0x64, 0x69, 0x75, 0x73,
  0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x69, 0x72, 0x63,
  0x6c, 0x65, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72,
  0x6e, 0x20, 0x6d, 0x61, 0x78, 0x28, 0x78, 0x2c, 0x20, 0x6c, 0x65, 0x6e,
  0x67, 0x74, 0x68, 0x28, 0x64, 0x2e, 0x78, 0x20, 0x2d, 0x20, 0x64, 0x2e,
  0x79, 0x29, 0x29, 0x3b, 0x20, 0x2f, 0x2f, 0x20, 0x69, 0x6e, 0x73, 0x69,
  0x64, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x69, 0x72, 0x63, 0x6c,
  0x65, 0x0a, 0x7d, 0x0a, 0x0a, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x63,
  0x69, 0x72, 0x63, 0x6c, 0x65, 0x44, 0x69, 0x73, 0x74, 0x28, 0x20, 0x76,
  0x65, 0x63, 0x32, 0x20, 0x70, 0x29, 0x7b, 0x0a, 0x20, 0x20, 0x72, 0x65,
  0x74, 0x75, 0x72, 0x6e, 0x20, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x28,
  0x70, 0x29, 0x20, 0x2d, 0x20, 0x31, 0x2e, 0x30, 0x3b, 0x0a, 0x7d, 0x0a,
  0x0a, 0x2f, 0x2f, 0x68, 0x74, 0x74, 0x70, 0x73, 0x3a, 0x2f, 0x2f, 0x77,
  0x77, 0x77, 0x2e, 0x73, 0x68, 0x61, 0x64, 0x65, 0x72, 0x74, 0x6f, 0x79,
  0x2e, 0x63, 0x6f, 0x6d, 0x2f, 0x76, 0x69, 0x65, 0x77, 0x2f, 0x33, 0x73,
  0x33, 0x47, 0x44, 0x6e, 0x0a, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x67,
  0x65, 0x74, 0x47, 0x6c, 0x6f, 0x77, 0x28, 0x66, 0x6c, 0x6f, 0x61, 0x74,
  0x20, 0x64, 0x69, 0x73, 0x74, 0x2c, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74,
  0x20, 0x72, 0x61, 0x64, 0x69, 0x75, 0x73, 0x2c, 0x20, 0x66, 0x6c, 0x6f,
  0x61, 0x74, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x6e, 0x73, 0x69, 0x74, 0x79,
  0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x72, 0x65, 0x74, 0x75, 0x72,
  0x6e, 0x20, 0x70, 0x6f, 0x77, 0x28, 0x72, 0x61, 0x64, 0x69, 0x75, 0x73,
  0x2f, 0x64, 0x69, 0x73, 0x74, 0x2c, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x6e,
  0x73, 0x69, 0x74, 0x79, 0x29, 0x3b, 0x0a, 0x7d, 0x0a, 0x0a, 0x76, 0x6f,
  0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x49, 0x6d, 0x61, 0x67, 0x65,
  0x28, 0x20, 0x6f, 0x75, 0x74, 0x20, 0x76, 0x65, 0x63, 0x34, 0x20, 0x66,
  0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, 0x20, 0x69, 0x6e,
  0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x66, 0x72, 0x61, 0x67, 0x43, 0x6f,
  0x6f, 0x72, 0x64, 0x20, 0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a,
  0x09, 0x76, 0x65, 0x63, 0x32, 0x20, 0x75, 0x76, 0x20, 0x3d, 0x20, 0x66,
  0x72, 0x61, 0x67, 0x43, 0x6f, 0x6f, 0x72, 0x64, 0x2f, 0x69, 0x52, 0x65,
  0x73, 0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x79, 0x3b,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x77,
  0x69, 0x64, 0x74, 0x68, 0x48, 0x65, 0x69, 0x67, 0x68, 0x74, 0x52, 0x61,
  0x74, 0x69, 0x6f, 0x20, 0x3d, 0x20, 0x69, 0x52, 0x65, 0x73, 0x6f, 0x6c,
  0x75, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x78, 0x2f, 0x69, 0x52, 0x65, 0x73,
  0x6f, 0x6c, 0x75, 0x74, 0x69, 0x6f, 0x6e, 0x2e, 0x79, 0x3b, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x63, 0x65, 0x6e, 0x74,
  0x72, 0x65, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76, 0x65, 0x63, 0x32,
  0x20, 0x70, 0x6f, 0x73, 0x3b, 0x0a, 0x09, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x74, 0x20, 0x3d, 0x20, 0x69, 0x54,
  0x69, 0x6d, 0x65, 0x20, 0x2a, 0x20, 0x30, 0x2e, 0x30, 0x32, 0x35, 0x3b,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x6c,
  0x6f, 0x61, 0x74, 0x20, 0x64, 0x69, 0x73, 0x74, 0x3b, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x67, 0x6c, 0x6f, 0x77,
  0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76, 0x65, 0x63, 0x33, 0x20, 0x63,
  0x6f, 0x6c, 0x20, 0x3d, 0x20, 0x76, 0x65, 0x63, 0x33, 0x28, 0x30, 0x29,
  0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2f,
  0x2f, 0x54, 0x68, 0x65, 0x20, 0x73, 0x70, 0x61, 0x63, 0x69, 0x6e, 0x67,
  0x20, 0x62, 0x65, 0x74, 0x77, 0x65, 0x65, 0x6e, 0x20, 0x73, 0x68, 0x61,
  0x70, 0x65, 0x73, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6f, 0x6e, 0x73,
  0x74, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x73, 0x63, 0x61, 0x6c,
  0x65, 0x20, 0x3d, 0x20, 0x35, 0x30, 0x30, 0x2e, 0x30, 0x3b, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x2f, 0x2f, 0x4e, 0x75, 0x6d, 0x62, 0x65, 0x72, 0x20,
  0x6f, 0x66, 0x20, 0x73, 0x68, 0x61, 0x70, 0x65, 0x73, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x20, 0x66, 0x6c, 0x6f, 0x61,
  0x74, 0x20, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x73, 0x20, 0x3d, 0x20, 0x38,
  0x2e, 0x30, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x64, 0x65, 0x70, 0x74, 0x68,
  0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x62,
  0x65, 0x6e, 0x64, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x20, 0x76, 0x65, 0x63, 0x33,
  0x20, 0x70, 0x75, 0x72, 0x70, 0x6c, 0x65, 0x20, 0x3d, 0x20, 0x76, 0x65,
  0x63, 0x33, 0x28, 0x30, 0x2e, 0x36, 0x31, 0x31, 0x2c, 0x20, 0x30, 0x2e,
  0x31, 0x32, 0x39, 0x2c, 0x20, 0x30, 0x2e, 0x39, 0x30, 0x39, 0x29, 0x3b,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x63, 0x6f, 0x6e, 0x73, 0x74, 0x20, 0x76,
  0x65, 0x63, 0x33, 0x20, 0x67, 0x72, 0x65, 0x65, 0x6e, 0x20, 0x3d, 0x20,
  0x76, 0x65, 0x63, 0x33, 0x28, 0x30, 0x2e, 0x31, 0x33, 0x33, 0x2c, 0x20,
  0x30, 0x2e, 0x36, 0x32, 0x2c, 0x20, 0x30, 0x2e, 0x36, 0x39, 0x38, 0x29,
  0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66,
  0x6c, 0x6f, 0x61, 0x74, 0x20, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x3b, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x72, 0x6f,
  0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x41, 0x6e, 0x67, 0x6c, 0x65, 0x3b,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x6d, 0x61, 0x74, 0x32, 0x20, 0x72, 0x6f,
  0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x46, 0x6f, 0x72, 0x20, 0x6d,
  0x6f, 0x76, 0x65, 0x6d, 0x65, 0x6e, 0x74, 0x20, 0x6f, 0x66, 0x20, 0x74,
  0x68, 0x65, 0x20, 0x61, 0x6e, 0x63, 0x68, 0x6f, 0x72, 0x20, 0x70, 0x6f,
  0x69, 0x6e, 0x74, 0x20, 0x69, 0x6e, 0x20, 0x74, 0x69, 0x6d, 0x65, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x64, 0x20,
  0x3d, 0x20, 0x32, 0x2e, 0x35, 0x2a, 0x28, 0x73, 0x69, 0x6e, 0x28, 0x74,
  0x29, 0x20, 0x2b, 0x20, 0x73, 0x69, 0x6e, 0x28, 0x33, 0x2e, 0x30, 0x2a,
  0x74, 0x29, 0x29, 0x3b, 0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f,
  0x43, 0x72, 0x65, 0x61, 0x74, 0x65, 0x20, 0x61, 0x6e, 0x20, 0x6f, 0x75,
  0x74, 0x20, 0x6f, 0x66, 0x20, 0x66, 0x72, 0x61, 0x6d, 0x65, 0x20, 0x61,
  0x6e, 0x63, 0x68, 0x6f, 0x72, 0x20, 0x70, 0x6f, 0x69, 0x6e, 0x74, 0x20,
  0x77, 0x68, 0x65, 0x72, 0x65, 0x20, 0x61, 0x6c, 0x6c, 0x20, 0x73, 0x68,
  0x61, 0x70, 0x65, 0x73, 0x20, 0x63, 0x6f, 0x6e, 0x76, 0x65, 0x72, 0x67,
  0x65, 0x20, 0x74, 0x6f, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x76, 0x65, 0x63, 0x32, 0x20, 0x61, 0x6e, 0x63, 0x68, 0x6f, 0x72,
  0x20, 0x3d, 0x20, 0x76, 0x65, 0x63, 0x32, 0x28, 0x30, 0x2e, 0x35, 0x20,
  0x2b, 0x20, 0x63, 0x6f, 0x73, 0x28, 0x64, 0x29, 0x2c, 0x20, 0x30, 0x2e,
  0x35, 0x20, 0x2b, 0x20, 0x73, 0x69, 0x6e, 0x28, 0x64, 0x29, 0x29, 0x3b,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f,
  0x43, 0x72, 0x65, 0x61, 0x74, 0x65, 0x20, 0x6c, 0x69, 0x67, 0x68, 0x74,
  0x20, 0x70, 0x75, 0x72, 0x70, 0x6c, 0x65, 0x20, 0x67, 0x6c, 0x6f, 0x77,
  0x20, 0x61, 0x74, 0x20, 0x74, 0x68, 0x65, 0x20, 0x61, 0x6e, 0x63, 0x68,
  0x6f, 0x72, 0x20, 0x6c, 0x6f, 0x61, 0x63, 0x74, 0x69, 0x6f, 0x6e, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x70, 0x6f, 0x73, 0x20, 0x3d, 0x20, 0x61, 0x6e,
  0x63, 0x68, 0x6f, 0x72, 0x20, 0x2d, 0x20, 0x75, 0x76, 0x3b, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x70, 0x6f, 0x73, 0x2e, 0x79, 0x20, 0x2f, 0x3d, 0x20,
  0x77, 0x69, 0x64, 0x74, 0x68, 0x48, 0x65, 0x69, 0x67, 0x68, 0x74, 0x52,
  0x61, 0x74, 0x69, 0x6f, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69,
  0x73, 0x74, 0x20, 0x3d, 0x20, 0x6c, 0x65, 0x6e, 0x67, 0x74, 0x68, 0x28,
  0x70, 0x6f, 0x73, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x67, 0x6c,
  0x6f, 0x77, 0x20, 0x3d, 0x20, 0x67, 0x65, 0x74, 0x47, 0x6c, 0x6f, 0x77,
  0x28, 0x64, 0x69, 0x73, 0x74, 0x2c, 0x20, 0x30, 0x2e, 0x33, 0x35, 0x2c,
  0x20, 0x31, 0x2e, 0x39, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x63,
  0x6f, 0x6c, 0x20, 0x2b, 0x3d, 0x20, 0x67, 0x6c, 0x6f, 0x77, 0x20, 0x2a,
  0x20, 0x76, 0x65, 0x63, 0x33, 0x28, 0x30, 0x2e, 0x37, 0x2c, 0x30, 0x2e,
  0x36, 0x2c, 0x31, 0x2e, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x0a, 0x09, 0x66, 0x6f, 0x72, 0x28, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20,
  0x69, 0x20, 0x3d, 0x20, 0x30, 0x2e, 0x30, 0x3b, 0x20, 0x69, 0x20, 0x3c,
  0x20, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x73, 0x3b, 0x20, 0x69, 0x2b, 0x2b,
  0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x54, 0x69,
  0x6d, 0x65, 0x20, 0x76, 0x61, 0x72, 0x79, 0x69, 0x6e, 0x67, 0x20, 0x64,
  0x65, 0x70, 0x74, 0x68, 0x20, 0x69, 0x6e, 0x66, 0x6f, 0x72, 0x6d, 0x61,
  0x74, 0x69, 0x6f, 0x6e, 0x20, 0x64, 0x65, 0x70, 0x65, 0x6e, 0x64, 0x69,
  0x6e, 0x67, 0x20, 0x6f, 0x6e, 0x20, 0x6c, 0x61, 0x79, 0x65, 0x72, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x64, 0x65, 0x70, 0x74,
  0x68, 0x20, 0x3d, 0x20, 0x66, 0x72, 0x61, 0x63, 0x74, 0x28, 0x69, 0x2f,
  0x6c, 0x61, 0x79, 0x65, 0x72, 0x73, 0x20, 0x2b, 0x20, 0x74, 0x29, 0x3b,
  0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f,
  0x4d, 0x6f, 0x76, 0x65, 0x20, 0x74, 0x68, 0x65, 0x20, 0x66, 0x6f, 0x63,
  0x75, 0x73, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x61,
  0x6d, 0x65, 0x72, 0x61, 0x20, 0x69, 0x6e, 0x20, 0x61, 0x20, 0x63, 0x69,
  0x72, 0x63, 0x6c, 0x65, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x63, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x20, 0x3d, 0x20, 0x76, 0x65,
  0x63, 0x32, 0x28, 0x30, 0x2e, 0x35, 0x20, 0x2b, 0x20, 0x30, 0x2e, 0x32,
  0x20, 0x2a, 0x20, 0x73, 0x69, 0x6e, 0x28, 0x74, 0x29, 0x2c, 0x20, 0x30,
  0x2e, 0x35, 0x20, 0x2b, 0x20, 0x30, 0x2e, 0x32, 0x20, 0x2a, 0x20, 0x63,
  0x6f, 0x73, 0x28, 0x74, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x2f, 0x2f, 0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20,
  0x73, 0x68, 0x61, 0x70, 0x65, 0x73, 0x20, 0x62, 0x65, 0x74, 0x77, 0x65,
  0x65, 0x6e, 0x20, 0x74, 0x68, 0x65, 0x20, 0x61, 0x6e, 0x63, 0x68, 0x6f,
  0x72, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x74, 0x68, 0x65, 0x20, 0x63, 0x61,
  0x6d, 0x65, 0x72, 0x61, 0x20, 0x66, 0x6f, 0x63, 0x75, 0x73, 0x20, 0x62,
  0x61, 0x73, 0x65, 0x64, 0x20, 0x6f, 0x6e, 0x20, 0x64, 0x65, 0x70, 0x74,
  0x68, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x62, 0x65,
  0x6e, 0x64, 0x20, 0x3d, 0x20, 0x6d, 0x69, 0x78, 0x28, 0x61, 0x6e, 0x63,
  0x68, 0x6f, 0x72, 0x2c, 0x20, 0x63, 0x65, 0x6e, 0x74, 0x72, 0x65, 0x2c,
  0x20, 0x64, 0x65, 0x70, 0x74, 0x68, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x09, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x70, 0x6f, 0x73, 0x20, 0x3d, 0x20, 0x62, 0x65, 0x6e, 0x64, 0x20, 0x2d,
  0x20, 0x75, 0x76, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x09, 0x70, 0x6f,
  0x73, 0x2e, 0x79, 0x20, 0x2f, 0x3d, 0x20, 0x77, 0x69, 0x64, 0x74, 0x68,
  0x48, 0x65, 0x69, 0x67, 0x68, 0x74, 0x52, 0x61, 0x74, 0x69, 0x6f, 0x3b,
  0x0a, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f,
  0x52, 0x6f, 0x74, 0x61, 0x74, 0x65, 0x20, 0x73, 0x68, 0x61, 0x70, 0x65,
  0x73, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x09, 0x72, 0x6f,
  0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x41, 0x6e, 0x67, 0x6c, 0x65, 0x20,
  0x3d, 0x20, 0x33, 0x2e, 0x31, 0x34, 0x20, 0x2a, 0x20, 0x73, 0x69, 0x6e,
  0x28, 0x64, 0x65, 0x70, 0x74, 0x68, 0x20, 0x2b, 0x20, 0x66, 0x72, 0x61,
  0x63, 0x74, 0x28, 0x74, 0x29, 0x20, 0x2a, 0x20, 0x36, 0x2e, 0x32, 0x38,
  0x29, 0x20, 0x2b, 0x20, 0x69, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x72, 0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20,
  0x3d, 0x20, 0x6d, 0x61, 0x74, 0x32, 0x28, 0x63, 0x6f, 0x73, 0x28, 0x72,
  0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x41, 0x6e, 0x67, 0x6c, 0x65,
  0x29, 0x2c, 0x20, 0x2d, 0x73, 0x69, 0x6e, 0x28, 0x72, 0x6f, 0x74, 0x61,
  0x74, 0x69, 0x6f, 0x6e, 0x41, 0x6e, 0x67, 0x6c, 0x65, 0x29, 0x2c, 0x20,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x73, 0x69, 0x6e, 0x28, 0x72, 0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f,
  0x6e, 0x41, 0x6e, 0x67, 0x6c, 0x65, 0x29, 0x2c, 0x20, 0x20, 0x63, 0x6f,
  0x73, 0x28, 0x72, 0x6f, 0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x41, 0x6e,
  0x67, 0x6c, 0x65, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x70, 0x6f, 0x73, 0x20, 0x2a, 0x3d, 0x20, 0x72, 0x6f, 0x74, 0x61, 0x74,
  0x69, 0x6f, 0x6e, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f,
  0x50, 0x6f, 0x73, 0x69, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x73, 0x68, 0x61,
  0x70, 0x65, 0x73, 0x20, 0x61, 0x63, 0x63, 0x6f, 0x72, 0x64, 0x69, 0x6e,
  0x67, 0x20, 0x74, 0x6f, 0x20, 0x64, 0x65, 0x70, 0x74, 0x68, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x09, 0x70, 0x6f, 0x73, 0x20, 0x2a, 0x3d, 0x20, 0x6d,
  0x69, 0x78, 0x28, 0x73, 0x63, 0x61, 0x6c, 0x65, 0x2c, 0x20, 0x30, 0x2e,
  0x30, 0x2c, 0x20, 0x64, 0x65, 0x70, 0x74, 0x68, 0x29, 0x3b, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x09, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x66, 0x6c, 0x6f, 0x61, 0x74, 0x20, 0x6d, 0x20, 0x3d, 0x20, 0x6d,
  0x6f, 0x64, 0x28, 0x69, 0x2c, 0x20, 0x34, 0x2e, 0x30, 0x29, 0x3b, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x69, 0x66, 0x28, 0x6d,
  0x20, 0x3d, 0x3d, 0x20, 0x30, 0x2e, 0x30, 0x29, 0x7b, 0x0a, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x09, 0x64, 0x69, 0x73, 0x74, 0x20,
  0x3d, 0x20, 0x61, 0x62, 0x73, 0x28, 0x62, 0x6f, 0x78, 0x44, 0x69, 0x73,
  0x74, 0x28, 0x70, 0x6f, 0x73, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x65, 0x6c, 0x73, 0x65, 0x20, 0x69,
  0x66, 0x28, 0x6d, 0x20, 0x3d, 0x3d, 0x20, 0x31, 0x2e, 0x30, 0x29, 0x7b,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x09, 0x64, 0x69,
  0x73, 0x74, 0x20, 0x3d, 0x20, 0x61, 0x62, 0x73, 0x28, 0x74, 0x72, 0x69,
  0x61, 0x6e, 0x67, 0x6c, 0x65, 0x44, 0x69, 0x73, 0x74, 0x28, 0x70, 0x6f,
  0x73, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x7d, 0x65, 0x6c, 0x73, 0x65, 0x20, 0x69, 0x66, 0x28, 0x6d, 0x20,
  0x3d, 0x3d, 0x20, 0x32, 0x2e, 0x30, 0x29, 0x7b, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x64, 0x69, 0x73,
  0x74, 0x20, 0x3d, 0x20, 0x61, 0x62, 0x73, 0x28, 0x63, 0x72, 0x6f, 0x73,
  0x73, 0x44, 0x69, 0x73, 0x74, 0x28, 0x70, 0x6f, 0x73, 0x29, 0x29, 0x3b,
  0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x7d, 0x65, 0x6c,
  0x73, 0x65, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x09, 0x64, 0x69, 0x73, 0x74, 0x20, 0x3d, 0x20, 0x61, 0x62, 0x73, 0x28,
  0x63, 0x69, 0x72, 0x63, 0x6c, 0x65, 0x44, 0x69, 0x73, 0x74, 0x28, 0x70,
  0x6f, 0x73, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x7d, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x0a,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x47, 0x65,
  0x74, 0x20, 0x67, 0x6c, 0x6f, 0x77, 0x20, 0x66, 0x72, 0x6f, 0x6d, 0x20,
  0x62, 0x61, 0x73, 0x65, 0x20, 0x72, 0x61, 0x64, 0x69, 0x75, 0x73, 0x20,
  0x61, 0x6e, 0x64, 0x20, 0x69, 0x6e, 0x74, 0x65, 0x6e, 0x73, 0x69, 0x74,
  0x79, 0x20, 0x6d, 0x6f, 0x64, 0x69, 0x66, 0x69, 0x65, 0x64, 0x20, 0x62,
  0x79, 0x20, 0x64, 0x65, 0x70, 0x74, 0x68, 0x0a, 0x20, 0x20, 0x20, 0x20,
  0x09, 0x67, 0x6c, 0x6f, 0x77, 0x20, 0x3d, 0x20, 0x67, 0x65, 0x74, 0x47,
  0x6c, 0x6f, 0x77, 0x28, 0x64, 0x69, 0x73, 0x74, 0x2c, 0x20, 0x72, 0x61,
  0x64, 0x69, 0x75, 0x73, 0x2b, 0x28, 0x31, 0x2e, 0x30, 0x2d, 0x64, 0x65,
  0x70, 0x74, 0x68, 0x29, 0x2a, 0x32, 0x2e, 0x30, 0x2c, 0x20, 0x69, 0x6e,
  0x74, 0x65, 0x6e, 0x73, 0x69, 0x74, 0x79, 0x20, 0x2b, 0x20, 0x64, 0x65,
  0x70, 0x74, 0x68, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f,
  0x2f, 0x46, 0x69, 0x6e, 0x64, 0x20, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x20,
  0x61, 0x6c, 0x6f, 0x6e, 0x67, 0x20, 0x73, 0x68, 0x61, 0x70, 0x65, 0x20,
  0x61, 0x6e, 0x64, 0x20, 0x6d, 0x61, 0x70, 0x20, 0x66, 0x72, 0x6f, 0x6d,
  0x20, 0x5b, 0x2d, 0x50, 0x49, 0x3b, 0x20, 0x50, 0x49, 0x5d, 0x20, 0x74,
  0x6f, 0x20, 0x5b, 0x30, 0x3b, 0x20, 0x31, 0x5d, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x20, 0x3d,
  0x20, 0x28, 0x61, 0x74, 0x61, 0x6e, 0x28, 0x70, 0x6f, 0x73, 0x2e, 0x79,
  0x2c, 0x20, 0x70, 0x6f, 0x73, 0x2e, 0x78, 0x29, 0x2b, 0x33, 0x2e, 0x31,
  0x34, 0x29, 0x2f, 0x36, 0x2e, 0x32, 0x38, 0x3b, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x53, 0x68, 0x69, 0x66, 0x74,
  0x20, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x20, 0x64, 0x65, 0x70, 0x65, 0x6e,
  0x64, 0x69, 0x6e, 0x67, 0x20, 0x6f, 0x6e, 0x20, 0x6c, 0x61, 0x79, 0x65,
  0x72, 0x20, 0x61, 0x6e, 0x64, 0x20, 0x6d, 0x61, 0x70, 0x20, 0x74, 0x6f,
  0x20, 0x5b, 0x31, 0x2e, 0x2e, 0x2e, 0x30, 0x2e, 0x2e, 0x2e, 0x31, 0x5d,
  0x0a, 0x09, 0x09, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x20, 0x3d, 0x20, 0x61,
  0x62, 0x73, 0x28, 0x28, 0x32, 0x2e, 0x30, 0x2a, 0x66, 0x72, 0x61, 0x63,
  0x74, 0x28, 0x61, 0x6e, 0x67, 0x6c, 0x65, 0x20, 0x2b, 0x20, 0x69, 0x2f,
  0x6c, 0x61, 0x79, 0x65, 0x72, 0x73, 0x29, 0x29, 0x20, 0x2d, 0x20, 0x31,
  0x2e, 0x30, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f,
  0x57, 0x68, 0x69, 0x74, 0x65, 0x20, 0x63, 0x6f, 0x72, 0x65, 0x0a, 0x20,
  0x20, 0x20, 0x20, 0x09, 0x2f, 0x2f, 0x63, 0x6f, 0x6c, 0x20, 0x2b, 0x3d,
  0x20, 0x31, 0x30, 0x2e, 0x30, 0x2a, 0x76, 0x65, 0x63, 0x33, 0x28, 0x73,
  0x6d, 0x6f, 0x6f, 0x74, 0x68, 0x73, 0x74, 0x65, 0x70, 0x28, 0x30, 0x2e,
  0x30, 0x33, 0x2c, 0x20, 0x30, 0x2e, 0x30, 0x32, 0x2c, 0x20, 0x64, 0x69,
  0x73, 0x74, 0x29, 0x29, 0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x20, 0x2f,
  0x2f, 0x47, 0x6c, 0x6f, 0x77, 0x20, 0x61, 0x63, 0x63, 0x6f, 0x72, 0x64,
  0x69, 0x6e, 0x67, 0x20, 0x74, 0x6f, 0x20, 0x61, 0x6e, 0x67, 0x6c, 0x65,
  0x20, 0x76, 0x61, 0x6c, 0x75, 0x65, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x20,
  0x09, 0x63, 0x6f, 0x6c, 0x20, 0x2b, 0x3d, 0x20, 0x67, 0x6c, 0x6f, 0x77,
  0x20, 0x2a, 0x20, 0x6d, 0x69, 0x78, 0x28, 0x67, 0x72, 0x65, 0x65, 0x6e,
  0x2c, 0x20, 0x70, 0x75, 0x72, 0x70, 0x6c, 0x65, 0x2c, 0x20, 0x61, 0x6e,
  0x67, 0x6c, 0x65, 0x29, 0x3b, 0x0a, 0x09, 0x7d, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2f, 0x2f, 0x54, 0x6f, 0x6e, 0x65,
  0x20, 0x6d, 0x61, 0x70, 0x70, 0x69, 0x6e, 0x67, 0x0a, 0x20, 0x20, 0x20,
  0x20, 0x2f, 0x2f, 0x63, 0x6f, 0x6c, 0x20, 0x3d, 0x20, 0x31, 0x2e, 0x30,
  0x20, 0x2d, 0x20, 0x65, 0x78, 0x70, 0x28, 0x2d, 0x63, 0x6f, 0x6c, 0x29,
  0x3b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x2f,
  0x2f, 0x4f, 0x75, 0x74, 0x70, 0x75, 0x74, 0x20, 0x74, 0x6f, 0x20, 0x73,
  0x63, 0x72, 0x65, 0x65, 0x6e, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x66, 0x72,
  0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x20, 0x3d, 0x20, 0x76, 0x65,
  0x63, 0x34, 0x28, 0x63, 0x6f, 0x6c, 0x2c, 0x31, 0x2e, 0x30, 0x29, 0x3b,
  0x0a, 0x7d, 0x0a, 0x2f, 0x2f, 0x20, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d,
  0x2d, 0x2d, 0x5b, 0x20, 0x4f, 0x72, 0x69, 0x67, 0x69, 0x6e, 0x61, 0x6c,
  0x20, 0x53, 0x68, 0x61, 0x64, 0x65, 0x72, 0x54, 0x6f, 0x79, 0x20, 0x65,
  0x6e, 0x64, 0x73, 0x20, 0x68, 0x65, 0x72, 0x65, 0x20, 0x5d, 0x2d, 0x2d,
  0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x2d, 0x20, 0x2f, 0x2f, 0x0a,
  0x0a, 0x76, 0x6f, 0x69, 0x64, 0x20, 0x6d, 0x61, 0x69, 0x6e, 0x28, 0x76,
  0x6f, 0x69, 0x64, 0x29, 0x0a, 0x7b, 0x0a, 0x20, 0x20, 0x20, 0x20, 0x6d,
  0x61, 0x69, 0x6e, 0x49, 0x6d, 0x61, 0x67, 0x65, 0x28, 0x67, 0x6c, 0x5f,
  0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6c, 0x6f, 0x72, 0x2c, 0x20, 0x67,
  0x6c, 0x5f, 0x46, 0x72, 0x61, 0x67, 0x43, 0x6f, 0x6f, 0x72, 0x64, 0x2e,
  0x78, 0x79, 0x29, 0x3b, 0x0a, 0x7d
};
static unsigned int ps_signs_shader_len = 4218;
