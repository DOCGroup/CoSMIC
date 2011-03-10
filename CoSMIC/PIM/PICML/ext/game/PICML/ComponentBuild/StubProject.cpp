// $Id$

#include "stdafx.h"
#include "StubProject.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/FileRef.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string StubProject_Impl::metaname = "StubProject";

  //
  // StubProject_Impl
  //
  StubProject_Impl::StubProject_Impl (void)
  {
  }

  //
  // StubProject_Impl
  //
  StubProject_Impl::StubProject_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~StubProject_Impl
  //
  StubProject_Impl::~StubProject_Impl (void)
  {
  }

  //
  // accept
  //
  void StubProject_Impl::accept (Visitor * v)
  {
    v->visit_StubProject (this);
  }

  //
  // get_FileRef
  //
  FileRef StubProject_Impl::get_FileRef (void) const
  {
    // Get the collection of children.
    std::vector <FileRef> items;
    this->children (items);

    return !items.empty () ? items.front () : FileRef ();
  }

  //
  // get_ImplementationArtifactReference
  //
  ImplementationArtifactReference StubProject_Impl::get_ImplementationArtifactReference (void) const
  {
    // Get the collection of children.
    std::vector <ImplementationArtifactReference> items;
    this->children (items);

    return !items.empty () ? items.front () : ImplementationArtifactReference ();
  }
}

