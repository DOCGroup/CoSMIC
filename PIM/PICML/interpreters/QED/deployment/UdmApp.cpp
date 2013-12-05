// UdmApp.cpp: implementation of the CUdmApp class.
// This file was automatically generated as UdmApp.cpp
// by UDM Interpreter Wizard on Wednesday, July 21, 2004 16:52:24

#include "stdafx.h"
#include "UdmApp.h"
#include "UdmConfig.h"
#include "QED_Deployment_Visitor.h"
#include "Utils/Utils.h"
#include "xercesc/util/PlatformUtils.hpp"

//
// Initialize
//
int CUdmApp::Initialize()
{
  return 0;
}


/*
  Remarks to CUdmApp::UdmMain(...):
  0.  The p_backend points to an already open backend, and the framework
  closes it automatically. DO NOT OPEN OR CLOSE IT!
  To commit changes use p_backend->CommitEditSequence().
  To abort changes use p_backend->AbortEditSequence().
  To save changes to a different file use p_backend->SaveAs() or p_backend->CloseAs().

  1.  Focus is the currently open model.

  2.  The possible values for param (from GME DecoratorLib.h component_startmode_enum):
  GME_MAIN_START      =   0,
  GME_BROWSER_START    =   1,
  GME_CONTEXT_START    =   2,
  GME_EMBEDDED_START    =   3,
  GME_MENU_START      =  16,
  GME_BGCONTEXT_START    =  18,
  GME_ICON_START      =  32,
  METAMODEL_CHECK_SYNTAX  = 101

  3. The framework catches all the exceptions and reports the error in a message box,
  clean up and close the transactions aborting the changes. You can override this
  behavior by catching udm_exception. Use udm_exception::what() to form an error
  message.
*/

//
// UdmMain
//
void CUdmApp::UdmMain (Udm::DataNetwork* p_backend,
                       Udm::Object focusObject,
                       std::set <Udm::Object> selectedObjects,
                       long param)
{
  if (this->outdir_.empty ())
  {
    std::string message = "Please specify the output directory";

    // If there is no output path specified
    if (!Utils::getPath (message, this->outdir_, this->outdir_))
      return;
  }

  // Get the root object and visit it.
  Udm::Object root_obj = p_backend->GetRootObject();
  PICML::RootFolder root = PICML::RootFolder::Cast (root_obj);

  xercesc::XMLPlatformUtils::Initialize ();

  QED_Deployment_Visitor visitor (this->outdir_);
  root.Accept (visitor);

  xercesc::XMLPlatformUtils::Terminate ();

  if (this->interactive_)
    ::AfxMessageBox ("Successfully generated QED deployment files.", MB_OK | MB_ICONINFORMATION);
}

//
// SetParameter
//
void CUdmApp::
SetParameter (const std::string & name, const std::string & value)
{
  if (name == "-non-interactive")
  {
    this->interactive_ = false;
  }
  else if (name == "-o")
  {
    this->outdir_ = value;
  }
}

//
// output_directory
//
const std::string & CUdmApp::output_directory (void) const
{
  return this->outdir_;
}
