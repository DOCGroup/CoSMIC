#ifndef _CUTS_BE_CIAO_VISITOR_H_
#define _CUTS_BE_CIAO_VISITOR_H_

#include "cuts/pir/Visitor.h"
#include <fstream>

namespace CUTS_CIAO
{
  //===========================================================================
  /**
   *
   */
  //===========================================================================

  class CUTS_Export Project_Visitor :
    public CUTS_PIR::Visitor
  {
  public:
    /// Constructor.
    Project_Visitor (const char * outdir);

    /// Destructor.
    virtual ~Project_Visitor (void);

    /// Visit a project.
    void visit_project (const CUTS_PIR::Project & project);

  private:
    /// Output directory for the project.
    std::string outdir_;
  };

  //===========================================================================
  /**
   *
   */
  //===========================================================================

  class File_Visitor :
    public CUTS_PIR::Visitor
  {
  public:
    /// Constructor.
    File_Visitor (const char * outdir);

    /// Destructor.
    virtual ~File_Visitor (void);

    /// Visit a file.
    void visit_file (const CUTS_PIR::File & file);

    /// Visit a module.
    void visit_module (const CUTS_PIR::Module & module);

    /// Visit a component.
    void visit_component (const CUTS_PIR::Component & component);

    /// Visit a component home.
    void visit_component_home (const CUTS_PIR::Component_Home & home);

    /// Visit an event sink.
    void visit_event_sink (const CUTS_PIR::Event_Sink & event_sink);

  private:
    /// Visit the contents of a module.
    void visit_module_contents (const CUTS_PIR::Module & module);

    void write_constructor (const CUTS_PIR::Component & component);

    void write_destructor (const CUTS_PIR::Component & component);

    void write_set_session_context (const CUTS_PIR::Component & component);

    void write_ciao_preactivate (const CUTS_PIR::Component & component);

    void write_ccm_passivate (const CUTS_PIR::Component & component);

    void write_member_variables (const CUTS_PIR::Component & component);

    /// Output directory for the project.
    std::string outdir_;

    /// Header file output stream.
    std::ofstream hofs_;

    /// Source file output stream.
    std::ofstream sofs_;

    /// Name of the current component.
    std::string component_;

    /// Name of the component factory.
    std::string factory_;
  };
}

#endif  // !defined _CUTS_BE_CIAO_VISITOR_H_
