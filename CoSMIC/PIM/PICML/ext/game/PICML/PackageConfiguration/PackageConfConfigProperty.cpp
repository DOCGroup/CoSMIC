// $Id$

#include "StdAfx.h"
#include "PackageConfConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfConfigProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
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
  const std::string PackageConfConfigProperty_Impl::metaname ("PackageConfConfigProperty");

  //
  // _create (const PackageConfigurationContainer_in)
  //
  PackageConfConfigProperty PackageConfConfigProperty_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageConfConfigProperty > (parent, PackageConfConfigProperty_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfConfigProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PackageConfConfigProperty (this);
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

