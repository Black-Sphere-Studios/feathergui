// Copyright �2013 Black Sphere Studios
// For conditions of distribution and use, see copyright notice in "feathergui.h"

#ifndef __FG_BUTTON_H__
#define __FG_BUTTON_H__

#include "fgWindow.h"

#ifdef  __cplusplus
extern "C" {
#endif

// A button is usually implemented as a simple background design, plus a centering GUI component that takes a static and
// displays it in the center of the button.
typedef struct _FG_BUTTON {
  fgWindow window;
  fgStatic* item; // item displayed in button
  fgStatic* neutral; // normal background for when button isn't in hover or active (being clicked) state
  fgStatic* hover; // background for hovering
  fgStatic* active; // background for being clicked
} fgButton;

struct FG_BUTTONSKIN {
  struct FG_WINDOWSKIN base;
  fgStatic* nuetral; // normal background for when button isn't in hover or active (being clicked) state
  fgStatic* hover; // background for hovering
  fgStatic* active;
};

FG_EXTERN fgWindow* FG_FASTCALL fgButton_Create(fgStatic* item, fgWindow* parent, const fgElement* element, FG_UINT id, fgFlag flags);
FG_EXTERN void FG_FASTCALL fgButton_Init(fgButton* self, fgWindow* parent, const fgElement* element, FG_UINT id, fgFlag flags);
FG_EXTERN char FG_FASTCALL fgButton_Message(fgButton* self, const FG_Msg* msg);

#ifdef  __cplusplus
}
#endif

#endif
