// $Id$

#include "StdAfx.h"
#include "BON2Component.h"

#include "cuts/fe/PICML/CUTS_PICMLVisitor.h"
#include "cuts/pir/Project.h"
#include "cuts/be/CIAO/CIAO_Visitor.h"

#include <fstream>
#include <strstream>

namespace BON
{

//###############################################################################################################################################
//
//   C L A S S : BON::Component
//
//###############################################################################################################################################

Component::Component ()
  : m_bIsInteractive (false)
{

}

Component::~Component ()
{
  if ( m_project )
  {
    m_project->finalizeObjects();
    finalize (m_project);
    m_project = NULL;
  }
}

// ====================================================
// This method is called after all the generic initialization is done
// This should be empty unless application-specific initialization is needed

void Component::initialize( Project& project )
{

}

// ====================================================
// This method is called before the whole BON2 project released and disposed
// This should be empty unless application-specific finalization is needed

void Component::finalize( Project& project )
{
  CUTS_PIR::Project::close ();
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

void Component::invokeEx (Project& project,
                          FCO& currentFCO,
                          const std::set<FCO>& setSelectedFCOs,
                          long lParam)
{
  // Get the output directory for the project.

  // Get the root folder for the project.
  BON::Folder root = project->getRootFolder ();

  // Visit all the child folders of the root folder.
  typedef std::set <BON::Folder> Folder_Set;
  Folder_Set folders = root->getChildFolders ();

  if (folders.size () > 0)
  {
    // Create the implementation visitor.
    PICML_BON::CUTS_PICMLVisitor visitor;

    for ( Folder_Set::iterator iter = folders.begin ();
          iter != folders.end ();
          iter ++)
    {
      visitor.visitFolder (*iter);
    }

    // Create a CIAO visitor for the CUTS_PIR and visit the project.
    std::auto_ptr <CUTS_CIAO::Project_Visitor> project_visitor (
      new CUTS_CIAO::Project_Visitor ("C:\\TEMP"));

    CUTS_PIR::Project::instance ()->name (project->getName ().c_str ());
    CUTS_PIR::Project::instance ()->accept (project_visitor.get ());
  }

  // Print a status message to the user.
  AfxMessageBox ("Successfully generated CoWorkEr implementation");
}

// ====================================================
// GME currently does not use this function
// You only need to implement it if other invokation mechanisms are used

void Component::objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam )
{
  if ( m_bIsInteractive )
    AfxMessageBox("This BON2 Component does not support objectInvokeEx method!");
}

//
// getParameter
//
Util::Variant Component::getParameter (const std::string& strName)
{
  return Util::Variant();
}

//
// setParameter
//
void Component::setParameter (const std::string & strName,
                              const Util::Variant& varValue)
{

}

}; // namespace BON

