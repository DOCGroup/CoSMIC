// $Id$

#include "stdafx.h"
#include "AssemblyConfigProperty.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigPropertyEnd.h"
#include "PICML/Common/Property.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string AssemblyConfigProperty_Impl::metaname = "AssemblyConfigProperty";

  //
  // AssemblyConfigProperty_Impl
  //
  AssemblyConfigProperty_Impl::AssemblyConfigProperty_Impl (void)
  {
  }

  //
  // AssemblyConfigProperty_Impl
  //
  AssemblyConfigProperty_Impl::AssemblyConfigProperty_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~AssemblyConfigProperty_Impl
  //
  AssemblyConfigProperty_Impl::~AssemblyConfigProperty_Impl (void)
  {
  }

  //
  // accept
  //
  void AssemblyConfigProperty_Impl::accept (Visitor * v)
  {
    v->visit_AssemblyConfigProperty (this);
  }

  //
  // src_AssemblyConfigPropertyEnd
  //
  AssemblyConfigPropertyEnd AssemblyConfigProperty_Impl::src_AssemblyConfigPropertyEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return AssemblyConfigPropertyEnd::_narrow (target);
  }

  //
  // dst_Property
  //
  Property AssemblyConfigProperty_Impl::dst_Property (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return Property::_narrow (target);
  }
}

