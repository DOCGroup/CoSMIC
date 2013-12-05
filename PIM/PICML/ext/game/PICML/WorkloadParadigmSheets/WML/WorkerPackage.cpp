// $Id$

#include "StdAfx.h"
#include "WorkerPackage.h"

#if !defined (__GAME_INLINE__)
#include "WorkerPackage.inl"
#endif

#include "PICML/Visitor.h"
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
  const std::string WorkerPackage_Impl::metaname ("WorkerPackage");

  //
  // _create (const WorkerPackage_in)
  //
  WorkerPackage WorkerPackage_Impl::_create (const WorkerPackage_in parent)
  {
    return ::GAME::Mga::create_object < WorkerPackage > (parent, WorkerPackage_Impl::metaname);
  }

  //
  // _create (const WorkerFile_in)
  //
  WorkerPackage WorkerPackage_Impl::_create (const WorkerFile_in parent)
  {
    return ::GAME::Mga::create_object < WorkerPackage > (parent, WorkerPackage_Impl::metaname);
  }

  //
  // accept
  //
  void WorkerPackage_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WorkerPackage (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_WorkerPackage
  //
  WorkerPackage WorkerPackage_Impl::parent_WorkerPackage (void)
  {
    return WorkerPackage::_narrow (this->parent ());
  }

  //
  // parent_WorkerFile
  //
  WorkerFile WorkerPackage_Impl::parent_WorkerFile (void)
  {
    return WorkerFile::_narrow (this->parent ());
  }

  //
  // get_WorkerPackages
  //
  size_t WorkerPackage_Impl::get_WorkerPackages (std::vector <WorkerPackage> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkerPackages
  //
  ::GAME::Mga::Iterator <WorkerPackage> WorkerPackage_Impl::get_WorkerPackages (void) const
  {
    return this->children <WorkerPackage> ();
  }
}

