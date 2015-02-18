// $Id$

#include "StdAfx.h"
#include "InputEffect.h"

#if !defined (__GAME_INLINE__)
#include "InputEffect.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/LoopState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/WhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/DoWhileState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/ForState.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchState.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/MultiInputAction.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/InputAction.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InputEffect_Impl::metaname ("InputEffect");

  //
  // is_abstract
  //
  const bool InputEffect_Impl::is_abstract = false;

  //
  // accept
  //
  void InputEffect_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InputEffect (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel InputEffect_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // BehaviorInputAction
  //
  BehaviorInputAction InputEffect_Impl::src_BehaviorInputAction (void) const
  {
    return BehaviorInputAction::_narrow (this->src ());
  }

  //
  // StateBase
  //
  StateBase InputEffect_Impl::dst_StateBase (void) const
  {
    return StateBase::_narrow (this->dst ());
  }
}

