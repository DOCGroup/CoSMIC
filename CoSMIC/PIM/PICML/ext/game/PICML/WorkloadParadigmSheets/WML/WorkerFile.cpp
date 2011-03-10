// $Id$

#include "stdafx.h"
#include "WorkerFile.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerPackage.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibrary.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string WorkerFile_Impl::metaname = "WorkerFile";

  //
  // WorkerFile_Impl
  //
  WorkerFile_Impl::WorkerFile_Impl (void)
  {
  }

  //
  // WorkerFile_Impl
  //
  WorkerFile_Impl::WorkerFile_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~WorkerFile_Impl
  //
  WorkerFile_Impl::~WorkerFile_Impl (void)
  {
  }

  //
  // accept
  //
  void WorkerFile_Impl::accept (Visitor * v)
  {
    v->visit_WorkerFile (this);
  }

  //
  // _create
  //
  WorkerFile WorkerFile_Impl::_create (const WorkerLibrary_in parent)
  {
    return ::GAME::Mga::create_object <WorkerFile> (parent, WorkerFile_Impl::metaname);
  }

  //
  // Location
  //
  void WorkerFile_Impl::Location (const std::string & val)
  {
    static const std::string attr_Location ("Location");
    this->attribute (attr_Location)->string_value (val);
  }

  //
  // Location
  //
  std::string WorkerFile_Impl::Location (void) const
  {
    static const std::string attr_Location ("Location");
    return this->attribute (attr_Location)->string_value ();
  }

  //
  // get_WorkerPackages
  //
  size_t WorkerFile_Impl::get_WorkerPackages (std::vector <WorkerPackage> & items) const
  {
    return this->children (items);
  }

  //
  // parent_WorkerLibrary
  //
  WorkerLibrary WorkerFile_Impl::parent_WorkerLibrary (void) const
  {
    return ::GAME::Mga::get_parent <WorkerLibrary> (this->object_.p);
  }
}

