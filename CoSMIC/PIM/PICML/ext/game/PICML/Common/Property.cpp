// $Id$

#include "stdafx.h"
#include "Property.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Common/RequirementBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Property_Impl::metaname = "Property";

  //
  // Property_Impl
  //
  Property_Impl::Property_Impl (void)
  {
  }

  //
  // Property_Impl
  //
  Property_Impl::Property_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Property_Impl
  //
  Property_Impl::~Property_Impl (void)
  {
  }

  //
  // parent_RequirementBase
  //
  RequirementBase Property_Impl::parent_RequirementBase (void) const
  {
    return ::GAME::Mga::get_parent <RequirementBase> (this->object_.p);
  }
}

