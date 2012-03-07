// $Id$

#include "StdAfx.h"
#include "ImplementationCapability.h"

#if !defined (__GAME_INLINE__)
#include "ImplementationCapability.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/Common/Capability.h"
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
  // _create (const ComponentImplementationContainer_in)
  //
  ImplementationCapability ImplementationCapability_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ImplementationCapability > (parent, ImplementationCapability_Impl::metaname);
  }

  //
  // accept
  //
  void ImplementationCapability_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ImplementationCapability (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

