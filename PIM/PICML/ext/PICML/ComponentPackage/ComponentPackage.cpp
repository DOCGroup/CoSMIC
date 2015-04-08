#include "StdAfx.h"
#include "ComponentPackage.h"

#if !defined (__GAME_INLINE__)
#include "ComponentPackage.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/ComponentPackage/PackageContainer.h"
#include "PICML/ComponentPackage/Implementation.h"
#include "PICML/ComponentPackage/PackageInfoProperty.h"
#include "PICML/PackageConfiguration/PackageConfBasePackage.h"
#include "PICML/ComponentPackage/PackageConfigProperty.h"
#include "PICML/ComponentPackage/PackageInterface.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ComponentPackage_Impl::metaname ("ComponentPackage");

  //
  // is_abstract
  //
  const bool ComponentPackage_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in)
  //
  ComponentPackage ComponentPackage_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create < ComponentPackage > (parent, ComponentPackage_Impl::metaname);
  }

  //
  // _create (const PackageConfigurationContainer_in)
  //
  ComponentPackage ComponentPackage_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create < ComponentPackage > (parent, ComponentPackage_Impl::metaname);
  }

  //
  // _create (const PackageContainer_in)
  //
  ComponentPackage ComponentPackage_Impl::_create (const PackageContainer_in parent)
  {
    return ::GAME::Mga::create < ComponentPackage > (parent, ComponentPackage_Impl::metaname);
  }

  //
  // accept
  //
  void ComponentPackage_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ComponentPackage (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly ComponentPackage_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer ComponentPackage_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // parent_PackageContainer
  //
  PackageContainer ComponentPackage_Impl::parent_PackageContainer (void)
  {
    return PackageContainer::_narrow (this->parent ());
  }

  //
  // src_of_Implementation
  //
  size_t ComponentPackage_Impl::src_of_Implementation (std::vector <Implementation> & items) const
  {
    return this->in_connections <Implementation> (items);
  }

  //
  // src_of_Implementation
  //
  GAME::Mga::Collection_T <Implementation> ComponentPackage_Impl::src_of_Implementation (void) const
  {
    return this->in_connections <Implementation> ("src");
  }

  //
  // src_of_PackageInfoProperty
  //
  size_t ComponentPackage_Impl::src_of_PackageInfoProperty (std::vector <PackageInfoProperty> & items) const
  {
    return this->in_connections <PackageInfoProperty> (items);
  }

  //
  // src_of_PackageInfoProperty
  //
  GAME::Mga::Collection_T <PackageInfoProperty> ComponentPackage_Impl::src_of_PackageInfoProperty (void) const
  {
    return this->in_connections <PackageInfoProperty> ("src");
  }

  //
  // src_of_PackageConfigProperty
  //
  size_t ComponentPackage_Impl::src_of_PackageConfigProperty (std::vector <PackageConfigProperty> & items) const
  {
    return this->in_connections <PackageConfigProperty> (items);
  }

  //
  // src_of_PackageConfigProperty
  //
  GAME::Mga::Collection_T <PackageConfigProperty> ComponentPackage_Impl::src_of_PackageConfigProperty (void) const
  {
    return this->in_connections <PackageConfigProperty> ("src");
  }

  //
  // src_of_PackageInterface
  //
  size_t ComponentPackage_Impl::src_of_PackageInterface (std::vector <PackageInterface> & items) const
  {
    return this->in_connections <PackageInterface> (items);
  }

  //
  // has_src_of_PackageInterface
  //
  bool ComponentPackage_Impl::has_src_of_PackageInterface (void) const
  {
    return this->in_connections <PackageInterface> ("src").count () == 1;
  }

  //
  // src_of_PackageInterface
  //
  PackageInterface ComponentPackage_Impl::src_of_PackageInterface (void) const
  {
    return this->in_connections <PackageInterface> ("src").first ();
  }

  //
  // dst_of_PackageConfBasePackage
  //
  size_t ComponentPackage_Impl::dst_of_PackageConfBasePackage (std::vector <PackageConfBasePackage> & items) const
  {
    return this->in_connections <PackageConfBasePackage> (items);
  }

  //
  // dst_of_PackageConfBasePackage
  //
  GAME::Mga::Collection_T <PackageConfBasePackage> ComponentPackage_Impl::dst_of_PackageConfBasePackage (void) const
  {
    return this->in_connections <PackageConfBasePackage> ("dst");
  }
}

