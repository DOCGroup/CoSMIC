// $Id$

#include "stdafx.h"
#include "BranchTransition.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchState.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BranchTransition_Impl::metaname = "BranchTransition";

  //
  // BranchTransition_Impl
  //
  BranchTransition_Impl::BranchTransition_Impl (void)
  {
  }

  //
  // BranchTransition_Impl
  //
  BranchTransition_Impl::BranchTransition_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BranchTransition_Impl
  //
  BranchTransition_Impl::~BranchTransition_Impl (void)
  {
  }

  //
  // accept
  //
  void BranchTransition_Impl::accept (Visitor * v)
  {
    v->visit_BranchTransition (this);
  }

  //
  // src_BranchState
  //
  BranchState BranchTransition_Impl::src_BranchState (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return BranchState::_narrow (target);
  }

  //
  // dst_ActionBase
  //
  ActionBase BranchTransition_Impl::dst_ActionBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ActionBase::_narrow (target);
  }

  //
  // Condition
  //
  void BranchTransition_Impl::Condition (const std::string & val)
  {
    static const std::string attr_Condition ("Condition");
    this->attribute (attr_Condition)->string_value (val);
  }

  //
  // Condition
  //
  std::string BranchTransition_Impl::Condition (void) const
  {
    static const std::string attr_Condition ("Condition");
    return this->attribute (attr_Condition)->string_value ();
  }
}

