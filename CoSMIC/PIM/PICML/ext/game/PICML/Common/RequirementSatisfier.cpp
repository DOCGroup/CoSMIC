// $Id$

#include "stdafx.h"
#include "RequirementSatisfier.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Common/SatisfierProperty.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequirementSatisfier_Impl::metaname = "RequirementSatisfier";

  //
  // RequirementSatisfier_Impl
  //
  RequirementSatisfier_Impl::RequirementSatisfier_Impl (void)
  {
  }

  //
  // RequirementSatisfier_Impl
  //
  RequirementSatisfier_Impl::RequirementSatisfier_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequirementSatisfier_Impl
  //
  RequirementSatisfier_Impl::~RequirementSatisfier_Impl (void)
  {
  }

  //
  // get_SatisfierPropertys
  //
  size_t RequirementSatisfier_Impl::get_SatisfierPropertys (std::vector <SatisfierProperty> & items) const
  {
    return this->children (items);
  }
}

