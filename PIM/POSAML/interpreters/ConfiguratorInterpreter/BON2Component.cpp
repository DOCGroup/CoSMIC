//###############################################################################################################################################
//
//	Meta and Builder Object Network V2.0 for GME
//	BON2Component.cpp
//
//###############################################################################################################################################

/*
	Copyright (c) Vanderbilt University, 2000-2004
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

#include <stdafx.h>
#include "BON2Component.h"

namespace BON
{

//###############################################################################################################################################
//
// 	C L A S S : BON::Component
//
//###############################################################################################################################################

Component::Component()
	: m_bIsInteractive( false )
{
}

Component::~Component()
{
	if ( m_project ) {
		m_project->finalizeObjects();
		finalize( m_project );
		m_project = NULL;
	}
}

// ====================================================
// This method is called after all the generic initialization is done
// This should be empty unless application-specific initialization is needed

void Component::initialize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This method is called before the whole BON2 project released and disposed
// This should be empty unless application-specific finalization is needed

void Component::finalize( Project& project )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// This is the obsolete component interface
// This present implementation either tries to call InvokeEx, or does nothing except of a notification

void Component::invoke( Project& project, const std::set<FCO>& setModels, long lParam )
{
	#ifdef SUPPORT_OLD_INVOKE
		Object focus;
		invokeEx( project, focus, setModels, lParam );
	#else
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support the obsolete invoke mechanism!");
	#endif
}

// ====================================================
// This is the main component method for Interpereters and Plugins.
// May also be used in case of invokeable Add-Ons

void Component::invokeEx( Project& project, FCO& currentFCO, const std::set<FCO>& setSelectedFCOs, long lParam )
{
#ifdef GME_ADDON
	project->setAutoCommit( false);
#endif
	// ======================
	// Insert application specific code here

 
    BON::Folder root = project->getRootFolder( ); // Get the root folder
 
    if ( !root )
    {
        AfxMessageBox("Could not find RootFolder" );
        return;
    }
     
    process_model(project);
    return;
    
}

// This method prompts a dialog to allow the user to specify a folder
BOOL Component::setPath (const std::string& description)
  {
    // Initalize the com library
    HRESULT hr = ::CoInitialize(NULL);
    if (FAILED(hr))
      return false;

    // Dialog instruction
    char display_buffer[MAX_PATH];
    BROWSEINFO folder_browsinfo;
    memset (&folder_browsinfo, 0, sizeof (folder_browsinfo));

    // Set GME as the owner of the dialog
    folder_browsinfo.hwndOwner = GetForegroundWindow();
    // Start the browse from desktop
    folder_browsinfo.pidlRoot = NULL;
    // Pointer to the folder name display buffer
    folder_browsinfo.pszDisplayName = &display_buffer[0];
    // Dialog instruction string
    folder_browsinfo.lpszTitle = description.c_str();
    // Use new GUI style and allow edit plus file view
    folder_browsinfo.ulFlags = BIF_RETURNONLYFSDIRS|BIF_USENEWUI;
    // No callback function
    folder_browsinfo.lpfn = NULL;
    // No parameter passing into the dialog
    folder_browsinfo.lParam = 0;


    LPITEMIDLIST folder_pidl = SHBrowseForFolder(&folder_browsinfo);

    if(folder_pidl == NULL)
      return false;
    else
      {
        TCHAR FolderNameBuffer[MAX_PATH];

        // Convert the selection into a path
        if (SHGetPathFromIDList (folder_pidl, FolderNameBuffer))
          outputPath_ = FolderNameBuffer;

        // Free the ItemIDList object returned from the call to
        // SHBrowseForFolder using Gawp utility function
        IMalloc * imalloc = 0;
        if ( SUCCEEDED( SHGetMalloc ( &imalloc )) )
          {
            imalloc->Free ( folder_pidl );
            imalloc->Release ( );
          }
      }
      save_file();
    ::CoUninitialize();
    return true;
  }

BOOL
Component::save_file()
{
	OPENFILENAME ofn;

	char szFile[MAX_PATH];
	strcpy(szFile, file_name_.c_str());

	// Initialize the OPENFILENAME structure
	ZeroMemory(&ofn, sizeof(ofn));
	ofn.lStructSize = sizeof(ofn);
	ofn.hwndOwner = 0;
    ofn.lpstrFile = szFile;
	ofn.lpstrTitle = "Save - Feature Options";

	ofn.nMaxFile = MAX_PATH;
	ofn.lpstrFilter = "All\0*.*\0"; // "All\0*.*\0Text\0*.txt\0";
	ofn.nFilterIndex = 1;
	ofn.lpstrFileTitle = NULL;
	ofn.nMaxFileTitle = 0;
	ofn.Flags = OFN_PATHMUSTEXIST;

	// GetSaveFileName() system call shows up the save file dialog
	BOOL result;
	if (result = GetSaveFileName(&ofn))
		file_name_ = szFile;
	
	return result;
}


void Component::process_features(MON::Aspect & aspect, BON::Model &model, Project& project)
{

   
    std::string server_strategy_factory = "static Server_Strategy_Factory \"";
    std::string client_strategy_factory = "static Client_Strategy_Factory \"";
    std::string advanced_resource_factory = "static Advanced_Resource_Factory \"";
    std::string url_link = "benchmark_test ";

    bool server = false;
    bool client = false;
    bool advanced = false;
    bool end_point = false;

    std::set<BON::Atom> childrenFeatureSet = model->getChildAtoms(aspect);
                     
    if(childrenFeatureSet.size() == 0)
    {
        project->consoleMsg("No features available",MSG_WARNING);
        //AfxMessageBox("No features available");
        return ;
    }

    for (std::set<BON::Atom>::iterator iterFCO = childrenFeatureSet.begin();
    iterFCO != childrenFeatureSet.end();
    ++iterFCO)
    {
        BON::Atom iterObj(*iterFCO);
        if(!iterObj)
        {
            project->consoleMsg("Object does not exist",MSG_WARNING);
            //AfxMessageBox ("Object does not exist");
            return;
        }
        std::string kind_name = iterObj->getName();

        if(kind_name == "Concurrency")
        {
            std::set<BON::FCO> Reactor_Concurrency_Connection = model->getChildFCOsAs("Reactor_Concurrency_Connection");
            if(Reactor_Concurrency_Connection.size() == 0)
            {
                project->consoleMsg("Reactor Concurrency Connection does not exist",MSG_WARNING);
                //AfxMessageBox ("Reactor Concurrency Connection does not exist");
                return;
            }
            std::string val = iterObj->getAttribute("Concurrency_Options")->getStringValue();
            if(!val.empty())
            {
                server_strategy_factory +="-ORBConcurrency "+ val ;
                server = true;
            }
        }
 
        else if(kind_name == "Reactor_Type")
        {
            std::set<BON::FCO> Reactor_Type_Connection = model->getChildFCOsAs("Reactor_Type_Connection");
            if(Reactor_Type_Connection.size() == 0)
            {
                project->consoleMsg("Reactor and Reactor_Type Connection does not exist",MSG_WARNING);
                //AfxMessageBox ("Reactor and Reactor_Type Connection does not exist");
                return ;
            }
            std::string val = iterObj->getAttribute("Reactor_Type_Options")->getStringValue();
            if(!val.empty())
            {
                advanced_resource_factory +=" -ORBReactorType "+ val ;
                advanced = true;
            }

        }
        else if(kind_name == "Thread_Queue")
        {
            std::set<BON::FCO> Reactor_Thread_Queue_Connection = model->getChildFCOsAs("Reactor_Thread_Queue_Connection");
            if(Reactor_Thread_Queue_Connection.size() == 0)
            {
                project->consoleMsg("Reactor and Thread_Queue Connection does not exist",MSG_WARNING);
               // AfxMessageBox ("Reactor Thread_Queue Connection does not exist");
                return;
            }
            std::string val = iterObj->getAttribute("Thread_Queue_Options")->getStringValue();
            if(!val.empty())
            {
                advanced_resource_factory += " -ORBReactorThreadQueue "+ val ;
                advanced = true;
            }

        }
        else if(kind_name == "End_Points")
        {
            std::set<BON::FCO> End_Point_Connection = model->getChildFCOsAs("End_Point_Connection");
            if(End_Point_Connection.size() == 0)
            {
                project->consoleMsg("Acceptor and End_Point Connection does not exist",MSG_WARNING);
                //AfxMessageBox ("Acceptor End_Point Connection does not exist");
                return;
            }
            std::map<std::string,std::string> protocol_list;
            protocol_list["TCP"] = "iiop";
            protocol_list["UDP"] = "uiop";
            protocol_list["Shared_Memory"] = "shmiop";

            std::string port = iterObj->getAttribute("Port")->getStringValue();
            std::string hostname = iterObj->getAttribute("HostName")->getStringValue();
            std::string protocol = iterObj->getAttribute("Protocol")->getStringValue();
                                 
            std::string str_protocol = protocol_list[protocol];
         
         
            if(port == "0")
            {
                project->consoleMsg("Enter valid port number",MSG_WARNING);
                //AfxMessageBox ("Enter proper port number");
                return;
            }

            url_link += "-ORBEndpoint "+str_protocol+"://"+hostname+":"+port;
         
            end_point = true;
      
        }
                             
    }
    std::ofstream svc_file;
    file_name_ =  "svc.conf";
    save_file();
    svc_file.open (file_name_.c_str ());

    if(advanced)
    {
        svc_file << advanced_resource_factory;
        svc_file << "\"\n";
    }
    if(server)
    {
        svc_file << server_strategy_factory;
        svc_file << "\"\n";
    }
 
    if(client)
    {
        svc_file << client_strategy_factory;
        svc_file << "\"\n";
    }
    svc_file.close ();
    AfxMessageBox("Generated configuration file ");
    //if(end_point)
    //{
        std::ofstream script_file;
        std::string file_name = "benchmark_test.bat";
        script_file.open (file_name.c_str());
        script_file << url_link;
        script_file.close();
        AfxMessageBox("Generated Benchmark test script file");
    //}
 }

BOOL Component::process_model(Project& project)
{

    BON::Folder root = project->getRootFolder( ); // Get the root folder
    std::set<BON::Model> myModelSet = root->getChildModels();

    int len = myModelSet.size();
    if(len < 0)
    {
       project->consoleMsg("Could not get any Models",MSG_INFO);
       return false;
    }
 
    for (std::set<BON::Model>::iterator iter = myModelSet.begin();
			iter != myModelSet.end();
			++iter)
    {

        BON::Model model = (*iter);
            

        std::string modelName = model->getObjectMeta().name();
     
   
        if(modelName == "Middleware")
        {
        
            MON::Project myMetaModel = project->getProjectMeta();
            std::set<MON::Aspect> myAspects = myMetaModel.aspects();

            for (std::set<MON::Aspect>::iterator iterAspect = myAspects.begin();
	            iterAspect != myAspects.end();
	            ++iterAspect)
            {
                MON::Aspect aspect = (*iterAspect);
                std::string aspectName = aspect.name();
                if(aspectName == "Feature")
                {
                    process_features(aspect,model,project);
                    break;
                }
            }
        }
    
    }
    return true;
}


// ====================================================
// GME currently does not use this function
// You only need to implement it if other invokation mechanisms are used

void Component::objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam )
	{
		if ( m_bIsInteractive )
			AfxMessageBox("This BON2 Component does not support objectInvokeEx method!");
	}

// ====================================================
// Implement application specific parameter-mechanism in these functions

Util::Variant Component::getParameter( const std::string& strName )
{
	// ======================
	// Insert application specific code here

	return Util::Variant();
}

void Component::setParameter( const std::string& strName, const Util::Variant& varValue )
{
	// ======================
	// Insert application specific code here
}

#ifdef GME_ADDON

// ====================================================
// If the component is an Add-On, then this method is called for every Global Event

void Component::globalEventPerformed( globalevent_enum event )
{
	// ======================
	// Insert application specific code here
}

// ====================================================
// If the component is an Add-On, then this method is called for every Object Event

void Component::objectEventPerformed( Object& object, unsigned long event, VARIANT v )
{
	// ======================
	// Insert application specific code here
}

#endif // GME_ADDON

}; // namespace BON

