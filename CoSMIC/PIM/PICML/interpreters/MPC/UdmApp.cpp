// UdmApp.cpp: implementation of the CUdmApp class.
// This file was automatically generated as UdmApp.cpp
// by UDM Interpreter Wizard on Tuesday, July 27, 2004 11:22:34



#include "stdafx.h"
#include "UdmApp.h"
#include "UdmConfig.h"
#include "MPC_Visitor.h"

#define SetUpVisitor(type, root, visitor)                               \
  do                                                                    \
    {                                                                   \
      PICML:: ## type start = PICML:: ## type ## ::Cast (root);         \
      start.Accept (visitor);                                           \
    } while (0)


/*********************************************************************************/
/* Initialization function. The framework calls it before preparing the backend. */
/* Initialize here the settings in the config global object.					  */
/* Return 0 if successful.														  */
/*********************************************************************************/
int CUdmApp::Initialize()
{

	// TODO: Your initialization code comes here...
	return 0;
}

static void showUsage()
{
  AfxMessageBox ("Interpretation must start from and IDL File");
  return;
}


// This method prompts a dialog to allow the user to specify a folder
static bool getPath (const std::string& description, std::string& path)
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


/* 
Remarks to CUdmApp::UdmMain(...):
0.	The p_backend points to an already open backend, and the framework 
	closes it automatically. DO NOT OPEN OR CLOSE IT!
	To commit changes use p_backend->CommitEditSequence().
	To abort changes use p_backend->AbortEditSequence().
	To save changes to a different file use p_backend->SaveAs() or p_backend->CloseAs().

1.	Focus is the currently open model.

2.	The possible values for param (from GME DecoratorLib.h component_startmode_enum):
	GME_MAIN_START			=   0,
	GME_BROWSER_START		=   1,
	GME_CONTEXT_START		=   2,
	GME_EMBEDDED_START		=   3,
	GME_MENU_START			=  16,
	GME_BGCONTEXT_START		=  18,
	GME_ICON_START			=  32,
	METAMODEL_CHECK_SYNTAX	= 101

 3. The framework catches all the exceptions and reports the error in a message box,
	clean up and close the transactions aborting the changes. You can override this 
	behavior by catching udm_exception. Use udm_exception::what() to form an error 
	message.
*/

/***********************************************/
/* Main entry point for Udm-based Interpreter  */
/***********************************************/

void CUdmApp::UdmMain(
					 Udm::DataNetwork* p_backend,		// Backend pointer(already open!)
					 Udm::Object focusObject,			// Focus object
					 set<Udm::Object> selectedObjects,	// Selected objects
					 long param)						// Parameters
{
	try
    {
		std::string outputPath;
		std::string message = "Please specify the Output Directory";
		getPath (message, outputPath);
				
		// Do not do anything if Cancel button is pressed
		if (outputPath.size () == 0)
			return;

		if (focusObject == Udm::null && selectedObjects.empty())
        {
			showUsage();
			return;
        }
		else
        {
			std::set<Udm::Object> mySet (selectedObjects);
			if (focusObject != Udm::null)
				mySet.insert (focusObject);

			for (std::set<Udm::Object>::iterator iter = mySet.begin();
			iter != mySet.end();
			++iter)
            {
				// Interpretation should start from MPC Aspect
				Udm::Object root = *iter;
				std::string kindName = (*iter).type().name();

				// Generate MPC file only for the Component
				if (kindName == "MPC")
				{
					PICML::MPC_Visitor visitor (outputPath);
					SetUpVisitor (MPC, root, visitor);
				}
				else
                {
					showUsage();
					return;
                }
			}

			AfxMessageBox ("MPC files successfully generated");
		}
	 }
      catch(udm_exception &ex)
        {
          AfxMessageBox ("Error: generation of MPC files failed");
		  AfxMessageBox (ex.what());
          return;
        }

/****************************** Demo Code End *************************/
													
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
