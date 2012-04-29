// $Id$

#include "StdAfx.h"
#include "WorkerLibrary.h"

#if !defined (__GAME_INLINE__)
#include "WorkerLibrary.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibraries.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerFile.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerLibrary_Impl::metaname ("WorkerLibrary");

  //
  // _create (const WorkerLibraries_in)
  //
  WorkerLibrary WorkerLibrary_Impl::_create (const WorkerLibraries_in parent)
  {
    return ::GAME::Mga::create_root_object < WorkerLibrary > (parent, WorkerLibrary_Impl::metaname);
  }

  //
  // accept
  //
  void WorkerLibrary_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WorkerLibrary (this);
    else
      v->visit_Model (this);
  }

  //
  // get_WorkerFiles
  //
  size_t WorkerLibrary_Impl::get_WorkerFiles (std::vector <WorkerFile> & items) const
  {
    return this->children (items);
  }

  //
  // get_WorkerFiles
  //
  ::GAME::Mga::Iterator <WorkerFile> WorkerLibrary_Impl::get_WorkerFiles (void) const
  {
    return this->children <WorkerFile> ();
  }
}

