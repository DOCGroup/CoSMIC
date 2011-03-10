// $Id$

#include "stdafx.h"
#include "WorkerLibrary.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerFile.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibraries.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerLibrary_Impl::metaname = "WorkerLibrary";

  //
  // WorkerLibrary_Impl
  //
  WorkerLibrary_Impl::WorkerLibrary_Impl (void)
  {
  }

  //
  // WorkerLibrary_Impl
  //
  WorkerLibrary_Impl::WorkerLibrary_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkerLibrary_Impl
  //
  WorkerLibrary_Impl::~WorkerLibrary_Impl (void)
  {
  }

  //
  // accept
  //
  void WorkerLibrary_Impl::accept (Visitor * v)
  {
    v->visit_WorkerLibrary (this);
  }

  //
  // _create
  //
  WorkerLibrary WorkerLibrary_Impl::_create (const WorkerLibraries_in parent)
  {
    return ::GAME::Mga::create_root_object <WorkerLibrary> (parent, WorkerLibrary_Impl::metaname);
  }

  //
  // Location
  //
  void WorkerLibrary_Impl::Location (const std::string & val)
  {
    static const std::string attr_Location ("Location");
    this->attribute (attr_Location)->string_value (val);
  }

  //
  // Location
  //
  std::string WorkerLibrary_Impl::Location (void) const
  {
    static const std::string attr_Location ("Location");
    return this->attribute (attr_Location)->string_value ();
  }

  //
  // get_WorkerFiles
  //
  size_t WorkerLibrary_Impl::get_WorkerFiles (std::vector <WorkerFile> & items) const
  {
    return this->children (items);
  }

  //
  // parent_WorkerLibraries
  //
  WorkerLibraries WorkerLibrary_Impl::parent_WorkerLibraries (void) const
  {
    return ::GAME::Mga::get_parent <WorkerLibraries> (this->object_.p);
  }
}

