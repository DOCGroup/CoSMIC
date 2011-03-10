// $Id$

#include "stdafx.h"
#include "State.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/Transition.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string State_Impl::metaname = "State";

  //
  // State_Impl
  //
  State_Impl::State_Impl (void)
  {
  }

  //
  // State_Impl
  //
  State_Impl::State_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~State_Impl
  //
  State_Impl::~State_Impl (void)
  {
  }

  //
  // accept
  //
  void State_Impl::accept (Visitor * v)
  {
    v->visit_State (this);
  }

  //
  // in_Transition_connections
  //
  size_t State_Impl::in_Transition_connections (std::vector <Transition> & conns) const
  {
    return this->in_connections (conns);
  }
}

