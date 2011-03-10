// $Id$

#include "stdafx.h"
#include "PackageConfReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/ComponentPackage/ComponentPackageReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfReference_Impl::metaname = "PackageConfReference";

  //
  // PackageConfReference_Impl
  //
  PackageConfReference_Impl::PackageConfReference_Impl (void)
  {
  }

  //
  // PackageConfReference_Impl
  //
  PackageConfReference_Impl::PackageConfReference_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfReference_Impl
  //
  PackageConfReference_Impl::~PackageConfReference_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfReference_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfReference (this);
  }

  //
  // _create
  //
  PackageConfReference PackageConfReference_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageConfReference> (parent, PackageConfReference_Impl::metaname);
  }

  //
  // src_PackageConfiguration
  //
  PackageConfiguration PackageConfReference_Impl::src_PackageConfiguration (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return PackageConfiguration::_narrow (target);
  }

  //
  // dst_ComponentPackageReference
  //
  ComponentPackageReference PackageConfReference_Impl::dst_ComponentPackageReference (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ComponentPackageReference::_narrow (target);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfReference_Impl::parent_PackageConfigurationContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageConfigurationContainer> (this->object_.p);
  }
}

