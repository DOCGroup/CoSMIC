// $Id$

#include "stdafx.h"
#include "PackageConfiguration.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfReference.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/PackageConfiguration/PackageConfConfigProperty.h"
#include "PICML/PackageConfiguration/PackageConfSelectRequirement.h"
#include "PICML/PackageConfiguration/PackageConfBasePackage.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfiguration_Impl::metaname = "PackageConfiguration";

  //
  // PackageConfiguration_Impl
  //
  PackageConfiguration_Impl::PackageConfiguration_Impl (void)
  {
  }

  //
  // PackageConfiguration_Impl
  //
  PackageConfiguration_Impl::PackageConfiguration_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfiguration_Impl
  //
  PackageConfiguration_Impl::~PackageConfiguration_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfiguration_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfiguration (this);
  }

  //
  // _create
  //
  PackageConfiguration PackageConfiguration_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageConfiguration> (parent, PackageConfiguration_Impl::metaname);
  }

  //
  // in_PackageConfReference_connections
  //
  size_t PackageConfiguration_Impl::in_PackageConfReference_connections (std::vector <PackageConfReference> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_PackageConfSpecializedConfig_connections
  //
  size_t PackageConfiguration_Impl::in_PackageConfSpecializedConfig_connections (std::vector <PackageConfSpecializedConfig> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_PackageConfConfigProperty_connections
  //
  size_t PackageConfiguration_Impl::in_PackageConfConfigProperty_connections (std::vector <PackageConfConfigProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_PackageConfSelectRequirement_connections
  //
  size_t PackageConfiguration_Impl::in_PackageConfSelectRequirement_connections (std::vector <PackageConfSelectRequirement> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_PackageConfBasePackage_connections
  //
  size_t PackageConfiguration_Impl::in_PackageConfBasePackage_connections (std::vector <PackageConfBasePackage> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfiguration_Impl::parent_PackageConfigurationContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageConfigurationContainer> (this->object_.p);
  }
}

