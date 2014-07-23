// $Id$

#include "StdAfx.h"
#include "MonolithicImplementationBase.h"

#if !defined (__GAME_INLINE__)
#include "MonolithicImplementationBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithicImplementationBase_Impl::metaname ("MonolithicImplementationBase");

  //
  // src_MonolithprimaryArtifact
  //
  size_t MonolithicImplementationBase_Impl::src_MonolithprimaryArtifact (std::vector <MonolithprimaryArtifact> & items) const
  {
    return this->in_connections <MonolithprimaryArtifact> (items);
  }

  //
  // src_MonolithExecParameter
  //
  size_t MonolithicImplementationBase_Impl::src_MonolithExecParameter (std::vector <MonolithExecParameter> & items) const
  {
    return this->in_connections <MonolithExecParameter> (items);
  }

  //
  // src_MonolithDeployRequirement
  //
  size_t MonolithicImplementationBase_Impl::src_MonolithDeployRequirement (std::vector <MonolithDeployRequirement> & items) const
  {
    return this->in_connections <MonolithDeployRequirement> (items);
  }
}

