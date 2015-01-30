// $Id$

#include "StdAfx.h"
#include "MonolithicImplementationBase.h"

#if !defined (__GAME_INLINE__)
#include "MonolithicImplementationBase.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ImplementationCommon/MonolithExecParameter.h"
#include "PICML/ImplementationCommon/MonolithDeployRequirement.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MonolithicImplementationBase_Impl::metaname ("MonolithicImplementationBase");

  //
  // src_of_MonolithExecParameter
  //
  size_t MonolithicImplementationBase_Impl::src_of_MonolithExecParameter (std::vector <MonolithExecParameter> & items) const
  {
    return this->in_connections <MonolithExecParameter> (items);
  }

  //
  // src_of_MonolithExecParameter
  //
  GAME::Mga::Collection_T <MonolithExecParameter> MonolithicImplementationBase_Impl::src_of_MonolithExecParameter (void) const
  {
    return this->in_connections <MonolithExecParameter> ("src");
  }

  //
  // src_of_MonolithDeployRequirement
  //
  size_t MonolithicImplementationBase_Impl::src_of_MonolithDeployRequirement (std::vector <MonolithDeployRequirement> & items) const
  {
    return this->in_connections <MonolithDeployRequirement> (items);
  }

  //
  // src_of_MonolithDeployRequirement
  //
  GAME::Mga::Collection_T <MonolithDeployRequirement> MonolithicImplementationBase_Impl::src_of_MonolithDeployRequirement (void) const
  {
    return this->in_connections <MonolithDeployRequirement> ("src");
  }

  //
  // src_of_MonolithprimaryArtifact
  //
  size_t MonolithicImplementationBase_Impl::src_of_MonolithprimaryArtifact (std::vector <MonolithprimaryArtifact> & items) const
  {
    return this->in_connections <MonolithprimaryArtifact> (items);
  }

  //
  // src_of_MonolithprimaryArtifact
  //
  GAME::Mga::Collection_T <MonolithprimaryArtifact> MonolithicImplementationBase_Impl::src_of_MonolithprimaryArtifact (void) const
  {
    return this->in_connections <MonolithprimaryArtifact> ("src");
  }
}

