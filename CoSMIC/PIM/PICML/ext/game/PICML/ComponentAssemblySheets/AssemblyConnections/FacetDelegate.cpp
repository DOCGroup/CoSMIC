// $Id$

#include "StdAfx.h"
#include "FacetDelegate.h"

#if !defined (__GAME_INLINE__)
#include "FacetDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortDelegate.h"
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
  const std::string FacetDelegate_Impl::metaname ("FacetDelegate");

  //
  // _create (const ComponentAssembly_in)
  //
  FacetDelegate FacetDelegate_Impl::_create (const ComponentAssembly_in parent)
  {
    return ::GAME::Mga::create_object < FacetDelegate > (parent, FacetDelegate_Impl::metaname);
  }

  //
  // accept
  //
  void FacetDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_FacetDelegate (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // ProvidedRequestPortDelegate
  //
  ProvidedRequestPortDelegate FacetDelegate_Impl::src_ProvidedRequestPortDelegate (void) const
  {
    return ProvidedRequestPortDelegate::_narrow (this->src ());
  }

  //
  // ProvidedRequestPortEnd
  //
  ProvidedRequestPortEnd FacetDelegate_Impl::dst_ProvidedRequestPortEnd (void) const
  {
    return ProvidedRequestPortEnd::_narrow (this->dst ());
  }
}

