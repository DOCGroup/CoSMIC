// $Id$

#include "StdAfx.h"
#include "Requirement.h"

#if !defined (__GAME_INLINE__)
#include "Requirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ImplementationArtifact/ArtifactDeployRequirement.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyselectRequirement.h"
#include "PICML/PackageConfiguration/PackageConfSelectRequirement.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/PackageConfiguration/PackageConfigurationContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Requirement_Impl::metaname ("Requirement");

  //
  // _create (const ComponentAssembly_in)
  //
  Requirement Requirement_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < Requirement > (parent, Requirement_Impl::metaname);
  }

  //
  // _create (const ArtifactContainer_in)
  //
  Requirement Requirement_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object < Requirement > (parent, Requirement_Impl::metaname);
  }

  //
  // _create (const PackageConfigurationContainer_in)
  //
  Requirement Requirement_Impl::_create (const PackageConfigurationContainer_in parent)
  {
    return ::GAME::Mga::create_object < Requirement > (parent, Requirement_Impl::metaname);
  }

  //
  // accept
  //
  void Requirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Requirement (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly Requirement_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer Requirement_Impl::parent_ArtifactContainer (void)
  {
    return ArtifactContainer::_narrow (this->parent ());
  }

  //
  // parent_PackageConfigurationContainer
  //
  PackageConfigurationContainer Requirement_Impl::parent_PackageConfigurationContainer (void)
  {
    return PackageConfigurationContainer::_narrow (this->parent ());
  }

  //
  // dst_ArtifactDeployRequirement
  //
  size_t Requirement_Impl::dst_ArtifactDeployRequirement (std::vector <ArtifactDeployRequirement> & items) const
  {
    return this->in_connections <ArtifactDeployRequirement> (items);
  }

  //
  // dst_AssemblyselectRequirement
  //
  size_t Requirement_Impl::dst_AssemblyselectRequirement (std::vector <AssemblyselectRequirement> & items) const
  {
    return this->in_connections <AssemblyselectRequirement> (items);
  }

  //
  // dst_PackageConfSelectRequirement
  //
  size_t Requirement_Impl::dst_PackageConfSelectRequirement (std::vector <PackageConfSelectRequirement> & items) const
  {
    return this->in_connections <PackageConfSelectRequirement> (items);
  }
}

