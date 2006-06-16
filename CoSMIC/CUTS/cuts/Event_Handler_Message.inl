// $Id: Event_Handler_Message.inl,v 1.1.2.1 2006/03/29 14:54:36 hillj Exp $

CUTS_INLINE
long CUTS_Event_Handler_Message::sender (void) const
{
  return this->sender_;
}

CUTS_INLINE
const ACE_Time_Value & CUTS_Event_Handler_Message::dispatch_time (void) const
{
  return this->dispatch_time_;
}

CUTS_INLINE
const ACE_Time_Value & CUTS_Event_Handler_Message::creation_time (void) const
{
  return this->creation_time_;
}

