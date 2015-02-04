// $Id$

#include "StdAfx.h"
#include "SimpleType.h"

#if !defined (__GAME_INLINE__)
#include "SimpleType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/DataValue.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string SimpleType_Impl::metaname ("SimpleType");

  //
  // is_abstract
  //
  const bool SimpleType_Impl::is_abstract = true;
}

