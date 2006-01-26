// $Id$

namespace CUTS_PIR
{
  //
  // home
  //
  CUTS_INLINE
  Component_Home * Component::home (void) const
  {
    return this->home_.get ();
  }

  CUTS_INLINE
  void Component::home (Component_Home * home)
  {
    this->home_.reset (home);
  }

  //
  // event_sinks_
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
  // in_event_types
  //
  CUTS_INLINE
  Component::Event_Types & Component::in_events_types (void)
  {
    return this->in_events_types_;
  }

  CUTS_INLINE
  const Component::Event_Types & Component::in_events_types (void) const
  {
    return this->in_events_types_;
  }
}
