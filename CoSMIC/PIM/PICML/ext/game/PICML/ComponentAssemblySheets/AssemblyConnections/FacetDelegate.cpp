// $Id$

#include "stdafx.h"
#include "FacetDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortDelegate.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/ProvidedRequestPortEnd.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string FacetDelegate_Impl::metaname = "FacetDelegate";

  //
  // FacetDelegate_Impl
  //
  FacetDelegate_Impl::FacetDelegate_Impl (void)
  {
  }

  //
  // FacetDelegate_Impl
  //
  FacetDelegate_Impl::FacetDelegate_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~FacetDelegate_Impl
  //
  FacetDelegate_Impl::~FacetDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void FacetDelegate_Impl::accept (Visitor * v)
  {
    v->visit_FacetDelegate (this);
  }

  //
  // src_ProvidedRequestPortDelegate
  //
  ProvidedRequestPortDelegate FacetDelegate_Impl::src_ProvidedRequestPortDelegate (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return ProvidedRequestPortDelegate::_narrow (target);
  }

  //
  // dst_ProvidedRequestPortEnd
  //
  ProvidedRequestPortEnd FacetDelegate_Impl::dst_ProvidedRequestPortEnd (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return ProvidedRequestPortEnd::_narrow (target);
  }
}

