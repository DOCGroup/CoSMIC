// $Id$

#include "StdAfx.h"
#include "WorkerLibraries.h"

#if !defined (__GAME_INLINE__)
#include "WorkerLibraries.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibrary.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerLibraries_Impl::metaname ("WorkerLibraries");

  //
  // is_abstract
  //
  const bool WorkerLibraries_Impl::is_abstract (0);

  //
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  WorkerLibraries WorkerLibraries_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_folder <WorkerLibraries> (parent, WorkerLibraries_Impl::metaname);
  }

  //
  // accept
  //
  void WorkerLibraries_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WorkerLibraries (this);
    else
      v->visit_Folder (this);
  }

  //
  // parent_RootFolder (void)
  //
  RootFolder WorkerLibraries_Impl::parent_RootFolder (void)
  {
    return RootFolder::_narrow (this->parent ());
  }

  //
  // get_WorkerLibrarys
  //
  size_t WorkerLibraries_Impl::get_WorkerLibrarys (std::vector <WorkerLibrary> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkerLibrarys
  //
  ::GAME::Mga::Collection_T <WorkerLibrary> WorkerLibraries_Impl::get_WorkerLibrarys (void) const
  {
    return this->children <WorkerLibrary> ();
  }
}

