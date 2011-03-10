// $Id$

#include "stdafx.h"
#include "BehaviorModel.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/BehaviorModel/Variable.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BehaviorModel_Impl::metaname = "BehaviorModel";

  //
  // BehaviorModel_Impl
  //
  BehaviorModel_Impl::BehaviorModel_Impl (void)
  {
  }

  //
  // BehaviorModel_Impl
  //
  BehaviorModel_Impl::BehaviorModel_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BehaviorModel_Impl
  //
  BehaviorModel_Impl::~BehaviorModel_Impl (void)
  {
  }

  //
  // get_Variables
  //
  size_t BehaviorModel_Impl::get_Variables (std::vector <Variable> & items) const
  {
    return this->children (items);
  }
}

