// $Id$

template <typename COMPONENT>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT>::bind (CUTS_Port_Agent * agent,
                                             Event_Method method)
{
  this->port_agent_ = agent;
  this->method_ = method;
}

template <typename COMPONENT>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT>::unbind (void)
{
  this->port_agent_ = 0;
  this->method_ = 0;
}

template <typename COMPONENT>
CUTS_INLINE
void CUTS_Event_Handler_T <COMPONENT>::handle_event (long dispatch_time)
{
  if (this->active_)
  {
    this->event_queue_.enqueue (new long (dispatch_time));
  }
}
