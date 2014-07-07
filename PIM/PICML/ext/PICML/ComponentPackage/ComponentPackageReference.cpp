// $Id$

#include "StdAfx.h"
#include "ComponentPackageReference.h"

#if !defined (__GAME_INLINE__)
#include "ComponentPackageReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "PICML/PackageConfiguration/PackageConfReference.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentPackageReference_Impl::metaname ("ComponentPackageReference");

  //
  // _create (const ComponentAssembly_in)
  //
  ComponentPackageReference ComponentPackageReference_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < ComponentPackageReference > (parent, ComponentPackageReference_Impl::metaname);
  }

  //
  // _create (const PackageConfigurationContainer_in)
  //
  ComponentPackageReference ComponentPackageReference_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < ComponentPackageReference > (parent, ComponentPackageReference_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentPackageReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentPackageReference (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ComponentPackageReference_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer ComponentPackageReference_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // dst_PackageConfReference
  //
  size_t ComponentPackageReference_Impl::dst_PackageConfReference (std::vector <PackageConfReference> & items) const
  {
    return this->in_connections <PackageConfReference> (items);
  }

  //
  // ComponentPackage_is_nil
  //
  bool ComponentPackageReference_Impl::ComponentPackage_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_ComponentPackage
  //
  void ComponentPackageReference_Impl::set_ComponentPackage (ComponentPackage_in item)
  {
    this->refers_to (item);
  }

  //
  // get_ComponentPackage
  //
  ComponentPackage ComponentPackageReference_Impl::get_ComponentPackage (void) const
  {
    return ComponentPackage::_narrow (this->refers_to ());
  }
}

