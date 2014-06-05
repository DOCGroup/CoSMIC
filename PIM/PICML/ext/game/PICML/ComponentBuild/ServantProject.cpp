// $Id$

#include "StdAfx.h"
#include "ServantProject.h"

#if !defined (__GAME_INLINE__)
#include "ServantProject.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"
#include "PICML/InterfaceDefinition/FileRef.h"
#include "PICML/ComponentBuild/Project.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ServantProject_Impl::metaname ("ServantProject");

  //
  // _create (const Project_in)
  //
  ServantProject ServantProject_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object < ServantProject > (parent, ServantProject_Impl::metaname);
  }

  //
  // accept
  //
  void ServantProject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ServantProject (this);
    else
      v->visit_Model (this);
  }

  //
  // has_ImplementationArtifactReference
  //
  bool ServantProject_Impl::has_ImplementationArtifactReference (void) const
  {
    return this->children <ImplementationArtifactReference> ().count () == 1;
  }

  //
  // get_ImplementationArtifactReference
  //
  ImplementationArtifactReference ServantProject_Impl::get_ImplementationArtifactReference (void) const
  {
    return this->children <ImplementationArtifactReference> ().first ();
  }

  //
  // has_ComponentServantArtifact
  //
  bool ServantProject_Impl::has_ComponentServantArtifact (void) const
  {
    return this->children <ComponentServantArtifact> ().count () == 1;
  }

  //
  // get_ComponentServantArtifact
  //
  ComponentServantArtifact ServantProject_Impl::get_ComponentServantArtifact (void) const
  {
    return this->children <ComponentServantArtifact> ().first ();
  }

  //
  // has_ComponentImplementationArtifact
  //
  bool ServantProject_Impl::has_ComponentImplementationArtifact (void) const
  {
    return this->children <ComponentImplementationArtifact> ().count () == 1;
  }

  //
  // get_ComponentImplementationArtifact
  //
  ComponentImplementationArtifact ServantProject_Impl::get_ComponentImplementationArtifact (void) const
  {
    return this->children <ComponentImplementationArtifact> ().first ();
  }

  //
  // has_FileRef
  //
  bool ServantProject_Impl::has_FileRef (void) const
  {
    return this->children <FileRef> ().count () == 1;
  }

  //
  // get_FileRef
  //
  FileRef ServantProject_Impl::get_FileRef (void) const
  {
    return this->children <FileRef> ().first ();
  }
}

