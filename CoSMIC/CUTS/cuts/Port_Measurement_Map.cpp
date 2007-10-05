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
find (size_t id, CUTS_Port_Measurement * & measure, bool auto_create)
{
  // Attempt to locate the port measurement in the map.
  if (this->hash_map_.find (id, measure) == 0)
    return 0;

  if (auto_create)
  {
    // Since we did not find one, we need to create a new
    // port measurement for the id.
    CUTS_Port_Measurement * temp = 0;
    ACE_NEW_RETURN (temp, CUTS_Port_Measurement, -1);
    ACE_Auto_Ptr <CUTS_Port_Measurement> auto_clean (temp);

    if (this->hash_map_.bind (id, temp) != 0)
    {
      ACE_ERROR ((LM_ERROR,
                  "*** error (CUTS_Port_Measurement_Map): failed to "
                  "store the port measurement for %u\n",
                  id));
      return -1;
    }

    measure = auto_clean.release ();
    return this->template_.prepare (*measure);
  }

  return -1;
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
