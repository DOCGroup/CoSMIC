// -*- C++ -*-
// $Id$

#include "RegistryNode.h"
#include "Component.h"
#include "Attribute.h"
#include "Connection.h"

namespace GAME
{
namespace Mga
{

//
// Default_Impl_Factory
//
GAME_INLINE
Default_Impl_Factory::~Default_Impl_Factory (void)
{

}

//
// allocate
//
GAME_INLINE
RegistryNode_Impl * Default_Impl_Factory::allocate (IMgaRegNode * ptr)
{
  return 0 != ptr ? new RegistryNode_Impl (ptr) : 0;
}

//
// allocate
//
GAME_INLINE
Component_Impl * Default_Impl_Factory::allocate (IMgaComponent * ptr)
{
  return 0 != ptr ? new Component_Impl (ptr) : 0;
}

//
// allocate
//
GAME_INLINE
Attribute_Impl * Default_Impl_Factory::allocate (IMgaAttribute * ptr)
{
  return 0 != ptr ? new Attribute_Impl (ptr) : 0;
}

//
// allocate
//
GAME_INLINE
ConnectionPoint_Impl * Default_Impl_Factory::allocate (IMgaConnPoint * ptr)
{
  return 0 != ptr ? new ConnectionPoint_Impl (ptr) : 0;
}

GAME_INLINE
void Default_Impl_Factory::impl_factory (Impl_Factory * impl)
{
  this->impl_ = impl;
}

}
}
