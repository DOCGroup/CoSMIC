// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Impl_Factory
//
GAME_INLINE
Impl_Factory::Impl_Factory (void)
{

}

//
// ~Impl_Factory
//
GAME_INLINE
Impl_Factory::~Impl_Factory (void)
{

}

//
// Default_Impl_Factory
//
GAME_INLINE
Default_Impl_Factory::~Default_Impl_Factory (void)
{

}

GAME_INLINE
void Default_Impl_Factory::impl_factory (Impl_Factory * impl)
{
  this->impl_ = impl;
}

}
}
