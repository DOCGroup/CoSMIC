// $Id$

#include "StdAfx.h"
#include "Invoke.h"

#if !defined (__GAME_INLINE__)
#include "Invoke.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Invoke_Impl::metaname ("Invoke");

  //
  // _create (const ComponentAssembly_in)
  //
  Invoke Invoke_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < Invoke > (parent, Invoke_Impl::metaname);
  }

  //
  // accept
  //
  void Invoke_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Invoke (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // RequiredRequestPortEnd
  //
  RequiredRequestPortEnd Invoke_Impl::src_RequiredRequestPortEnd (void) const
  {
    return RequiredRequestPortEnd::_narrow (this->src ());
  }

  //
  // ProvidedRequestPortEnd
  //
  ProvidedRequestPortEnd Invoke_Impl::dst_ProvidedRequestPortEnd (void) const
  {
    return ProvidedRequestPortEnd::_narrow (this->dst ());
  }
}

