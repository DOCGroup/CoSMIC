// $Id$

#include "stdafx.h"
#include "Environment.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Environment_Impl::metaname = "Environment";

  //
  // Environment_Impl
  //
  Environment_Impl::Environment_Impl (void)
  {
  }

  //
  // Environment_Impl
  //
  Environment_Impl::Environment_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Environment_Impl
  //
  Environment_Impl::~Environment_Impl (void)
  {
  }

  //
  // accept
  //
  void Environment_Impl::accept (Visitor * v)
  {
    v->visit_Environment (this);
  }
}

