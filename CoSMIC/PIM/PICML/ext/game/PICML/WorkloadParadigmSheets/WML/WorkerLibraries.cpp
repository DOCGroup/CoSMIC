// $Id$

#include "stdafx.h"
#include "WorkerLibraries.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibrary.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerLibraries_Impl::metaname = "WorkerLibraries";

  //
  // WorkerLibraries_Impl
  //
  WorkerLibraries_Impl::WorkerLibraries_Impl (void)
  {
  }

  //
  // WorkerLibraries_Impl
  //
  WorkerLibraries_Impl::WorkerLibraries_Impl (IMgaFolder * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkerLibraries_Impl
  //
  WorkerLibraries_Impl::~WorkerLibraries_Impl (void)
  {
  }

  //
  // accept
  //
  void WorkerLibraries_Impl::accept (Visitor * v)
  {
    v->visit_WorkerLibraries (this);
  }

  //
  // _create
  //
  WorkerLibraries WorkerLibraries_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <WorkerLibraries> (parent, WorkerLibraries_Impl::metaname);
  }

  ::GAME::Mga::RootFolder WorkerLibraries_Impl::parent_RootFolder (void) const
  {
    return ::GAME::Mga::get_parent < ::GAME::Mga::RootFolder > (this->object_.p);
  }
}

