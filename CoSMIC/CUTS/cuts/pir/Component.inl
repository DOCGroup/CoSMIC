// $Id$

namespace CUTS_PIR
{
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
}
