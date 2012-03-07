// $Id$

#include "StdAfx.h"
#include "WorkerPackage.h"

#if !defined (__GAME_INLINE__)
#include "WorkerPackage.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerFile.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackageBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerPackage_Impl::metaname ("WorkerPackage");

  //
  // _create (const WorkerFile_in)
  //
  WorkerPackage WorkerPackage_Impl::_create (const WorkerFile_in parent)
  {
    return ::GAME::Mga::create_object < WorkerPackage > (parent, WorkerPackage_Impl::metaname);
  }

  //
  // _create (const WorkerPackageBase_in)
  //
  WorkerPackage WorkerPackage_Impl::_create (const WorkerPackageBase_in parent)
  {
    return ::GAME::Mga::create_object < WorkerPackage > (parent, WorkerPackage_Impl::metaname);
  }

  //
  // accept
  //
  void WorkerPackage_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_WorkerPackage (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }
}

