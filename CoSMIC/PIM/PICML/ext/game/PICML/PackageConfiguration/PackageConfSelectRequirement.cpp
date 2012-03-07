// $Id$

#include "StdAfx.h"
#include "PackageConfSelectRequirement.h"

#if !defined (__GAME_INLINE__)
#include "PackageConfSelectRequirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Requirement.h"
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
  const std::string PackageConfSelectRequirement_Impl::metaname ("PackageConfSelectRequirement");

  //
  // _create (const PackageConfigurationContainer_in)
  //
  PackageConfSelectRequirement PackageConfSelectRequirement_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < PackageConfSelectRequirement > (parent, PackageConfSelectRequirement_Impl::metaname);
  }

  //
  // accept
  //
  void PackageConfSelectRequirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_PackageConfSelectRequirement (this);
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

