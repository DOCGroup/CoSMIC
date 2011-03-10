// $Id$

#include "stdafx.h"
#include "ImplementationCapability.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/Common/Capability.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationCapability_Impl::metaname = "ImplementationCapability";

  //
  // ImplementationCapability_Impl
  //
  ImplementationCapability_Impl::ImplementationCapability_Impl (void)
  {
  }

  //
  // ImplementationCapability_Impl
  //
  ImplementationCapability_Impl::ImplementationCapability_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationCapability_Impl
  //
  ImplementationCapability_Impl::~ImplementationCapability_Impl (void)
  {
  }

  //
  // accept
  //
  void ImplementationCapability_Impl::accept (Visitor * v)
  {
    v->visit_ImplementationCapability (this);
  }

  //
  // _create
  //
  ImplementationCapability ImplementationCapability_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object <ImplementationCapability> (parent, ImplementationCapability_Impl::metaname);
  }

  //
  // src_ComponentImplementation
  //
  ComponentImplementation ImplementationCapability_Impl::src_ComponentImplementation (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ComponentImplementation::_narrow (target);
  }

  //
  // dst_Capability
  //
  Capability ImplementationCapability_Impl::dst_Capability (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Capability::_narrow (target);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ImplementationCapability_Impl::parent_ComponentImplementationContainer (void) const
  {
    return ::GAME::Mga::get_parent <ComponentImplementationContainer> (this->object_.p);
  }
}

