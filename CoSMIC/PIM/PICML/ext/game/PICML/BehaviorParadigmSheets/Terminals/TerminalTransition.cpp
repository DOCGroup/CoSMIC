// $Id$

#include "stdafx.h"
#include "TerminalTransition.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/Terminals/Terminal.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TerminalTransition_Impl::metaname = "TerminalTransition";

  //
  // TerminalTransition_Impl
  //
  TerminalTransition_Impl::TerminalTransition_Impl (void)
  {
  }

  //
  // TerminalTransition_Impl
  //
  TerminalTransition_Impl::TerminalTransition_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TerminalTransition_Impl
  //
  TerminalTransition_Impl::~TerminalTransition_Impl (void)
  {
  }

  //
  // accept
  //
  void TerminalTransition_Impl::accept (Visitor * v)
  {
    v->visit_TerminalTransition (this);
  }

  //
  // src_State
  //
  State TerminalTransition_Impl::src_State (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return State::_narrow (target);
  }

  //
  // dst_Terminal
  //
  Terminal TerminalTransition_Impl::dst_Terminal (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Terminal::_narrow (target);
  }
}

