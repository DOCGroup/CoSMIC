// $Id$

#include "stdafx.h"
#include "Module.h"

static AFX_EXTENSION_MODULE extdll = {0, 0};

namespace GAME
{
namespace Dialogs
{

//
// initialize_module
//
int initialize_module (void)
{
  new CDynLinkLibrary (extdll);

  INITCOMMONCONTROLSEX common_controls;
  common_controls.dwSize = sizeof (INITCOMMONCONTROLSEX);
  common_controls.dwICC = ICC_LISTVIEW_CLASSES;

  if (0 == ::AfxInitCommonControlsEx (&common_controls))
    return -1;

   return 0;
}

}
}

//
// DllMain
//
extern "C"
int APIENTRY DllMain (HINSTANCE hinst, DWORD reason, LPVOID)
{
  switch (reason)
  {
  case DLL_PROCESS_ATTACH:
    if (0 == ::AfxInitExtensionModule (extdll, hinst))
       return 0;

    break;

  case DLL_PROCESS_DETACH:
    ::AfxTermExtensionModule (extdll);
    break;
  }

  return 1;
}
