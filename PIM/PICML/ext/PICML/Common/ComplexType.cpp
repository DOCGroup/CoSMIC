// $Id$

#include "StdAfx.h"
#include "ComplexType.h"

#if !defined (__GAME_INLINE__)
#include "ComplexType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/ComplexTypeReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ComplexType_Impl::metaname ("ComplexType");

  //
  // is_abstract
  //
  const bool ComplexType_Impl::is_abstract = true;
}

