// $Id$

namespace GAME
{
//
// Event_Sink_Impl
//
GAME_INLINE
Event_Sink_Impl::Event_Sink_Impl (void)
{

}

//
// Event_Sink_Impl
//
GAME_INLINE
Event_Sink_Impl::~Event_Sink_Impl (void)
{

}

//
// handle_global_event
//
GAME_INLINE
int Event_Sink_Impl::
handle_global_event (globalevent_enum global_event)
{
  return 0;
}

//
// handle_object_event
//
GAME_INLINE
int Event_Sink_Impl::
handle_object_event (GAME::Object & obj, unsigned long mask)
{
  return 0;
}

}
