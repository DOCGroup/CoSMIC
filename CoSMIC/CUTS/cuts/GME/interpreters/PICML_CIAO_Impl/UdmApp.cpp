// $Id$

#include "StdAfx.h"

// Utility includes
//#include "UdmStatic.h"
//#include "UmlExt.h"
//#include "UdmUtil.h"

#include "UdmApp.h"
//#include "UdmConfig.h"
#include "Main_Dialog.h"
#include "PICML/Utils.h"

/* Backend specific headers */
#include "cuts/be/CIAO/CoWorkEr_Cache.h"
#include "cuts/be/CIAO/Dependency_Graph.h"
#include "cuts/be/CIAO/Dependency_Generator.h"
#include "cuts/be/CIAO/UDM_CIAO_Visitor.h"
#include "cuts/be/CIAO/Workspace_Generator.h"
#include "cuts/be/CIAO/CoWorkEr_Generator.h"
#include "cuts/be/CIAO/CUTS_Project.h"

class CFolderDialog : public CFileDialog
{
public:
  CFolderDialog (void)
    : CFileDialog (TRUE, 0, 0, OFN_EXPLORER | OFN_HIDEREADONLY, "*.")
  {

  }

  virtual ~CFolderDialog (void) { }

  virtual void OnFolderChange (void)
  {
    AfxMessageBox ("OnFolderChange");
  }

  virtual void OnFileNameChange (void)
  {
    AfxMessageBox ("OnFileNameChange");
  }

  virtual BOOL OnFileNameOK (void)
  {
    AfxMessageBox ("OnFileNameOK");
    return 0;
  }
};

/* Dummy function for UDM meta initialization */
extern void dummy(void);

// Initialization function. The framework calls it before preparing the
// backend. Initialize here the settings in the config static object.
// Return 0 if successful.
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

/***********************************************/
/* Main entry point for Udm-based Interpreter  */
/***********************************************/

void CUdmApp::UdmMain(Udm::DataNetwork* p_backend,
                      Udm::Object focusObject,
                      set <Udm::Object> selectedObjects,
                      long param)
{
  //CFolderDialog folder;
  //folder.DoModal ();

  // Initialize the <CUTS_Project>. We need to make sure the project is
  // valid before continuing. It just doesn't make any sense to continue
  // to waste the end-user's time if the project is invalid. Eventually,
  // we would like to be able to make invalid projects valid.
  // Get the root folder for the project.
  PICML::RootFolder root =
    PICML::RootFolder::Cast (p_backend->GetRootObject());

  root.Accept (*CUTS_Project::instance ());

  if (!CUTS_Project::instance ()->is_valid ())
  {
    ::AfxMessageBox (CUTS_Project::instance ()->message ().c_str (),
                     MB_OK | MB_ICONEXCLAMATION);
    CUTS_Project::close ();
    return;
  }


  // Show the main dialog and let the <end-user> select which
  // <option> they want to execute. If the user selects to
  // cancel the process then we just return.
  Main_Dialog main_dialog (::AfxGetMainWnd ());

  if (main_dialog.DoModal () == IDCANCEL)
    return;

  switch (main_dialog.option ())
  {
  case Main_Dialog::OPT_GENERATE_MODELS:
    {
      CUTS_UDM_CoWorkEr_Generator coworker_generator;
      root.Accept (coworker_generator);
    }
    break;

  case Main_Dialog::OPT_GENERATE_SOURCE:
    {
      std::string output_dir;
      std::string message ("Please specify the output directory");

      if (PICML::getPath (message, output_dir))
      {
        // Generate the dependency graph for the model.
        CUTS_Dependency_Graph dependency_graph;
        CUTS_Dependency_Generator dependency_generator (dependency_graph);
        root.Accept (dependency_generator);

        // Generate the source code for the PICML model.
        CUTS::UDM_CIAO_Visitor ciao_generator (output_dir,
                                               dependency_graph);
        root.Accept (ciao_generator);

        // Generate the workspace for the project.
        CUTS_Workspace_Generator workspace_generator (output_dir,
                                                      dependency_graph);
        root.Accept (workspace_generator);

        ::AfxMessageBox ("Successfully completed code generation",
                         MB_OK | MB_ICONINFORMATION);
      }
    }
    break;
  }

  CUTS_Project::close ();
}