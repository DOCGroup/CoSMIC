// $Id$

#include "StdAfx.h"
#include "WorkerFile.h"

#if !defined (__GAME_INLINE__)
#include "WorkerFile.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackage.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibrary.h"
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
  // is_abstract
  //
  const bool WorkerFile_Impl::is_abstract (0);

  //
  // _create (const WorkerLibrary_in)
  //
  WorkerFile WorkerFile_Impl::_create (const WorkerLibrary_in parent)
  {
    return ::GAME::Mga::create < WorkerFile > (parent, WorkerFile_Impl::metaname);
  }

  //
  // accept
  //
  void WorkerFile_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WorkerFile (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_WorkerLibrary
  //
  WorkerLibrary WorkerFile_Impl::parent_WorkerLibrary (void)
  {
    return WorkerLibrary::_narrow (this->parent ());
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
  ::GAME::Mga::Collection_T <WorkerPackage> WorkerFile_Impl::get_WorkerPackages (void) const
  {
    return this->children <WorkerPackage> ();
  }
}

