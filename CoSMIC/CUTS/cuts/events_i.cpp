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
    // Allocate a payload for the specified size and fill it with
    // garbage. This will force the middleware to send a dummy event
    // with some sort of payload.
    char * temp = ::CORBA::string_alloc (size);
    this->fill (temp, size);

    // Store the payload, and size in the event.
    OBV_CUTS::Payload_Event::payload (temp);
    OBV_CUTS::Payload_Event::size (size);
  }

  //
  // fill
  //
  void Payload_Event_i::fill (char * buf, size_t size)
  {
    static char fill_char = 'A';
    char * end_of_buf = buf + size;

    // Fill the string with the dummy character.
    while (buf != end_of_buf)
      *buf ++ = fill_char;

    // Set the NULL-terminator.
    *buf = '\0';

    // Set the next fill character.
    fill_char = fill_char == 'Z' ? 'A' : fill_char + 1;
  }
}
