// Copyright �2017 Black Sphere Studios
// For conditions of distribution and use, see copyright notice in "feathergui.h"

#include "bss-util/khash.h"
#include "fgSkin.h"
#include "fgResource.h"
#include "fgText.h"
#include "feathercpp.h"
#include "bss-util/cXML.h"
#include "bss-util/cTrie.h"
#include "bss-util/cArraySort.h"
#include "fgButton.h"
#include "fgTextbox.h"
#include "fgCombobox.h"
#include "fgCurve.h"
#include "fgWindow.h"
#include "fgList.h"
#include <fstream>
#include <sstream>

using namespace bss_util;

KHASH_INIT(fgSkins, const char*, fgSkin*, 1, kh_str_hash_funcins, kh_str_hash_insequal);

static_assert(sizeof(fgSkinLayoutArray) == sizeof(fgVector), "mismatch between vector sizes");
static_assert(sizeof(fgStyleArray) == sizeof(fgVector), "mismatch between vector sizes");
static_assert(sizeof(fgClassLayoutArray) == sizeof(fgVector), "mismatch between vector sizes");

char CompStylePair(const fgSkinTree::fgStylePair& l, const fgSkinTree::fgStylePair& r)
{
  uint8_t lb = bitcount(l.map);
  uint8_t rb = bitcount(r.map);
  char ret = SGNCOMPARE(rb, lb);
  return !ret ? SGNCOMPARE(r.map, l.map) : ret;
}
typedef cArraySort<fgSkinTree::fgStylePair, &CompStylePair> StyleArraySort;

void fgSkin_Init(fgSkin* self)
{
  memset(self, 0, sizeof(fgSkin));
}

template<class HASH, class T, void (*DESTROY)(T*), void(*DEL)(HASH*, khint_t)>
char DestroyHashElement(HASH* self, khiter_t iter)
{
  if(kh_exist(self, iter))
  {
    (*DESTROY)(kh_val(self, iter));
    fgfree(kh_val(self, iter), __FILE__, __LINE__);
    fgFreeText(kh_key(self, iter), __FILE__, __LINE__);
    (*DEL)(self, iter);
    return 1;
  }
  return 0;
}

template<class HASH, class T, void(*DESTROYELEM)(T*), void(*DEL)(HASH*, khint_t), void(*DESTROYHASH)(HASH*)>
void DestroyHash(HASH* self)
{
  if(self)
  {
    khiter_t cur = kh_begin(self);
    while(cur != kh_end(self)) DestroyHashElement<HASH, T, DESTROYELEM, DEL>(self, cur++);
    (*DESTROYHASH)(self);
  }
}
void fgSkin_Destroy(fgSkin* self)
{
  fgStyle_Destroy(&self->style);
  fgSkinTree_Destroy(&self->tree);
  fgSkinBase_Destroy(&self->base);
}

fgSkin* fgSkin_GetSkin(const fgSkin* self, const char* name)
{
  if(!self || !name)
    return 0;
  fgSkin* r = fgSkinBase_GetSkin(&self->base, name);
  return !r ? fgSkin_GetSkin(self->inherit, name) : r;
}

void fgSkinTree_Init(fgSkinTree* self)
{
  memset(self, 0, sizeof(fgSkinTree));
}
void fgSkinTree_Destroy(fgSkinTree* self)
{
  reinterpret_cast<fgSkinLayoutArray&>(self->children).~cArraySort();

  for(size_t i = 0; i < self->styles.l; ++i)
    fgStyle_Destroy(&self->styles.p[i].style);
}

size_t fgSkinTree_AddChild(fgSkinTree* self, const char* type, fgFlag flags, const fgTransform* transform, short units, int order)
{
  size_t r = ((fgSkinLayoutArray&)self->children).Insert(fgSkinLayoutConstruct(type, flags, transform, units, order));
  self->children.p[r].instance = fgroot_instance->backend.fgCreate(type, 0, 0, 0, flags, (units == -1) ? 0 : transform, units);
  return r;
}
char fgSkinTree_RemoveChild(fgSkinTree* self, FG_UINT child)
{
  return DynArrayRemove((fgFontArray&)self->children, child);
}
fgSkinLayout* fgSkinTree_GetChild(const fgSkinTree* self, FG_UINT child)
{
  return self->children.p + child;
}

FG_UINT fgSkinTree_AddStyle(fgSkinTree* self, const char* name)
{
  size_t len = strlen(name) + 1;
  DYNARRAY(char, tokenize, len);
  MEMCPY(tokenize, len, name, len);
  char* context;
  char* token = STRTOK(tokenize, "+", &context);
  FG_UINT style = 0;
  while(token)
  {
    style |= fgStyle_GetName(token);
    token = STRTOK(0, "+", &context);
  }

  self->stylemask |= style;
  fgSkinTree::fgStylePair pair = { style, 0 };
  if(((StyleArraySort&)self->styles).Find(pair) == (size_t)~0)
    ((StyleArraySort&)self->styles).Insert(pair);
  return style;
}

char fgSkinTree_RemoveStyle(fgSkinTree* self, FG_UINT style)
{
  fgSkinTree::fgStylePair pair = { style, 0 };
  size_t i = ((StyleArraySort&)self->styles).Find(pair);
  if(i == (size_t)~0)
    return 0;
  fgStyle_Destroy(&self->styles.p[i].style);
  return ((StyleArraySort&)self->styles).Remove(i);
}
fgStyle* fgSkinTree_GetStyle(const fgSkinTree* self, FG_UINT style)
{
  fgSkinTree::fgStylePair pair = { style, 0 };
  size_t i = ((StyleArraySort&)self->styles).Find(pair);
  return (i == (size_t)~0) ? 0 : (&self->styles.p[i].style);
}

void fgSkinBase_Destroy(fgSkinBase* self)
{
  reinterpret_cast<fgResourceArray&>(self->resources).~cDynArray();
  reinterpret_cast<fgFontArray&>(self->fonts).~cDynArray();
  DestroyHash<kh_fgSkins_t, fgSkin, &fgSkin_Destroy, &kh_del_fgSkins, &kh_destroy_fgSkins>(self->skinmap);
}

size_t fgSkinBase_AddAsset(fgSkinBase* self, void* resource)
{
  return ((fgResourceArray&)self->resources).Add(resource);
}
char fgSkinBase_RemoveAsset(fgSkinBase* self, FG_UINT resource)
{
  return DynArrayRemove((fgResourceArray&)self->resources, resource);
}
void* fgSkinBase_GetAsset(const fgSkinBase* self, FG_UINT resource)
{
  return DynGet<fgResourceArray>(self->resources, resource).ref;
}
size_t fgSkinBase_AddFont(fgSkinBase* self, void* font)
{
  return ((fgFontArray&)self->fonts).Add(font);
}
char fgSkinBase_RemoveFont(fgSkinBase* self, FG_UINT font)
{
  return DynArrayRemove((fgFontArray&)self->fonts, font);
}
void* fgSkinBase_GetFont(const fgSkinBase* self, FG_UINT font)
{
  return DynGet<fgFontArray>(self->fonts, font).ref;
}
fgSkin* fgSkinBase_AddSkin(fgSkinBase* self, const char* name)
{
  if(!self->skinmap)
    self->skinmap = kh_init_fgSkins();

  if(!name) return 0;
  int r = 0;
  khiter_t iter = kh_put(fgSkins, self->skinmap, name, &r);
  if(r != 0) // If r is 0 the element already exists so we don't want to re-initialize it
  {
    kh_val(self->skinmap, iter) = fgmalloc<fgSkin>(1, __FILE__, __LINE__);
    fgSkin_Init(kh_val(self->skinmap, iter));
    kh_val(self->skinmap, iter)->base.parent = self;
    kh_key(self->skinmap, iter) = fgCopyText(name, __FILE__, __LINE__);
  }

  return kh_val(self->skinmap, iter);
}
char fgSkinBase_RemoveSkin(fgSkinBase* self, const char* name)
{
  if(!self->skinmap || !name)
    return 0;

  return DestroyHashElement<struct kh_fgSkins_s, fgSkin, &fgSkin_Destroy, &kh_del_fgSkins>(self->skinmap, kh_get(fgSkins, self->skinmap, name));
}
fgSkin* fgSkinBase_GetSkin(const fgSkinBase* self, const char* name)
{
  if(!self || !name || !self->skinmap)
    return 0;
  khiter_t iter = kh_get(fgSkins, self->skinmap, name);
  return (iter != kh_end(self->skinmap) && kh_exist(self->skinmap, iter)) ? kh_val(self->skinmap, iter) : 0;
}

void fgSkinElement_Init(fgSkinElement* self, const char* type, fgFlag flags, const fgTransform* transform, short units, int order)
{
  self->type = fgCopyText(type, __FILE__, __LINE__);
  self->transform = *transform;
  self->units = units;
  self->flags = flags;
  self->order = order;
  fgStyle_Init(&self->style);
}
void fgSkinElement_Destroy(fgSkinElement* self)
{
  if(self->type) fgFreeText(self->type, __FILE__, __LINE__);
  fgStyle_Destroy(&self->style);
}

void fgSkinLayout_Init(fgSkinLayout* self, const char* type, fgFlag flags, const fgTransform* transform, short units, int order)
{
  memset(self, 0, sizeof(fgSkinLayout));
  fgSkinElement_Init(&self->layout, type, flags, transform, units, order);
  self->instance = 0;
}
void fgSkinLayout_Destroy(fgSkinLayout* self)
{
  fgSkinElement_Destroy(&self->layout);
  if(self->instance) VirtualFreeChild(self->instance);
  fgSkinTree_Destroy(&self->tree);
}

const char* fgSkin_ParseFont(const char* font, char quote, int* size, short* weight, char* italic)
{
  *size = 14; // Set defaults
  *weight = 400;
  *italic = 0;
  if(!font) return 0;
  const char* s = strchr(font, ' ');
  if(!s) return font;
  while(isspace(*++s));
  if(!s[0]) return font;
  *size = (int)strtol(font, 0, 10);

  if(s[0] == quote) return s;
  const char* f = strchr(s, ' ');
  size_t slen = f - s;
  if(!f || f[-1] == ',') return s;
  while(isspace(*++f));
  if(!f[0]) return s;

  if(!STRNICMP(s, "bold", slen))
    *weight = 700;
  else if(!STRNICMP(s, "bolder", slen))
    *weight = 900;
  else if(!STRNICMP(s, "normal", slen))
    *weight = 400;
  else if(!STRNICMP(s, "light", slen))
    *weight = 300;
  else if(!STRNICMP(s, "lighter", slen))
    *weight = 100;
  else if(!STRNICMP(s, "italic", slen))
    *italic = true;
  else
    *weight = (short)strtol(s, 0, 10);

  if(f[0] == quote) return f;
  const char* g = strchr(f, ' ');
  size_t flen = g - f;
  if(!g || g[-1] == ',') return f;
  while(isspace(*++g));
  if(!g[0]) return f;

  if(!STRNICMP(f, "italic", flen))
    *italic = true;

  return g;
}

char* fgSkin_GetFontFamily(char* s, char quote, char** context)
{
  if(!s)
  {
    s = *context;
    if(!s) // This can happen in error cases
      return 0;
    if(s[0] == ',')
      ++s;
  }
  else
    *context = 0;

  while(isspace(s[0])) ++s;
  if(!s[0]) return 0;
  char* end;
  if(s[0] == quote)
    end = strchr(++s, quote);
  else
    end = strchr(s, ' ');
  if(!end || !end[0])
    return s;
  *end = 0;
  *context = end + 1;
  return s;
}

int fgStyle_LoadUnit(const char* str, size_t len)
{
  int flags = FGUNIT_DP;
  if(!len) len = strlen(str);
  if(len > 2)
  {
    if(str[len - 2] == 'e' && str[len - 1] == 'm')
      flags = FGUNIT_EM;
    else if(str[len - 2] == 's' && str[len - 1] == 'p')
      flags = FGUNIT_SP;
    else if(str[len - 2] == 'p' && str[len - 1] == 'x')
      flags = FGUNIT_PX;
  }

  return flags;
}

int fgStyle_LoadCoord(const char* attribute, size_t len, Coord& coord)
{
  coord = Coord { 0, 0 };
  if(!attribute) return 0;
  if(!len) len = strlen(attribute);
  const char* rel = strchr(attribute, ':');
  size_t first = len;
  if(rel)
  {
    coord.rel = (FREL)atof(rel + 1);
    if(attribute[len - 1] == '%') // Check if this is a percentage and scale it accordingly.
      coord.rel *= 0.01f;
    first = attribute - rel;
  }
  else if(attribute[len - 1] == '%')
  {
    coord.rel = (FREL)(atof(attribute) * 0.01);
    return 0;
  }

  coord.abs = (FABS)atof(attribute);
  return fgStyle_LoadUnit(attribute, first);
}
int fgStyle_LoadAbsRect(const char* attribute, AbsRect& r)
{
  size_t len = strlen(attribute) + 1;
  DYNARRAY(char, buf, len);
  MEMCPY(buf, len, attribute, len);
  char* context;
  const char* s0 = STRTOK(buf, ", ", &context);
  const char* s1 = STRTOK(0, ", ", &context);
  const char* s2 = STRTOK(0, ", ", &context);
  const char* s3 = STRTOK(0, ", ", &context);

  r.left = (FABS)atof(s0);
  r.top = (FABS)atof(s1);
  r.right = (FABS)atof(s2);
  r.bottom = (FABS)atof(s3);
  return (fgStyle_LoadUnit(s0, 0) << FGUNIT_LEFT) |
    (fgStyle_LoadUnit(s1, 0) << FGUNIT_TOP) |
    (fgStyle_LoadUnit(s2, 0) << FGUNIT_RIGHT) |
    (fgStyle_LoadUnit(s3, 0) << FGUNIT_BOTTOM);
}

int fgStyle_LoadAbsVec(const char* attribute, AbsVec& r)
{
  size_t len = strlen(attribute) + 1;
  DYNARRAY(char, buf, len);
  MEMCPY(buf, len, attribute, len);
  char* context;
  const char* s0 = STRTOK(buf, ", ", &context);
  const char* s1 = STRTOK(0, ", ", &context);

  r.x = (FABS)atof(s0);
  r.y = (FABS)atof(s1);
  return (fgStyle_LoadUnit(s0, 0) << FGUNIT_X) |
    (fgStyle_LoadUnit(s1, 0) << FGUNIT_Y);
}

int fgStyle_LoadCRect(const char* attribute, CRect& r)
{
  size_t len = strlen(attribute) + 1;
  DYNARRAY(char, buf, len);
  MEMCPY(buf, len, attribute, len);
  char* context;
  const char* s0 = STRTOK(buf, ", ", &context);
  const char* s1 = STRTOK(0, ", ", &context);
  const char* s2 = STRTOK(0, ", ", &context);
  const char* s3 = STRTOK(0, ", ", &context);

  return (fgStyle_LoadCoord(s0, 0, r.left) << FGUNIT_LEFT) |
    (fgStyle_LoadCoord(s1, 0, r.top) << FGUNIT_TOP) |
    (fgStyle_LoadCoord(s2, 0, r.right) << FGUNIT_RIGHT) |
    (fgStyle_LoadCoord(s3, 0, r.bottom) << FGUNIT_BOTTOM);
}

int fgStyle_LoadCVec(const char* attribute, CVec& v)
{
  size_t len = strlen(attribute) + 1;
  DYNARRAY(char, buf, len);
  MEMCPY(buf, len, attribute, len);
  char* context;
  const char* s0 = STRTOK(buf, ", ", &context);
  const char* s1 = STRTOK(0, ", ", &context);
  return (fgStyle_LoadCoord(s0, 0, v.x) << FGUNIT_X) | (fgStyle_LoadCoord(s1, 0, v.y) << FGUNIT_Y);
}

int fgStyle_NodeEvalTransform(const cXMLNode* node, fgTransform& t)
{
  static cTrie<uint16_t, true> attr(9, "area", "center", "rotation", "left", "top", "right", "bottom", "width", "height");
  int flags = 0;
  bool hastransform = false;

  for(size_t i = 0; i < node->GetAttributes(); ++i)
  {
    const cXMLValue* a = node->GetAttribute(i);
    switch(attr[a->Name.c_str()])
    {
    case 0:
      flags &= (~(FGUNIT_LEFT_MASK | FGUNIT_TOP_MASK | FGUNIT_RIGHT_MASK | FGUNIT_BOTTOM_MASK));
      flags |= fgStyle_LoadCRect(a->String, t.area);
      break;
    case 1:
      flags &= (~(FGUNIT_X_MASK | FGUNIT_Y_MASK));
      flags |= fgStyle_LoadCVec(a->String, t.center);
      break;
    case 2:
      t.rotation = (FABS)a->Float;
      break;
    case 3:
      flags = (flags&(FGUNIT_LEFT_MASK)) | fgStyle_LoadCoord(a->String, 0, t.area.left);
      break;
    case 4:
      flags = (flags&(FGUNIT_TOP_MASK)) | fgStyle_LoadCoord(a->String, 0, t.area.top);
      break;
    case 5:
      flags = (flags&(FGUNIT_RIGHT_MASK)) | fgStyle_LoadCoord(a->String, 0, t.area.right);
      break;
    case 6:
      flags = (flags&(FGUNIT_BOTTOM_MASK)) | fgStyle_LoadCoord(a->String, 0, t.area.bottom);
      break;
    case 7:
      flags = (flags&(FGUNIT_RIGHT_MASK)) | fgStyle_LoadUnit(a->String, 0) | FGUNIT_RIGHT_WIDTH;
      t.area.right.abs = (FABS)a->Float;
      break;
    case 8:
      flags = (flags&(FGUNIT_BOTTOM_MASK)) | fgStyle_LoadUnit(a->String, 0) | FGUNIT_BOTTOM_HEIGHT;
      t.area.bottom.abs = (FABS)a->Float;
      break;
    default:
      continue;
    }
    hastransform = true;
  }

  if(!hastransform) return -1;
  return flags;
}

uint32_t fgStyle_ParseColor(const cXMLValue* attr)
{
  fgColor color;
  color.color = attr->Integer;
  if(attr->String.length() == 8 && attr->String[0] == '0' && attr->String[1] == 'x') // If this is true, it's a non-alpha color value
  {
    rswap(color.r, color.b);
    color.a = 255;
  }
  else
  {
    rswap(color.r, color.a);
    rswap(color.g, color.b);
  }
  return color.color;
}
void fgStyle_LoadAttributesXML(fgStyle* self, const cXMLNode* cur, int flags, fgSkinBase* root, const char* path, const char** id, fgKeyValueArray* userdata)
{
  static cTrie<uint16_t, true> t(44, "id", "min-width", "min-height", "max-width", "max-height", "skin", "alpha", "margin", "padding", "text",
    "placeholder", "color", "placecolor", "cursorcolor", "selectcolor", "hovercolor", "dragcolor", "edgecolor", "font", "lineheight",
    "letterspacing", "value", "uv", "resource", "outline", "area", "center", "rotation", "left", "top", "right", "bottom", "width", "height",
    "name", "flags", "order", "inherit", "range", "splitter", "contextmenu", "reorder", "xmlns:xsi", "xmlns:fg", "xsi:schemaLocation");
  static cTrie<uint16_t, true> tvalue(5, "checkbox", "curve", "progressbar", "radiobutton", "slider");
  static cTrie<uint16_t, true> tenum(5, "true", "false", "none", "checked", "indeterminate");

  int minflags = 0x8000000;
  AbsVec mindim = { -1, -1 };
  int maxflags = 0x8000000;
  AbsVec maxdim = { -1, -1 };

  for(size_t i = 0; i < cur->GetAttributes(); ++i)
  {
    const cXMLValue* attr = cur->GetAttribute(i);
    const uint16_t ID = t[attr->Name.c_str()];

    switch(ID)
    {
    case 0:
      if(id)
        *id = fgCopyText(attr->String, __FILE__, __LINE__);
      break;
    case 1:
      mindim.x = (FABS)attr->Float;
      minflags &= (~0x8000000);
      minflags |= (fgStyle_LoadUnit(attr->String, attr->String.length() + 1) << FGUNIT_X);
      break;
    case 2:
      mindim.y = (FABS)attr->Float;
      minflags &= (~0x8000000);
      minflags |= (fgStyle_LoadUnit(attr->String, attr->String.length() + 1) << FGUNIT_Y);
      break;
    case 3:
      maxdim.x = (FABS)attr->Float;
      maxflags &= (~0x8000000);
      maxflags |= (fgStyle_LoadUnit(attr->String, attr->String.length() + 1) << FGUNIT_X);
      break;
    case 4:
      maxdim.y = (FABS)attr->Float;
      maxflags &= (~0x8000000);
      maxflags |= (fgStyle_LoadUnit(attr->String, attr->String.length() + 1) << FGUNIT_Y);
      break;
    case 5: // skin
    {
      fgSkin* skin = fgSkinBase_GetSkin(root, attr->String);
      if(!skin) // Attempt loading it as an absolute XML path
        skin = fgSkinBase_LoadFileXML(root, attr->String);
      if(!skin) // relative XML path
        skin = fgSkinBase_LoadFileXML(root, cStr(path) + attr->String);
      if(!skin) // absolute UBJSON path
        skin = fgSkinBase_LoadFileUBJSON(root, attr->String);
      if(!skin) // relative UBJSON path
        skin = fgSkinBase_LoadFileUBJSON(root, cStr(path) + attr->String);
      if(skin)
        AddStyleMsg<FG_SETSKIN, void*>(self, skin);
    }
    break;
    case 6:
      AddStyleMsg<FG_SETALPHA, FABS>(self, (FABS)attr->Float);
      break;
    case 7:
    {
      AbsRect r;
      int f = fgStyle_LoadAbsRect(attr->String, r);
      AddStyleSubMsgArg<FG_SETMARGIN, AbsRect>(self, f, &r);
      break;
    }
    case 8:
    {
      AbsRect r;
      int f = fgStyle_LoadAbsRect(attr->String, r);
      AddStyleSubMsgArg<FG_SETPADDING, AbsRect>(self, f, &r);
      break;
    }
    case 9: // text
    case 10: // placeholder
    {
      FG_Msg msg = { 0 };
      msg.type = FG_SETTEXT;
      msg.subtype = ((ID == 9) ? FGTEXTFMT_UTF8 : FGTEXTFMT_PLACEHOLDER_UTF8);
      msg.p = const_cast<char*>(attr->String.c_str());
      fgStyle_AddStyleMsg(self, &msg, attr->String.length() + 1, 0);
      break;
    }
    case 11:
      AddStyleSubMsg<FG_SETCOLOR, ptrdiff_t>(self, FGSETCOLOR_MAIN, fgStyle_ParseColor(attr));
      break;
    case 12:
      AddStyleSubMsg<FG_SETCOLOR, ptrdiff_t>(self, FGSETCOLOR_PLACEHOLDER, fgStyle_ParseColor(attr));
      break;
    case 13:
      AddStyleSubMsg<FG_SETCOLOR, ptrdiff_t>(self, FGSETCOLOR_CURSOR, fgStyle_ParseColor(attr));
      break;
    case 14:
      AddStyleSubMsg<FG_SETCOLOR, ptrdiff_t>(self, FGSETCOLOR_SELECT, fgStyle_ParseColor(attr));
      break;
    case 15:
      AddStyleSubMsg<FG_SETCOLOR, ptrdiff_t>(self, FGSETCOLOR_HOVER, fgStyle_ParseColor(attr));
      break;
    case 16:
      AddStyleSubMsg<FG_SETCOLOR, ptrdiff_t>(self, FGSETCOLOR_DRAG, fgStyle_ParseColor(attr));
      break;
    case 17:
      AddStyleSubMsg<FG_SETCOLOR, ptrdiff_t>(self, FGSETCOLOR_EDGE, fgStyle_ParseColor(attr));
      break;
    case 18: // font
    {
      int size;
      short weight;
      char italic;
      cStr families = fgSkin_ParseFont(attr->String.c_str(), '\'', &size, &weight, &italic);
      char* context = 0;
      char* family = fgSkin_GetFontFamily(families.UnsafeString(), '\'', &context);
      fgFont font = 0;
      while(family != 0)
      {
        if((font = fgroot_instance->backend.fgCreateFont(flags, family, weight, italic, size, &fgroot_instance->dpi)) != 0)
          break;
        family = fgSkin_GetFontFamily(0, '\'', &context);
      }
      if(font != 0)
      {
        FG_UINT index = (FG_UINT)fgSkinBase_AddFont(root, font);
        AddStyleMsg<FG_SETFONT, void*>(self, fgSkinBase_GetFont(root, index));
      }
      break;
    }
    case 19:
      AddStyleMsg<FG_SETLINEHEIGHT, FABS>(self, (FABS)attr->Float);
      break;
    case 20:
      AddStyleMsg<FG_SETLETTERSPACING, FABS>(self, (FABS)attr->Float);
      break;
    case 21: // Value's type changes depending on what type we are
      switch(tvalue[cur->GetName()])
      {
      case 0: // Checkbox
        switch(tenum[attr->String])
        {
        case 0:
        case 3: // Both true and checked map to checked
          AddStyleSubMsg<FG_SETVALUE, ptrdiff_t>(self, FGVALUE_INT64, FGCHECKED_CHECKED);
          break;
        case 4:
          AddStyleSubMsg<FG_SETVALUE, ptrdiff_t>(self, FGVALUE_INT64, FGCHECKED_INDETERMINATE);
          break;
        default: // Everything else maps to not checked
          AddStyleSubMsg<FG_SETVALUE, ptrdiff_t>(self, FGVALUE_INT64, FGCHECKED_NONE);
          break;
        }
      case 1: // Curve
        break; // Not implemented
      case 2: // Progressbar
      case 4: // Slider
      default: // Anything else
        AddStyleSubMsg<FG_SETVALUE, FABS>(self, FGVALUE_FLOAT, (FABS)attr->Float);
        break;
      case 3: // Radiobutton
        switch(tenum[attr->String])
        {
        case 0:
        case 3: // true, checked, and indeterminate all map to true
        case 4:
          AddStyleSubMsg<FG_SETVALUE, ptrdiff_t>(self, FGVALUE_INT64, 1);
          break;
        default: // Everything else maps to not checked
          AddStyleSubMsg<FG_SETVALUE, ptrdiff_t>(self, FGVALUE_INT64, 0);
          break;
        }
      }
      break;
    case 22: // uv
    {
      CRect uv;
      int f = fgStyle_LoadCRect(attr->String, uv);
      AddStyleSubMsgArg<FG_SETUV, CRect>(self, f, &uv);
      break;
    }
    case 23: // resource
    {
      FG_UINT res = (FG_UINT)fgSkinBase_AddAsset(root, fgCreateAssetFile(flags, attr->String));
      AddStyleMsg<FG_SETASSET, void*>(self, fgSkinBase_GetAsset(root, res));
      break;
    }
    case 24: // outline
      AddStyleSubMsg<FG_SETOUTLINE, FABS>(self, fgStyle_LoadUnit(attr->String.c_str(), attr->String.length() + 1), (FABS)attr->Float);
      break;
    case 25: // area
    case 26: // center
    case 27: // rotation
    case 28: // left
    case 29: // top
    case 30: // right
    case 31: // bottom
    case 32: // width
    case 33: // height
    case 34: // name
    case 35: // flags
    case 36: // order
    case 37: // inherit
      break; // These are processed before we get here, so ignore them.
    case 38: // range
      AddStyleSubMsg<FG_SETRANGE, ptrdiff_t>(self, FGVALUE_INT64, attr->Integer);
      break;
    case 39: // splitter
    {
      AbsVec splitter;
      int f = fgStyle_LoadAbsVec(attr->String, splitter);
      AddStyleSubMsg<FG_SETVALUE, float>(self, FGVALUE_FLOAT, splitter.x);
      AddStyleSubMsg<FG_SETRANGE, float>(self, FGVALUE_FLOAT, splitter.y);
      break;
    }
    case 41: // reorder
      if(!STRICMP(attr->String, "top"))
        AddStyleSubMsg<FG_SETPARENT>(self, FGSETPARENT_LAST);
      else if(!STRICMP(attr->String, "bottom"))
        AddStyleSubMsg<FG_SETPARENT>(self, FGSETPARENT_FIRST);
      break;
    case 42:
    case 43:
    case 44: // These are all XML specific values that are only used for setting the XSD file
      break;
    case 40: // contextmenu is a recognized option, but we put it in as custom userdata anyway because we can't resolve it until the layout is resolved.
    default: // Otherwise, unrecognized attributes are set as custom userdata
      if(!userdata)
      {
        FG_Msg msg = { 0 };
        msg.type = FG_SETUSERDATA;
        msg.p = const_cast<char*>(attr->String.c_str());
        msg.p2 = const_cast<char*>(attr->Name.c_str());
        fgStyle_AddStyleMsg(self, &msg, attr->String.length() + 1, attr->Name.length() + 1);
      }
      else
      {
        size_t i = userdata->AddConstruct();
        (*userdata)[i].key = fgCopyText(attr->Name.c_str(), __FILE__, __LINE__);
        (*userdata)[i].value = fgCopyText(attr->String.c_str(), __FILE__, __LINE__);
      }
    break;
    }
  }

  if(!(minflags & 0x8000000))
    AddStyleSubMsg<FG_SETDIM, FABS, FABS>(self, minflags | FGDIM_MIN, mindim.x, mindim.y);
  if(!(maxflags & 0x8000000))
    AddStyleSubMsg<FG_SETDIM, FABS, FABS>(self, maxflags | FGDIM_MAX, maxdim.x, maxdim.y);
}


fgFlag fgSkinBase_GetFlagsFromString(const char* s, fgFlag* remove)
{
  static cTrie<uint16_t, true> t(54, "BACKGROUND", "NOCLIP", "IGNORE", "HIDDEN", "SILENT", "EXPANDX", "EXPANDY", "DISABLE", "SNAPX", "SNAPY", "HIDEH",
    "HIDEV", "SHOWH", "SHOWV", "IGNOREMARGINEDGEX", "IGNOREMARGINEDGEY", "TILEX", "TILEY", "DISTRIBUTEX", "DISTRIBUTEY", "SINGLESELECT", "MULTISELECT",
    "DRAGGABLE", "HIDEH", "HIDEV", "SHOWH", "SHOWV", "CHARWRAP", "WORDWRAP", "ELLIPSES", "RTL", "RIGHTALIGN", "CENTER", "SUBPIXEL", "ACTION",
    "SINGLELINE", "NOFOCUS", "RECT", "CIRCLE", "LINE", "QUADRATIC", "CUBIC", "BSPLINE", "MINIMIZABLE", "MAXIMIZABLE", "RESIZABLE",
    "NOTITLEBAR", "NOBORDER", "EXPAND", "SNAP", "TILE", "DISTRIBUTE", "TRIANGLE", "IGNOREMARGINEDGE");

  if(!s)
    return 0;
  fgFlag out = 0;
  const char* n;
  while(s)
  {
    n = strchr(s, '|');
    bool del = s[0] == '-';
    if(del)
      ++s;
    uint16_t i = !n ? t[s] : t.Get(s, n - s);
    fgFlag f = 0;
    if(i < t.Length())
    {
      switch(i)
      {
      default:
        f = (1 << i);
        break;
      case 21: f = FGLIST_MULTISELECT; break; // We can't rely on the default method here because MULTISELECT is actually two seperate flags
      case 22: f = FGLIST_DRAGGABLE; break;
      case 23: f = FGSCROLLBAR_HIDEH; break;
      case 24: f = FGSCROLLBAR_HIDEV; break;
      case 25: f = FGSCROLLBAR_SHOWH; break;
      case 26: f = FGSCROLLBAR_SHOWV; break;
      case 27: f = FGTEXT_CHARWRAP; break;
      case 28: f = FGTEXT_WORDWRAP; break;
      case 29: f = FGTEXT_ELLIPSES; break;
      case 30: f = FGTEXT_RTL; break;
      case 31: f = FGTEXT_RIGHTALIGN;  break;
      case 32: f = FGTEXT_CENTER;  break;
      case 33: f = FGTEXT_SUBPIXEL;  break;
      case 34: f = FGTEXTBOX_ACTION;  break;
      case 35: f = FGTEXTBOX_SINGLELINE;  break;
      case 36: f = FGBUTTON_NOFOCUS;  break;
      case 37: f = FGRESOURCE_RECT;  break;
      case 38: f = FGRESOURCE_CIRCLE;  break;
      case 39: f = FGCURVE_LINE;  break;
      case 40: f = FGCURVE_QUADRATIC;  break;
      case 41: f = FGCURVE_CUBIC;  break;
      case 42: f = FGCURVE_BSPLINE;  break;
      case 43: f = FGWINDOW_MINIMIZABLE;  break;
      case 44: f = FGWINDOW_MAXIMIZABLE;  break;
      case 45: f = FGWINDOW_RESIZABLE;  break;
      case 46: f = FGWINDOW_NOTITLEBAR;  break;
      case 47: f = FGWINDOW_NOBORDER;  break;
      case 48: f = FGELEMENT_EXPAND;  break;
      case 49: f = FGELEMENT_SNAP;  break;
      case 50: f = FGBOX_TILE;  break;
      case 51: f = FGBOX_DISTRIBUTEX | FGBOX_DISTRIBUTEY;  break;
      case 52: f = FGRESOURCE_TRIANGLE; break;
      case 53: f = FGBOX_IGNOREMARGINEDGE; break;
      }
    }

    if(del && remove != 0)
      *remove |= f;
    else
      out |= f;
    s = !n? 0 : n + 1;
  }
  
  return out;
}

fgSkin* fgSkinBase_GetInherit(fgSkinBase* self, const char* inherit)
{
  if(!inherit) return 0;
  fgSkin* r = 0;
  while(!r && self != 0)
  {
    r = fgSkinBase_GetSkin(self, inherit);
    self = self->parent;
  }
  return r;
}

// Styles parse flags differently - the attributes use the parent flags for resource/font loading, then creates add and remove flag messages
void fgSkinBase_LoadStyleNodeXML(fgSkinBase* self, fgStyle* style, fgFlag rootflags, const cXMLNode* cur)
{
  fgStyle_LoadAttributesXML(style, cur, rootflags, self, 0, 0, 0);
  fgFlag remove = 0;
  fgFlag add = fgSkinBase_GetFlagsFromString(cur->GetAttributeString("flags"), &remove);
  if(remove)
    AddStyleMsg<FG_SETFLAG, ptrdiff_t, size_t>(style, remove, 0);
  if(add)
    AddStyleMsg<FG_SETFLAG, ptrdiff_t, size_t>(style, add, 1);
}

void fgSkinBase_LoadSubNodeXML(fgSkinTree* tree, fgStyle* style, fgSkinBase* root, fgSkin* skin, const cXMLNode* cur)
{
  fgFlag remove = 0;
  fgFlag rootflags = fgSkinBase_GetFlagsFromString(cur->GetAttributeString("flags"), &remove);
  if(remove)
    AddStyleMsg<FG_SETFLAG, ptrdiff_t, size_t>(style, remove, 0);
  if(rootflags)
    AddStyleMsg<FG_SETFLAG, ptrdiff_t, size_t>(style, rootflags, 1);

  fgTransform ts = { 0 };
  int tsunits = fgStyle_NodeEvalTransform(cur, ts);
  if(tsunits != -1)
    AddStyleSubMsgArg<FG_SETTRANSFORM, fgTransform>(style, tsunits, &ts);

  fgStyle_LoadAttributesXML(style, cur, rootflags, root, 0, 0, 0);
  if(skin)
    skin->inherit = fgSkinBase_GetInherit(&skin->base, cur->GetAttributeString("inherit"));

  for(size_t i = 0; i < cur->GetNodes(); ++i)
  {
    const cXMLNode* node = cur->GetNode(i);
    if(skin != nullptr && !STRICMP(node->GetName(), "skin"))
      fgSkinBase_LoadNodeXML(&skin->base, node);
    else if(!STRICMP(node->GetName(), "style"))
      fgSkinBase_LoadStyleNodeXML(root, fgSkinTree_GetStyle(tree, fgSkinTree_AddStyle(tree, node->GetAttributeString("name"))), rootflags, node);
    else
    {
      fgTransform transform = { 0 };
      short units = fgStyle_NodeEvalTransform(node, transform);
      fgFlag rmflags = 0;
      fgFlag flags = fgSkinBase_GetFlagsFromString(node->GetAttributeString("flags"), &rmflags);
      flags = (flags | fgGetTypeFlags(node->GetName()))&(~rmflags);
      fgSkinLayout* child = fgSkinTree_GetChild(tree, (FG_UINT)fgSkinTree_AddChild(tree, node->GetName(), flags, &transform, units, (int)node->GetAttributeInt("order")));
      fgStyle_LoadAttributesXML(&child->layout.style, node, flags, root, 0, 0, 0);
      _sendsubmsg<FG_SETSTYLE, void*, size_t>(child->instance, FGSETSTYLE_POINTER, (void*)&child->layout.style, ~0);
      fgSkinBase_LoadSubNodeXML(&child->tree, &child->layout.style, root, 0, node);
    }
  }
}

fgSkin* fgSkinBase_LoadNodeXML(fgSkinBase* self, const cXMLNode* root)
{
  const char* id = root->GetAttributeString("id");
  if(!id)
    id = root->GetAttributeString("name");
  if(!id)
     return 0;
  fgSkin* s = fgSkinBase_AddSkin(self, id);
  fgSkinBase_LoadSubNodeXML(&s->tree, &s->style, &s->base, s, root);
  return s;
}

fgSkin* fgSkinBase_LoadStreamXML(fgSkinBase* self, std::istream& s)
{
  cXML xml(s);
  size_t index = 0;
  const cXMLNode* root;
  fgSkin* ret = 0;

  while(root = xml.GetNode(index++))
  {
    if(!STRICMP(root->GetName(), "fg:skin"))
      ret = fgSkinBase_LoadNodeXML(self, root);
  }

  return ret;
}

fgSkin* fgSkinBase_LoadFileXML(fgSkinBase* self, const char* file)
{
  std::ifstream s(file, std::ios_base::in| std::ios_base::binary);
  return fgSkinBase_LoadStreamXML(self, s);
}
fgSkin* fgSkinBase_LoadXML(fgSkinBase* self, const char* data, FG_UINT length)
{
  std::istringstream s(std::string(data, length));
  return fgSkinBase_LoadStreamXML(self, s);
}

fgSkin* fgSkinBase_LoadFileUBJSON(fgSkinBase* self, const char* file)
{
  return 0;
}
fgSkin* fgSkinBase_LoadUBJSON(fgSkinBase* self, const void* data, FG_UINT length)
{
  return 0;
}

size_t fgSkinTree::AddChild(const char* type, fgFlag flags, const fgTransform* transform, short units, int order) { return fgSkinTree_AddChild(this, type, flags, transform, units, order); }
char fgSkinTree::RemoveChild(FG_UINT child) { return fgSkinTree_RemoveChild(this, child); }
fgSkinLayout* fgSkinTree::GetChild(FG_UINT child) const { return fgSkinTree_GetChild(this, child); }
FG_UINT fgSkinTree::AddStyle(const char* name) { return fgSkinTree_AddStyle(this, name); }
char fgSkinTree::RemoveStyle(FG_UINT style) { return fgSkinTree_RemoveStyle(this, style); }
fgStyle* fgSkinTree::GetStyle(FG_UINT style) const { return fgSkinTree_GetStyle(this, style); }

fgSkin* fgSkinBase::AddSkin(const char* name) { return fgSkinBase_AddSkin(this, name); }
char fgSkinBase::RemoveSkin(const char* name) { return fgSkinBase_RemoveSkin(this, name); }
fgSkin* fgSkinBase::GetSkin(const char* name) const { return fgSkinBase_GetSkin(this, name); }
size_t fgSkinBase::AddAsset(void* resource) { return fgSkinBase_AddAsset(this, resource); }
char fgSkinBase::RemoveAsset(FG_UINT resource) { return fgSkinBase_RemoveAsset(this, resource); }
void* fgSkinBase::GetAsset(FG_UINT resource) const { return fgSkinBase_GetAsset(this, resource); }
size_t fgSkinBase::AddFont(void* font) { return fgSkinBase_AddFont(this, font); }
char fgSkinBase::RemoveFont(FG_UINT font) { return fgSkinBase_RemoveFont(this, font); }
void* fgSkinBase::GetFont(FG_UINT font) const { return fgSkinBase_GetFont(this, font); }

fgSkin* fgSkinBase::LoadFileUBJSON(const char* file) { return fgSkinBase_LoadFileUBJSON(this, file); }
fgSkin* fgSkinBase::LoadUBJSON(const void* data, FG_UINT length) { return fgSkinBase_LoadUBJSON(this, data, length); }
fgSkin* fgSkinBase::LoadFileXML(const char* file) { return fgSkinBase_LoadFileXML(this, file); }
fgSkin* fgSkinBase::LoadXML(const char* data, FG_UINT length) { return fgSkinBase_LoadXML(this, data, length); }

fgSkin* fgSkin::GetSkin(const char* name) const { return fgSkin_GetSkin(this, name); }