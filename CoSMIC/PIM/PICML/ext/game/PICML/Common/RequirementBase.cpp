// $Id$

#include "stdafx.h"
#include "RequirementBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string RequirementBase_Impl::metaname = "RequirementBase";

  //
  // RequirementBase_Impl
  //
  RequirementBase_Impl::RequirementBase_Impl (void)
  {
  }

  //
  // RequirementBase_Impl
  //
  RequirementBase_Impl::RequirementBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~RequirementBase_Impl
  //
  RequirementBase_Impl::~RequirementBase_Impl (void)
  {
  }

  //
  // get_Propertys
  //
  size_t RequirementBase_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }
}

