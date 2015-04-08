#include "StdAfx.h"
#include "EffectBase.h"

#if !defined (__GAME_INLINE__)
#include "EffectBase.inl"
#endif

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string EffectBase_Impl::metaname ("EffectBase");

  //
  // is_abstract
  //
  const bool EffectBase_Impl::is_abstract = true;
}

