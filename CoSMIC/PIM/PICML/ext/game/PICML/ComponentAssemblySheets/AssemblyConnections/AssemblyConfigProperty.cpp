// $Id$

#include "StdAfx.h"
#include "AssemblyConfigProperty.h"

#if !defined (__GAME_INLINE__)
#include "AssemblyConfigProperty.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/AssemblyConfigPropertyEnd.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/Common/Property.h"
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
  // _create (const ComponentAssembly_in)
  //
  AssemblyConfigProperty AssemblyConfigProperty_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < AssemblyConfigProperty > (parent, AssemblyConfigProperty_Impl::metaname);
  }

  //
  // accept
  //
  void AssemblyConfigProperty_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_AssemblyConfigProperty (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
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

