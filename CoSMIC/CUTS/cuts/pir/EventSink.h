#ifndef _CUTS_PIR_EVENTSINK_H_
#define _CUTS_PIR_EVENTSINK_H_

#include "cuts/pir/Method.h"

namespace CUTS_PIR
{
  class CUTS_Export Event_Sink :
    virtual public Method,
    virtual public Reference_Element,
    public Visitor_Element_T <Visitor, Event_Sink, &Visitor::visit_event_sink>
  {
  public:
    /// Constructor.
    Event_Sink (void);

    /// Destructor.
    virtual ~Event_Sink (void);

    using Visitor_Element_T <
      Visitor, Event_Sink, &Visitor::visit_event_sink>::accept;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/EventSink.inl"
#endif

#endif  // !defined _CUTS_PIR_EVENTSINK_H_
