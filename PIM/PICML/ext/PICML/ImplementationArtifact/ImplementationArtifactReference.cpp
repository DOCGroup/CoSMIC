// $Id$

#include "StdAfx.h"
#include "ImplementationArtifactReference.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationArtifactReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"
#include "PICML/ImplementationArtifact/ArtifactDependsOn.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementationContainer.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementationContainer.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ComponentBuild/ExecutorProject.h"
#include "PICML/ComponentBuild/ServantProject.h"
#include "PICML/ComponentBuild/StubProject.h"
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
  // is_abstract
  //
  const bool ImplementationArtifactReference_Impl::is_abstract (0);

  //
  // _create (const ImplementationContainer_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // _create (const ExecutorProject_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ExecutorProject_in parent)
  {
    return ::GAME::Mga::create < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // _create (const ServantProject_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const ServantProject_in parent)
  {
    return ::GAME::Mga::create < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
  }

  //
  // _create (const StubProject_in)
  //
  ImplementationArtifactReference ImplementationArtifactReference_Impl::_create (const StubProject_in parent)
  {
    return ::GAME::Mga::create < ImplementationArtifactReference > (parent, ImplementationArtifactReference_Impl::metaname);
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
  // parent_ImplementationContainer
  //
  ImplementationContainer ImplementationArtifactReference_Impl::parent_ImplementationContainer (void)
  {
    return ImplementationContainer::_narrow (this->parent ());
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ImplementationArtifactReference_Impl::parent_ArtifactContainer (void)
  {
    return ArtifactContainer::_narrow (this->parent ());
  }

  //
  // parent_ExecutorProject
  //
  ExecutorProject ImplementationArtifactReference_Impl::parent_ExecutorProject (void)
  {
    return ExecutorProject::_narrow (this->parent ());
  }

  //
  // parent_ServantProject
  //
  ServantProject ImplementationArtifactReference_Impl::parent_ServantProject (void)
  {
    return ServantProject::_narrow (this->parent ());
  }

  //
  // parent_StubProject
  //
  StubProject ImplementationArtifactReference_Impl::parent_StubProject (void)
  {
    return StubProject::_narrow (this->parent ());
  }

  //
  // dst_of_MonolithprimaryArtifact
  //
  size_t ImplementationArtifactReference_Impl::dst_of_MonolithprimaryArtifact (std::vector <MonolithprimaryArtifact> & items) const
  {
    return this->in_connections <MonolithprimaryArtifact> (items);
  }

  //
  // dst_of_MonolithprimaryArtifact
  //
  GAME::Mga::Collection_T <MonolithprimaryArtifact> ImplementationArtifactReference_Impl::dst_of_MonolithprimaryArtifact (void) const
  {
    return this->in_connections <MonolithprimaryArtifact> ("dst");
  }

  //
  // dst_of_ArtifactDependsOn
  //
  size_t ImplementationArtifactReference_Impl::dst_of_ArtifactDependsOn (std::vector <ArtifactDependsOn> & items) const
  {
    return this->in_connections <ArtifactDependsOn> (items);
  }

  //
  // dst_of_ArtifactDependsOn
  //
  GAME::Mga::Collection_T <ArtifactDependsOn> ImplementationArtifactReference_Impl::dst_of_ArtifactDependsOn (void) const
  {
    return this->in_connections <ArtifactDependsOn> ("dst");
  }

  //
  // ImplementationArtifact_is_nil
  //
  bool ImplementationArtifactReference_Impl::ImplementationArtifact_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_ImplementationArtifact
  //
  void ImplementationArtifactReference_Impl::refers_to_ImplementationArtifact (ImplementationArtifact_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ImplementationArtifact
  //
  ImplementationArtifact ImplementationArtifactReference_Impl::refers_to_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->refers_to ());
  }
}

