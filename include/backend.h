//THIS FILE AUTOGENERATED
#ifndef BACKEND_H
#define BACKEND_H

#include <stdint.h> // for integers
#include <stdbool.h> // for bool

enum FG_Format {
  FG_Format_JPG = 6,
  FG_Format_WEAK_LAYER = 3,
  FG_Format_SVG = 15,
  FG_Format_BMP = 5,
  FG_Format_ICO = 8,
  FG_Format_WEBP = 12,
  FG_Format_LAYER = 2,
  FG_Format_GIF = 9,
  FG_Format_MKV = 18,
  FG_Format_DDS = 13,
  FG_Format_MP4 = 17,
  FG_Format_WIC = 14,
  FG_Format_ATLAS = 4,
  FG_Format_UNKNOWN = 255,
  FG_Format_BUFFER = 1,
  FG_Format_GRADIENT = 0,
  FG_Format_PNG = 7,
  FG_Format_TIFF = 10,
  FG_Format_AVI = 16,
  FG_Format_TGA = 11,
  FG_Format_WEBM = 19
};
typedef struct FG_Vec__ FG_Vec;
typedef float FG_anon_1[2];
struct FG_Vec__ {
  float x;
    float y;
    
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
enum FG_Level {
  FG_Level_NONE = -1,
  FG_Level_FATAL = 0,
  FG_Level_DEBUG = 4,
  FG_Level_WARNING = 2,
  FG_Level_ERROR = 1,
  FG_Level_NOTICE = 3
};
typedef void (* FG_Log)(void *, FG_Level, const char*, ...);
typedef struct FG_Rect__ FG_Rect;
typedef float FG_anon_2[4];
struct FG_Rect__ {
  union {
    struct
    {
      float left;
      float top;
      float right;
      float bottom;
    };

    struct
    {
      FG_Vec topleft;
      FG_Vec bottomright;
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
};;
};
enum FG_AssetFlags {
  FG_AssetFlags_CUBE_MAP = 8,
  FG_AssetFlags_CACHE_LAYER = 4,
  FG_AssetFlags_NO_MIPMAP = 2,
  FG_AssetFlags_LINEAR = 1
};
typedef struct FG_anon_3__ FG_anon_3;
typedef struct FG_Veci__ FG_Veci;
typedef int32_t FG_anon_4[2];
struct FG_Veci__ {
  int x;
    int y;
    
};
struct FG_anon_3__ {
  FG_Veci size;
  FG_Vec dpi;
};
typedef struct FG_anon_5__ FG_anon_5;
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
  FG_ShaderType type;
  uint32_t length;
  uint32_t multi;
  const char* name;
};
struct FG_anon_5__ {
  uint32_t count;
  uint16_t stride;
  uint8_t primitive;
  FG_ShaderParameter * parameters;
  uint32_t n_parameters;
};
struct FG_Asset__ {
  FG_Data data;
  FG_Format format;
  int flags;
  union {
    struct {
      FG_Veci size;
      FG_Vec dpi;
    };
    struct {
      unsigned int count;
      unsigned short stride;
      unsigned char primitive;
      FG_ShaderParameter * parameters;
      unsigned int n_parameters;
    };
  };
};
enum FG_AntiAliasing {
  FG_AntiAliasing_NO_AA = 0,
  FG_AntiAliasing_LCD_V = 3,
  FG_AntiAliasing_AA = 1,
  FG_AntiAliasing_LCD = 2
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
typedef struct FG_Command__ FG_Command;
enum FG_Category {
  FG_Category_ARC = 4,
  FG_Category_LINES = 6,
  FG_Category_ICOSPHERE = 9,
  FG_Category_RECT = 2,
  FG_Category_SHADER = 11,
  FG_Category_CURVE = 7,
  FG_Category_ASSET = 1,
  FG_Category_CUBE = 8,
  FG_Category_CYLINDER = 10,
  FG_Category_CIRCLE = 3,
  FG_Category_TRIANGLE = 5,
  FG_Category_TEXT = 0
};
typedef struct FG_anon_6__ FG_anon_6;
typedef struct FG_Font__ FG_Font;
struct FG_Font__ {
  FG_Data data;
  FG_Vec dpi;
  float baseline;
  float lineheight;
  uint32_t pt;
  FG_AntiAliasing aa;
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
struct FG_anon_6__ {
  FG_Font * font;
  void * layout;
  FG_Rect * area;
  FG_Color color;
  float blur;
  float rotate;
  float z;
};
typedef struct FG_anon_7__ FG_anon_7;
struct FG_anon_7__ {
  FG_Asset * asset;
  FG_Rect * area;
  FG_Rect * source;
  FG_Color color;
  float time;
  float rotate;
  float z;
};
typedef struct FG_anon_8__ FG_anon_8;
typedef struct FG_anon_9__ FG_anon_9;
struct FG_anon_9__ {
  FG_Rect * corners;
  float rotate;
};
typedef struct FG_anon_10__ FG_anon_10;
struct FG_anon_10__ {
  float innerRadius;
  float innerBorder;
};
typedef struct FG_anon_11__ FG_anon_11;
struct FG_anon_11__ {
  FG_Vec angles;
  float innerRadius;
};
typedef struct FG_anon_12__ FG_anon_12;
struct FG_anon_12__ {
  FG_Rect * corners;
  float rotate;
};
struct FG_anon_8__ {
  FG_Rect * area;
  FG_Color fillColor;
  float border;
  FG_Color borderColor;
  float blur;
  FG_Asset * asset;
  float z;
  union {
  FG_anon_9 rect;
  FG_anon_10 circle;
  FG_anon_11 arc;
  FG_anon_12 triangle;
};;
};
typedef struct FG_anon_13__ FG_anon_13;
struct FG_anon_13__ {
  FG_Vec * points;
  uint32_t count;
  FG_Color color;
};
typedef struct FG_anon_14__ FG_anon_14;
struct FG_anon_14__ {
  FG_Vec * anchors;
  uint32_t count;
  FG_Color fillColor;
  float stroke;
  FG_Color strokeColor;
};
typedef struct FG_anon_15__ FG_anon_15;
typedef struct FG_Shader__ FG_Shader;
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
};;
};
struct FG_anon_15__ {
  FG_Shader * shader;
  FG_Asset * vertices;
  FG_Asset * indices;
  FG_ShaderValue * values;
};
struct FG_Command__ {
  uint8_t category;
  union {
  FG_anon_6 text;
  FG_anon_7 asset;
  FG_anon_8 shape;
  FG_anon_13 lines;
  FG_anon_14 curve;
  FG_anon_15 shader;
};;
};
typedef void (* FG_Delegate)(void *);
typedef struct FG_MsgReceiver__ FG_MsgReceiver;
struct FG_MsgReceiver__ {
  void * * vftable;
};
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
typedef struct FG_Display__ FG_Display;
struct FG_Display__ {
  FG_Veci size;
  FG_Veci offset;
  FG_Vec dpi;
  float scale;
  void * handle;
  bool primary;
};
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
};;
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
typedef struct FG_Msg__ FG_Msg;
typedef struct FG_anon_16__ FG_anon_16;
struct FG_anon_16__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_17__ FG_anon_17;
struct FG_anon_17__ {
  float x;
  float y;
  float delta;
  float hdelta;
};
typedef struct FG_anon_18__ FG_anon_18;
struct FG_anon_18__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
typedef struct FG_anon_19__ FG_anon_19;
struct FG_anon_19__ {
  uint16_t index;
  uint16_t button;
  uint8_t modkeys;
};
typedef struct FG_anon_20__ FG_anon_20;
struct FG_anon_20__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
typedef struct FG_anon_21__ FG_anon_21;
struct FG_anon_21__ {
  uint16_t index;
  uint16_t button;
  uint8_t modkeys;
};
typedef struct FG_anon_22__ FG_anon_22;
struct FG_anon_22__ {
  ;
};
typedef struct FG_anon_23__ FG_anon_23;
struct FG_anon_23__ {
  uint8_t key;
  uint8_t modkeys;
  uint16_t scancode;
};
typedef struct FG_anon_24__ FG_anon_24;
struct FG_anon_24__ {
  int32_t subkind;
};
typedef struct FG_anon_25__ FG_anon_25;
struct FG_anon_25__ {
  int32_t unicode;
  uint8_t modkeys;
};
typedef struct FG_anon_26__ FG_anon_26;
struct FG_anon_26__ {
  uint8_t key;
  uint8_t modkeys;
  uint16_t scancode;
};
typedef struct FG_anon_27__ FG_anon_27;
struct FG_anon_27__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_28__ FG_anon_28;
struct FG_anon_28__ {
  float x;
  float y;
  float z;
  float r;
  float pressure;
  uint16_t index;
  uint8_t flags;
  uint8_t modkeys;
};
typedef struct FG_anon_29__ FG_anon_29;
struct FG_anon_29__ {
  uint32_t flags;
};
typedef struct FG_anon_30__ FG_anon_30;
struct FG_anon_30__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_31__ FG_anon_31;
struct FG_anon_31__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_32__ FG_anon_32;
struct FG_anon_32__ {
  uint16_t index;
  float value;
  uint16_t axis;
  uint8_t modkeys;
};
typedef struct FG_anon_33__ FG_anon_33;
struct FG_anon_33__ {
  ;
};
typedef struct FG_anon_34__ FG_anon_34;
struct FG_anon_34__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
  uint8_t button;
};
typedef struct FG_anon_35__ FG_anon_35;
typedef struct FG_Vec3D__ FG_Vec3D;
typedef float FG_anon_36[3];
struct FG_Vec3D__ {
  float x;
    float y;
    float z;
    
};
struct FG_anon_35__ {
  uint16_t index;
  FG_Vec3D velocity;
  FG_Vec3D rotation;
};
typedef struct FG_anon_37__ FG_anon_37;
struct FG_anon_37__ {
  FG_Rect area;
};
typedef struct FG_anon_38__ FG_anon_38;
struct FG_anon_38__ {
  int32_t kind;
  void * target;
  uint32_t count;
};
typedef struct FG_anon_39__ FG_anon_39;
struct FG_anon_39__ {
  FG_Rect rect;
};
typedef struct FG_anon_40__ FG_anon_40;
struct FG_anon_40__ {
  ;
};
typedef struct FG_anon_41__ FG_anon_41;
struct FG_anon_41__ {
  float x;
  float y;
  uint8_t all;
  uint8_t modkeys;
};
struct FG_Msg__ {
  uint16_t kind;
  union {
  FG_anon_16 touchMove;
  FG_anon_17 mouseScroll;
  FG_anon_18 mouseOn;
  FG_anon_19 joyButtonUp;
  FG_anon_20 mouseOff;
  FG_anon_21 joyButtonDown;
  FG_anon_22 getWindowFlags;
  FG_anon_23 keyDown;
  FG_anon_24 action;
  FG_anon_25 keyChar;
  FG_anon_26 keyUp;
  FG_anon_27 touchEnd;
  FG_anon_28 touchBegin;
  FG_anon_29 setWindowFlags;
  FG_anon_30 mouseUp;
  FG_anon_31 mouseDblClick;
  FG_anon_32 joyAxis;
  FG_anon_33 lostFocus;
  FG_anon_34 mouseDown;
  FG_anon_35 joyOrientation;
  FG_anon_37 draw;
  FG_anon_38 drop;
  FG_anon_39 setWindowRect;
  FG_anon_40 gotFocus;
  FG_anon_41 mouseMove;
};;
};
typedef FG_Result (* FG_Behavior)(FG_MsgReceiver *, void *, void *, FG_Msg *);
enum FG_ModKey {
  FG_ModKey_CONTROL = 2,
  FG_ModKey_SHIFT = 1,
  FG_ModKey_NUMLOCK = 32,
  FG_ModKey_HELD = 64,
  FG_ModKey_ALT = 4,
  FG_ModKey_CAPSLOCK = 16,
  FG_ModKey_SUPER = 8
};
enum FG_Window {
  FG_Window_NOBORDER = 16,
  FG_Window_NOCAPTION = 8,
  FG_Window_FULLSCREEN = 256,
  FG_Window_MINIMIZED = 32,
  FG_Window_CLOSED = 128,
  FG_Window_MAXIMIZABLE = 2,
  FG_Window_MINIMIZABLE = 1,
  FG_Window_RESIZABLE = 4,
  FG_Window_MAXIMIZED = 64
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
  FG_DrawFlags flags;
  FG_Color constant;
};
enum FG_JoyAxis {
  FG_JoyAxis_X = 0,
  FG_JoyAxis_INVALID = 65535,
  FG_JoyAxis_U = 4,
  FG_JoyAxis_Y = 1,
  FG_JoyAxis_V = 5,
  FG_JoyAxis_Z = 2,
  FG_JoyAxis_R = 3
};
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
typedef struct FG_Backend__ FG_Backend;
typedef void (* FG_anon_42)(FG_Backend *);
typedef int32_t (* FG_anon_43)(FG_Backend *, void *, FG_Command *, uint32_t, FG_BlendState *);
typedef FG_Asset * (* FG_anon_44)(FG_Backend *, const char*, uint32_t, FG_Format, int32_t);
typedef int32_t (* FG_anon_45)(FG_Backend *, void *, FG_Clipboard);
typedef int32_t (* FG_anon_46)(FG_Backend *, uint32_t, FG_Display *);
typedef int32_t (* FG_anon_47)(FG_Backend *, void *, FG_Rect *);
typedef int32_t (* FG_anon_48)(FG_Backend *);
typedef void * (* FG_anon_49)(FG_Backend *, FG_MsgReceiver *, void *, FG_Vec *, FG_Vec *, const char*, uint64_t, void *);
typedef int32_t (* FG_anon_50)(FG_Backend *, void *, FG_Clipboard, const char*, uint32_t);
typedef FG_Vec (* FG_anon_51)(FG_Backend *, FG_Font *, void *, FG_Rect *, uint32_t);
typedef int32_t (* FG_anon_52)(FG_Backend *, void *);
typedef int32_t (* FG_anon_53)(FG_Backend *, void *, void *, FG_Rect *, ...);
typedef bool (* FG_anon_54)(FG_Backend *, void *, FG_Color);
typedef int32_t (* FG_anon_55)(FG_Backend *, void *, FG_Asset *);
typedef void * (* FG_anon_56)(FG_Backend *);
typedef int32_t (* FG_anon_57)(FG_Backend *, void *, FG_Display *);
enum FG_Primitive {
  FG_Primitive_LINE = 1,
  FG_Primitive_INDEX_INT = 11,
  FG_Primitive_TRIANGLE = 2,
  FG_Primitive_INDEX_BYTE = 9,
  FG_Primitive_LINE_STRIP = 3,
  FG_Primitive_INDEX_SHORT = 10,
  FG_Primitive_TRIANGLE_STRIP_ADJACENCY = 8,
  FG_Primitive_LINE_STRIP_ADJACENCY = 7,
  FG_Primitive_POINT = 0,
  FG_Primitive_TRIANGLE_ADJACENCY = 6,
  FG_Primitive_LINE_ADJACENCY = 5,
  FG_Primitive_TRIANGLE_STRIP = 4
};
typedef FG_Asset * (* FG_anon_58)(FG_Backend *, void *, uint32_t, uint8_t, FG_ShaderParameter *, uint32_t);
typedef int32_t (* FG_anon_59)(FG_Backend *, FG_Asset *);
typedef bool (* FG_anon_60)(FG_Backend *, void *, FG_Clipboard);
typedef FG_Asset * (* FG_anon_61)(FG_Backend *, void *, FG_Vec *, int32_t);
typedef int32_t (* FG_anon_62)(FG_Backend *, void *, FG_MsgReceiver *, void *, FG_Vec *, FG_Vec *, const char*, uint64_t);
typedef int32_t (* FG_anon_63)(FG_Backend *, FG_Shader *);
typedef int32_t (* FG_anon_64)(FG_Backend *, FG_Font *);
typedef FG_Font * (* FG_anon_65)(FG_Backend *, const char*, uint16_t, bool, uint32_t, FG_Vec, FG_AntiAliasing);
typedef int32_t (* FG_anon_66)(FG_Backend *, void *, FG_Cursor);
typedef FG_Shader * (* FG_anon_67)(FG_Backend *, const char*, const char*, const char*, const char*, const char*, const char*, FG_ShaderParameter *, uint32_t);
typedef int32_t (* FG_anon_68)(FG_Backend *, void *, FG_Asset *, float *, float, FG_BlendState *);
enum FG_BreakStyle {
  FG_BreakStyle_NONE = 0,
  FG_BreakStyle_CHARACTER = 2,
  FG_BreakStyle_WORD = 1
};
typedef void * (* FG_anon_69)(FG_Backend *, FG_Font *, const char*, FG_Rect *, float, float, FG_BreakStyle, void *);
typedef uint32_t (* FG_anon_70)(FG_Backend *, FG_Font *, void *, FG_Rect *, FG_Vec, FG_Vec *);
typedef uint32_t (* FG_anon_71)(FG_Backend *, void *, FG_Clipboard, void *, uint32_t);
typedef int32_t (* FG_anon_72)(FG_Backend *, void *, FG_Asset *, float *);
typedef void * (* FG_anon_73)(FG_Backend *, void *, const char*, FG_Rect *, ...);
typedef int32_t (* FG_anon_74)(FG_Backend *, void *, void *);
struct FG_Backend__ {
  FG_anon_42 destroy;
  FG_Feature features;
  uint32_t formats;
  FG_Vec dpi;
  float scale;
  uint64_t cursorblink;
  uint64_t tooltipdelay;
  FG_anon_43 draw;
  FG_anon_44 createAsset;
  FG_anon_45 clearClipboard;
  FG_anon_46 getDisplayIndex;
  FG_anon_47 pushClip;
  FG_anon_48 processMessages;
  FG_anon_47 dirtyRect;
  FG_anon_49 createWindow;
  FG_anon_50 putClipboard;
  FG_anon_51 fontPos;
  FG_anon_52 popLayer;
  FG_anon_53 setSystemControl;
  FG_anon_54 clear;
  FG_anon_55 setRenderTarget;
  FG_anon_56 getSyncObject;
  FG_anon_57 getDisplayWindow;
  FG_anon_58 createBuffer;
  FG_anon_59 destroyAsset;
  FG_anon_52 endDraw;
  FG_anon_60 checkClipboard;
  FG_anon_61 createLayer;
  FG_anon_57 getDisplay;
  FG_anon_62 setWindow;
  FG_anon_52 destroyLayout;
  FG_anon_63 destroyShader;
  FG_anon_64 destroyFont;
  FG_anon_65 createFont;
  FG_anon_52 popClip;
  FG_anon_66 setCursor;
  FG_anon_67 createShader;
  FG_anon_68 pushLayer;
  FG_anon_69 fontLayout;
  FG_anon_70 fontIndex;
  FG_anon_52 destroyWindow;
  FG_anon_71 getClipboard;
  FG_anon_72 getProjection;
  FG_anon_73 createSystemControl;
  FG_anon_74 destroySystemControl;
  FG_anon_47 beginDraw;
};
typedef struct FG_Color16__ FG_Color16;
struct FG_Color16__ {
  uint64_t v;
};
typedef struct FG_URect__ FG_URect;
struct FG_URect__ {
  FG_Rect abs;
  FG_Rect rel;
};
enum FG_Touch {
  FG_Touch_MOVE = 1,
  FG_Touch_HOVER = 2,
  FG_Touch_PALM = 4
};
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
typedef FG_Backend * (* FG_InitBackend)(void *, FG_Log, FG_Behavior);
typedef struct FG_UVec__ FG_UVec;
struct FG_UVec__ {
  FG_Vec abs;
  FG_Vec rel;
};

#endif