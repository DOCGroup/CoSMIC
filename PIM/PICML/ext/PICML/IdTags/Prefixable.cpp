// $Id$

#include "StdAfx.h"
#include "Prefixable.h"

#if !defined (__GAME_INLINE__)
#include "Prefixable.inl"
#endif

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Prefixable_Impl::metaname ("Prefixable");

  //
  // is_abstract
  //
  const bool Prefixable_Impl::is_abstract = true;
}

