// $Id$

#include "StdAfx.h"
#include "ExecutorProject.h"

#if !defined (__GAME_INLINE__)
#include "ExecutorProject.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/ComponentBuild/Project.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ExecutorProject_Impl::metaname ("ExecutorProject");

  //
  // _create (const Project_in)
  //
  ExecutorProject ExecutorProject_Impl::_create (const Project_in parent)
  {
    return ::GAME::Mga::create_object < ExecutorProject > (parent, ExecutorProject_Impl::metaname);
  }

  //
  // accept
  //
  void ExecutorProject_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ExecutorProject (this);
    else
      v->visit_Model (this);
  }

  //
  // has_ImplementationArtifactReference
  //
  bool ExecutorProject_Impl::has_ImplementationArtifactReference (void) const
  {
    return this->children <ImplementationArtifactReference> ().count () == 1;
  }

  //
  // get_ImplementationArtifactReference
  //
  ImplementationArtifactReference ExecutorProject_Impl::get_ImplementationArtifactReference (void) const
  {
    return this->children <ImplementationArtifactReference> ().first ();
  }

  //
  // has_ComponentImplementationArtifact
  //
  bool ExecutorProject_Impl::has_ComponentImplementationArtifact (void) const
  {
    return this->children <ComponentImplementationArtifact> ().count () == 1;
  }

  //
  // get_ComponentImplementationArtifact
  //
  ComponentImplementationArtifact ExecutorProject_Impl::get_ComponentImplementationArtifact (void) const
  {
    return this->children <ComponentImplementationArtifact> ().first ();
  }

  //
  // has_ComponentServantArtifact
  //
  bool ExecutorProject_Impl::has_ComponentServantArtifact (void) const
  {
    return this->children <ComponentServantArtifact> ().count () == 1;
  }

  //
  // get_ComponentServantArtifact
  //
  ComponentServantArtifact ExecutorProject_Impl::get_ComponentServantArtifact (void) const
  {
    return this->children <ComponentServantArtifact> ().first ();
  }
}

