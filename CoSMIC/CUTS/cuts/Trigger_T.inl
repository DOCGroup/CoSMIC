// $Id$

//=============================================================================
/*
 * CUTS_Trigger_T
 */
//=============================================================================

//
// signal
//
template <typename COMPONENT>
CUTS_INLINE
void CUTS_Trigger_T <COMPONENT>::signal (void) const
{
  this->reactor ()->notify (this, ACE_Event_Handler::TIMER_MASK);
}

//
// handle_timeout
//
template <typename COMPONENT>
CUTS_INLINE
int CUTS_Trigger_T <COMPONENT>::handle_timeout (const ACE_Time_Value &current_time,
                                                const void * act)
{
  (this->component_->*this->method_) ();
  return 0;
}

//
// is_active
//
template <typename COMPONENT>
CUTS_INLINE
bool CUTS_Trigger_T <COMPONENT>::is_active (void) const
{
  return this->active_;
}

//=============================================================================
/*
 * CUTS_Periodic_Trigger_T
 */
//=============================================================================

//
// probability
//
template <typename COMPONENT>
CUTS_INLINE
double CUTS_Periodic_Trigger_T <COMPONENT>::probability (void) const
{
  return this->probability_;
}

//
// timeout
//
template <typename COMPONENT>
CUTS_INLINE
long CUTS_Periodic_Trigger_T <COMPONENT>::timeout (void) const
{
  return this->timeout_;
}
