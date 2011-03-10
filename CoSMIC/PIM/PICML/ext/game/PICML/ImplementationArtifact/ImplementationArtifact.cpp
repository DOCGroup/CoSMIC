// $Id$

#include "stdafx.h"
#include "ImplementationArtifact.h"

#include "game/mga/Attribute.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ImplementationArtifact/ArtifactDependency.h"
#include "PICML/ImplementationArtifact/ArtifactInfoProperty.h"
#include "PICML/ImplementationArtifact/ArtifactExecParameter.h"
#include "PICML/ImplementationArtifact/ArtifactDeployRequirement.h"
#include "PICML/ImplementationArtifact/ArtifactDependsOn.h"
#include "PICML/ImplementationArtifact/ArtifactDependency.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationArtifact_Impl::metaname = "ImplementationArtifact";

  //
  // ImplementationArtifact_Impl
  //
  ImplementationArtifact_Impl::ImplementationArtifact_Impl (void)
  {
  }

  //
  // ImplementationArtifact_Impl
  //
  ImplementationArtifact_Impl::ImplementationArtifact_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationArtifact_Impl
  //
  ImplementationArtifact_Impl::~ImplementationArtifact_Impl (void)
  {
  }

  //
  // accept
  //
  void ImplementationArtifact_Impl::accept (Visitor * v)
  {
    v->visit_ImplementationArtifact (this);
  }

  //
  // _create
  //
  ImplementationArtifact ImplementationArtifact_Impl::_create (const ArtifactContainer_in parent)
  {
    return ::GAME::Mga::create_object <ImplementationArtifact> (parent, ImplementationArtifact_Impl::metaname);
  }

  //
  // architecture
  //
  void ImplementationArtifact_Impl::architecture (const std::string & val)
  {
    static const std::string attr_architecture ("architecture");
    this->attribute (attr_architecture)->string_value (val);
  }

  //
  // architecture
  //
  std::string ImplementationArtifact_Impl::architecture (void) const
  {
    static const std::string attr_architecture ("architecture");
    return this->attribute (attr_architecture)->string_value ();
  }

  //
  // artifactVersion
  //
  void ImplementationArtifact_Impl::artifactVersion (const std::string & val)
  {
    static const std::string attr_artifactVersion ("artifactVersion");
    this->attribute (attr_artifactVersion)->string_value (val);
  }

  //
  // artifactVersion
  //
  std::string ImplementationArtifact_Impl::artifactVersion (void) const
  {
    static const std::string attr_artifactVersion ("artifactVersion");
    return this->attribute (attr_artifactVersion)->string_value ();
  }

  //
  // configuration
  //
  void ImplementationArtifact_Impl::configuration (const std::string & val)
  {
    static const std::string attr_configuration ("configuration");
    this->attribute (attr_configuration)->string_value (val);
  }

  //
  // configuration
  //
  std::string ImplementationArtifact_Impl::configuration (void) const
  {
    static const std::string attr_configuration ("configuration");
    return this->attribute (attr_configuration)->string_value ();
  }

  //
  // operatingSystem
  //
  void ImplementationArtifact_Impl::operatingSystem (const std::string & val)
  {
    static const std::string attr_operatingSystem ("operatingSystem");
    this->attribute (attr_operatingSystem)->string_value (val);
  }

  //
  // operatingSystem
  //
  std::string ImplementationArtifact_Impl::operatingSystem (void) const
  {
    static const std::string attr_operatingSystem ("operatingSystem");
    return this->attribute (attr_operatingSystem)->string_value ();
  }

  //
  // in_ArtifactDependency_connections
  //
  size_t ImplementationArtifact_Impl::in_ArtifactDependency_connections (std::vector <ArtifactDependency> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ArtifactInfoProperty_connections
  //
  size_t ImplementationArtifact_Impl::in_ArtifactInfoProperty_connections (std::vector <ArtifactInfoProperty> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ArtifactExecParameter_connections
  //
  size_t ImplementationArtifact_Impl::in_ArtifactExecParameter_connections (std::vector <ArtifactExecParameter> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ArtifactDeployRequirement_connections
  //
  size_t ImplementationArtifact_Impl::in_ArtifactDeployRequirement_connections (std::vector <ArtifactDeployRequirement> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_ArtifactDependsOn_connections
  //
  size_t ImplementationArtifact_Impl::in_ArtifactDependsOn_connections (std::vector <ArtifactDependsOn> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_ArtifactContainer
  //
  ArtifactContainer ImplementationArtifact_Impl::parent_ArtifactContainer (void) const
  {
    return ::GAME::Mga::get_parent <ArtifactContainer> (this->object_.p);
  }
}

