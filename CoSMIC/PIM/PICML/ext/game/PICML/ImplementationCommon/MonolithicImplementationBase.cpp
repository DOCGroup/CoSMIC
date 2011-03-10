// $Id$

#include "stdafx.h"
#include "MonolithicImplementationBase.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithicImplementationBase_Impl::metaname = "MonolithicImplementationBase";

  //
  // MonolithicImplementationBase_Impl
  //
  MonolithicImplementationBase_Impl::MonolithicImplementationBase_Impl (void)
  {
  }

  //
  // MonolithicImplementationBase_Impl
  //
  MonolithicImplementationBase_Impl::MonolithicImplementationBase_Impl (IMgaFCO * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MonolithicImplementationBase_Impl
  //
  MonolithicImplementationBase_Impl::~MonolithicImplementationBase_Impl (void)
  {
  }

  //
  // in_MonolithDeployRequirement_connections
  //
  size_t MonolithicImplementationBase_Impl::in_MonolithDeployRequirement_connections (std::vector <MonolithDeployRequirement> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_MonolithExecParameter_connections
  //
  size_t MonolithicImplementationBase_Impl::in_MonolithExecParameter_connections (std::vector <MonolithExecParameter> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // in_MonolithprimaryArtifact_connections
  //
  size_t MonolithicImplementationBase_Impl::in_MonolithprimaryArtifact_connections (std::vector <MonolithprimaryArtifact> & conns) const
  {
    return this->in_connections (conns);
  }
}

