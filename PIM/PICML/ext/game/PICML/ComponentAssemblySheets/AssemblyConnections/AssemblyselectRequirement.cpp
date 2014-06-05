// $Id$

#include "StdAfx.h"
#include "AssemblyselectRequirement.h"

#if !defined (__GAME_INLINE__)
#include "AssemblyselectRequirement.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Requirement.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "PICML/RealTimeRequirements/RTRequirements.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigPropertyEnd.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInstance/ConnectorInstance.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ComponentInstance.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string AssemblyselectRequirement_Impl::metaname ("AssemblyselectRequirement");

  //
  // _create (const ComponentAssembly_in)
  //
  AssemblyselectRequirement AssemblyselectRequirement_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < AssemblyselectRequirement > (parent, AssemblyselectRequirement_Impl::metaname);
  }

  //
  // accept
  //
  void AssemblyselectRequirement_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AssemblyselectRequirement (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly AssemblyselectRequirement_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // AssemblyConfigPropertyEnd
  //
  AssemblyConfigPropertyEnd AssemblyselectRequirement_Impl::src_AssemblyConfigPropertyEnd (void) const
  {
    return AssemblyConfigPropertyEnd::_narrow (this->src ());
  }

  //
  // Requirement
  //
  Requirement AssemblyselectRequirement_Impl::dst_Requirement (void) const
  {
    return Requirement::_narrow (this->dst ());
  }
}

