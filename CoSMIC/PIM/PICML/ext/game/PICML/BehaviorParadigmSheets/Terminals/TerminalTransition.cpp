// $Id$

#include "StdAfx.h"
#include "TerminalTransition.h"

#if !defined (__GAME_INLINE__)
#include "TerminalTransition.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/State.h"
#include "PICML/BehaviorParadigmSheets/Terminals/Terminal.h"
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
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_TerminalTransition (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

