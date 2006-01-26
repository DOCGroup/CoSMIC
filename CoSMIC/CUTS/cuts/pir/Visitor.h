#ifndef _CUTS_PIR_VISITOR_H_
#define _CUTS_PIR_VISITOR_H_

#include "cuts/config.h"

namespace CUTS_PIR
{
  // forward declarations
  class Component;
  class Component_Home;
  class Event;
  class Event_Sink;
  class File;
  class Project;
  class Method;
  class Module;

  //===========================================================================
  /**
   *
   */
  //===========================================================================

  class CUTS_Export Visitor
  {
  public:
    /// Destructor.
    virtual ~Visitor (void);

    /// Visit a component.
    virtual void visit_component (const Component & component);

    /// Visit a module.
    virtual void visit_module (const Module & module);

    /// Visit a file.
    virtual void visit_file (const File & file);

    /// Visit a project.
    virtual void visit_project (const Project & project);

    /// Visit a component home.
    virtual void visit_component_home (const Component_Home & home);

    /// Visit a method.
    virtual void visit_method (const Method & method);

    /// Visit an event.
    virtual void visit_event (const Event & event);

    /// Visit an event.
    virtual void visit_event_sink (const Event_Sink & event_sink);

  protected:
    /// Constructor.
    Visitor (void);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Visitor.inl"
#endif

#endif  // !defined _CUTS_PIR_VISITOR_H_
