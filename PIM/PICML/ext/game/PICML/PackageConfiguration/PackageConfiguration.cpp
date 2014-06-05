// $Id$

#include "StdAfx.h"
#include "PackageConfiguration.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfiguration.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfBasePackage.h"
#include "PICML/PackageConfiguration/PackageConfSelectRequirement.h"
#include "PICML/PackageConfiguration/PackageConfConfigProperty.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"
#include "PICML/PackageConfiguration/PackageConfReference.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfiguration_Impl::metaname ("PackageConfiguration");

  //
  // _create (const PackageConfigurationContainer_in)
  //
  PackageConfiguration PackageConfiguration_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageConfiguration > (parent, PackageConfiguration_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfiguration_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfiguration (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfiguration_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // src_PackageConfBasePackage
  //
  size_t PackageConfiguration_Impl::src_PackageConfBasePackage (std::vector <PackageConfBasePackage> & items) const
  {
    return this->in_connections <PackageConfBasePackage> (items);
  }

  //
  // src_PackageConfSelectRequirement
  //
  size_t PackageConfiguration_Impl::src_PackageConfSelectRequirement (std::vector <PackageConfSelectRequirement> & items) const
  {
    return this->in_connections <PackageConfSelectRequirement> (items);
  }

  //
  // src_PackageConfConfigProperty
  //
  size_t PackageConfiguration_Impl::src_PackageConfConfigProperty (std::vector <PackageConfConfigProperty> & items) const
  {
    return this->in_connections <PackageConfConfigProperty> (items);
  }

  //
  // src_PackageConfSpecializedConfig
  //
  size_t PackageConfiguration_Impl::src_PackageConfSpecializedConfig (std::vector <PackageConfSpecializedConfig> & items) const
  {
    return this->in_connections <PackageConfSpecializedConfig> (items);
  }

  //
  // src_PackageConfReference
  //
  size_t PackageConfiguration_Impl::src_PackageConfReference (std::vector <PackageConfReference> & items) const
  {
    return this->in_connections <PackageConfReference> (items);
  }
}

