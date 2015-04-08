#include "StdAfx.h"
#include "MultiOutputBase.h"

#if !defined (__GAME_INLINE__)
#include "MultiOutputBase.inl"
#endif

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MultiOutputBase_Impl::metaname ("MultiOutputBase");

  //
  // is_abstract
  //
  const bool MultiOutputBase_Impl::is_abstract = true;
}

