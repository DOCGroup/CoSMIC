// $Id$

#include "StdAfx.h"
#include "Transition.h"

#if !defined (__GAME_INLINE__)
#include "Transition.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/OutputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/CallAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/Action.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/RequestAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/QueryAction.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Transition_Impl::metaname ("Transition");

  //
  // _create (const BehaviorModel_in)
  //
  Transition Transition_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < Transition > (parent, Transition_Impl::metaname);
  }

  //
  // accept
  //
  void Transition_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Transition (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel Transition_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // State
  //
  State Transition_Impl::src_State (void) const
  {
    return State::_narrow (this->src ());
  }

  //
  // ActionBase
  //
  ActionBase Transition_Impl::dst_ActionBase (void) const
  {
    return ActionBase::_narrow (this->dst ());
  }
}

