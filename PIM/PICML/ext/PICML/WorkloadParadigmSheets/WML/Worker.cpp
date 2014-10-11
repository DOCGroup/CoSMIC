// $Id$

#include "StdAfx.h"
#include "Worker.h"

#if !defined (__GAME_INLINE__)
#include "Worker.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/WorkerType.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackageBase.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackage.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerFile.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Worker_Impl::metaname ("Worker");

  //
  // _create (const WorkerPackageBase_in)
  //
  Worker Worker_Impl::_create (const WorkerPackageBase_in parent)
  {
    return ::GAME::Mga::create_object < Worker > (parent, Worker_Impl::metaname);
  }

  //
  // accept
  //
  void Worker_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Worker (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_WorkerPackageBase
  //
  WorkerPackageBase Worker_Impl::parent_WorkerPackageBase (void)
  {
    return WorkerPackageBase::_narrow (this->parent ());
  }

  //
  // get_Operations
  //
  size_t Worker_Impl::get_Operations (std::vector <Operation> & items) const
  {
    return this->children (items);
  }

  //
  // get_Operations
  //
  ::GAME::Mga::Collection_T <Operation> Worker_Impl::get_Operations (void) const
  {
    return this->children <Operation> ();
  }
}

