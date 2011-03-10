// $Id$

#include "stdafx.h"
#include "LoopTransition.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string LoopTransition_Impl::metaname = "LoopTransition";

  //
  // LoopTransition_Impl
  //
  LoopTransition_Impl::LoopTransition_Impl (void)
  {
  }

  //
  // LoopTransition_Impl
  //
  LoopTransition_Impl::LoopTransition_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~LoopTransition_Impl
  //
  LoopTransition_Impl::~LoopTransition_Impl (void)
  {
  }

  //
  // accept
  //
  void LoopTransition_Impl::accept (Visitor * v)
  {
    v->visit_LoopTransition (this);
  }

  //
  // src_LoopState
  //
  LoopState LoopTransition_Impl::src_LoopState (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return LoopState::_narrow (target);
  }

  //
  // dst_ActionBase
  //
  ActionBase LoopTransition_Impl::dst_ActionBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ActionBase::_narrow (target);
  }
}

