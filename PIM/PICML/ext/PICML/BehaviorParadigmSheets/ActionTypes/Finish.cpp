// $Id$

#include "StdAfx.h"
#include "Finish.h"

#if !defined (__GAME_INLINE__)
#include "Finish.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/MultiInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/InputAction.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/WhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/DoWhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/ForState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchState.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Finish_Impl::metaname ("Finish");

  //
  // _create (const BehaviorModel_in, StateBase_in src, BehaviorInputAction_in dst)
  //
  Finish Finish_Impl::_create (const BehaviorModel_in parent, StateBase_in src, BehaviorInputAction_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, Finish_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void Finish_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Finish (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel Finish_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // StateBase
  //
  StateBase Finish_Impl::src_StateBase (void) const
  {
    return StateBase::_narrow (this->src ());
  }

  //
  // BehaviorInputAction
  //
  BehaviorInputAction Finish_Impl::dst_BehaviorInputAction (void) const
  {
    return BehaviorInputAction::_narrow (this->dst ());
  }
}

