// $Id$

#include "StdAfx.h"
#include "Invoke.h"

#if !defined (__GAME_INLINE__)
#include "Invoke.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ProvidedRequestPortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/SupportsInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortEnd.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/RequiredRequestPortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/RequiredRequestPortDelegate.h"
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
  // is_abstract
  //
  const bool Invoke_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in, RequiredRequestPortEnd_in src, ProvidedRequestPortEnd_in dst)
  //
  Invoke Invoke_Impl::_create (const ComponentAssembly_in parent, RequiredRequestPortEnd_in src, ProvidedRequestPortEnd_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, Invoke_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void Invoke_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Invoke (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly Invoke_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
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

