// $Id$

#include "Port_Measurement_Map.h"

#if !defined (__CUTS_INLINE__)
#include "Port_Measurement_Map.inl"
#endif

//
// empty
//
void CUTS_Port_Measurement_Map::empty (void)
{
  hash_map_t::ITERATOR iter = this->hash_map_;

  while (!iter.done ())
  {
    delete iter->item ();
    iter.advance ();
  }

  this->hash_map_.unbind_all ();
}

//
// operator []
//
CUTS_Port_Measurement * CUTS_Port_Measurement_Map::operator [] (size_t id)
{
  // Attempt to locate the port measurement in the map.
  CUTS_Port_Measurement * port = 0;

  if (this->hash_map_.find (id, port) == -1)
  {
    // Since we did not find one, we need to create a new
    // port measurement for the id.
    ACE_NEW_RETURN (port, CUTS_Port_Measurement, 0);

    if (port != 0)
    {
      // Try to add the port measurement to the hash map. If we fail,
      // then we need to delete the allocated memory.
      if (this->hash_map_.bind (id, port) == -1)
      {
        delete port;
        port = 0;
      }
    }
  }

  return port;
}
