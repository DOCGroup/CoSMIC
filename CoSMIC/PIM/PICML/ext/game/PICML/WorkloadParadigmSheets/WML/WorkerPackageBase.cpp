// $Id$

#include "stdafx.h"
#include "WorkerPackageBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/WorkloadParadigmSheets/WML/Worker.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerPackageBase_Impl::metaname = "WorkerPackageBase";

  //
  // WorkerPackageBase_Impl
  //
  WorkerPackageBase_Impl::WorkerPackageBase_Impl (void)
  {
  }

  //
  // WorkerPackageBase_Impl
  //
  WorkerPackageBase_Impl::WorkerPackageBase_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkerPackageBase_Impl
  //
  WorkerPackageBase_Impl::~WorkerPackageBase_Impl (void)
  {
  }

  //
  // get_Workers
  //
  size_t WorkerPackageBase_Impl::get_Workers (std::vector <Worker> & items) const
  {
    return this->children (items);
  }
}

