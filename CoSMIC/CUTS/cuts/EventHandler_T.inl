// $Id$

//=============================================================================
/*
 * CUTS_Event_Handler_Base_T
 */
//=============================================================================

//
// bind
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::
bind (const char * name,
      Component_Type * component,
      Event_Method method)
{
  this->port_agent_.name (name);
  this->component_ = component;
  this->method_ = method;
}

//
// unbind
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::unbind (void)
{
  this->port_agent_.name ("unknown");
  this->component_ = 0;
  this->method_ = 0;
}

//
// port_agent
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
CUTS_Port_Agent &
CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::port_agent (void)
{
  return this->port_agent_;
}

//
// activate
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::activate (void)
{
  this->active_ = true;
  this->port_agent_.activate ();
}

//
// deactivate
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::deactivate (void)
{
  this->active_ = false;
  this->port_agent_.deactivate ();
}

//
// is_active
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
bool CUTS_Event_Handler_Base_T <COMPONENT, EVENTTYPE>::is_active (void) const
{
  return this->active_;
}

//=============================================================================
/*
 * CUTS_Event_Handler_T
 */
//=============================================================================

//
// activate
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::activate (void)
{
  this->impl_->activate ();
}

//
// deactivate
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::deactivate (void)
{
  this->impl_->deactivate ();
}

//
// handle_event
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::handle_event (EVENTTYPE * ev)
{
  this->impl_->handle_event (ev);
}

//
// port_agent
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
CUTS_Port_Agent & CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::port_agent (void)
{
  return this->impl_->port_agent ();
}

//
// bind
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::bind (
  const char * name,
  Component_Type * component,
  Event_Method method)
{
  this->impl_->bind (name, component, method);
}

//
// unbind
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::unbind (void)
{
  this->impl_->unbind ();
}

//
// mode
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
CUTS_Event_Handler::Event_Mode
CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::mode (void) const
{
  return this->mode_;
}

//
// priority
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
int CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::priority (void) const
{
  return this->impl_->priority ();
}

//
// priority
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::priority (int prio)
{
  this->impl_->priority (prio);
}

//
// thread_count
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE size_t
CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::thread_count (void) const
{
  return this->impl_->thread_count ();
}

//
// thread_count
//
template <typename COMPONENT, typename EVENTTYPE>
CUTS_INLINE void
CUTS_Event_Handler_T <COMPONENT, EVENTTYPE>::thread_count (size_t count)
{
  this->impl_->thread_count (count);
}
