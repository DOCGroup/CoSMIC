// $Id$

#include "stdafx.h"
#include "ApplicationTask.h"

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
  const std::string ApplicationTask_Impl::metaname = "ApplicationTask";

  //
  // ApplicationTask_Impl
  //
  ApplicationTask_Impl::ApplicationTask_Impl (void)
  {
  }

  //
  // ApplicationTask_Impl
  //
  ApplicationTask_Impl::ApplicationTask_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ApplicationTask_Impl
  //
  ApplicationTask_Impl::~ApplicationTask_Impl (void)
  {
  }

  //
  // accept
  //
  void ApplicationTask_Impl::accept (Visitor * v)
  {
    v->visit_ApplicationTask (this);
  }
}

