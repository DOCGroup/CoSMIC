// $Id$

#include "stdafx.h"
#include "Worker.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackageBase.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Worker_Impl::metaname = "Worker";

  //
  // Worker_Impl
  //
  Worker_Impl::Worker_Impl (void)
  {
  }

  //
  // Worker_Impl
  //
  Worker_Impl::Worker_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Worker_Impl
  //
  Worker_Impl::~Worker_Impl (void)
  {
  }

  //
  // accept
  //
  void Worker_Impl::accept (Visitor * v)
  {
    v->visit_Worker (this);
  }

  //
  // _create
  //
  Worker Worker_Impl::_create (const WorkerPackageBase_in parent)
  {
    return ::GAME::Mga::create_object <Worker> (parent, Worker_Impl::metaname);
  }

  //
  // Abstract
  //
  void Worker_Impl::Abstract (bool val)
  {
    static const std::string attr_Abstract ("Abstract");
    this->attribute (attr_Abstract)->bool_value (val);
  }

  //
  // Abstract
  //
  bool Worker_Impl::Abstract (void) const
  {
    static const std::string attr_Abstract ("Abstract");
    return this->attribute (attr_Abstract)->bool_value ();
  }

  //
  // get_Operations
  //
  size_t Worker_Impl::get_Operations (std::vector <Operation> & items) const
  {
    return this->children (items);
  }

  //
  // parent_WorkerPackageBase
  //
  WorkerPackageBase Worker_Impl::parent_WorkerPackageBase (void) const
  {
    return ::GAME::Mga::get_parent <WorkerPackageBase> (this->object_.p);
  }
}

