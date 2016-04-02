// Copyright �2016 Black Sphere Studios
// For conditions of distribution and use, see copyright notice in "feathergui.h"

#ifndef _FG_LIST_H__
#define _FG_LIST_H__

#include "fgBox.h"

#ifdef  __cplusplus
extern "C" {
#endif

enum FGLIST_FLAGS
{
  FGLIST_SINGLESELECT = (1 << 17),
  FGLIST_MULTISELECT = (1 << 18),
  FGLIST_DRAGGABLE = (1 << 19),
};

// A List is an arbitrary list of items with a number of different layout options that are selectable and/or draggable.
typedef struct {
  fgBox box;
  fgChild selector;
  fgChild hover;
  fgChild* selected; // points to current selected item
  fgMouseState mouse;
#ifdef  __cplusplus
  inline operator fgChild*() { return &box.window.window.element; }
  inline fgChild* operator->() { return operator fgChild*(); }
#endif
} fgList;

FG_EXTERN fgChild* FG_FASTCALL fgList_Create(fgChild* BSS_RESTRICT parent, fgChild* BSS_RESTRICT prev, const fgElement* element, FG_UINT id, fgFlag flags);
FG_EXTERN void FG_FASTCALL fgList_Init(fgList* self, fgChild* BSS_RESTRICT parent, fgChild* BSS_RESTRICT prev, const fgElement* element, FG_UINT id, fgFlag flags);
FG_EXTERN void FG_FASTCALL fgList_Destroy(fgList* self);
FG_EXTERN size_t FG_FASTCALL fgList_Message(fgList* self, const FG_Msg* msg);

#ifdef  __cplusplus
}
#endif

#endif