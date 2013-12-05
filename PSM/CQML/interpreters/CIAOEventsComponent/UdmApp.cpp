// UdmApp.cpp: implementation of the CUdmApp class.
// This file was automatically generated as UdmApp.cpp
// by UDM Interpreter Wizard on Friday, November 23, 2007 09:55:04

#include "stdafx.h"
#include "UdmApp.h"
#include "UdmConfig.h"
#include "Uml.h"

#include "Utils/Utils.h"
#include "xercesc/util/PlatformUtils.hpp"
#include "CQML/CQML.h"
#include "CIAOEvents/CIAOEventsVisitor.h"

#include <sstream>


extern void dummy(void); // Dummy function for UDM meta initialization

// static variable decl.
std::string CUdmApp::output_path_;

/*********************************************************************************/
/* Initialization function. The framework calls it before preparing the backend. */
/* Initialize here the settings in the config global object.            */
/* Return 0 if successful.                              */
/*********************************************************************************/
int CUdmApp::Initialize()
{

  // TODO: Your initialization code comes here...
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

/***********************************************/
/* Main entry point for Udm-based Interpreter  */
/***********************************************/

void CUdmApp::UdmMain(
           Udm::DataNetwork* p_backend,    // Backend pointer(already open!)
           Udm::Object focusObject,      // Focus object
           set<Udm::Object> selectedObjects,  // Selected objects
           long param)            // Parameters
{
  try
    {
    xercesc::XMLPlatformUtils::Initialize();
      try
        {
          // We only need to ask for the output path it wasn't already
          // set before hand. The only want to can be set before hand
          // is by some external application invoking put_ComponentParameter
          // method for the interpreter. :o)

          if (CUdmApp::output_path_.empty ())
          {
            std::string message = "Please specify the output directory";
      if (!Utils::getPath (message, CUdmApp::output_path_))
              return;
          }

      CQML::CIAOEventsVisitor visitor (CUdmApp::output_path_);
          CQML::RootFolder start =
        CQML::RootFolder::Cast (p_backend->GetRootObject());
          start.Accept (visitor);
        }
      catch(udm_exception &e)
        {
          AfxMessageBox ("Caught UDM Exception: " + CString (e.what()));
          return;
        }
    catch (const xercesc::DOMException& e)
        {
          const unsigned int maxChars = 2047;
      XMLCh errText[maxChars + 1];

          std::stringstream estream;
          estream << "DOMException code: " << e.code << std::endl;
          if (xercesc::DOMImplementation::loadDOMExceptionMsg(e.code, errText, maxChars))
            {
        std::string message (xercesc::XMLString::transcode (errText));
              estream << "Message is: " << message << std::endl;
            }
          AfxMessageBox (estream.str().c_str());
          return;
        }
    xercesc::XMLPlatformUtils::Terminate();
    }
  catch (const xercesc::XMLException& e)
    {
      std::string message (xercesc::XMLString::transcode (e.getMessage()));
      AfxMessageBox (message.c_str());
      return;
    }
  AfxMessageBox ("Descriptor files were successfully generated!",
                 MB_OK| MB_ICONINFORMATION);
  return;
}



#ifdef _DEBUG
/*****************************************************/
/* Debug time helper function. If the object has an  */
/* attribute called "name", this function retreives  */
/* it to help you to find it in the model during the */
/* application development.  Usualy every GME Object   */
/* has a "name" attribute. If an object hapens not   */
/* to have it,function retreives <no name specified>.*/
/*****************************************************/
string CUdmApp::ExtractName(Udm::Object ob)
{
  Uml::Class cls= ob.type();
  set<Uml::Attribute> attrs=cls.attributes();

  // Adding parent attributes
  set<Uml::Attribute> aattrs=Uml::AncestorAttributes(cls);
  attrs.insert(aattrs.begin(),aattrs.end());

  for(set<Uml::Attribute>::iterator ai = attrs.begin();ai != attrs.end(); ai++)
  {
    if(string(ai->type())=="String")
    {
      string str=ai->name();
      if(str=="name")
      {
        string value=ob.getStringAttr(*ai);
        if(value.empty())value="<empty string>";
        return value;
      }
    }
  }
  return string("<no name specified>");
}
#endif

void CUdmApp::SetParameter (const std::string & name,
                            const std::string & value)
{
  if (name == "output")
    CUdmApp::output_path_ = value;
}
