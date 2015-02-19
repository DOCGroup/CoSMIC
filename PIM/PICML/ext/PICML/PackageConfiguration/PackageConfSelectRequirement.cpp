// $Id$

#include "StdAfx.h"
#include "PackageConfSelectRequirement.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfSelectRequirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PackageConfiguration/PackageConfiguration.h"
#include "PICML/Common/Requirement.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PackageConfSelectRequirement_Impl::metaname ("PackageConfSelectRequirement");

  //
  // is_abstract
  //
  const bool PackageConfSelectRequirement_Impl::is_abstract = false;

  //
  // _create (const PackageConfigurationContainer_in, PackageConfiguration_in src, Requirement_in dst)
  //
  PackageConfSelectRequirement PackageConfSelectRequirement_Impl::_create (const PackageConfigurationContainer_in parent, PackageConfiguration_in src, Requirement_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, PackageConfSelectRequirement_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void PackageConfSelectRequirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PackageConfSelectRequirement (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer PackageConfSelectRequirement_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // PackageConfiguration
  //
  PackageConfiguration PackageConfSelectRequirement_Impl::src_PackageConfiguration (void) const
  {
    return PackageConfiguration::_narrow (this->src ());
  }

  //
  // Requirement
  //
  Requirement PackageConfSelectRequirement_Impl::dst_Requirement (void) const
  {
    return Requirement::_narrow (this->dst ());
  }
}

