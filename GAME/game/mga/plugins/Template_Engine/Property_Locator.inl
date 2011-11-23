// -*- C++ -*-
// $Id$

//
// ~Property_Locator
//
GAME_INLINE
Property_Locator::~Property_Locator (void)
{

}

//
// reset
//
GAME_INLINE
void Property_Locator::reset (void)
{
  this->names_.clear ();
  this->attrs_.clear ();
}

//
// names
//
GAME_INLINE
std::set <GAME::Mga::Object> & Property_Locator::names (void)
{
  return this->names_;
}

//
// attributes
//
GAME_INLINE
std::vector <GAME::Mga::Attribute> & Property_Locator::attributes (void)
{
  return this->attrs_;
}
