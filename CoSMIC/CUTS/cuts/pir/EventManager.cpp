#include "cuts/pir/EventManager.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/EventManager.inl"
#endif

#include "cuts/pir/Event.h"

namespace CUTS_PIR
{
  Event_Manager::Event_Manager (void)
  {

  }

  Event_Manager::~Event_Manager (void)
  {
    for (iterator iter = begin (); iter != end (); iter ++)
    {
      delete iter->second;
    }
  }
}
