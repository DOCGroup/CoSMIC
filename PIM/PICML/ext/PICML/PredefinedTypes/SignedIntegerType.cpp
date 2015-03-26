// $Id$

#include "StdAfx.h"
#include "SignedIntegerType.h"

#if !defined (__GAME_INLINE__)
#include "SignedIntegerType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SignedIntegerType_Impl::metaname ("SignedIntegerType");

  //
  // is_abstract
  //
  const bool SignedIntegerType_Impl::is_abstract = true;
}

