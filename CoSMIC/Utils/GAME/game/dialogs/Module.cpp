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
    // Extension DLL one-time initialization
    if (!::AfxInitExtensionModule (extdll, hinst))
       return 0;

    break;

  case DLL_PROCESS_DETACH:
    ::AfxTermExtensionModule (extdll);
    break;
  }

  return 1;
}
