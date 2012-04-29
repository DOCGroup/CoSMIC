// $Id$

#include "StdAfx.h"
#include "ImplementationArtifactReference.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationArtifactReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentBuild/StubProject.h"
#include "PICML/ComponentBuild/ServantProject.h"
#include "PICML/ComponentBuild/ExecutorProject.h"
#include "PICML/ImplementationArtifact/ArtifactDependsOn.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationArtifactReference_Impl::metaname ("ImplementationArtifactReference");

  //
  // _create (const StubProject_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const StubProject_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // _create (const ServantProject_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ServantProject_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // _create (const ExecutorProject_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ExecutorProject_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // _create (const ImplementationContainer_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationArtifactReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ImplementationArtifactReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // dst_ArtifactDependsOn
  //
  size_t ImplementationArtifactReference_Impl::dst_ArtifactDependsOn (std::vector <ArtifactDependsOn> & items) const
  {
    return this->in_connections <ArtifactDependsOn> (items);
  }

  //
  // dst_MonolithprimaryArtifact
  //
  size_t ImplementationArtifactReference_Impl::dst_MonolithprimaryArtifact (std::vector <MonolithprimaryArtifact> & items) const
  {
    return this->in_connections <MonolithprimaryArtifact> (items);
  }

  //
  // ImplementationArtifact_is_nil
  //
  bool ImplementationArtifactReference_Impl::ImplementationArtifact_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ImplementationArtifact
  //
  ImplementationArtifact ImplementationArtifactReference_Impl::get_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->refers_to ());
  }
}

