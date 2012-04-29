// $Id$

#include "StdAfx.h"
#include "State.h"

#if !defined (__GAME_INLINE__)
#include "State.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/Transition.h"
#include "PICML/BehaviorParadigmSheets/Terminals/TerminalTransition.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string State_Impl::metaname ("State");

  //
  // _create (const BehaviorModel_in)
  //
  State State_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < State > (parent, State_Impl::metaname);
  }

  //
  // accept
  //
  void State_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_State (this);
    else
      v->visit_Atom (this);
  }

  //
  // src_Transition
  //
  size_t State_Impl::src_Transition (std::vector <Transition> & items) const
  {
    return this->in_connections <Transition> (items);
  }

  //
  // src_TerminalTransition
  //
  size_t State_Impl::src_TerminalTransition (std::vector <TerminalTransition> & items) const
  {
    return this->in_connections <TerminalTransition> (items);
  }
}

