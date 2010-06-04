// -*- C++ -*-
// $Id$

namespace GAME
{
namespace utils
{
//
// Icon_Manager
//
GAME_INLINE
Icon_Manager::Icon_Manager (void)
: is_init_ (false)
{

}

//
// ~Icon_Manager
//
GAME_INLINE
Icon_Manager::~Icon_Manager (void)
{

}

//
// init
//
GAME_INLINE
bool Icon_Manager::
init (const GAME::Project & project, 
      const Registrar & r, 
      Registrar::ACCESS_MODE mode)
{
  this->is_init_ = this->refresh (project, r, mode);
  return this->is_init_;
}

//
// is_init
//
GAME_INLINE
bool Icon_Manager::is_init (void) const
{
  return this->is_init_;
}

}
}
