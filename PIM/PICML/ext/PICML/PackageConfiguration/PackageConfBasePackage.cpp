#include "StdAfx.h"
#include "PackageConfBasePackage.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfBasePackage.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/ComponentPackage/ComponentPackage.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfBasePackage_Impl::metaname ("PackageConfBasePackage");

  //
  // is_abstract
  //
  const bool PackageConfBasePackage_Impl::is_abstract = false;

  //
  // _create (const PackageConfigurationContainer_in, PackageConfiguration_in src, ComponentPackage_in dst)
  //
  PackageConfBasePackage PackageConfBasePackage_Impl::_create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, ComponentPackage_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PackageConfBasePackage_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PackageConfBasePackage_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfBasePackage (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfBasePackage_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // PackageConfiguration
  //
  PackageConfiguration PackageConfBasePackage_Impl::src_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->src ());
  }

  //
  // ComponentPackage
  //
  ComponentPackage PackageConfBasePackage_Impl::dst_ComponentPackage (void) const
  {
    return ComponentPackage::_narrow (this->dst ());
  }
}

