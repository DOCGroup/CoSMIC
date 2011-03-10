// $Id$

#include "stdafx.h"
#include "PackageConfSelectRequirement.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/Common/Requirement.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfSelectRequirement_Impl::metaname = "PackageConfSelectRequirement";

  //
  // PackageConfSelectRequirement_Impl
  //
  PackageConfSelectRequirement_Impl::PackageConfSelectRequirement_Impl (void)
  {
  }

  //
  // PackageConfSelectRequirement_Impl
  //
  PackageConfSelectRequirement_Impl::PackageConfSelectRequirement_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PackageConfSelectRequirement_Impl
  //
  PackageConfSelectRequirement_Impl::~PackageConfSelectRequirement_Impl (void)
  {
  }

  //
  // accept
  //
  void PackageConfSelectRequirement_Impl::accept (Visitor * v)
  {
    v->visit_PackageConfSelectRequirement (this);
  }

  //
  // _create
  //
  PackageConfSelectRequirement PackageConfSelectRequirement_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object <PackageConfSelectRequirement> (parent, PackageConfSelectRequirement_Impl::metaname);
  }

  //
  // src_PackageConfiguration
  //
  PackageConfiguration PackageConfSelectRequirement_Impl::src_PackageConfiguration (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return PackageConfiguration::_narrow (target);
  }

  //
  // dst_Requirement
  //
  Requirement PackageConfSelectRequirement_Impl::dst_Requirement (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Requirement::_narrow (target);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfSelectRequirement_Impl::parent_PackageConfigurationContainer (void) const
  {
    return ::GAME::Mga::get_parent <PackageConfigurationContainer> (this->object_.p);
  }
}

