// $Id$

#include "StdAfx.h"
#include "TerminalTransition.h"

#if !defined (__GAME_INLINE__)
#include "TerminalTransition.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/Terminals/Terminal.h"
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
  const std::string TerminalTransition_Impl::metaname ("TerminalTransition");

  //
  // _create (const BehaviorModel_in)
  //
  TerminalTransition TerminalTransition_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < TerminalTransition > (parent, TerminalTransition_Impl::metaname);
  }

  //
  // accept
  //
  void TerminalTransition_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TerminalTransition (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel TerminalTransition_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // State
  //
  State TerminalTransition_Impl::src_State (void) const
  {
    return State::_narrow (this->src ());
  }

  //
  // Terminal
  //
  Terminal TerminalTransition_Impl::dst_Terminal (void) const
  {
    return Terminal::_narrow (this->dst ());
  }
}
