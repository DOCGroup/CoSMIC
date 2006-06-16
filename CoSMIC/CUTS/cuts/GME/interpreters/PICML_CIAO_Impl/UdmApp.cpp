/*
  Copyright (c) Vanderbilt University, 2000-2001
  ALL RIGHTS RESERVED
  Vanderbilt University disclaims all warranties with regard to this
  software, including all implied warranties of merchantability
  and fitness.  In no event shall Vanderbilt University be liable for
  any special, indirect or consequential damages or any damages
  whatsoever resulting from loss of use, data or profits, whether
  in an action of contract, negligence or other tortious action,
  arising out of or in connection with the use or performance of
  this software.
*/


// UdmApp.cpp: implementation of the CUdmApp class.
// This file was automatically generated as UdmApp.cpp
// by UDM Interpreter Wizard on Monday, May 13, 2002 13:45:42

// Tihamér Levendovszky 05-13-02

#include "stdafx.h"
#pragma warning( disable : 4290 )
#include <afxdlgs.h> // For CFileDialog
#include "resource.h"
#include <stdlib.h>
#include <sstream>

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "UdmStatic.h"
#include "UmlExt.h"
#include "UdmUtil.h"

#include "UdmApp.h"
#include "UdmConfig.h"

#include "PICML/Utils.h"
#include "cuts/be/CIAO/CoWorkEr_Cache.h"
#include "cuts/be/CIAO/Dependency_Graph.h"
#include "cuts/be/CIAO/Dependency_Generator.h"
#include "cuts/be/CIAO/UDM_CIAO_Visitor.h"
#include "cuts/be/CIAO/Workspace_Generator.h"

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

void CUdmApp::UdmMain(Udm::DataNetwork* p_backend,
                      Udm::Object focusObject,
                      set<Udm::Object> selectedObjects,
                      long param)
{
  try
  {
    XMLPlatformUtils::Initialize();

    try
    {
      std::string output_dir;
      std::string message ("Please specify the output directory");

      if (PICML::getPath (message, output_dir))
      {
        // Get the root folder for the project.
        PICML::RootFolder root =
          PICML::RootFolder::Cast (p_backend->GetRootObject());

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

        AfxMessageBox ("Successfully completed code generation",
                       MB_OK | MB_ICONINFORMATION);
      }
    }
    catch(udm_exception &e)
    {
      AfxMessageBox ("Caught UDM Exception: " + CString (e.what()),
                     MB_ICONERROR | MB_OK);
    }
    catch (const DOMException& e)
    {
      const unsigned int maxChars = 2047;
      XMLCh errText[maxChars + 1];

      std::stringstream estream;
      estream << "DOMException code: " << e.code << std::endl;

      if (xercesc::DOMImplementation::loadDOMExceptionMsg(e.code, errText, maxChars))
      {
        std::string message (XMLString::transcode (errText));
        estream << "Message is: " << message << std::endl;
      }

      AfxMessageBox (estream.str().c_str(), MB_ICONERROR | MB_OK);
    }

    XMLPlatformUtils::Terminate();
  }
  catch (const XMLException& e)
  {
    std::string message (XMLString::transcode (e.getMessage()));
    AfxMessageBox (message.c_str(), MB_ICONERROR | MB_OK);
  }
}
