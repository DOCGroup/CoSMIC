// $Id$

#include "stdafx.h"
#include "Terminal.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/EffectTypes/TerminalEffect.h"
#include "PICML/BehaviorParadigmSheets/Terminals/TerminalTransition.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Terminal_Impl::metaname = "Terminal";

  //
  // Terminal_Impl
  //
  Terminal_Impl::Terminal_Impl (void)
  {
  }

  //
  // Terminal_Impl
  //
  Terminal_Impl::Terminal_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Terminal_Impl
  //
  Terminal_Impl::~Terminal_Impl (void)
  {
  }

  //
  // accept
  //
  void Terminal_Impl::accept (Visitor * v)
  {
    v->visit_Terminal (this);
  }

  //
  // in_TerminalEffect_connections
  //
  size_t Terminal_Impl::in_TerminalEffect_connections (std::vector <TerminalEffect> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_TerminalTransition_connections
  //
  size_t Terminal_Impl::in_TerminalTransition_connections (std::vector <TerminalTransition> & conns) const
  {
    return this->in_connections (conns);
  }
}

