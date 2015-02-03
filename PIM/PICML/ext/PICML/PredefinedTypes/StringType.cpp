// $Id$

#include "StdAfx.h"
#include "StringType.h"

#if !defined (__GAME_INLINE__)
#include "StringType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string StringType_Impl::metaname ("StringType");

  //
  // is_abstract
  //
  const bool StringType_Impl::is_abstract (1);
}

