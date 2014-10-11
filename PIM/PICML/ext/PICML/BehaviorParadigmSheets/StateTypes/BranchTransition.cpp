// $Id$

#include "StdAfx.h"
#include "BranchTransition.h"

#if !defined (__GAME_INLINE__)
#include "BranchTransition.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchState.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/CallAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/RequestAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/OutputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Action.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string BranchTransition_Impl::metaname ("BranchTransition");

  //
  // _create (const BehaviorModel_in)
  //
  BranchTransition BranchTransition_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < BranchTransition > (parent, BranchTransition_Impl::metaname);
  }

  //
  // accept
  //
  void BranchTransition_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_BranchTransition (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel BranchTransition_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // BranchState
  //
  BranchState BranchTransition_Impl::src_BranchState (void) const
  {
    return BranchState::_narrow (this->src ());
  }

  //
  // ActionBase
  //
  ActionBase BranchTransition_Impl::dst_ActionBase (void) const
  {
    return ActionBase::_narrow (this->dst ());
  }
}

