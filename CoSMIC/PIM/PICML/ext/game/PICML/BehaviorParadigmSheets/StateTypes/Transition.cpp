// $Id$

#include "stdafx.h"
#include "Transition.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Transition_Impl::metaname = "Transition";

  //
  // Transition_Impl
  //
  Transition_Impl::Transition_Impl (void)
  {
  }

  //
  // Transition_Impl
  //
  Transition_Impl::Transition_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Transition_Impl
  //
  Transition_Impl::~Transition_Impl (void)
  {
  }

  //
  // accept
  //
  void Transition_Impl::accept (Visitor * v)
  {
    v->visit_Transition (this);
  }

  //
  // src_State
  //
  State Transition_Impl::src_State (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return State::_narrow (target);
  }

  //
  // dst_ActionBase
  //
  ActionBase Transition_Impl::dst_ActionBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ActionBase::_narrow (target);
  }
}

