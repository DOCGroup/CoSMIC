// $Id$

#include "cuts/events_i.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/events_i.inl"
#endif

namespace OBV_CUTS
{
  //
  // size
  //
  void Payload_Event_i::size (const ::CORBA::Long size)
  {
    // Allocate a payload for the specified size.
    char * temp = ::CORBA::string_alloc (size);
    OBV_CUTS::Payload_Event::payload (temp);

    OBV_CUTS::Payload_Event::size (size);
  }
}
