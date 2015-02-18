// $Id$

#include "StdAfx.h"
#include "PredefinedType.h"

#if !defined (__GAME_INLINE__)
#include "PredefinedType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/Variable.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PredefinedType_Impl::metaname ("PredefinedType");

  //
  // is_abstract
  //
  const bool PredefinedType_Impl::is_abstract = true;

  //
  // parent_PredefinedTypes
  //
  PredefinedTypes PredefinedType_Impl::parent_PredefinedTypes (void)
  {
    return PredefinedTypes::_narrow (this->parent ());
  }
}

