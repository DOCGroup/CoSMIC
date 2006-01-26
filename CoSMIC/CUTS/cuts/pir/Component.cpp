#include "cuts/pir/Component.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/pir/Component.inl"
#endif

#include "cuts/pir/ComponentHome.h"
#include "cuts/pir/EventSink.h"

namespace CUTS_PIR
{
  Component::Component (void)
  {

  }

  Component::~Component (void)
  {
    for ( Event_Sinks::iterator iter = this->event_sinks_.begin ();
          iter != this->event_sinks_.end ();
          iter ++)
    {
      delete *iter;
    }
  }
}
