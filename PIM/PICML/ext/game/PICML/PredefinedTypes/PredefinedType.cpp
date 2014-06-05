// $Id$

#include "StdAfx.h"
#include "PredefinedType.h"

#if !defined (__GAME_INLINE__)
#include "PredefinedType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/Variable.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PredefinedType_Impl::metaname ("PredefinedType");

  //
  // parent_PredefinedTypes
  //
  PredefinedTypes PredefinedType_Impl::parent_PredefinedTypes (void)
  {
    return PredefinedTypes::_narrow (this->parent ());
  }
}

