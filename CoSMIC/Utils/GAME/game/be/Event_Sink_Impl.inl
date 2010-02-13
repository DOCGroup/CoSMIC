// $Id$

namespace GME
{
//
// Event_Sink_Impl
//
GME_INLINE
Event_Sink_Impl::Event_Sink_Impl (void)
{

}

//
// Event_Sink_Impl
//
GME_INLINE
Event_Sink_Impl::~Event_Sink_Impl (void)
{

}

//
// handle_global_event
//
GME_INLINE
int Event_Sink_Impl::
handle_global_event (globalevent_enum global_event)
{
  return 0;
}

//
// handle_object_event
//
GME_INLINE
int Event_Sink_Impl::
handle_object_event (GME::Object & obj, unsigned long mask)
{
  return 0;
}

}
