#ifndef _CUTS_PIR_VISITOR_H_
#define _CUTS_PIR_VISITOR_H_

#include "cuts/config.h"

namespace CUTS_PIR
{
  // forward declarations
  class Action_Property;
  class Component;
  class Component_Home;
  class Event;
  class Event_Sink;
  class Event_Source;
  class Facet;
  class File;
  class Periodic_Action;
  class Project;
  class Method;
  class Module;
  class Object;
  class Output_Action;
  class Worker_Type;
  class Worker_Action;

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

    /// Visit an object.
    virtual void visit_object (const Object & object);

    /// Visit a facet.
    virtual void visit_facet (const Facet & facet);

    virtual void visit_worker_type (const Worker_Type & type);

    virtual void visit_worker_action (const Worker_Action & action);

    virtual void visit_action_property (const Action_Property & prop);

    virtual void visit_output_action (const Output_Action & action);

    virtual void visit_periodic_action (const Periodic_Action & action);

  protected:
    /// Constructor.
    Visitor (void);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Visitor.inl"
#endif

#endif  // !defined _CUTS_PIR_VISITOR_H_
