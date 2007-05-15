// $Id$

#include "Port_Measurement_Map.h"

#if !defined (__CUTS_INLINE__)
#include "Port_Measurement_Map.inl"
#endif

#include "ace/CORBA_macros.h"

//
// CUTS_Port_Measurement_Map
//
CUTS_Port_Measurement_Map::CUTS_Port_Measurement_Map (void)
{

}

//
// empty
//
void CUTS_Port_Measurement_Map::empty (void)
{
  hash_map_t::ITERATOR iter (this->hash_map_);

  for (; !iter.done (); iter ++)
    delete iter->item ();

  this->hash_map_.unbind_all ();
}

//
// find
//
int CUTS_Port_Measurement_Map::
find (size_t id, CUTS_Port_Measurement * & measure)
{
  // Attempt to locate the port measurement in the map.
  if (this->hash_map_.find (id, measure) == 0)
    return 0;

  // Since we did not find one, we need to create a new
  // port measurement for the id.
  ACE_NEW_RETURN (measure, CUTS_Port_Measurement, -1);
  ACE_Auto_Ptr <CUTS_Port_Measurement> auto_clean (measure);

  if (this->hash_map_.bind (id, measure) != 0)
    return -1;

  auto_clean.release ();
  return this->template_.prepare (*measure);
}

//
// reset
//
void CUTS_Port_Measurement_Map::reset (void)
{
  hash_map_t::ITERATOR iter (this->hash_map_);

  for (; !iter.done (); iter ++)
    iter->item ()->reset ();
}
