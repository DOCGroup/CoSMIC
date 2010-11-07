// $Id$

#include "StdAfx.h"
#include "CBMLManager_i.c"
#include "game/dialogs/Module.h"

namespace GAME
{
/**
 * CBML_Model_Intelligence_Module
 */
class CBML_Model_Intelligence_Module :
  public CAtlDllModuleT < CBML_Model_Intelligence_Module >
{
public :
  DECLARE_LIBID (LIBID_CBMLManager_AddonLib)

  DECLARE_REGISTRY_APPID_RESOURCEID (1001, "{FC3DDE48-DD56-4F65-87DD-7DE9A262CEDC}")
};

static CBML_Model_Intelligence_Module _AtlModule;

//
// DllCanUnloadNow
//
STDAPI DllCanUnloadNow (void)
{
  return (::AfxDllCanUnloadNow () == S_OK && ::GAME::_AtlModule.GetLockCount () == 0) ? S_OK : S_FALSE;
}

//
// DllGetClassObject
//
STDAPI DllGetClassObject (REFCLSID rclsid, REFIID riid, LPVOID* ppv)
{
  return ::GAME::_AtlModule.GetClassObject (rclsid, riid, ppv);
}

//
// DllRegisterServer
//
STDAPI DllRegisterServer (void)
{
  return GAME::_AtlModule.DllRegisterServer ();
}

//
// DllUnregisterServer
//
STDAPI DllUnregisterServer (void)
{
  return GAME::_AtlModule.DllUnregisterServer ();
}

}

///////////////////////////////////////////////////////////////////////////////
//

/**
 * @class PICML_Model_Intelligence_App
 *
 * The application for the model intelligence. This is like the
 * main entry point for the component's module/application.
 */
class CBML_Model_Intelligence_App : public CWinApp
{
public:
  //
  // Component_Module_App
  //
  CBML_Model_Intelligence_App (void)
    : CWinApp ("CBML Model Intelligence")
  {
  }

  //
  // InitInstance
  //
  virtual BOOL InitInstance (void)
  {
    // Initialize the GAME dialogs module.
    GAME::Dialogs::initialize_module ();

    GAME::_AtlModule.InitLibId ();
    return CWinApp::InitInstance();
  }

  //
  // ExitInstance
  //
  virtual int ExitInstance (void)
  {
    GAME::_AtlModule.Term ();
    return CWinApp::ExitInstance();
  }

  DECLARE_MESSAGE_MAP ()
};

BEGIN_MESSAGE_MAP (CBML_Model_Intelligence_App, CWinApp)
END_MESSAGE_MAP()

static CBML_Model_Intelligence_App _theApp;
