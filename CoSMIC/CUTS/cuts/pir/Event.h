#ifndef _CUTS_PIR_EVENT_H_
#define _CUTS_PIR_EVENT_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  class CUTS_Export Event :
    public Module_Element,
    public Visitor_Element_T <Visitor, Event, &Visitor::visit_event>
  {
  public:
    Event (Module * module = 0);

    virtual ~Event (void);
  };
}

#endif  // !defined _CUTS_PIR_EVENT_H_
