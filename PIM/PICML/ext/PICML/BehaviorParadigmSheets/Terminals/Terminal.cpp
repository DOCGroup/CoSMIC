// $Id$

#include "StdAfx.h"
#include "Terminal.h"

#if !defined (__GAME_INLINE__)
#include "Terminal.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/TerminalEffect.h"
#include "PICML/BehaviorParadigmSheets/Terminals/TerminalTransition.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Terminal_Impl::metaname ("Terminal");

  //
  // _create (const BehaviorModel_in)
  //
  Terminal Terminal_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < Terminal > (parent, Terminal_Impl::metaname);
  }

  //
  // accept
  //
  void Terminal_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Terminal (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel Terminal_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // src_TerminalEffect
  //
  size_t Terminal_Impl::src_TerminalEffect (std::vector <TerminalEffect> & items) const
  {
    return this->in_connections <TerminalEffect> (items);
  }

  //
  // dst_TerminalTransition
  //
  size_t Terminal_Impl::dst_TerminalTransition (std::vector <TerminalTransition> & items) const
  {
    return this->in_connections <TerminalTransition> (items);
  }
}

