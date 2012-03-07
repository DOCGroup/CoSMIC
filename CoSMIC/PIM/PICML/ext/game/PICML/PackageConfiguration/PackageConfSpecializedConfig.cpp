// $Id$

#include "StdAfx.h"
#include "PackageConfSpecializedConfig.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfSpecializedConfig.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationReference.h"
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
  const std::string PackageConfSpecializedConfig_Impl::metaname ("PackageConfSpecializedConfig");

  //
  // _create (const PackageConfigurationContainer_in)
  //
  PackageConfSpecializedConfig PackageConfSpecializedConfig_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageConfSpecializedConfig > (parent, PackageConfSpecializedConfig_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfSpecializedConfig_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PackageConfSpecializedConfig (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // PackageConfiguration
  //
  PackageConfiguration PackageConfSpecializedConfig_Impl::src_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->src ());
  }

  //
  // PackageConfigurationReference
  //
  PackageConfigurationReference PackageConfSpecializedConfig_Impl::dst_PackageConfigurationReference (void) const
  {
    return PackageConfigurationReference::_narrow (this->dst ());
  }
}

