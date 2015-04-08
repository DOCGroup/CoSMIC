#include "stdafx.h"
#include "Resource.h"
#include "DecoratorLib.h"
#include "DecoratorLib_i.c"
#include "Decorator.h"

/**
 * @class CDecoratorModule
 */
class CDecoratorModule : public CAtlDllModuleT < CDecoratorModule >
{
public :
	DECLARE_LIBID (LIBID_DecoratorLib)
  DECLARE_REGISTRY_APPID_RESOURCEID (IDR_DECORATOR, "{CDD72C3A-3340-4225-83D6-46B10E9A763E}")
};

CDecoratorModule _AtlModule;

/**
 * @class CDecoratorApp
 */
class CDecoratorApp : public CWinApp
{
public:
  virtual BOOL InitInstance (void) {
    _AtlModule.InitLibId ();
    return CWinApp::InitInstance();
  }

  virtual int ExitInstance (void) {
    _AtlModule.Term ();
    return CWinApp::ExitInstance();
  }

  DECLARE_MESSAGE_MAP ()
};

BEGIN_MESSAGE_MAP (CDecoratorApp, CWinApp)

END_MESSAGE_MAP()

CDecoratorApp theApp;

//
// DllCanUnloadNow
//
STDAPI DllCanUnloadNow (void)
{
  return (AfxDllCanUnloadNow () == S_OK && _AtlModule.GetLockCount () == 0) ? S_OK : S_FALSE;
}

//
// DllGetClassObject
//
STDAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
  return _AtlModule.GetClassObject (rclsid, riid, ppv);
}

//
// DllRegisterServer
//
STDAPI DllRegisterServer (void)
{
  return _AtlModule.DllRegisterServer ();
}

//
// DllUnregisterServer
//
STDAPI DllUnregisterServer (void)
{
  return _AtlModule.DllUnregisterServer ();
}
