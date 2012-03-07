// $Id$

#include "StdAfx.h"
#include "WorkerFile.h"

#if !defined (__GAME_INLINE__)
#include "WorkerFile.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibrary.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackage.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackageBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerFile_Impl::metaname ("WorkerFile");

  //
  // _create (const WorkerLibrary_in)
  //
  WorkerFile WorkerFile_Impl::_create (const WorkerLibrary_in parent)
  {
    return ::GAME::Mga::create_object < WorkerFile > (parent, WorkerFile_Impl::metaname);
  }

  //
  // _create (const WorkerPackageBase_in)
  //
  WorkerFile WorkerFile_Impl::_create (const WorkerPackageBase_in parent)
  {
    return ::GAME::Mga::create_object < WorkerFile > (parent, WorkerFile_Impl::metaname);
  }

  //
  // accept
  //
  void WorkerFile_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_WorkerFile (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // get_WorkerPackages
  //
  size_t WorkerFile_Impl::get_WorkerPackages (std::vector <WorkerPackage> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkerPackages
  //
  ::GAME::Mga::Iterator <WorkerPackage> WorkerFile_Impl::get_WorkerPackages (void) const
  {
    return this->children <WorkerPackage> ();
  }
}

