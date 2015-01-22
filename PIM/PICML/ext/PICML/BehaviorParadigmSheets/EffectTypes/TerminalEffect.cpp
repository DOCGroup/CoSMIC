// $Id$

#include "StdAfx.h"
#include "TerminalEffect.h"

#if !defined (__GAME_INLINE__)
#include "TerminalEffect.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/Terminals/Terminal.h"
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
  const std::string TerminalEffect_Impl::metaname ("TerminalEffect");

  //
  // accept
  //
  void TerminalEffect_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TerminalEffect (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel TerminalEffect_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // Terminal
  //
  Terminal TerminalEffect_Impl::src_Terminal (void) const
  {
    return Terminal::_narrow (this->src ());
  }

  //
  // StateBase
  //
  StateBase TerminalEffect_Impl::dst_StateBase (void) const
  {
    return StateBase::_narrow (this->dst ());
  }
}

