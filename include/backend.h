//THIS FILE AUTOGENERATED
#ifndef BACKEND_H
#define BACKEND_H

#include <stdint.h> // for integers
#include <stdbool.h> // for bool

enum FG_Format {
  FG_Format_JPG = 11,
  FG_Format_WEAK_LAYER = 7,
  FG_Format_VERTEX_BUFFER = 1,
  FG_Format_SVG = 20,
  FG_Format_STORAGE_BUFFER = 4,
  FG_Format_BMP = 10,
  FG_Format_ICO = 13,
  FG_Format_WEBP = 17,
  FG_Format_LAYER = 6,
  FG_Format_ELEMENT_BUFFER = 2,
  FG_Format_GIF = 14,
  FG_Format_MKV = 23,
  FG_Format_UNKNOWN_BUFFER = 5,
  FG_Format_DDS = 18,
  FG_Format_MP4 = 22,
  FG_Format_AVI = 21,
  FG_Format_WIC = 19,
  FG_Format_ATLAS = 9,
  FG_Format_UNKNOWN = 255,
  FG_Format_UNIFORM_BUFFER = 3,
  FG_Format_GRADIENT = 0,
  FG_Format_PNG = 12,
  FG_Format_TIFF = 15,
  FG_Format_TEXTURE = 8,
  FG_Format_TGA = 16,
  FG_Format_WEBM = 24
};
enum FG_BlendValue {
  FG_BlendValue_DST_COLOR = 4,
  FG_BlendValue_SRC_ALPHA_SATURATE = 14,
  FG_BlendValue_INV_SRC_COLOR = 3,
  FG_BlendValue_INV_CONSTANT_ALPHA = 13,
  FG_BlendValue_INV_SRC_ALPHA = 7,
  FG_BlendValue_CONSTANT_ALPHA = 12,
  FG_BlendValue_ZERO = 0,
  FG_BlendValue_INV_CONSTANT_COLOR = 11,
  FG_BlendValue_CONSTANT_COLOR = 10,
  FG_BlendValue_ONE = 1,
  FG_BlendValue_SRC_ALPHA = 6,
  FG_BlendValue_SRC_COLOR = 2,
  FG_BlendValue_INV_DST_ALPHA = 9,
  FG_BlendValue_DST_ALPHA = 8,
  FG_BlendValue_INV_DST_COLOR = 5
};
typedef struct FG_Rect__ FG_Rect;
typedef float FG_anon_1[4];
struct FG_Rect__ {
  union {
    struct
    {
      float left;
      float top;
      float right;
      float bottom;
    };

    float ltrb[4];
  };
};
typedef struct FG_Asset__ FG_Asset;
typedef struct FG_Data__ FG_Data;
struct FG_Data__ {
  union {
  void * data;
  uint32_t index;
};
};
enum FG_AssetFlags {
  FG_AssetFlags_CUBE_MAP = 8,
  FG_AssetFlags_CACHE_LAYER = 4,
  FG_AssetFlags_NO_MIPMAP = 2,
  FG_AssetFlags_LINEAR = 1
};
typedef struct FG_anon_2__ FG_anon_2;
typedef struct FG_Veci__ FG_Veci;
typedef int32_t FG_anon_3[2];
struct FG_Veci__ {
  int x;
    int y;
    
};
typedef struct FG_Vec__ FG_Vec;
typedef float FG_anon_4[2];
struct FG_Vec__ {
  float x;
    float y;
    
};
struct FG_anon_2__ {
  FG_Veci size;
  FG_Vec dpi;
};
typedef struct FG_anon_5__ FG_anon_5;
enum FG_PixelFormat {
  FG_PixelFormat_R8G8B8A8_UINT = 36,
  FG_PixelFormat_D16_UNORM = 67,
  FG_PixelFormat_R8G8B8A8_UNORM = 34,
  FG_PixelFormat_B5G5R5A1_UNORM = 100,
  FG_PixelFormat_V408 = 131,
  FG_PixelFormat_IA44 = 125,
  FG_PixelFormat_AYUV = 114,
  FG_PixelFormat_R16_UNORM = 68,
  FG_PixelFormat_R32G32_UINT = 23,
  FG_PixelFormat_Y416 = 116,
  FG_PixelFormat_BC6H_UF16 = 109,
  FG_PixelFormat_R8G8B8X8_TYPELESS = 39,
  FG_PixelFormat_D24_UNORM_X8_TYPELESS = 57,
  FG_PixelFormat_R32_INT = 54,
  FG_PixelFormat_R16G16_UNORM = 46,
  FG_PixelFormat_B8G8R8X8_TYPELESS = 106,
  FG_PixelFormat_R5G5B5A1_UNORM = 98,
  FG_PixelFormat_D24_UNORM_S8_UINT = 56,
  FG_PixelFormat_R8G8_B8G8_UNORM = 80,
  FG_PixelFormat_BC1_TYPELESS = 82,
  FG_PixelFormat_BC4_UNORM = 92,
  FG_PixelFormat_R16G16B16A16_TYPELESS = 9,
  FG_PixelFormat_R8G8B8X8_UINT = 42,
  FG_PixelFormat_R16G16B16A16_INT = 14,
  FG_PixelFormat_R24G8_TYPELESS = 55,
  FG_PixelFormat_BC3_TYPELESS = 88,
  FG_PixelFormat_BC6H_SF16 = 110,
  FG_PixelFormat_R8_SNORM = 75,
  FG_PixelFormat_P010 = 118,
  FG_PixelFormat_R8_UNORM = 73,
  FG_PixelFormat_A8_UNORM = 77,
  FG_PixelFormat_R10G10B10A2_UNORM = 30,
  FG_PixelFormat_R32G32B32_FLOAT = 6,
  FG_PixelFormat_R32G8X24_TYPELESS = 25,
  FG_PixelFormat_Y210 = 121,
  FG_PixelFormat_NV11 = 123,
  FG_PixelFormat_R8G8_TYPELESS = 60,
  FG_PixelFormat_D32_FLOAT_S8X24_UINT = 26,
  FG_PixelFormat_R10G10B10A2_TYPELESS = 29,
  FG_PixelFormat_R16_FLOAT = 66,
  FG_PixelFormat_R32G32B32A32_UINT = 3,
  FG_PixelFormat_B8G8R8X8_UNORM = 102,
  FG_PixelFormat_BC1_UNORM = 83,
  FG_PixelFormat_BC3_UNORM_SRGB = 90,
  FG_PixelFormat_R32_FLOAT_X8X24_TYPELESS = 27,
  FG_PixelFormat_R8G8B8A8_TYPELESS = 33,
  FG_PixelFormat_R16G16B16A16_FLOAT = 10,
  FG_PixelFormat_R32G32B32A32_TYPELESS = 1,
  FG_PixelFormat_P016 = 119,
  FG_PixelFormat_A8P8 = 127,
  FG_PixelFormat_R16G16_SNORM = 48,
  FG_PixelFormat_R8_UINT = 74,
  FG_PixelFormat_B8G8R8A8_TYPELESS = 104,
  FG_PixelFormat_R32G32B32A32_FLOAT = 2,
  FG_PixelFormat_R32G32B32_INT = 8,
  FG_PixelFormat_NV12 = 117,
  FG_PixelFormat_BC5_UNORM = 95,
  FG_PixelFormat_R8G8B8A8_INT = 38,
  FG_PixelFormat_V208 = 130,
  FG_PixelFormat_R8G8B8X8_UNORM = 40,
  FG_PixelFormat_P8 = 126,
  FG_PixelFormat_R32G32_TYPELESS = 21,
  FG_PixelFormat_B8G8R8A8_UNORM = 101,
  FG_PixelFormat_B5G6R5_UNORM = 99,
  FG_PixelFormat_X32_TYPELESS_G8X24_UINT = 28,
  FG_PixelFormat_BC4_SNORM = 93,
  FG_PixelFormat_Y216 = 122,
  FG_PixelFormat_R16G16_FLOAT = 45,
  FG_PixelFormat_R10G10B10A2_UINT = 31,
  FG_PixelFormat_R32G32B32A32_INT = 4,
  FG_PixelFormat_BC3_UNORM = 89,
  FG_PixelFormat_R32_FLOAT = 52,
  FG_PixelFormat_R10G10B10_XR_BIAS_A2_UNORM = 103,
  FG_PixelFormat_R16G16B16_FLOAT = 16,
  FG_PixelFormat_YUY2 = 120,
  FG_PixelFormat_R32G32_INT = 24,
  FG_PixelFormat_R16G16B16_INT = 20,
  FG_PixelFormat_BC2_TYPELESS = 85,
  FG_PixelFormat_BC7_TYPELESS = 111,
  FG_PixelFormat_BC5_TYPELESS = 94,
  FG_PixelFormat_BC4_TYPELESS = 91,
  FG_PixelFormat_B8G8R8X8_UNORM_SRGB = 107,
  FG_PixelFormat_P208 = 129,
  FG_PixelFormat_B4G4R4A4_UNORM = 128,
  FG_PixelFormat_X24_TYPELESS_G8_UINT = 59,
  FG_PixelFormat_R16G16B16_SNORM = 19,
  FG_PixelFormat_R8G8_UNORM = 61,
  FG_PixelFormat_BC2_UNORM = 86,
  FG_PixelFormat_D32_FLOAT = 51,
  FG_PixelFormat_G8R8_G8B8_UNORM = 81,
  FG_PixelFormat_R16G16_TYPELESS = 44,
  FG_PixelFormat_R16G16B16A16_SNORM = 13,
  FG_PixelFormat_R16_UINT = 69,
  FG_PixelFormat_R8G8B8X8_INT = 43,
  FG_PixelFormat_R16G16B16_TYPELESS = 15,
  FG_PixelFormat_BC5_SNORM = 96,
  FG_PixelFormat_Y410 = 115,
  FG_PixelFormat_R24_UNORM_X8_TYPELESS = 58,
  FG_PixelFormat_R8G8B8A8_SNORM = 37,
  FG_PixelFormat_R8G8_SNORM = 63,
  FG_PixelFormat_R8_TYPELESS = 72,
  FG_PixelFormat_R32G32_FLOAT = 22,
  FG_PixelFormat_R8_INT = 76,
  FG_PixelFormat_R32_TYPELESS = 50,
  FG_PixelFormat_R9G9B9E5_SHAREDEXP = 79,
  FG_PixelFormat_R16G16_INT = 49,
  FG_PixelFormat_R16G16B16A16_UINT = 12,
  FG_PixelFormat_R11G11B10_FLOAT = 32,
  FG_PixelFormat_BC2_UNORM_SRGB = 87,
  FG_PixelFormat_R32_UINT = 53,
  FG_PixelFormat_R8G8B8X8_SNORM = 41,
  FG_PixelFormat_R8G8_INT = 64,
  FG_PixelFormat_R16G16_UINT = 47,
  FG_PixelFormat_R16G16B16A16_UNORM = 11,
  FG_PixelFormat_R16_SNORM = 70,
  FG_PixelFormat_BC7_UNORM = 112,
  FG_PixelFormat_AI44 = 124,
  FG_PixelFormat_R16_INT = 71,
  FG_PixelFormat_R16_TYPELESS = 65,
  FG_PixelFormat_R16G16B16_UNORM = 17,
  FG_PixelFormat_R1_UNORM = 78,
  FG_PixelFormat_R8G8B8A8_UNORM_SRGB = 35,
  FG_PixelFormat_B8G8R8A8_UNORM_SRGB = 105,
  FG_PixelFormat_BC1_UNORM_SRGB = 84,
  FG_PixelFormat_UNKNOWN = 0,
  FG_PixelFormat_R5G6B5_UNORM = 97,
  FG_PixelFormat_BC6H_TYPELESS = 108,
  FG_PixelFormat_R32G32B32_TYPELESS = 5,
  FG_PixelFormat_R16G16B16_UINT = 18,
  FG_PixelFormat_BC7_UNORM_SRGB = 113,
  FG_PixelFormat_R32G32B32_UINT = 7,
  FG_PixelFormat_R8G8_UINT = 62
};
struct FG_anon_5__ {
  uint32_t bytes;
  uint8_t subformat;
};
struct FG_Asset__ {
  FG_Data data;
  enum FG_Format format;
  int flags;
  union {
    struct {
      FG_Veci size;
      FG_Vec dpi;
    };
    struct {
      uint32_t bytes;
      uint8_t subformat;
    };
  };
};
typedef struct FG_Backend__ FG_Backend;
typedef void (* FG_anon_6)(FG_Backend *);
enum FG_Feature {
  FG_Feature_BACKGROUND_OPACITY = 16777216,
  FG_Feature_LINES_ALPHA = 16384,
  FG_Feature_RECT_CORNERS = 64,
  FG_Feature_ARC_INNER = 1024,
  FG_Feature_LAYER_TRANSFORM = 131072,
  FG_Feature_SHAPE_ALPHA = 32,
  FG_Feature_TEXT_ANTIALIAS = 1,
  FG_Feature_TEXT_BLUR = 4,
  FG_Feature_TEXT_SUBPIXEL = 2,
  FG_Feature_ARC_BORDER = 2048,
  FG_Feature_IMMEDIATE_MODE = 33554432,
  FG_Feature_CURVE_STROKE = 32768,
  FG_Feature_SHADER_GLSL_ES2 = 2097152,
  FG_Feature_SHADER_HLSL2 = 8388608,
  FG_Feature_SHADER_GLSL4 = 4194304,
  FG_Feature_TEXT_ALPHA = 8,
  FG_Feature_BATCHING = 1048576,
  FG_Feature_TRIANGLE_BORDER = 8192,
  FG_Feature_GAMMA = 524288,
  FG_Feature_SHAPE_BLUR = 16,
  FG_Feature_LAYER_OPACITY = 262144,
  FG_Feature_TRIANGLE_CORNERS = 4096,
  FG_Feature_CIRCLE_BORDER = 512,
  FG_Feature_RECT_BORDER = 128,
  FG_Feature_CURVE_FILL = 65536,
  FG_Feature_CIRCLE_INNER = 256
};
typedef struct FG_Window__ FG_Window;
struct FG_Window__ {
  void * handle;
  void * device;
  void * context;
  void * memory;
};
typedef struct FG_Command__ FG_Command;
enum FG_Category {
  FG_Category_ARC = 4,
  FG_Category_SHADER = 13,
  FG_Category_LINES = 6,
  FG_Category_ICOSPHERE = 11,
  FG_Category_ASSET = 1,
  FG_Category_RECT = 2,
  FG_Category_CUBE = 10,
  FG_Category_CURVE = 7,
  FG_Category_CIRCLE = 3,
  FG_Category_LINES3D = 8,
  FG_Category_CYLINDER = 12,
  FG_Category_CURVE3D = 9,
  FG_Category_TRIANGLE = 5,
  FG_Category_TEXT = 0
};
typedef struct FG_anon_8__ FG_anon_8;
typedef struct FG_Font__ FG_Font;
enum FG_AntiAliasing {
  FG_AntiAliasing_AA = 1,
  FG_AntiAliasing_LCD_V = 4,
  FG_AntiAliasing_SDF = 8,
  FG_AntiAliasing_LCD = 2
};
struct FG_Font__ {
  FG_Data data;
  FG_Vec dpi;
  float baseline;
  float lineheight;
  uint32_t pt;
  enum FG_AntiAliasing aa;
};
typedef struct FG_Color__ FG_Color;
struct FG_Color__ {
  union {
    unsigned int v;
    unsigned char colors[4];
    struct
    {
      unsigned char b;
      unsigned char g;
      unsigned char r;
      unsigned char a;
    };
  };
};
struct FG_anon_8__ {
  FG_Font * font;
  void * layout;
  FG_Rect * area;
  FG_Color color;
  float blur;
  float rotate;
  float z;
};
typedef struct FG_anon_9__ FG_anon_9;
struct FG_anon_9__ {
  FG_Asset * asset;
  FG_Rect * area;
  FG_Rect * source;
  FG_Color color;
  float time;
  float rotate;
  float z;
};
typedef struct FG_anon_10__ FG_anon_10;
typedef struct FG_anon_11__ FG_anon_11;
struct FG_anon_11__ {
  FG_Rect * corners;
  float rotate;
};
typedef struct FG_anon_12__ FG_anon_12;
struct FG_anon_12__ {
  float innerRadius;
  float innerBorder;
};
typedef struct FG_anon_13__ FG_anon_13;
struct FG_anon_13__ {
  FG_Vec angles;
  float innerRadius;
};
typedef struct FG_anon_14__ FG_anon_14;
struct FG_anon_14__ {
  FG_Rect * corners;
  float rotate;
};
struct FG_anon_10__ {
  FG_Rect * area;
  FG_Color fillColor;
  float border;
  FG_Color borderColor;
  float blur;
  FG_Asset * asset;
  float z;
  union {
  FG_anon_11 rect;
  FG_anon_12 circle;
  FG_anon_13 arc;
  FG_anon_14 triangle;
};
};
typedef struct FG_anon_15__ FG_anon_15;
typedef struct FG_Vec3__ FG_Vec3;
typedef float FG_anon_16[3];
struct FG_Vec3__ {
  float x;
    float y;
    float z;
    
};
struct FG_anon_15__ {
  union {
  FG_Vec * points;
  FG_Vec3 * points3D;
};
  uint32_t count;
  FG_Color color;
};
typedef struct FG_anon_17__ FG_anon_17;
struct FG_anon_17__ {
  union {
  FG_Vec * points;
  FG_Vec3 * points3D;
};
  uint32_t count;
  FG_Color fillColor;
  float stroke;
  FG_Color strokeColor;
};
typedef struct FG_anon_18__ FG_anon_18;
typedef struct FG_Shader__ FG_Shader;
typedef struct FG_ShaderParameter__ FG_ShaderParameter;
enum FG_ShaderType {
  FG_ShaderType_COLOR32 = 5,
  FG_ShaderType_FLOAT = 1,
  FG_ShaderType_TEXTURE = 6,
  FG_ShaderType_INT = 3,
  FG_ShaderType_DOUBLE = 2,
  FG_ShaderType_TEXCUBE = 7,
  FG_ShaderType_UINT = 4,
  FG_ShaderType_HALF = 0
};
struct FG_ShaderParameter__ {
  enum FG_ShaderType type;
  uint32_t length;
  uint32_t multi;
  const char* name;
  uint16_t index;
  uint16_t step;
};
struct FG_Shader__ {
  void * data;
  FG_ShaderParameter * parameters;
  uint32_t n_parameters;
};
typedef struct FG_ShaderValue__ FG_ShaderValue;
struct FG_ShaderValue__ {
  union {
  float f32;
  double f64;
  int32_t i32;
  uint32_t u32;
  float * pf32;
  double * pf64;
  int32_t * pi32;
  uint32_t * pu32;
  FG_Asset * asset;
};
};
struct FG_anon_18__ {
  FG_Shader * shader;
  int32_t subdivision;
  FG_ShaderValue * values;
};
typedef struct FG_anon_19__ FG_anon_19;
enum FG_Primitive {
  FG_Primitive_LINE = 1,
  FG_Primitive_TRIANGLE = 2,
  FG_Primitive_LINE_STRIP = 3,
  FG_Primitive_TRIANGLE_STRIP_ADJACENCY = 8,
  FG_Primitive_LINE_STRIP_ADJACENCY = 7,
  FG_Primitive_POINT = 0,
  FG_Primitive_TRIANGLE_ADJACENCY = 6,
  FG_Primitive_LINE_ADJACENCY = 5,
  FG_Primitive_TRIANGLE_STRIP = 4
};
struct FG_anon_19__ {
  FG_Shader * shader;
  uint8_t primitive;
  void * input;
  uint32_t count;
  FG_ShaderValue * values;
};
struct FG_Command__ {
  uint8_t category;
  union {
  FG_anon_8 text;
  FG_anon_9 asset;
  FG_anon_10 shape;
  FG_anon_15 lines;
  FG_anon_17 curve;
  FG_anon_18 shape3D;
  FG_anon_19 shader;
};
};
typedef struct FG_BlendState__ FG_BlendState;
enum FG_BlendOp {
  FG_BlendOp_ADD = 0,
  FG_BlendOp_REV_SUBTRACT = 2,
  FG_BlendOp_SUBTRACT = 1
};
enum FG_DrawFlags {
  FG_DrawFlags_LINEAR = 32,
  FG_DrawFlags_WIREFRAME = 4,
  FG_DrawFlags_CCW_FRONT_FACE = 1,
  FG_DrawFlags_POINTMODE = 8,
  FG_DrawFlags_INSTANCED = 16,
  FG_DrawFlags_CULL_FACE = 2
};
struct FG_BlendState__ {
  uint8_t srcBlend;
  uint8_t destBlend;
  uint8_t colorBlend;
  uint8_t srcBlendAlpha;
  uint8_t destBlendAlpha;
  uint8_t alphaBlend;
  uint8_t mask;
  enum FG_DrawFlags flags;
  FG_Color constant;
};
typedef int32_t (* FG_anon_7)(FG_Backend *, FG_Window *, FG_Command *, uint32_t, FG_BlendState *);
typedef FG_Asset * (* FG_anon_20)(FG_Backend *, FG_Window *, const char*, uint32_t, enum FG_Format, int32_t);
enum FG_Clipboard {
  FG_Clipboard_NONE = 0,
  FG_Clipboard_ALL = 7,
  FG_Clipboard_CUSTOM = 6,
  FG_Clipboard_WAVE = 2,
  FG_Clipboard_BITMAP = 3,
  FG_Clipboard_ELEMENT = 5,
  FG_Clipboard_FILE = 4,
  FG_Clipboard_TEXT = 1
};
typedef int32_t (* FG_anon_21)(FG_Backend *, FG_Window *, enum FG_Clipboard);
typedef struct FG_Display__ FG_Display;
struct FG_Display__ {
  FG_Veci size;
  FG_Veci offset;
  FG_Vec dpi;
  float scale;
  void * handle;
  bool primary;
};
typedef int32_t (* FG_anon_22)(FG_Backend *, uint32_t, FG_Display *);
typedef int32_t (* FG_anon_23)(FG_Backend *, FG_Window *, FG_Rect *);
typedef struct FG_MsgReceiver__ FG_MsgReceiver;
struct FG_MsgReceiver__ {
  void * * vftable;
};
typedef FG_Window * (* FG_anon_24)(FG_Backend *, FG_MsgReceiver *, void *, FG_Vec *, FG_Vec *, const char*, uint64_t);
typedef int32_t (* FG_anon_25)(FG_Backend *, FG_Asset *, float);
typedef FG_Window * (* FG_anon_26)(FG_Backend *, FG_MsgReceiver *, FG_Window, FG_Vec3, FG_Vec3);
typedef int32_t (* FG_anon_27)(FG_Backend *, FG_Window *);
typedef int32_t (* FG_anon_28)(FG_Backend *, FG_Window *, enum FG_Clipboard, const char*, uint32_t);
typedef FG_Vec (* FG_anon_29)(FG_Backend *, FG_Font *, void *, FG_Rect *, uint32_t);
typedef FG_Font * (* FG_anon_30)(FG_Backend *, const char*, uint16_t, bool, uint32_t, FG_Vec, enum FG_AntiAliasing);
typedef bool (* FG_anon_31)(FG_Backend *, FG_Window *, FG_Color);
typedef void * (* FG_anon_32)(FG_Backend *);
typedef int32_t (* FG_anon_33)(FG_Backend *, FG_Window *, FG_Display *);
typedef FG_Asset * (* FG_anon_34)(FG_Backend *, FG_Window *, void *, uint32_t, uint8_t, enum FG_Format);
typedef int32_t (* FG_anon_35)(FG_Backend *, FG_Window *, FG_Asset *);
typedef void * (* FG_anon_36)(FG_Backend *, FG_Asset * *, uint32_t, FG_ShaderParameter *, uint32_t);
typedef int32_t (* FG_anon_37)(FG_Backend *, FG_Window *, void *, FG_Rect *, ...);
typedef uint32_t (* FG_anon_38)(FG_Backend *, FG_Window *, enum FG_Clipboard, void *, uint32_t);
typedef int32_t (* FG_anon_39)(FG_Backend *, void *, FG_Display *);
typedef FG_Asset * (* FG_anon_40)(FG_Backend *, FG_Window *, FG_Vec *, uint8_t, int32_t);
typedef int32_t (* FG_anon_41)(FG_Backend *);
typedef int32_t (* FG_anon_42)(FG_Backend *, FG_Window *, void *);
typedef int32_t (* FG_anon_43)(FG_Backend *, FG_Window *, FG_MsgReceiver *, void *, FG_Vec *, FG_Vec *, const char*, uint64_t);
typedef uint32_t (* FG_anon_44)(FG_Backend *, FG_Font *, void *, FG_Rect *, FG_Vec, FG_Vec *);
typedef int32_t (* FG_anon_45)(FG_Backend *, FG_Shader *);
typedef int32_t (* FG_anon_46)(FG_Backend *, FG_Font *);
typedef int32_t (* FG_anon_47)(FG_Backend *, void *);
typedef FG_Asset * (* FG_anon_48)(FG_Backend *, FG_Window *, FG_Vec *, int32_t);
enum FG_Cursor {
  FG_Cursor_NONE = 0,
  FG_Cursor_RESIZEWE = 7,
  FG_Cursor_RESIZEALL = 10,
  FG_Cursor_RESIZENS = 6,
  FG_Cursor_CUSTOM = 14,
  FG_Cursor_IBEAM = 2,
  FG_Cursor_ARROW = 1,
  FG_Cursor_DRAG = 13,
  FG_Cursor_RESIZENESW = 9,
  FG_Cursor_NO = 11,
  FG_Cursor_RESIZENWSE = 8,
  FG_Cursor_HELP = 12,
  FG_Cursor_WAIT = 4,
  FG_Cursor_HAND = 5,
  FG_Cursor_CROSS = 3
};
typedef int32_t (* FG_anon_49)(FG_Backend *, FG_Window *, enum FG_Cursor);
enum FG_BreakStyle {
  FG_BreakStyle_NONE = 0,
  FG_BreakStyle_CHARACTER = 2,
  FG_BreakStyle_WORD = 1
};
typedef void * (* FG_anon_50)(FG_Backend *, FG_Font *, const char*, FG_Rect *, float, float, enum FG_BreakStyle, void *);
typedef int32_t (* FG_anon_51)(FG_Backend *, FG_Window *, FG_Asset *, float *, float, FG_BlendState *);
typedef FG_Shader * (* FG_anon_52)(FG_Backend *, const char*, const char*, const char*, const char*, const char*, const char*, FG_ShaderParameter *, uint32_t);
typedef int32_t (* FG_anon_53)(FG_Backend *, FG_Window *, FG_Asset *, float *);
typedef void * (* FG_anon_54)(FG_Backend *, FG_Window *, const char*, FG_Rect *, ...);
typedef int32_t (* FG_anon_55)(FG_Backend *, FG_Asset *);
typedef bool (* FG_anon_56)(FG_Backend *, FG_Window *, enum FG_Clipboard);
struct FG_Backend__ {
  FG_anon_6 destroy;
  enum FG_Feature features;
  uint32_t formats;
  FG_Vec dpi;
  float scale;
  uint64_t cursorblink;
  uint64_t tooltipdelay;
  FG_anon_7 draw;
  FG_anon_20 createAsset;
  FG_anon_21 clearClipboard;
  FG_anon_22 getDisplayIndex;
  FG_anon_23 pushClip;
  FG_anon_23 beginDraw;
  FG_anon_23 dirtyRect;
  FG_anon_24 createWindow;
  FG_anon_25 prefetchAsset;
  FG_anon_26 createRegion;
  FG_anon_27 popRenderTarget;
  FG_anon_28 putClipboard;
  FG_anon_29 fontPos;
  FG_anon_27 popLayer;
  FG_anon_30 createFont;
  FG_anon_31 clear;
  FG_anon_32 getSyncObject;
  FG_anon_33 getDisplayWindow;
  FG_anon_34 createBuffer;
  FG_anon_35 pushRenderTarget;
  FG_anon_36 createShaderInput;
  FG_anon_27 endDraw;
  FG_anon_37 setSystemControl;
  FG_anon_38 getClipboard;
  FG_anon_39 getDisplay;
  FG_anon_40 createRenderTarget;
  FG_anon_41 processMessages;
  FG_anon_42 destroySystemControl;
  FG_anon_43 setWindow;
  FG_anon_44 fontIndex;
  FG_anon_45 destroyShader;
  FG_anon_46 destroyFont;
  FG_anon_47 destroyLayout;
  FG_anon_48 createLayer;
  FG_anon_49 setCursor;
  FG_anon_47 destroyShaderInput;
  FG_anon_50 fontLayout;
  FG_anon_51 pushLayer;
  FG_anon_52 createShader;
  FG_anon_27 destroyWindow;
  FG_anon_27 popClip;
  FG_anon_53 getProjection;
  FG_anon_54 createSystemControl;
  FG_anon_55 destroyAsset;
  FG_anon_56 checkClipboard;
};
static int32_t FG_BeginDraw(FG_Backend * self, FG_Window * window, FG_Rect * area) { return (*self->beginDraw)(self, window, area); }
static FG_Window * FG_CreateWindow(FG_Backend * self, FG_MsgReceiver * element, void * display, FG_Vec * pos, FG_Vec * dim, const char* caption, uint64_t flags) { return (*self->createWindow)(self, element, display, pos, dim, caption, flags); }
static int32_t FG_PrefetchAsset(FG_Backend * self, FG_Asset * asset, float time) { return (*self->prefetchAsset)(self, asset, time); }
enum FG_Level {
  FG_Level_NONE = -1,
  FG_Level_FATAL = 0,
  FG_Level_DEBUG = 4,
  FG_Level_WARNING = 2,
  FG_Level_ERROR = 1,
  FG_Level_NOTICE = 3
};
enum FG_Kind {
  FG_Kind_MOUSEOFF = 16,
  FG_Kind_TOUCHEND = 23,
  FG_Kind_KEYCHAR = 9,
  FG_Kind_KEYDOWN = 10,
  FG_Kind_MOUSEDBLCLICK = 13,
  FG_Kind_ACTION = 0,
  FG_Kind_GOTFOCUS = 4,
  FG_Kind_JOYBUTTONDOWN = 6,
  FG_Kind_DROP = 2,
  FG_Kind_SETWINDOWFLAGS = 20,
  FG_Kind_MOUSEON = 17,
  FG_Kind_DRAW = 1,
  FG_Kind_MOUSEMOVE = 15,
  FG_Kind_SETWINDOWRECT = 21,
  FG_Kind_JOYBUTTONUP = 7,
  FG_Kind_MOUSEDOWN = 14,
  FG_Kind_MOUSESCROLL = 18,
  FG_Kind_JOYAXIS = 5,
  FG_Kind_TOUCHBEGIN = 22,
  FG_Kind_JOYORIENTATION = 8,
  FG_Kind_TOUCHMOVE = 24,
  FG_Kind_LOSTFOCUS = 12,
  FG_Kind_MOUSEUP = 19,
  FG_Kind_GETWINDOWFLAGS = 3,
  FG_Kind_KEYUP = 11
};
static FG_Vec FG_FontPos(FG_Backend * self, FG_Font * font, void * layout, FG_Rect * area, uint32_t index) { return (*self->fontPos)(self, font, layout, area, index); }
static int32_t FG_PopLayer(FG_Backend * self, FG_Window * window) { return (*self->popLayer)(self, window); }
typedef struct FG_Color16__ FG_Color16;
struct FG_Color16__ {
  uint64_t v;
};
static bool FG_Clear(FG_Backend * self, FG_Window * window, FG_Color color) { return (*self->clear)(self, window, color); }
typedef struct FG_Result__ FG_Result;
struct FG_Result__ {
  union {
  int32_t touchMove;
  int32_t mouseScroll;
  int32_t mouseOn;
  int32_t joyButtonUp;
  int32_t mouseOff;
  int32_t joyButtonDown;
  uint32_t getWindowFlags;
  int32_t keyDown;
  int32_t action;
  int32_t keyChar;
  int32_t keyUp;
  int32_t touchEnd;
  int32_t touchBegin;
  int32_t setWindowFlags;
  int32_t mouseUp;
  int32_t mouseDblClick;
  int32_t joyAxis;
  int32_t lostFocus;
  int32_t mouseDown;
  int32_t joyOrientation;
  int32_t draw;
  void * drop;
  int32_t setWindowRect;
  int32_t gotFocus;
  int32_t mouseMove;
};
};
typedef struct FG_Msg__ FG_Msg;
typedef struct FG_anon_57__ FG_anon_57;
struct FG_anon_57__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_58__ FG_anon_58;
struct FG_anon_58__ {
  float x;
  float y;
  float delta;
  float hdelta;
};
typedef struct FG_anon_59__ FG_anon_59;
struct FG_anon_59__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
typedef struct FG_anon_60__ FG_anon_60;
struct FG_anon_60__ {
  uint16_t index;
  uint16_t button;
  uint8_t modkeys;
};
typedef struct FG_anon_61__ FG_anon_61;
struct FG_anon_61__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
typedef struct FG_anon_62__ FG_anon_62;
struct FG_anon_62__ {
  uint16_t index;
  uint16_t button;
  uint8_t modkeys;
};
typedef struct FG_anon_63__ FG_anon_63;
struct FG_anon_63__ {
  char __padding;
};
typedef struct FG_anon_64__ FG_anon_64;
struct FG_anon_64__ {
  uint8_t key;
  uint8_t modkeys;
  uint16_t scancode;
};
typedef struct FG_anon_65__ FG_anon_65;
struct FG_anon_65__ {
  int32_t subkind;
};
typedef struct FG_anon_66__ FG_anon_66;
struct FG_anon_66__ {
  int32_t unicode;
  uint8_t modkeys;
};
typedef struct FG_anon_67__ FG_anon_67;
struct FG_anon_67__ {
  uint8_t key;
  uint8_t modkeys;
  uint16_t scancode;
};
typedef struct FG_anon_68__ FG_anon_68;
struct FG_anon_68__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_69__ FG_anon_69;
struct FG_anon_69__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_70__ FG_anon_70;
struct FG_anon_70__ {
  uint32_t flags;
};
typedef struct FG_anon_71__ FG_anon_71;
struct FG_anon_71__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_72__ FG_anon_72;
struct FG_anon_72__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_73__ FG_anon_73;
struct FG_anon_73__ {
  uint16_t index;
  float value;
  uint16_t axis;
  uint8_t modkeys;
};
typedef struct FG_anon_74__ FG_anon_74;
struct FG_anon_74__ {
  char __padding;
};
typedef struct FG_anon_75__ FG_anon_75;
struct FG_anon_75__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_76__ FG_anon_76;
struct FG_anon_76__ {
  uint16_t index;
  FG_Vec3 velocity;
  FG_Vec3 rotation;
};
typedef struct FG_anon_77__ FG_anon_77;
struct FG_anon_77__ {
  FG_Rect area;
};
typedef struct FG_anon_78__ FG_anon_78;
struct FG_anon_78__ {
  int32_t kind;
  void * target;
  uint32_t count;
};
typedef struct FG_anon_79__ FG_anon_79;
struct FG_anon_79__ {
  FG_Rect rect;
};
typedef struct FG_anon_80__ FG_anon_80;
struct FG_anon_80__ {
  char __padding;
};
typedef struct FG_anon_81__ FG_anon_81;
struct FG_anon_81__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
struct FG_Msg__ {
  uint16_t kind;
  union {
  FG_anon_57 touchMove;
  FG_anon_58 mouseScroll;
  FG_anon_59 mouseOn;
  FG_anon_60 joyButtonUp;
  FG_anon_61 mouseOff;
  FG_anon_62 joyButtonDown;
  FG_anon_63 getWindowFlags;
  FG_anon_64 keyDown;
  FG_anon_65 action;
  FG_anon_66 keyChar;
  FG_anon_67 keyUp;
  FG_anon_68 touchEnd;
  FG_anon_69 touchBegin;
  FG_anon_70 setWindowFlags;
  FG_anon_71 mouseUp;
  FG_anon_72 mouseDblClick;
  FG_anon_73 joyAxis;
  FG_anon_74 lostFocus;
  FG_anon_75 mouseDown;
  FG_anon_76 joyOrientation;
  FG_anon_77 draw;
  FG_anon_78 drop;
  FG_anon_79 setWindowRect;
  FG_anon_80 gotFocus;
  FG_anon_81 mouseMove;
};
};
typedef FG_Result (* FG_Behavior)(FG_MsgReceiver *, FG_Window *, void *, FG_Msg *);
static int32_t FG_PushRenderTarget(FG_Backend * self, FG_Window * window, FG_Asset * target) { return (*self->pushRenderTarget)(self, window, target); }
static int32_t FG_EndDraw(FG_Backend * self, FG_Window * window) { return (*self->endDraw)(self, window); }
static int32_t FG_SetWindow(FG_Backend * self, FG_Window * window, FG_MsgReceiver * element, void * display, FG_Vec * pos, FG_Vec * dim, const char* caption, uint64_t flags) { return (*self->setWindow)(self, window, element, display, pos, dim, caption, flags); }
static int32_t FG_SetCursor(FG_Backend * self, FG_Window * window, enum FG_Cursor cursor) { return (*self->setCursor)(self, window, cursor); }
static int32_t FG_PushLayer(FG_Backend * self, FG_Window * window, FG_Asset * layer, float * transform, float opacity, FG_BlendState * blendstate) { return (*self->pushLayer)(self, window, layer, transform, opacity, blendstate); }
static FG_Shader * FG_CreateShader(FG_Backend * self, const char* ps, const char* vs, const char* gs, const char* cs, const char* ds, const char* hs, FG_ShaderParameter * parameters, uint32_t n_parameters) { return (*self->createShader)(self, ps, vs, gs, cs, ds, hs, parameters, n_parameters); }
enum FG_Keys {
  FG_Keys_4 = 52,
  FG_Keys_S = 83,
  FG_Keys_PAGEDOWN = 34,
  FG_Keys_EXECUTE = 43,
  FG_Keys_F7 = 118,
  FG_Keys_PAGEUP = 33,
  FG_Keys_8 = 56,
  FG_Keys_W = 87,
  FG_Keys_NUMPAD_EQUAL = 146,
  FG_Keys_6 = 54,
  FG_Keys_F16 = 127,
  FG_Keys_NUMPAD5 = 101,
  FG_Keys_Y = 89,
  FG_Keys_RETURN = 13,
  FG_Keys_F9 = 120,
  FG_Keys_LSUPER = 91,
  FG_Keys_KANA = 21,
  FG_Keys_BACK = 8,
  FG_Keys_GRAVE = 192,
  FG_Keys_DELETE = 46,
  FG_Keys_LSHIFT = 160,
  FG_Keys_F14 = 125,
  FG_Keys_JUNJA = 23,
  FG_Keys_RSUPER = 92,
  FG_Keys_FINAL = 24,
  FG_Keys_B = 66,
  FG_Keys_LCONTROL = 162,
  FG_Keys_INSERT = 45,
  FG_Keys_F15 = 126,
  FG_Keys_APPS = 93,
  FG_Keys_XBUTTON1 = 5,
  FG_Keys_SELECT = 41,
  FG_Keys_H = 72,
  FG_Keys_F = 70,
  FG_Keys_F21 = 132,
  FG_Keys_J = 74,
  FG_Keys_L = 76,
  FG_Keys_NUMLOCK = 144,
  FG_Keys_RSHIFT = 161,
  FG_Keys_COMMA = 188,
  FG_Keys_F20 = 131,
  FG_Keys_NUMPAD1 = 97,
  FG_Keys_LEFT_BRACKET = 219,
  FG_Keys_SPACE = 32,
  FG_Keys_F18 = 129,
  FG_Keys_F23 = 134,
  FG_Keys_SEMICOLON = 186,
  FG_Keys_MODECHANGE = 31,
  FG_Keys_MENU = 18,
  FG_Keys_NUMPAD9 = 105,
  FG_Keys_5 = 53,
  FG_Keys_R = 82,
  FG_Keys_F19 = 130,
  FG_Keys_F6 = 117,
  FG_Keys_T = 84,
  FG_Keys_NUMPAD_MULTIPLY = 106,
  FG_Keys_ACCEPT = 30,
  FG_Keys_F22 = 133,
  FG_Keys_UP = 38,
  FG_Keys_NUMPAD2 = 98,
  FG_Keys_CANCEL = 3,
  FG_Keys_9 = 57,
  FG_Keys_X = 88,
  FG_Keys_F25 = 136,
  FG_Keys_NUMPAD0 = 96,
  FG_Keys_V = 86,
  FG_Keys_DOWN = 40,
  FG_Keys_SNAPSHOT = 44,
  FG_Keys_NUMPAD3 = 99,
  FG_Keys_F24 = 135,
  FG_Keys_NUMPAD8 = 104,
  FG_Keys_APOSTROPHE = 222,
  FG_Keys_A = 65,
  FG_Keys_NUMPAD6 = 102,
  FG_Keys_TAB = 9,
  FG_Keys_LBUTTON = 1,
  FG_Keys_PLUS = 187,
  FG_Keys_C = 67,
  FG_Keys_RIGHT_BRACKET = 221,
  FG_Keys_BACKSLASH = 220,
  FG_Keys_SLASH = 191,
  FG_Keys_PERIOD = 190,
  FG_Keys_HOME = 36,
  FG_Keys_NUMPAD4 = 100,
  FG_Keys_F1 = 112,
  FG_Keys_LMENU = 164,
  FG_Keys_E = 69,
  FG_Keys_RCONTROL = 163,
  FG_Keys_D = 68,
  FG_Keys_NONCONVERT = 29,
  FG_Keys_F11 = 122,
  FG_Keys_F8 = 119,
  FG_Keys_7 = 55,
  FG_Keys_NUMPAD7 = 103,
  FG_Keys_G = 71,
  FG_Keys_3 = 51,
  FG_Keys_F4 = 115,
  FG_Keys_RIGHT = 39,
  FG_Keys_RMENU = 165,
  FG_Keys_XBUTTON2 = 6,
  FG_Keys_SCROLL = 145,
  FG_Keys_CAPITAL = 20,
  FG_Keys_F12 = 123,
  FG_Keys_I = 73,
  FG_Keys_RBUTTON = 2,
  FG_Keys_1 = 49,
  FG_Keys_OEM_8 = 223,
  FG_Keys_P = 80,
  FG_Keys_U = 85,
  FG_Keys_Z = 90,
  FG_Keys_NULL = 0,
  FG_Keys_CONTROL = 17,
  FG_Keys_NUMPAD_DECIMAL = 110,
  FG_Keys_K = 75,
  FG_Keys_CLEAR = 12,
  FG_Keys_M = 77,
  FG_Keys_F2 = 113,
  FG_Keys_KANJI = 25,
  FG_Keys_ESCAPE = 27,
  FG_Keys_SHIFT = 16,
  FG_Keys_F13 = 124,
  FG_Keys_MBUTTON = 4,
  FG_Keys_LEFT = 37,
  FG_Keys_HELP = 47,
  FG_Keys_MINUS = 189,
  FG_Keys_N = 78,
  FG_Keys_0 = 48,
  FG_Keys_CONVERT = 28,
  FG_Keys_O = 79,
  FG_Keys_PRINT = 42,
  FG_Keys_SLEEP = 95,
  FG_Keys_NUMPAD_ADD = 107,
  FG_Keys_NUMPAD_DIVIDE = 111,
  FG_Keys_END = 35,
  FG_Keys_F10 = 121,
  FG_Keys_NUMPAD_SUBTRACT = 109,
  FG_Keys_SEPARATOR = 108,
  FG_Keys_Q = 81,
  FG_Keys_F5 = 116,
  FG_Keys_2 = 50,
  FG_Keys_F3 = 114,
  FG_Keys_PAUSE = 19,
  FG_Keys_F17 = 128
};
static void * FG_CreateSystemControl(FG_Backend * self, FG_Window * window, const char* id, FG_Rect * area, ...) { return (*self->createSystemControl)(self, window, id, area); }
typedef struct FG_UVec__ FG_UVec;
struct FG_UVec__ {
  FG_Vec abs;
  FG_Vec rel;
};
static int32_t FG_Draw(FG_Backend * self, FG_Window * window, FG_Command * commands, uint32_t n_commands, FG_BlendState * blendstate) { return (*self->draw)(self, window, commands, n_commands, blendstate); }
static FG_Asset * FG_CreateAsset(FG_Backend * self, FG_Window * window, const char* data, uint32_t count, enum FG_Format format, int32_t flags) { return (*self->createAsset)(self, window, data, count, format, flags); }
static int32_t FG_ClearClipboard(FG_Backend * self, FG_Window * window, enum FG_Clipboard kind) { return (*self->clearClipboard)(self, window, kind); }
static int32_t FG_GetDisplayIndex(FG_Backend * self, uint32_t index, FG_Display * out) { return (*self->getDisplayIndex)(self, index, out); }
static int32_t FG_PushClip(FG_Backend * self, FG_Window * window, FG_Rect * area) { return (*self->pushClip)(self, window, area); }
static int32_t FG_DirtyRect(FG_Backend * self, FG_Window * window, FG_Rect * area) { return (*self->dirtyRect)(self, window, area); }
static FG_Asset * FG_CreateRenderTarget(FG_Backend * self, FG_Window * window, FG_Vec * size, uint8_t format, int32_t flags) { return (*self->createRenderTarget)(self, window, size, format, flags); }
enum FG_ModKey {
  FG_ModKey_CONTROL = 2,
  FG_ModKey_SHIFT = 1,
  FG_ModKey_NUMLOCK = 32,
  FG_ModKey_HELD = 64,
  FG_ModKey_ALT = 4,
  FG_ModKey_CAPSLOCK = 16,
  FG_ModKey_SUPER = 8
};
enum FG_MouseButton {
  FG_MouseButton_X2 = 16,
  FG_MouseButton_M = 4,
  FG_MouseButton_X4 = 64,
  FG_MouseButton_X3 = 32,
  FG_MouseButton_R = 2,
  FG_MouseButton_X5 = 128,
  FG_MouseButton_L = 1,
  FG_MouseButton_X1 = 8
};
static FG_Window * FG_CreateRegion(FG_Backend * self, FG_MsgReceiver * element, FG_Window window, FG_Vec3 pos, FG_Vec3 dim) { return (*self->createRegion)(self, element, window, pos, dim); }
enum FG_JoyAxis {
  FG_JoyAxis_X = 0,
  FG_JoyAxis_INVALID = 65535,
  FG_JoyAxis_U = 4,
  FG_JoyAxis_Y = 1,
  FG_JoyAxis_V = 5,
  FG_JoyAxis_Z = 2,
  FG_JoyAxis_R = 3
};
enum FG_Joy {
  FG_Joy_Button4 = 3,
  FG_Joy_Button21 = 20,
  FG_Joy_Button11 = 10,
  FG_Joy_Button12 = 11,
  FG_Joy_Button25 = 24,
  FG_Joy_Button3 = 2,
  FG_Joy_Button15 = 14,
  FG_Joy_ID2 = 256,
  FG_Joy_Button31 = 30,
  FG_Joy_Button32 = 31,
  FG_Joy_Button2 = 1,
  FG_Joy_Button28 = 27,
  FG_Joy_Button18 = 17,
  FG_Joy_ID7 = 1536,
  FG_Joy_ID15 = 3584,
  FG_Joy_ID14 = 3328,
  FG_Joy_Button22 = 21,
  FG_Joy_Button9 = 8,
  FG_Joy_ID12 = 2816,
  FG_Joy_ID3 = 512,
  FG_Joy_ID11 = 2560,
  FG_Joy_ID10 = 2304,
  FG_Joy_ID9 = 2048,
  FG_Joy_ID1 = 0,
  FG_Joy_ID8 = 1792,
  FG_Joy_Button20 = 19,
  FG_Joy_ID16 = 3840,
  FG_Joy_Button8 = 7,
  FG_Joy_ID6 = 1280,
  FG_Joy_Button26 = 25,
  FG_Joy_ID5 = 1024,
  FG_Joy_Button23 = 22,
  FG_Joy_Button1 = 0,
  FG_Joy_Button24 = 23,
  FG_Joy_ID4 = 768,
  FG_Joy_Button29 = 28,
  FG_Joy_Button16 = 15,
  FG_Joy_Button7 = 6,
  FG_Joy_Button10 = 9,
  FG_Joy_Button27 = 26,
  FG_Joy_Button30 = 29,
  FG_Joy_Button5 = 4,
  FG_Joy_Button17 = 16,
  FG_Joy_Button19 = 18,
  FG_Joy_ID13 = 3072,
  FG_Joy_Button14 = 13,
  FG_Joy_Button13 = 12,
  FG_Joy_Button6 = 5
};
typedef void (* FG_Log)(void *, enum FG_Level, const char*, ...);
typedef void (* FG_Delegate)(void *);
static int32_t FG_PopRenderTarget(FG_Backend * self, FG_Window * window) { return (*self->popRenderTarget)(self, window); }
typedef struct FG_URect__ FG_URect;
struct FG_URect__ {
  FG_Rect abs;
  FG_Rect rel;
};
static int32_t FG_DestroyShaderInput(FG_Backend * self, void * input) { return (*self->destroyShaderInput)(self, input); }
static FG_Font * FG_CreateFont(FG_Backend * self, const char* family, uint16_t weight, bool italic, uint32_t pt, FG_Vec dpi, enum FG_AntiAliasing aa) { return (*self->createFont)(self, family, weight, italic, pt, dpi, aa); }
static int32_t FG_DestroyShader(FG_Backend * self, FG_Shader * shader) { return (*self->destroyShader)(self, shader); }
enum FG_WindowFlag {
  FG_WindowFlag_NOBORDER = 16,
  FG_WindowFlag_NOCAPTION = 8,
  FG_WindowFlag_FULLSCREEN = 256,
  FG_WindowFlag_MINIMIZED = 32,
  FG_WindowFlag_CLOSED = 128,
  FG_WindowFlag_MAXIMIZABLE = 2,
  FG_WindowFlag_MINIMIZABLE = 1,
  FG_WindowFlag_RESIZABLE = 4,
  FG_WindowFlag_MAXIMIZED = 64
};
static void * FG_GetSyncObject(FG_Backend * self) { return (*self->getSyncObject)(self); }
static FG_Asset * FG_CreateBuffer(FG_Backend * self, FG_Window * window, void * data, uint32_t bytes, uint8_t format, enum FG_Format type) { return (*self->createBuffer)(self, window, data, bytes, format, type); }
static bool FG_CheckClipboard(FG_Backend * self, FG_Window * window, enum FG_Clipboard kind) { return (*self->checkClipboard)(self, window, kind); }
static int32_t FG_DestroyAsset(FG_Backend * self, FG_Asset * asset) { return (*self->destroyAsset)(self, asset); }
static int32_t FG_GetProjection(FG_Backend * self, FG_Window * window, FG_Asset * layer, float * proj4x4) { return (*self->getProjection)(self, window, layer, proj4x4); }
static int32_t FG_PopClip(FG_Backend * self, FG_Window * window) { return (*self->popClip)(self, window); }
static void * FG_FontLayout(FG_Backend * self, FG_Font * font, const char* text, FG_Rect * area, float lineHeight, float letterSpacing, enum FG_BreakStyle breakStyle, void * previous) { return (*self->fontLayout)(self, font, text, area, lineHeight, letterSpacing, breakStyle, previous); }
static uint32_t FG_GetClipboard(FG_Backend * self, FG_Window * window, enum FG_Clipboard kind, void * target, uint32_t count) { return (*self->getClipboard)(self, window, kind, target, count); }
static int32_t FG_DestroySystemControl(FG_Backend * self, FG_Window * window, void * control) { return (*self->destroySystemControl)(self, window, control); }
static uint32_t FG_FontIndex(FG_Backend * self, FG_Font * font, void * layout, FG_Rect * area, FG_Vec pos, FG_Vec * cursor) { return (*self->fontIndex)(self, font, layout, area, pos, cursor); }
static int32_t FG_GetDisplay(FG_Backend * self, void * handle, FG_Display * out) { return (*self->getDisplay)(self, handle, out); }
static int32_t FG_DestroyFont(FG_Backend * self, FG_Font * font) { return (*self->destroyFont)(self, font); }
static int32_t FG_PutClipboard(FG_Backend * self, FG_Window * window, enum FG_Clipboard kind, const char* data, uint32_t count) { return (*self->putClipboard)(self, window, kind, data, count); }
static FG_Asset * FG_CreateLayer(FG_Backend * self, FG_Window * window, FG_Vec * size, int32_t flags) { return (*self->createLayer)(self, window, size, flags); }
static int32_t FG_GetDisplayWindow(FG_Backend * self, FG_Window * window, FG_Display * out) { return (*self->getDisplayWindow)(self, window, out); }
static int32_t FG_SetSystemControl(FG_Backend * self, FG_Window * window, void * control, FG_Rect * area, ...) { return (*self->setSystemControl)(self, window, control, area); }
enum FG_Touch {
  FG_Touch_MOVE = 1,
  FG_Touch_HOVER = 2,
  FG_Touch_PALM = 4
};
static int32_t FG_ProcessMessages(FG_Backend * self) { return (*self->processMessages)(self); }
static int32_t FG_DestroyWindow(FG_Backend * self, FG_Window * window) { return (*self->destroyWindow)(self, window); }
static void * FG_CreateShaderInput(FG_Backend * self, FG_Asset * * buffers, uint32_t n_buffers, FG_ShaderParameter * parameters, uint32_t n_parameters) { return (*self->createShaderInput)(self, buffers, n_buffers, parameters, n_parameters); }
static int32_t FG_DestroyLayout(FG_Backend * self, void * layout) { return (*self->destroyLayout)(self, layout); }
typedef FG_Backend * (* FG_InitBackend)(void *, FG_Log, FG_Behavior);

#endif