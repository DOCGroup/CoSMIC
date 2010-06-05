// -*- C++ -*-
// $Id$

namespace GAME
{
namespace graphics
{
//
// Image_Resolver
//
GAME_INLINE
Image_Resolver::Image_Resolver (void)
: is_init_ (false)
{

}

//
// ~Image_Resolver
//
GAME_INLINE
Image_Resolver::~Image_Resolver (void)
{

}

//
// init
//
GAME_INLINE
bool Image_Resolver::
init (const GAME::Project & project, 
      const utils::Registrar & r, 
      utils::Registrar::ACCESS_MODE mode)
{
  this->is_init_ = this->refresh (project, r, mode);
  return this->is_init_;
}

//
// is_init
//
GAME_INLINE
bool Image_Resolver::is_init (void) const
{
  return this->is_init_;
}

}
}
