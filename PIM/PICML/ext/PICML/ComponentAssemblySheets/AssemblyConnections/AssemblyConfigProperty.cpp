// $Id$

#include "StdAfx.h"
#include "AssemblyConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "AssemblyConfigProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/Property.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/SimpleProperty.h"
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
  const std::string AssemblyConfigProperty_Impl::metaname ("AssemblyConfigProperty");

  //
  // _create (const ComponentAssembly_in, AssemblyConfigPropertyEnd_in src, Property_in dst)
  //
  AssemblyConfigProperty AssemblyConfigProperty_Impl::_create (const ComponentAssembly_in parent, AssemblyConfigPropertyEnd_in src, Property_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, AssemblyConfigProperty_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void AssemblyConfigProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_AssemblyConfigProperty (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly AssemblyConfigProperty_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
  }

  //
  // AssemblyConfigPropertyEnd
  //
  AssemblyConfigPropertyEnd AssemblyConfigProperty_Impl::src_AssemblyConfigPropertyEnd (void) const
  {
    return AssemblyConfigPropertyEnd::_narrow (this->src ());
  }

  //
  // Property
  //
  Property AssemblyConfigProperty_Impl::dst_Property (void) const
  {
    return Property::_narrow (this->dst ());
  }
}

