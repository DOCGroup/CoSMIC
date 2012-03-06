// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// Impl_Factory

//
// Impl_Factory
//
GAME_INLINE
Impl_Factory::Impl_Factory (void)
: next_ (0)
{

}

//
// ~Impl_Factory
//
GAME_INLINE
Impl_Factory::~Impl_Factory (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// Impl_Factory_Base

GAME_INLINE
Impl_Factory_Base::Impl_Factory_Base (void)
{

}

//
// Impl_Factory_Base
//
GAME_INLINE
Impl_Factory_Base::~Impl_Factory_Base (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// Default_Impl_Factory

//
// Default_Impl_Factory
//
GAME_INLINE
Default_Impl_Factory::~Default_Impl_Factory (void)
{

}

///////////////////////////////////////////////////////////////////////////////
// Impl_Factory_Manager

//
// Impl_Factory_Manager
//
GAME_INLINE
Impl_Factory_Manager::Impl_Factory_Manager (void)
{
  this->set_next (&this->default_impl_);
}

//
// Impl_Factory_Manager
//
GAME_INLINE
Impl_Factory_Manager::~Impl_Factory_Manager (void)
{

}

}
}
