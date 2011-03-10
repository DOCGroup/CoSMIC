// $Id$

#include "stdafx.h"
#include "WorkerPackage.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerFile.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerPackage_Impl::metaname = "WorkerPackage";

  //
  // WorkerPackage_Impl
  //
  WorkerPackage_Impl::WorkerPackage_Impl (void)
  {
  }

  //
  // WorkerPackage_Impl
  //
  WorkerPackage_Impl::WorkerPackage_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkerPackage_Impl
  //
  WorkerPackage_Impl::~WorkerPackage_Impl (void)
  {
  }

  //
  // accept
  //
  void WorkerPackage_Impl::accept (Visitor * v)
  {
    v->visit_WorkerPackage (this);
  }

  //
  // _create
  //
  WorkerPackage WorkerPackage_Impl::_create (const WorkerFile_in parent)
  {
    return ::GAME::Mga::create_object <WorkerPackage> (parent, WorkerPackage_Impl::metaname);
  }

  //
  // _create
  //
  WorkerPackage WorkerPackage_Impl::_create (const WorkerPackage_in parent)
  {
    return ::GAME::Mga::create_object <WorkerPackage> (parent, WorkerPackage_Impl::metaname);
  }

  //
  // get_WorkerPackages
  //
  size_t WorkerPackage_Impl::get_WorkerPackages (std::vector <WorkerPackage> & items) const
  {
    return this->children (items);
  }

  //
  // parent_WorkerFile
  //
  WorkerFile WorkerPackage_Impl::parent_WorkerFile (void) const
  {
    return ::GAME::Mga::get_parent <WorkerFile> (this->object_.p);
  }
}

