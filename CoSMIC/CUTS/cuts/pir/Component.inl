// $Id$

namespace CUTS_PIR
{
  //
  // activate_method
  //
  CUTS_INLINE
  void Component::activate_method (const Method * method)
  {
    this->activate_method_.reset (method);
  }

  CUTS_INLINE
  const Method * Component::activate_method (void) const
  {
    return this->activate_method_.get ();
  }

  //
  // home
  //
  CUTS_INLINE
  Component_Home * Component::home (void)
  {
    return this->home_.get ();
  }

  CUTS_INLINE
  const Component_Home * Component::home (void) const
  {
    return this->home_.get ();
  }

  //
  // facets
  //
  CUTS_INLINE
  Component::Worker_Types & Component::worker_types (void)
  {
    return this->worker_types_;
  }

  CUTS_INLINE
  const Component::Worker_Types & Component::worker_types (void) const
  {
    return this->worker_types_;
  }

  //
  // facets
  //
  CUTS_INLINE
  Component::Facets & Component::facets (void)
  {
    return this->facets_;
  }

  CUTS_INLINE
  const Component::Facets & Component::facets (void) const
  {
    return this->facets_;
  }

  //
  // event_sinks
  //
  CUTS_INLINE
  Component::Event_Sinks & Component::event_sinks (void)
  {
    return this->event_sinks_;
  }

  CUTS_INLINE
  const Component::Event_Sinks & Component::event_sinks (void) const
  {
    return this->event_sinks_;
  }

  //
  // event_sources
  //
  CUTS_INLINE
  const Component::Event_Sources & Component::event_sources (void) const
  {
    return this->event_sources_;
  }

  CUTS_INLINE
  Component::Event_Sources & Component::event_sources (void)
  {
    return this->event_sources_;
  }

  //
  // periodic_actions
  //
  CUTS_INLINE
  Component::Periodic_Actions & Component::periodic_actions (void)
  {
    return this->periodic_actions_;
  }

  CUTS_INLINE
  const Component::Periodic_Actions & Component::periodic_actions (void) const
  {
    return this->periodic_actions_;
  }
}
