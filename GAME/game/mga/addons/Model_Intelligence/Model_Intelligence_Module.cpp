// $Id: Model_Intelligence_Module.cpp 2839 2012-02-11 18:59:36Z hillj $

#include "StdAfx.h"
#include "resource.h"

#include "Model_Intelligence_i.c"
#include "game/mga/dialogs/Module.h"

namespace GAME
{
/**
 * GAME_Model_Intelligence_Module
 */
class GAME_Model_Intelligence_Module :
  public CAtlDllModuleT < GAME_Model_Intelligence_Module >
{
public :
  DECLARE_LIBID (LIBID_Model_Intelligence_AddonLib)

  DECLARE_REGISTRY_APPID_RESOURCEID (2008, "{21d9dfcc-4568-48d8-874a-9683fb21409d}")
};

static GAME_Model_Intelligence_Module _AtlModule;

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
 * @class GAME_Model_Intelligence_App
 *
 * The application for the model intelligence. This is like the
 * main entry point for the component's module/application.
 */
class GAME_Model_Intelligence_App : public CWinApp
{
public:
  //
  // Component_Module_App
  //
  GAME_Model_Intelligence_App (void)
    : CWinApp ("GAME Model Intelligence")
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

BEGIN_MESSAGE_MAP (GAME_Model_Intelligence_App, CWinApp)
END_MESSAGE_MAP()

static GAME_Model_Intelligence_App _theApp;
