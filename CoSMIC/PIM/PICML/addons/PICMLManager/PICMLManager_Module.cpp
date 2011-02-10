// $Id$

#include "StdAfx.h"
#include "PICMLManager_i.c"
#include "resource.h"

#include "game/mga/dialogs/Module.h"

namespace GAME
{
/**
 * PICML_Model_Intelligence_Module
 */
class PICML_Model_Intelligence_Module :
  public CAtlDllModuleT < PICML_Model_Intelligence_Module >
{
public :
  DECLARE_LIBID (LIBID_PICMLManager_AddonLib)

  DECLARE_REGISTRY_APPID_RESOURCEID (IDR_LIB, "{B418C3B8-9D67-41E5-BF50-1C9AACA12192}")
};

static PICML_Model_Intelligence_Module _AtlModule;

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
class PICML_Model_Intelligence_App : public CWinApp
{
public:
  //
  // Component_Module_App
  //
  PICML_Model_Intelligence_App (void)
    : CWinApp ("PICML Model Intelligence")
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

BEGIN_MESSAGE_MAP (PICML_Model_Intelligence_App, CWinApp)
END_MESSAGE_MAP()

static PICML_Model_Intelligence_App _theApp;
