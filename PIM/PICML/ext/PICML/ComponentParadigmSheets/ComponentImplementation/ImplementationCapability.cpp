// $Id$

#include "StdAfx.h"
#include "ImplementationCapability.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationCapability.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/Common/Capability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationCapability_Impl::metaname ("ImplementationCapability");

  //
  // is_abstract
  //
  const bool ImplementationCapability_Impl::is_abstract (0);

  //
  // _create (const ComponentImplementationContainer_in, ComponentImplementation_in src, Capability_in dst)
  //
  ImplementationCapability ImplementationCapability_Impl::_create (const ComponentImplementationContainer_in parent, ComponentImplementation_in src, Capability_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, ImplementationCapability_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void ImplementationCapability_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ImplementationCapability (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer ImplementationCapability_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // ComponentImplementation
  //
  ComponentImplementation ImplementationCapability_Impl::src_ComponentImplementation (void) const
  {
    return ComponentImplementation::_narrow (this->src ());
  }

  //
  // Capability
  //
  Capability ImplementationCapability_Impl::dst_Capability (void) const
  {
    return Capability::_narrow (this->dst ());
  }
}

