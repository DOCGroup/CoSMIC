#include "StdAfx.h"
#include "FacetDelegate.h"

#if !defined (__GAME_INLINE__)
#include "FacetDelegate.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/ComponentAssembly/ComponentAssembly.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/ProvidedRequestPortInstance.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortDelegate.h"
#include "PICML/ComponentParadigmSheets/ComponentInstance/SupportsInstance.h"
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
  // is_abstract
  //
  const bool FacetDelegate_Impl::is_abstract = false;

  //
  // _create (const ComponentAssembly_in, ProvidedRequestPortDelegate_in src, ProvidedRequestPortEnd_in dst)
  //
  FacetDelegate FacetDelegate_Impl::_create (const ComponentAssembly_in parent, ProvidedRequestPortDelegate_in src, ProvidedRequestPortEnd_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, FacetDelegate_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void FacetDelegate_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_FacetDelegate (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_ComponentAssembly
  //
  ComponentAssembly FacetDelegate_Impl::parent_ComponentAssembly (void)
  {
    return ComponentAssembly::_narrow (this->parent ());
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

