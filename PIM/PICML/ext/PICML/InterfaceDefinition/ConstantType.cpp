#include "StdAfx.h"
#include "ConstantType.h"

#if !defined (__GAME_INLINE__)
#include "ConstantType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Discriminator.h"
#include "PICML/InterfaceDefinition/Constant.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ConstantType_Impl::metaname ("ConstantType");

  //
  // is_abstract
  //
  const bool ConstantType_Impl::is_abstract = true;
}

