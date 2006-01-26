// $Id$

//=============================================================================
/*
 * CUTS_Single_Event_Handler
 */
//=============================================================================

//
// register_counter
//
CUTS_INLINE
bool CUTS_Single_Event_Handler::register_counter (CUTS_Bounded_Counter * counter)
{
  return this->counter_.insert (counter).second;
}

//
// unregister_counter
//
CUTS_INLINE
void CUTS_Single_Event_Handler::unregister_counter (CUTS_Bounded_Counter * counter)
{
  this->counter_.erase (counter);
}
