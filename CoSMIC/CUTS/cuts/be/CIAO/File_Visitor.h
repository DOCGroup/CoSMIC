#ifndef _CUTS_BE_CIAO_FILE_VISITOR_H_
#define _CUTS_BE_CIAO_FILE_VISITOR_H_

#include "cuts/pir/Visitor.h"
#include <fstream>
#include <set>

namespace CUTS_CIAO
{
  //===========================================================================
  /**
   * @class File_Visitor
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

    /// Visit a facet.
    void visit_facet (const CUTS_PIR::Facet & facet);

    void visit_worker_type (const CUTS_PIR::Worker_Type & type);

  private:
    /// Visit the contents of a module.
    void visit_module_contents (const CUTS_PIR::Module & module);

    /// Write the constructor.
    void write_constructor (const CUTS_PIR::Component & component);

    /// Write the destructor.
    void write_destructor (const CUTS_PIR::Component & component);

    /// Write the set_session_context method.
    void write_set_session_context (const CUTS_PIR::Component & component);

    /// Write the ciao_preactivate method.
    void write_ciao_preactivate (const CUTS_PIR::Component & component);

    /// Write the ccm_passivate method.
    void write_ccm_passivate (const CUTS_PIR::Component & component);

    /// Write the member variables.
    void write_member_variables (const CUTS_PIR::Component & component);

    /// Output directory for the project.
    std::string outdir_;

    /// Header file output stream.
    std::ofstream hofs_;

    /// Source file output stream.
    std::ofstream sofs_;

    /// Name of the current component.
    std::string component_;

    /// Type definition for the type of events.
    typedef std::set <CUTS_PIR::Event *> Event_Types;

    /// Collection of event types received by a component.
    std::set <CUTS_PIR::Event *> event_types_;
  };
}

#endif  // !defined _CUTS_CIAO_BE_FILE_VISITOR_H_
