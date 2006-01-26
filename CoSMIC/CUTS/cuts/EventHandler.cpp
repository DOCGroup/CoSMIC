// $Id$

#include "cuts/EventHandler.h"

#if !defined (__CUTS_INLINE__)
# include "cuts/EventHandler.inl"
#endif

#include "cuts/Counter.h"

//=============================================================================
/*
 * CUTS_Single_Event_Handler
 */
//=============================================================================

//
// CUTS_Single_Event_Handler
//
CUTS_Single_Event_Handler::CUTS_Single_Event_Handler (void)
{

}

//
// ~CUTS_Single_Event_Handler
//
CUTS_Single_Event_Handler::~CUTS_Single_Event_Handler (void)
{

}

//
// handle_event
//
void CUTS_Single_Event_Handler::handle_event (void)
{
  for ( CUTS_Counter_Set::iterator iter = this->counter_.begin ();
        iter != this->counter_.end ();
        iter ++)
  {
    (*iter)->increment ();
  }
}
