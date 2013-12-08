// $Id$

#include "StdAfx.h"
#include "Effect.h"

#if !defined (__GAME_INLINE__)
#include "Effect.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/WhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/DoWhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/ForState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchState.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
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
  const std::string Effect_Impl::metaname ("Effect");

  //
  // _create (const BehaviorModel_in)
  //
  Effect Effect_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < Effect > (parent, Effect_Impl::metaname);
  }

  //
  // accept
  //
  void Effect_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Effect (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel Effect_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // ActionBase
  //
  ActionBase Effect_Impl::src_ActionBase (void) const
  {
    return ActionBase::_narrow (this->src ());
  }

  //
  // StateBase
  //
  StateBase Effect_Impl::dst_StateBase (void) const
  {
    return StateBase::_narrow (this->dst ());
  }
}
