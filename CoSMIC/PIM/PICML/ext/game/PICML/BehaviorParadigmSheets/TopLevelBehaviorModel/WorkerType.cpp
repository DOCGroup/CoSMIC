// $Id$

#include "stdafx.h"
#include "WorkerType.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/WorkloadParadigmSheets/WML/Worker.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerType_Impl::metaname = "WorkerType";

  //
  // WorkerType_Impl
  //
  WorkerType_Impl::WorkerType_Impl (void)
  {
  }

  //
  // WorkerType_Impl
  //
  WorkerType_Impl::WorkerType_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkerType_Impl
  //
  WorkerType_Impl::~WorkerType_Impl (void)
  {
  }

  //
  // accept
  //
  void WorkerType_Impl::accept (Visitor * v)
  {
    v->visit_WorkerType (this);
  }

  //
  // _create
  //
  WorkerType WorkerType_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create_object <WorkerType> (parent, WorkerType_Impl::metaname);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior WorkerType_Impl::parent_TopLevelBehavior (void) const
  {
    return ::GAME::Mga::get_parent <TopLevelBehavior> (this->object_.p);
  }
}

