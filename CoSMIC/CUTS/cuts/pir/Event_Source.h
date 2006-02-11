#ifndef _CUTS_PIR_EVENT_SOURCE_H_
#define _CUTS_PIR_EVENT_SOURCE_H_

#include "cuts/pir/Port.h"

namespace CUTS_PIR
{
  class CUTS_Export Event_Source :
    public Port
  {
  public:
    Event_Source (void);
    virtual ~Event_Source (void);

  private:
    Event_Source (const Event_Source &);
    const Event_Source & operator = (const Event_Source &);
  };
}

#endif  // !defined _CUTS_PIR_EVENT_SOURCE_H_
