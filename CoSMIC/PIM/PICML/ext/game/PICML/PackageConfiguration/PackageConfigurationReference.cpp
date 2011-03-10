// $Id$

#include "stdafx.h"
#include "PackageConfigurationReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfSpecializedConfig.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfigurationReference_Impl::metaname = "PackageConfigurationReference";

  //
  // PackageConfigurationReference_Impl
  //
  PackageConfigurationReference_Impl::PackageConfigurationReference_Impl (void)
  {
  }

  //
  // PackageConfigurationReference_Impl
  //
  PackageConfigurationReference_Impl::PackageConfigurationReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfigurationReference_Impl
  //
  PackageConfigurationReference_Impl::~PackageConfigurationReference_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfigurationReference_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfigurationReference (this);
  }

  //
  // in_PackageConfSpecializedConfig_connections
  //
  size_t PackageConfigurationReference_Impl::in_PackageConfSpecializedConfig_connections (std::vector <PackageConfSpecializedConfig> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // refers_to_PackageConfiguration
  //
  PackageConfiguration PackageConfigurationReference_Impl::refers_to_PackageConfiguration (void) const
  {
    return ::GAME::Mga::get_refers_to <PackageConfiguration> (this);
  }
}

