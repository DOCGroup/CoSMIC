// $Id$

#include "StdAfx.h"
#include "BON2Component.h"

#include "PICML/Utils.h"
#include "cuts/fe/PICML/CUTS_PICMLVisitor.h"
#include "cuts/pir/Project.h"
#include "cuts/be/CIAO/Project_Visitor.h"

#include <fstream>
#include <strstream>

namespace BON
{
  //===========================================================================
  /*
   * class Component
   */
  //===========================================================================

  //
  // Component
  //
  Component::Component ()
    : m_bIsInteractive (false)
  {

  }

  //
  // ~Component
  //
  Component::~Component ()
  {
    if ( m_project )
    {
      m_project->finalizeObjects();
      finalize (m_project);
      m_project = NULL;
    }
  }

  //
  // initialized
  //
  void Component::initialize( Project& project )
  {
    CUTS_PIR::Project::instance ()->name (project->getName ());
  }

  //
  // finalize
  //
  void Component::finalize( Project& project )
  {
    CUTS_PIR::Project::close ();
  }

  //
  // invoke
  //
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

  //
  // invokeEx
  //
  void Component::invokeEx (Project& project,
                            FCO& currentFCO,
                            const std::set<FCO>& setSelectedFCOs,
                            long lParam)
  {
    // Get the output directory for the project.
    std::string output_directory;
    if (PICML::getPath ("Select output directory for generated CoWorkErs",
                        output_directory))
    {
      // Create the implementation visitor.
      PICML_BON::CUTS_PICMLVisitor visitor;
      visitor.visitProject (project);

      // Create a CIAO visitor for the CUTS_PIR and visit the project.
      std::auto_ptr <CUTS_CIAO::Project_Visitor> project_visitor (
        new CUTS_CIAO::Project_Visitor (output_directory.c_str ()));

      CUTS_PIR::Project::instance ()->accept (project_visitor.get ());

      // Print a status message to the user.
      AfxMessageBox ("Successfully generated CoWorkEr implementation");
    }
  }


  //
  // objectInvokeEx
  //
  void Component::objectInvokeEx( Project& project, Object& currentObject, const std::set<Object>& setSelectedObjects, long lParam )
  {

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
}
