#include "StdAfx.h"
#include "IntegerType.h"

#if !defined (__GAME_INLINE__)
#include "IntegerType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string IntegerType_Impl::metaname ("IntegerType");

  //
  // is_abstract
  //
  const bool IntegerType_Impl::is_abstract = true;
}

