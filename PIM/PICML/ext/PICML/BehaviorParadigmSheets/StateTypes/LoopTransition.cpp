// $Id$

#include "StdAfx.h"
#include "LoopTransition.h"

#if !defined (__GAME_INLINE__)
#include "LoopTransition.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/WhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/DoWhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/ForState.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
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
  const std::string LoopTransition_Impl::metaname ("LoopTransition");

  //
  // is_abstract
  //
  const bool LoopTransition_Impl::is_abstract (0);

  //
  // _create (const BehaviorModel_in, LoopState_in src, ActionBase_in dst)
  //
  LoopTransition LoopTransition_Impl::_create (const BehaviorModel_in parent, LoopState_in src, ActionBase_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, LoopTransition_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void LoopTransition_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LoopTransition (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel LoopTransition_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // LoopState
  //
  LoopState LoopTransition_Impl::src_LoopState (void) const
  {
    return LoopState::_narrow (this->src ());
  }

  //
  // ActionBase
  //
  ActionBase LoopTransition_Impl::dst_ActionBase (void) const
  {
    return ActionBase::_narrow (this->dst ());
  }
}

