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
#include <afxdlgs.h> // For CFileDialog
#include "resource.h"

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
#include "XercesString.h"

#include "UdmStatic.h"
#include "UmlExt.h"
#include "UdmUtil.h"

#include "UdmApp.h"
#include "UdmConfig.h"

#include "PICML.h"


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
     GME_MAIN_START		=   0,
     GME_BROWSER_START		=   1,
     GME_CONTEXT_START		=   2,
     GME_EMBEDDED_START		=   3,
     GME_MENU_START		=  16,
     GME_BGCONTEXT_START	=  18,
     GME_ICON_START		=  32,
     METAMODEL_CHECK_SYNTAX	= 101

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
                      set<Udm::Object> selectedObjects,	// Selected objects
                      long param)			// Parameters
{
  try
    {
      XMLPlatformUtils::Initialize();
    }
  catch (const XMLException& toCatch)
    {
      AfxMessageBox ("Error during Xerces-c Initialization.\n"
                     "  Exception message:" + XStr (toCatch.getMessage()));
      return;
    }
  std::string outputPath;
  std::string message = "Please specify the Output Directory";
  getPath (message, outputPath);


  if (focusObject == Udm::null && selectedObjects.empty())
    {
    }

  std::set<Udm::Object> mySet (setSelectedFCOs);
  if (focusObject != Udm::null)
    mySet.insert (currentFCO);

  std::string messageText = "The following files: \n";

  for (std::set<Udm::Object>::iterator iter = mySet.begin();
       iter != mySet.end();
       ++iter)
    {
      std::string fileBase;
      std::string fileExt;
      if ((*iter)->getFCOMeta().name() == "TopLevelPackage")
          {
            fileBase = "package";
            fileExt = ".pcd";
          }
        else if ((*iter)->getFCOMeta().name() == "ImplementationArtifact")
          fileExt = ".iad";
        else if ((*iter)->getFCOMeta().name() == "ComponentInterface")
          fileExt = ".ccd";
        else if ((*iter)->getFCOMeta().name() == "ComponentPackage")
          fileExt = ".cpd";
        else if ((*iter)->getFCOMeta().name() == "ComponentImplementation")
          fileExt = ".cid";
        else
          {
            AfxMessageBox ("Interpretation must start from a TopLevelPackage, "
                           "or an ImplementationArtifact, or a "
                           "ComponentInterface, or a ComponentPackage, "
                           "ComponentImplementation !");
            return;
          }

        FCO root = (*iter);
        // Set the name of the root element
        std::string rootPrefix ("Deployment:");
        std::string rootSuffix ("Description");
        std::string rootName (root->getFCOMeta().name());
        if (fileBase.length() == 0)
          fileBase = root->getName();
        rootName = rootPrefix + rootName + rootSuffix;
        std::string fileName = fileBase + fileExt;
        fileName = outputPath + "\\" + fileName;

        Compass::SchemaVisitor* visitor = new Compass::SchemaVisitor(fileName,
                                                                     rootName);
        std::auto_ptr<Compass::SchemaVisitor> cleanup_visitor (visitor);
        if ((*iter)->getFCOMeta().name() == "TopLevelPackage")
          {
            Compass::TopLevelPackage start
              = Compass::TopLevelPackage ((*iter));
            start->accept(visitor);
          }
        else if ((*iter)->getFCOMeta().name() == "ImplementationArtifact")
          {
            Compass::ImplementationArtifact start
              = Compass::ImplementationArtifact ((*iter));
            start->accept(visitor);
          }
        else if ((*iter)->getFCOMeta().name() == "ComponentInterface")
          {
            Compass::ComponentInterface start
              = Compass::ComponentInterface ((*iter));
            start->accept(visitor);
          }
        else if ((*iter)->getFCOMeta().name() == "ComponentPackage")
          {
            Compass::ComponentPackage start
              = Compass::ComponentPackage ((*iter));
            start->accept(visitor);
          }
        else if ((*iter)->getFCOMeta().name() == "ComponentImplementation")
          {
            Compass::ComponentImplementation start
              = Compass::ComponentImplementation ((*iter));
            start->accept(visitor);
          }
        visitor->printDocument();
        messageText += fileName + "\n";
      }
    try
      {
        XMLPlatformUtils::Terminate();
      }
    catch (const XMLException& toCatch)
      {
        AfxMessageBox ("Error during Xerces-c Finalization.\n"
                       "  Exception message:" + XStr (toCatch.getMessage()));
        return;
      }
    AfxMessageBox (messageText.c_str() + CString(" were successfully generated ! "));    return;

    try
    {



    }

  catch(udm_exception &e)
    {
      AfxMessageBox(e.what());
    }
}


// This method prompts a dialog to allow the user to specify a folder
bool getPath (const std::string& description, std::string& path)
{
  // Initalize the com library
  //WINOLEAPI com_lib_return = OleInitialize(NULL);

  // Dialog instruction
  char display_buffer[MAX_PATH];
  BROWSEINFO folder_browsinfo;
  memset (&folder_browsinfo, 0, sizeof (folder_browsinfo));

  // Set GME as the owner of the dialog
  folder_browsinfo.hwndOwner = GetForegroundWindow();
  // Start the brows from desktop
  folder_browsinfo.pidlRoot = NULL;
  // Pointer to the folder name display buffer
  folder_browsinfo.pszDisplayName = &display_buffer[0];
  // Diaglog instruction string
  folder_browsinfo.lpszTitle = description.c_str();
  // Use new GUI style and allow edit plus file view
  folder_browsinfo.ulFlags = BIF_BROWSEINCLUDEFILES | BIF_RETURNONLYFSDIRS;
  // No callback function
  folder_browsinfo.lpfn = NULL;
  // No parameter passing into the dialog
  folder_browsinfo.lParam = 0;

  LPITEMIDLIST folder_pidl;
  folder_pidl = SHBrowseForFolder(&folder_browsinfo);

  if(folder_pidl == NULL)
    return false;
  else
    {
      TCHAR FolderNameBuffer[MAX_PATH];

      // Convert the selection into a path
      if (SHGetPathFromIDList (folder_pidl, FolderNameBuffer))
        path = FolderNameBuffer;

      // Free the ItemIDList object returned from the call to
      // SHBrowseForFolder using Gawp utility function
      IMalloc * imalloc = 0;
      if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
        {
          imalloc->Free ( folder_pidl );
          imalloc->Release ( );
        }
    }
  return true;
}

#ifdef _DEBUG
/*****************************************************/
/* Debug time helper function. If the object has an  */
/* attribute called "name", this function retreives  */
/* it to help you to find it in the model during the */
/* application development.	Usualy every GME Object	 */
/* has a "name" attribute. If an object hapens not	 */
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
