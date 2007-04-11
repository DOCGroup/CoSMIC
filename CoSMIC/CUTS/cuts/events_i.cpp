// $Id$

#include "cuts/events_i.h"

#if !defined (__CUTS_INLINE__)
#include "cuts/events_i.inl"
#endif

namespace CUTS
{
  //
  // size
  //
  CUTS_INLINE
  void Payload_Event_i::size (const ::CORBA::Long size)
  {
    // Set the payload size.
    OBV_CUTS::Payload_Event::size (size);

    // Allocate a payload for the specified size.
    char * temp = ::CORBA::string_alloc (size - sizeof (::CORBA::ULong));
    OBV_CUTS::Payload_Event::payload (temp);
  }
}
