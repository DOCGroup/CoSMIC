// $Id$

#include "StdAfx.h"
#include "UdmApp.h"
#include "Main_Dialog.h"
#include "Utils/Utils.h"

#include "cuts/be/CUTS_Project.h"
#include "cuts/be/CoWorkEr_Cache.h"
#include "cuts/be/CoWorkEr_Generator.h"

#include "cuts/be/BE_Options.h"
#include "cuts/be/CIAO/CIAO_Manager.h"

//
// dummy function for UDM meta initialization
//
extern void dummy(void);

//
// Initialize
//
int CUdmApp::Initialize()
{
  return 0;
}

/*
  Remarks to CUdmApp::UdmMain(...):
  0. The p_backend points to an already open backend, and the framework
  closes it automatically. DO NOT OPEN OR CLOSE IT! To commit changes
  use p_backend->CommitEditSequence(). To abort changes use
  p_backend->AbortEditSequence(). To save changes to a different file
  use p_backend->SaveAs() or p_backend->CloseAs().

  1. Focus is the currently open model.

  2. The possible values for param (from GME DecoratorLib.h
  component_startmode_enum):
  GME_MAIN_START    =   0,
  GME_BROWSER_START    =   1,
  GME_CONTEXT_START    =   2,
  GME_EMBEDDED_START    =   3,
  GME_MENU_START    =  16,
  GME_BGCONTEXT_START  =  18,
  GME_ICON_START    =  32,
  METAMODEL_CHECK_SYNTAX  = 101

  3. The framework catches all the exceptions and reports the error in a
  message box, clean up and close the transactions aborting the changes.
  You can override this behavior by catching udm_exception. Use
  udm_exception::what() to form an error message.
*/
void CUdmApp::UdmMain(Udm::DataNetwork* p_backend,
                      Udm::Object focusObject,
                      set <Udm::Object> selectedObjects,
                      long param)
{
  // Show the main dialog and let the <end-user> select which
  // <option> they want to execute. If the user selects to
  // cancel the process then we just return.
  Main_Dialog dialog (::AfxGetMainWnd ());

  if (dialog.DoModal () == IDCANCEL)
    return;

  // Get the root folder for the project.
  PICML::RootFolder root =
    PICML::RootFolder::Cast (p_backend->GetRootObject());

  switch (dialog.option ())
  {
  case Main_Dialog::OPT_GENERATE_MODELS:
    {
      root.Accept (*CUTS_Project::instance ());

      CUTS_UDM_CoWorkEr_Generator coworker_generator;
      root.Accept (coworker_generator);
    }
    break;

  case Main_Dialog::OPT_GENERATE_SOURCE:
    {
      // Initialize the backend options. Eventually, the user will
      // be able to set these via a dialog.
      CUTS_BE_OPTIONS ()->project_name_ = root.name ();
      CUTS_BE_OPTIONS ()->exec_suffix_  = "_exec";
      CUTS_BE_OPTIONS ()->proxy_suffix_ = "_proxy";

      // Request the user to select an output directory.
      bool valid = Utils::getPath ("Please specify the output directory",
                                   CUTS_BE_OPTIONS ()->output_directory_);
      if (valid)
      {
        // Create a CIAO manager and pass it the root element.
        CIAO_BE_Manager manager;
        manager.handle (root);

        // Display a useful dialog message to the user.
        ::AfxMessageBox ("Implementation code generation complete",
                         MB_OK | MB_ICONINFORMATION);
      }
      else
      {
        // Display a useful dialog message to the user.
        ::AfxMessageBox ("Operation has been canceled",
                         MB_OK | MB_ICONINFORMATION);
      }
    }
    break;

  default:
    ::AfxMessageBox ("Invalid selection", MB_OK | MB_ICONERROR);
  }
}
