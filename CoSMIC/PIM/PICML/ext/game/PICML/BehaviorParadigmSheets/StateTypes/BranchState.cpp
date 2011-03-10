// $Id$

#include "stdafx.h"
#include "BranchState.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/BranchTransition.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string BranchState_Impl::metaname = "BranchState";

  //
  // BranchState_Impl
  //
  BranchState_Impl::BranchState_Impl (void)
  {
  }

  //
  // BranchState_Impl
  //
  BranchState_Impl::BranchState_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~BranchState_Impl
  //
  BranchState_Impl::~BranchState_Impl (void)
  {
  }

  //
  // accept
  //
  void BranchState_Impl::accept (Visitor * v)
  {
    v->visit_BranchState (this);
  }

  //
  // in_BranchTransition_connections
  //
  size_t BranchState_Impl::in_BranchTransition_connections (std::vector <BranchTransition> & conns) const
  {
    return this->in_connections (conns);
  }
}

