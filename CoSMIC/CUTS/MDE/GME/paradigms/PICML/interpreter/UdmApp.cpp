// $Id$

#include "StdAfx.h"
#include "UdmApp.h"
#include "Main_Dialog.h"
#include "Utils/Utils.h"

#include "cuts/be/CUTS_Project.h"
#include "cuts/be/CoWorkEr_Cache.h"
#include "cuts/be/CoWorkEr_Generator.h"
#include "cuts/be/BE_Assembly_Generator.h"

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

//
// UdmMain
//
void CUdmApp::UdmMain(Udm::DataNetwork* p_backend,
                      Udm::Object focusObject,
                      set <Udm::Object> selectedObjects,
                      long param)
{
  // Displaay the main dialog and initialize it with the
  // current backend options.
  CWnd * parent = ::AfxGetMainWnd ();
  CUTS_BE_Options * options = CUTS_BE_OPTIONS ();
  Main_Dialog dialog (options, parent);

  if (dialog.DoModal () == IDCANCEL)
    return;

  // Get the root folder for the project.
  PICML::RootFolder root =
    PICML::RootFolder::Cast (p_backend->GetRootObject());

  switch (CUTS_BE_OPTIONS ()->option_)
  {
  case CUTS_BE_Options::OPT_GENERATE_MODELS:
    {
      // Generate the CUTS project.
      root.Accept (*CUTS_Project::instance ());

      // Generate the CoWorkEr models.
      CUTS_CoWorkEr_Generator coworker_generator;
      root.Accept (coworker_generator);

      ::AfxMessageBox ("Successfully generated CUTS proxy components",
                       MB_ICONINFORMATION | MB_OK);
    }
    break;

  case CUTS_BE_Options::OPT_GENERATE_PROXY_ASSEMBLIES:
    {
      // Generate the CUTS project.
      root.Accept (*CUTS_Project::instance ());

      CUTS_BE_Assembly_Generator generator;
      root.Accept (generator);

      ::AfxMessageBox ("Successfully generated CUTS proxy assemblies",
                       MB_ICONINFORMATION | MB_OK);
    }
    break;

  case CUTS_BE_Options::OPT_GENERATE_SOURCE:
    {
      // Initialize the backend options. Eventually, the user will
      // be able to set these via a dialog.
      CUTS_BE_OPTIONS ()->exec_suffix_  = "_exec";

      // Create a CIAO manager and pass it the root element.
      CIAO_BE_Manager manager;
      manager.handle (root);

      // Display a useful dialog message to the user.
      ::AfxMessageBox ("Successfully generated implementation files",
                        MB_OK | MB_ICONINFORMATION);
    }
    break;

  default:
    ::AfxMessageBox ("Unknown menu option", MB_OK | MB_ICONERROR);
  }
}
