// $Id$

#include "stdafx.h"
#include "BehaviorInputAction.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/EffectTypes/InputEffect.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Finish.h"
#include "PICML/Common/Property.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BehaviorInputAction_Impl::metaname = "BehaviorInputAction";

  //
  // BehaviorInputAction_Impl
  //
  BehaviorInputAction_Impl::BehaviorInputAction_Impl (void)
  {
  }

  //
  // BehaviorInputAction_Impl
  //
  BehaviorInputAction_Impl::BehaviorInputAction_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BehaviorInputAction_Impl
  //
  BehaviorInputAction_Impl::~BehaviorInputAction_Impl (void)
  {
  }

  //
  // in_InputEffect_connections
  //
  size_t BehaviorInputAction_Impl::in_InputEffect_connections (std::vector <InputEffect> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_Finish_connections
  //
  size_t BehaviorInputAction_Impl::in_Finish_connections (std::vector <Finish> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // get_Propertys
  //
  size_t BehaviorInputAction_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }
}

