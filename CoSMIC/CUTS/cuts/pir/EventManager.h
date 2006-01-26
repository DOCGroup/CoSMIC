#ifndef _CUTS_PIR_EVENT_MANAGER_H_
#define _CUTS_PIR_EVENT_MANAGER_H_

#include "cuts/config.h"
#include <map>
#include <string>

namespace CUTS_PIR
{
  class Event;

  class CUTS_Export Event_Manager :
    public std::map <std::string, Event *>
  {
  public:
    Event_Manager (void);

    ~Event_Manager (void);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/EventManager.inl"
#endif

#endif  // !defined _CUTS_PIR_EVENT_MANAGER_H_
