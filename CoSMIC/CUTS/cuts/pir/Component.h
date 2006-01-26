#ifndef _CUTS_PIR_COMPONENT_H_
#define _CUTS_PIR_COMPONENT_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"
#include <memory>
#include <set>

namespace CUTS_PIR
{
  // forward declarations
  class Component_Home;
  class Method;

  class CUTS_Export Component :
    public Visitor_Element_T <Visitor, Component, &Visitor::visit_component>,
    public Element
  {
  public:
    typedef std::set <const Event *> Event_Types ;
    typedef std::set <Event_Sink *> Event_Sinks;

    /// Constructor.
    Component (void);

    /// Destructor.
    virtual ~Component (void);

    /// Get the home for the component.
    Component_Home * home (void) const;

    /// Set the home for the component.
    void home (Component_Home * home);

    Event_Sinks & event_sinks (void);

    const Event_Sinks & event_sinks (void) const;

    const Event_Types & in_events_types (void) const;

    Event_Types & in_events_types (void);

  private:
    /// Name of the component factory.
    std::string factory_;

    /// Home for the component.
    std::auto_ptr <Component_Home> home_;

    /// Set of methods in the component.
    Event_Sinks event_sinks_;

    /// Set of event types recieved at this component.
    Event_Types in_events_types_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Component.inl"
#endif

#endif  // !defined _CUTS_PIR_COMPONENT_H_
