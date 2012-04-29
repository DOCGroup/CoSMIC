// $Id$

#include "StdAfx.h"
#include "LoopTransition.h"

#if !defined (__GAME_INLINE__)
#include "LoopTransition.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
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
  // _create (const BehaviorModel_in)
  //
  LoopTransition LoopTransition_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < LoopTransition > (parent, LoopTransition_Impl::metaname);
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

