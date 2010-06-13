// $Id$

namespace GAME
{
//
// Event_Handler_Impl
//
GAME_INLINE
Event_Handler_Impl::Event_Handler_Impl (void)
{

}

//
// Event_Handler_Impl
//
GAME_INLINE
Event_Handler_Impl::Event_Handler_Impl (long mask)
: current_mask_ (mask)
{

}

//
// ~Event_Handler_Impl
//
GAME_INLINE
Event_Handler_Impl::~Event_Handler_Impl (void)
{

}

//
// initialize
//
GAME_INLINE
int Event_Handler_Impl::initialize (GAME::Project & project)
{
  return 0;
}

//
// handle_global_event
//
GAME_INLINE
int Event_Handler_Impl::
handle_global_event (long global_event)
{
  return 0;
}

//
// handle_object_event
//
GAME_INLINE
int Event_Handler_Impl::
handle_object_event (GAME::Object & obj, unsigned long mask)
{
  return 0;
}

//
// event_mask
//
GAME_INLINE
long Event_Handler_Impl::event_mask (void) const
{
  return this->current_mask_;
}

}
