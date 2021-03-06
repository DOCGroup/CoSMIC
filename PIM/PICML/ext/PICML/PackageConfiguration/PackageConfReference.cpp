#include "StdAfx.h"
#include "PackageConfReference.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfReference.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfReference_Impl::metaname ("PackageConfReference");

  //
  // is_abstract
  //
  const bool PackageConfReference_Impl::is_abstract = false;

  //
  // _create (const PackageConfigurationContainer_in, PackageConfiguration_in src, ComponentPackageReference_in dst)
  //
  PackageConfReference PackageConfReference_Impl::_create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, ComponentPackageReference_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PackageConfReference_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PackageConfReference_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfReference (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfReference_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // PackageConfiguration
  //
  PackageConfiguration PackageConfReference_Impl::src_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->src ());
  }

  //
  // ComponentPackageReference
  //
  ComponentPackageReference PackageConfReference_Impl::dst_ComponentPackageReference (void) const
  {
    return ComponentPackageReference::_narrow (this->dst ());
  }
}

