#include "StdAfx.h"
#include "CharType.h"

#if !defined (__GAME_INLINE__)
#include "CharType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string CharType_Impl::metaname ("CharType");

  //
  // is_abstract
  //
  const bool CharType_Impl::is_abstract = true;
}

