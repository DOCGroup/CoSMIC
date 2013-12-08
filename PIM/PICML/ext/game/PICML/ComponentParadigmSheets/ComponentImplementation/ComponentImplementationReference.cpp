// $Id$

#include "StdAfx.h"
#include "ComponentImplementationReference.h"

#if !defined (__GAME_INLINE__)
#include "ComponentImplementationReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/Implementation.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementation.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/MonolithicImplementation.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentImplementationReference_Impl::metaname ("ComponentImplementationReference");

  //
  // _create (const PackageContainer_in)
  //
  ComponentImplementationReference ComponentImplementationReference_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentImplementationReference > (parent, ComponentImplementationReference_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentImplementationReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentImplementationReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_PackageContainer
  //
  PackageContainer ComponentImplementationReference_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // dst_Implementation
  //
  size_t ComponentImplementationReference_Impl::dst_Implementation (std::vector <Implementation> & items) const
  {
    return this->in_connections <Implementation> (items);
  }

  //
  // ComponentImplementation_is_nil
  //
  bool ComponentImplementationReference_Impl::ComponentImplementation_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_ComponentImplementation
  //
  void ComponentImplementationReference_Impl::set_ComponentImplementation (ComponentImplementation_in item)
  {
    this->refers_to (item);
  }

  //
  // get_ComponentImplementation
  //
  ComponentImplementation ComponentImplementationReference_Impl::get_ComponentImplementation (void) const
  {
    return ComponentImplementation::_narrow (this->refers_to ());
  }
}
