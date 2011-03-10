// $Id$

#include "stdafx.h"
#include "TerminalEffect.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string TerminalEffect_Impl::metaname = "TerminalEffect";

  //
  // TerminalEffect_Impl
  //
  TerminalEffect_Impl::TerminalEffect_Impl (void)
  {
  }

  //
  // TerminalEffect_Impl
  //
  TerminalEffect_Impl::TerminalEffect_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~TerminalEffect_Impl
  //
  TerminalEffect_Impl::~TerminalEffect_Impl (void)
  {
  }

  //
  // accept
  //
  void TerminalEffect_Impl::accept (Visitor * v)
  {
    v->visit_TerminalEffect (this);
  }
}

