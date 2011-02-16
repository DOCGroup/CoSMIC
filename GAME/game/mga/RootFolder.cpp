// $Id$

#include "stdafx.h"
#include "RootFolder.h"

#if !defined (__GAME_INLINE__)
#include "RootFolder.inl"
#endif

#include "Visitor.h"

namespace GAME
{
namespace Mga
{

//
// accept
//
void RootFolder_Impl::accept (Visitor * v)
{
  v->visit_RootFolder (this);
}

}
}
