#ifndef _CUTS_PIR_EVENTSINK_H_
#define _CUTS_PIR_EVENTSINK_H_

#include "cuts/pir/Method.h"

namespace CUTS_PIR
{
  class CUTS_Export Event_Sink :
    public Method,
    public Visitor_Element_T <Visitor, Event_Sink, &Visitor::visit_event_sink>
  {
  public:
    /// Constructor.
    Event_Sink (Event * event_type);

    /// Destructor.
    virtual ~Event_Sink (void);

    /// Get the event type.
    Event * event_type (void) const;

    using Visitor_Element_T <
      Visitor, Event_Sink, &Visitor::visit_event_sink>::accept;

  private:
    /// Type of event receieved at sink.
    Event * event_type_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/EventSink.inl"
#endif

#endif  // !defined _CUTS_PIR_EVENTSINK_H_
