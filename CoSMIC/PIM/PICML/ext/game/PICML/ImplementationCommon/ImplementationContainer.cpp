// $Id$

#include "stdafx.h"
#include "ImplementationContainer.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"
#include "PICML/ImplementationCommon/InfoProperty.h"
#include "PICML/Common/ImplementationRequirement.h"
#include "PICML/ImplementationArtifact/ImplementationArtifactReference.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/Common/Property.h"
#include "PICML/ImplementationCommon/ConfigProperty.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ImplementationContainer_Impl::metaname = "ImplementationContainer";

  //
  // ImplementationContainer_Impl
  //
  ImplementationContainer_Impl::ImplementationContainer_Impl (void)
  {
  }

  //
  // ImplementationContainer_Impl
  //
  ImplementationContainer_Impl::ImplementationContainer_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ImplementationContainer_Impl
  //
  ImplementationContainer_Impl::~ImplementationContainer_Impl (void)
  {
  }

  //
  // get_MonolithDeployRequirements
  //
  size_t ImplementationContainer_Impl::get_MonolithDeployRequirements (std::vector <MonolithDeployRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_InfoPropertys
  //
  size_t ImplementationContainer_Impl::get_InfoPropertys (std::vector <InfoProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationRequirements
  //
  size_t ImplementationContainer_Impl::get_ImplementationRequirements (std::vector <ImplementationRequirement> & items) const
  {
    return this->children (items);
  }

  //
  // get_ImplementationArtifactReferences
  //
  size_t ImplementationContainer_Impl::get_ImplementationArtifactReferences (std::vector <ImplementationArtifactReference> & items) const
  {
    return this->children (items);
  }

  //
  // get_MonolithExecParameters
  //
  size_t ImplementationContainer_Impl::get_MonolithExecParameters (std::vector <MonolithExecParameter> & items) const
  {
    return this->children (items);
  }

  //
  // get_Propertys
  //
  size_t ImplementationContainer_Impl::get_Propertys (std::vector <Property> & items) const
  {
    return this->children (items);
  }

  //
  // get_ConfigPropertys
  //
  size_t ImplementationContainer_Impl::get_ConfigPropertys (std::vector <ConfigProperty> & items) const
  {
    return this->children (items);
  }

  //
  // get_MonolithprimaryArtifacts
  //
  size_t ImplementationContainer_Impl::get_MonolithprimaryArtifacts (std::vector <MonolithprimaryArtifact> & items) const
  {
    return this->children (items);
  }
}

