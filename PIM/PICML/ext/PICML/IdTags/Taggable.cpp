// $Id$

#include "StdAfx.h"
#include "Taggable.h"

#if !defined (__GAME_INLINE__)
#include "Taggable.inl"
#endif

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Taggable_Impl::metaname ("Taggable");

  //
  // is_abstract
  //
  const bool Taggable_Impl::is_abstract (1);
}

