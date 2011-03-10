// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

//
// Reference_Impl
//
GAME_INLINE
Reference_Impl::Reference_Impl (void)
{

}

//
// Reference_Impl
//
GAME_INLINE
Reference_Impl::Reference_Impl (IMgaReference * ref)
//: FCO_Impl (ref)
{
  this->object_ = ref;
}

//
// ~Reference_Impl
//
GAME_INLINE
Reference_Impl::~Reference_Impl (void)
{

}

}
}
