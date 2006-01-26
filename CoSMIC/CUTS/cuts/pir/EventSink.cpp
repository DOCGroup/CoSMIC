#include "cuts/pir/EventSink.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/EventSink.inl"
#endif

namespace CUTS_PIR
{
  Event_Sink::Event_Sink (Event * event_type)
    : event_type_ (event_type)
  {

  }

  Event_Sink::~Event_Sink (void)
  {

  }
}
