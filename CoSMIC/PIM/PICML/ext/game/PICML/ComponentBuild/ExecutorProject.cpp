// $Id$

#include "stdafx.h"
#include "ExecutorProject.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ExecutorProject_Impl::metaname = "ExecutorProject";

  //
  // ExecutorProject_Impl
  //
  ExecutorProject_Impl::ExecutorProject_Impl (void)
  {
  }

  //
  // ExecutorProject_Impl
  //
  ExecutorProject_Impl::ExecutorProject_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ExecutorProject_Impl
  //
  ExecutorProject_Impl::~ExecutorProject_Impl (void)
  {
  }

  //
  // accept
  //
  void ExecutorProject_Impl::accept (Visitor * v)
  {
    v->visit_ExecutorProject (this);
  }

  //
  // get_ImplementationArtifactReference
  //
  ImplementationArtifactReference ExecutorProject_Impl::get_ImplementationArtifactReference (void) const
  {
    // Get the collection of children.
    std::vector <ImplementationArtifactReference> items;
    this->children (items);

    return !items.empty () ? items.front () : ImplementationArtifactReference ();
  }
}

