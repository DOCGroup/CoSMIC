// $Id$

#include "stdafx.h"
#pragma warning( disable : 4290 )

#include <windows.h>
#include <shlobj.h>
#include "resource.h"
#include <stdlib.h>
#include <sstream>

#include "UdmStatic.h"
#include "UmlExt.h"
#include "UdmUtil.h"

#include "UdmApp.h"
#include "UdmConfig.h"

#include "Utils/Utils.h"

#include "CQML/CQML.h"
#include "FaultTolerance/FaultToleranceVisitor.h"

using xercesc::XMLPlatformUtils;
using xercesc::XMLException;
using xercesc::DOMException;
using xercesc::XMLString;

extern void dummy(void); // Dummy function for UDM meta initialization

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

void CUdmApp::UdmMain(Udm::DataNetwork* p_backend,      // Backend pointer
                                                        // (already open!)
                      Udm::Object focusObject,          // Focus object
                      set<Udm::Object> selectedObjects,  // Selected objects
                      long param)      // Parameters
{
      XMLPlatformUtils::Initialize();
      try
        {
          std::string outputPath;
          std::string message = "Please specify the Output Directory";
          if (! ::Utils::getPath (message, outputPath))       return;
    //outputPath = "C:\\Documents and Settings\\sumant\\Desktop\\DOC Files\\backup";
          CQML::FaultToleranceVisitor visitor (outputPath);
          CQML::RootFolder
            start = CQML::RootFolder::Cast (p_backend->GetRootObject());
          start.Accept (visitor);
          //system ("\"C:\\Program Files\\Mozilla Firefox\\firefox.exe\" -turbo -nosplash www.vanderbilt.edu" );
        }
      catch(udm_exception &e)
        {
          AfxMessageBox ("FaultTolerance Interpretation Failed. Caught UDM Exception: "
                         + CString (e.what()));
          return;
        }
  AfxMessageBox ("Descriptor files were successfully generated!",
                 MB_OK| MB_ICONINFORMATION);
  return;
}
