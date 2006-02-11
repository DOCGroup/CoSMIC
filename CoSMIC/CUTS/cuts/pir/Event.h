#ifndef _CUTS_PIR_EVENT_H_
#define _CUTS_PIR_EVENT_H_

#include "cuts/pir/Module_Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  class CUTS_Export Event :
    public Module_Element,
    public Visitor_Element_T <Visitor, Event, &Visitor::visit_event>
  {
  public:
    /// Constructor.
    Event (const Module * module = 0);

    /// Destructor.
    virtual ~Event (void);

  private:
    Event (const Event &);
    const Event & operator = (const Event &);
  };
}

#endif  // !defined _CUTS_PIR_EVENT_H_
