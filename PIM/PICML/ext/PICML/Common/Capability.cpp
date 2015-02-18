// $Id$

#include "StdAfx.h"
#include "Capability.h"

#if !defined (__GAME_INLINE__)
#include "Capability.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Capability_Impl::metaname ("Capability");

  //
  // is_abstract
  //
  const bool Capability_Impl::is_abstract = false;

  //
  // _create (const ComponentImplementationContainer_in)
  //
  Capability Capability_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create < Capability > (parent, Capability_Impl::metaname);
  }

  //
  // accept
  //
  void Capability_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Capability (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentImplementationContainer
  //
  ComponentImplementationContainer Capability_Impl::parent_ComponentImplementationContainer (void)
  {
    return ComponentImplementationContainer::_narrow (this->parent ());
  }

  //
  // dst_of_ImplementationCapability
  //
  size_t Capability_Impl::dst_of_ImplementationCapability (std::vector <ImplementationCapability> & items) const
  {
    return this->in_connections <ImplementationCapability> (items);
  }

  //
  // dst_of_ImplementationCapability
  //
  GAME::Mga::Collection_T <ImplementationCapability> Capability_Impl::dst_of_ImplementationCapability (void) const
  {
    return this->in_connections <ImplementationCapability> ("dst");
  }
}

