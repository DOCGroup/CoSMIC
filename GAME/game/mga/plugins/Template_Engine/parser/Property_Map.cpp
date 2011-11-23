// $Id$

#include "stdafx.h"
#include "Property_Map.h"

#if !defined (__GAME_INLINE__)
#include "Property_Map.inl"
#endif

//
// Property_Map
//
Property_Map::Property_Map (const Property_Map & copy)
: map_ (copy.size ())
{
  for (map_type::CONST_ITERATOR iter (copy.map ()); !iter.done (); ++ iter)
    this->map_.bind (iter->key (), iter->item ());
}

//
// join
//
size_t Property_Map::
join (const Property_Map & map, bool overwrite)
{
  int retval;
  size_t count = 0;
  const_iterator iter (map.map ());

  for ( ; !iter.done (); ++ iter)
  {
    // Insert the item into the map.
    if (overwrite)
      retval = this->map_.rebind (iter->key (), iter->item ());
    else
      retval = this->map_.bind (iter->key (), iter->item ());

    if (retval == 0 || (overwrite && retval != -1))
      ++ count;
  }

  return count;
}

//
// operator []
//
std::string & Property_Map::operator [] (const std::string & key)
{
  std::string value ("");
  map_type::ENTRY * entry = 0;

  // Try to locate the item in the map. If it is, then we override
  // the empty string value. Otherwise, we insert the key into the
  // map with the empty value.
  this->map_.trybind (key, value, entry);

  // Return the value to the client.
  return entry->item ();
}
