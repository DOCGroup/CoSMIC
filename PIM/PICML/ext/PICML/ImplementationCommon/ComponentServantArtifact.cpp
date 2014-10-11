// $Id$

#include "StdAfx.h"
#include "ComponentServantArtifact.h"

#if !defined (__GAME_INLINE__)
#include "ComponentServantArtifact.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ImplementationArtifact.h"
#include "PICML/ImplementationCommon/ImplementationContainer.h"
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
  const std::string ComponentServantArtifact_Impl::metaname ("ComponentServantArtifact");

  //
  // _create (const ImplementationContainer_in)
  //
  ComponentServantArtifact ComponentServantArtifact_Impl::_create (const ImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentServantArtifact > (parent, ComponentServantArtifact_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  ComponentServantArtifact ComponentServantArtifact_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentServantArtifact > (parent, ComponentServantArtifact_Impl::metaname);
  }

  //
  // _create (const ExecutorProject_in)
  //
  ComponentServantArtifact ComponentServantArtifact_Impl::_create (const ExecutorProject_in parent)
  {
    return ::GAME::Mga::create_object < ComponentServantArtifact > (parent, ComponentServantArtifact_Impl::metaname);
  }

  //
  // _create (const ServantProject_in)
  //
  ComponentServantArtifact ComponentServantArtifact_Impl::_create (const ServantProject_in parent)
  {
    return ::GAME::Mga::create_object < ComponentServantArtifact > (parent, ComponentServantArtifact_Impl::metaname);
  }

  //
  // _create (const StubProject_in)
  //
  ComponentServantArtifact ComponentServantArtifact_Impl::_create (const StubProject_in parent)
  {
    return ::GAME::Mga::create_object < ComponentServantArtifact > (parent, ComponentServantArtifact_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentServantArtifact_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentServantArtifact (this);
    else
      v->visit_Reference (this);
  }

  //
  // ImplementationArtifact_is_nil
  //
  bool ComponentServantArtifact_Impl::ImplementationArtifact_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_ImplementationArtifact
  //
  void ComponentServantArtifact_Impl::set_ImplementationArtifact (ImplementationArtifact_in item)
  {
    this->refers_to (item);
  }

  //
  // get_ImplementationArtifact
  //
  ImplementationArtifact ComponentServantArtifact_Impl::get_ImplementationArtifact (void) const
  {
    return ImplementationArtifact::_narrow (this->refers_to ());
  }
}

