// $Id$

#include "StdAfx.h"
#include "Capability.h"

#if !defined (__GAME_INLINE__)
#include "Capability.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ImplementationCapability.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/Common/RequirementSatisfier.h"
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
  // _create (const ComponentImplementationContainer_in)
  //
  Capability Capability_Impl::_create (const ComponentImplementationContainer_in parent)
  {
    return ::GAME::Mga::create_object < Capability > (parent, Capability_Impl::metaname);
  }

  //
  // _create (const RequirementSatisfier_in)
  //
  Capability Capability_Impl::_create (const RequirementSatisfier_in parent)
  {
    return ::GAME::Mga::create_object < Capability > (parent, Capability_Impl::metaname);
  }

  //
  // accept
  //
  void Capability_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Capability (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }

  //
  // dst_ImplementationCapability
  //
  size_t Capability_Impl::dst_ImplementationCapability (std::vector <ImplementationCapability> & items) const
  {
    return this->in_connections <ImplementationCapability> (items);
  }
}

