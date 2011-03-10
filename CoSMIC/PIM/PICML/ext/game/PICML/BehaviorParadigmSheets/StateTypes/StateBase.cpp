// $Id$

#include "stdafx.h"
#include "StateBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string StateBase_Impl::metaname = "StateBase";

  //
  // StateBase_Impl
  //
  StateBase_Impl::StateBase_Impl (void)
  {
  }

  //
  // StateBase_Impl
  //
  StateBase_Impl::StateBase_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~StateBase_Impl
  //
  StateBase_Impl::~StateBase_Impl (void)
  {
  }
}

