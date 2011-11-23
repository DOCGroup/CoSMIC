// $Id$

#include <iostream>

//
// Property_Map
//
GAME_INLINE
Property_Map::Property_Map (void)
{

}

//
// ~Property_Map
//
GAME_INLINE
Property_Map::~Property_Map (void)
{

}

//
// get
//
GAME_INLINE
int Property_Map::
get (const std::string & key, std::string & value) const
{
  return this->map_.find (key, value);
}

//
// set
//
GAME_INLINE
int Property_Map::
set (const std::string & key, const std::string & value)
{
  return this->map_.rebind (key, value);
}

//
// set
//
GAME_INLINE
int Property_Map::
set (const std::pair <std::string, std::string> & entry)
{
  return this->set (entry.first, entry.second);
}

//
// size
//
GAME_INLINE
size_t Property_Map::size (void) const
{
  return this->map_.current_size ();
}

//
// contains
//
GAME_INLINE
bool Property_Map::contains (const std::string & name) const
{
  return this->map_.find (name) == 0;
}

//
// begin
//
GAME_INLINE
Property_Map::iterator Property_Map::begin (void)
{
  return this->map_.begin ();
}

//
// begin
//
GAME_INLINE
Property_Map::const_iterator Property_Map::begin (void) const
{
  return this->map_.begin ();
}

//
// end
//
GAME_INLINE
Property_Map::iterator Property_Map::end (void)
{
  return this->map_.end ();
}

//
// end
//
GAME_INLINE
Property_Map::const_iterator Property_Map::end (void) const
{
  return this->map_.end ();
}

//
// map
//
GAME_INLINE
const Property_Map::map_type & Property_Map::map (void) const
{
  return this->map_;
}

//
// map
//
GAME_INLINE
void Property_Map::clear (void)
{
  this->map_.unbind_all ();
}

//
// map
//
GAME_INLINE
bool Property_Map::empty (void) const
{
  return this->map_.current_size () == 0;
}
