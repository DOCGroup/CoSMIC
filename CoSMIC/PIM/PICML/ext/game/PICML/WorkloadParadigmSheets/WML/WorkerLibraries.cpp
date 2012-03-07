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
  // _create (const ::GAME::Mga::RootFolder_in)
  //
  WorkerLibraries WorkerLibraries_Impl::_create (const ::GAME::Mga::RootFolder_in parent)
  {
    return ::GAME::Mga::create_root_object <WorkerLibraries> (parent, WorkerLibraries_Impl::metaname);
  }

  //
  // accept
  //
  void WorkerLibraries_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_WorkerLibraries (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Folder (this);
    }
  }

  //
  // get_WorkerLibrarys
  //
  size_t WorkerLibraries_Impl::get_WorkerLibrarys (std::vector <WorkerLibrary> & items) const
  {
    return this->children (items);
  }
}

