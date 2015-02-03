// $Id$

#include "StdAfx.h"
#include "PackageConfConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfConfigProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfConfigProperty_Impl::metaname ("PackageConfConfigProperty");

  //
  // is_abstract
  //
  const bool PackageConfConfigProperty_Impl::is_abstract (0);

  //
  // _create (const PackageConfigurationContainer_in, PackageConfiguration_in src, Property_in dst)
  //
  PackageConfConfigProperty PackageConfConfigProperty_Impl::_create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PackageConfConfigProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PackageConfConfigProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfConfigProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfConfigProperty_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // PackageConfiguration
  //
  PackageConfiguration PackageConfConfigProperty_Impl::src_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->src ());
  }

  //
  // Property
  //
  Property PackageConfConfigProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

