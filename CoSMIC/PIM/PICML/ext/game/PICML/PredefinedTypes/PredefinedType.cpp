// $Id$

#include "stdafx.h"
#include "PredefinedType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/PredefinedTypes/PredefinedTypes.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PredefinedType_Impl::metaname = "PredefinedType";

  //
  // PredefinedType_Impl
  //
  PredefinedType_Impl::PredefinedType_Impl (void)
  {
  }

  //
  // PredefinedType_Impl
  //
  PredefinedType_Impl::PredefinedType_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PredefinedType_Impl
  //
  PredefinedType_Impl::~PredefinedType_Impl (void)
  {
  }

  //
  // parent_PredefinedTypes
  //
  PredefinedTypes PredefinedType_Impl::parent_PredefinedTypes (void) const
  {
    return ::GAME::Mga::get_parent <PredefinedTypes> (this->object_.p);
  }
}

