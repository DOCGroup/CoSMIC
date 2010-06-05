// $Id$

#define DECLARE_DECORATOR_MODULE(LIBID, RCID, RCGUID) \
namespace GAME { \
class Decorator_Module : public CAtlDllModuleT < Decorator_Module > { \
public : \
	DECLARE_LIBID (LIBID) \
  DECLARE_REGISTRY_APPID_RESOURCEID (RCID, RCGUID) \
}; \
Decorator_Module _AtlModule; \
class Decorator_App : public CWinApp { \
public: \
  virtual BOOL InitInstance (void) { \
    AFX_MANAGE_STATE (AfxGetStaticModuleState ()) \
    _AtlModule.InitLibId (); \
    return CWinApp::InitInstance(); \
  } \
  virtual int ExitInstance (void) { \
    AFX_MANAGE_STATE (AfxGetStaticModuleState ())\
    _AtlModule.Term (); \
    return CWinApp::ExitInstance(); \
  } \
  DECLARE_MESSAGE_MAP () \
}; \
BEGIN_MESSAGE_MAP (Decorator_App, CWinApp) \
END_MESSAGE_MAP() \
Decorator_App theApp; \
}  \
STDAPI DllCanUnloadNow (void) { return (::AfxDllCanUnloadNow () == S_OK && ::GAME::_AtlModule.GetLockCount () == 0) ? S_OK : S_FALSE; } \
STDAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, LPVOID* ppv) { return ::GAME::_AtlModule.GetClassObject (rclsid, riid, ppv); } \
STDAPI DllRegisterServer (void) { return GAME::_AtlModule.DllRegisterServer (); } \
STDAPI DllUnregisterServer (void) { return GAME::_AtlModule.DllUnregisterServer (); }
