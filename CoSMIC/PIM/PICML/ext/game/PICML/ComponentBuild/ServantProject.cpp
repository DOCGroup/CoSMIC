// $Id$

#include "stdafx.h"
#include "ServantProject.h"

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
  const std::string ServantProject_Impl::metaname = "ServantProject";

  //
  // ServantProject_Impl
  //
  ServantProject_Impl::ServantProject_Impl (void)
  {
  }

  //
  // ServantProject_Impl
  //
  ServantProject_Impl::ServantProject_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ServantProject_Impl
  //
  ServantProject_Impl::~ServantProject_Impl (void)
  {
  }

  //
  // accept
  //
  void ServantProject_Impl::accept (Visitor * v)
  {
    v->visit_ServantProject (this);
  }

  //
  // get_FileRef
  //
  FileRef ServantProject_Impl::get_FileRef (void) const
  {
    // Get the collection of children.
    std::vector <FileRef> items;
    this->children (items);

    return !items.empty () ? items.front () : FileRef ();
  }

  //
  // get_ImplementationArtifactReference
  //
  ImplementationArtifactReference ServantProject_Impl::get_ImplementationArtifactReference (void) const
  {
    // Get the collection of children.
    std::vector <ImplementationArtifactReference> items;
    this->children (items);

    return !items.empty () ? items.front () : ImplementationArtifactReference ();
  }
}

