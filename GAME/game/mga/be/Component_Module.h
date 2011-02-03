// $Id$

#define DECLARE_COMPONENT_MODULE(APPNAME, LIBID, RCID, RCGUID) \
namespace GAME { \
namespace Mga { \
class Component_Module : public CAtlDllModuleT < Component_Module > { \
public : \
  DECLARE_LIBID (LIBID) \
  DECLARE_REGISTRY_APPID_RESOURCEID (RCID, RCGUID) \
}; \
static Component_Module _AtlModule; \
class Component_Module_App : public CWinApp { \
public: \
  Component_Module_App (void) \
    : CWinApp (APPNAME) { } \
  virtual BOOL InitInstance (void) { \
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ()); \
    _AtlModule.InitLibId (); \
    return CWinApp::InitInstance(); \
  } \
  virtual int ExitInstance (void) { \
    AFX_MANAGE_STATE (::AfxGetStaticModuleState ());\
    _AtlModule.Term (); \
    return CWinApp::ExitInstance(); \
  } \
  DECLARE_MESSAGE_MAP () \
}; \
BEGIN_MESSAGE_MAP (Component_Module_App, CWinApp) \
END_MESSAGE_MAP() \
static Component_Module_App _theApp; \
} \
} \
STDAPI DllCanUnloadNow (void) { return (::AfxDllCanUnloadNow () == S_OK && GAME::Mga::_AtlModule.GetLockCount () == 0) ? S_OK : S_FALSE; } \
STDAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, LPVOID* ppv) { return GAME::Mga::_AtlModule.GetClassObject (rclsid, riid, ppv); } \
STDAPI DllRegisterServer (void) { return GAME::Mga::_AtlModule.DllRegisterServer (); } \
STDAPI DllUnregisterServer (void) { return GAME::Mga::_AtlModule.DllUnregisterServer (); }
