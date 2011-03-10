// $Id$

#include "stdafx.h"
#include "AssemblyselectRequirement.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigPropertyEnd.h"
#include "PICML/Common/Requirement.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AssemblyselectRequirement_Impl::metaname = "AssemblyselectRequirement";

  //
  // AssemblyselectRequirement_Impl
  //
  AssemblyselectRequirement_Impl::AssemblyselectRequirement_Impl (void)
  {
  }

  //
  // AssemblyselectRequirement_Impl
  //
  AssemblyselectRequirement_Impl::AssemblyselectRequirement_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AssemblyselectRequirement_Impl
  //
  AssemblyselectRequirement_Impl::~AssemblyselectRequirement_Impl (void)
  {
  }

  //
  // accept
  //
  void AssemblyselectRequirement_Impl::accept (Visitor * v)
  {
    v->visit_AssemblyselectRequirement (this);
  }

  //
  // src_AssemblyConfigPropertyEnd
  //
  AssemblyConfigPropertyEnd AssemblyselectRequirement_Impl::src_AssemblyConfigPropertyEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return AssemblyConfigPropertyEnd::_narrow (target);
  }

  //
  // dst_Requirement
  //
  Requirement AssemblyselectRequirement_Impl::dst_Requirement (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Requirement::_narrow (target);
  }
}

