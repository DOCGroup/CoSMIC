#ifndef _CUTS_PIR_COMPONENT_H_
#define _CUTS_PIR_COMPONENT_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"
#include <memory>
#include <set>

namespace CUTS_PIR
{
  //===========================================================================
  /**
   * @class Component
   */
  //===========================================================================

  class CUTS_Export Component :
    public Element,
    public Visitor_Element_T <Visitor, Component, &Visitor::visit_component>
  {
  public:
    /// Type definition for the component event sinks.
    typedef std::set <Event_Sink *> Event_Sinks;

    /// Type definition for the component facets.
    typedef std::set <Facet *> Facets;

    typedef std::set <Worker_Type *> Worker_Types;

    /// Constructor.
    Component (void);

    /// Destructor.
    virtual ~Component (void);

    /// Get the collection of event sinks.
    Event_Sinks & event_sinks (void);

    /// Get the collection of event sinks.
    const Event_Sinks & event_sinks (void) const;

    /// Get the home for the component.
    Component_Home * home (void);

    /// Get the home for the component.
    const Component_Home * home (void) const;

    /// Get the home for the component.
    void home (Component_Home * home);

    /// Get the facets for the component.
    Facets & facets (void);

    /// Get the facets for the component.
    const Facets & facets (void) const;

    Worker_Types & worker_types (void);

    const Worker_Types & worker_types (void) const;

  private:
    /// The home for this component.
    std::auto_ptr <Component_Home> home_;

    /// Set of methods in the component.
    Event_Sinks event_sinks_;

    /// Collection of facets provided by this component.
    Facets facets_;

    Worker_Types worker_types_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Component.inl"
#endif

#endif  // !defined _CUTS_PIR_COMPONENT_H_
