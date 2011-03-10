// $Id$

#include "stdafx.h"
#include "ProvidedRequestPortDelegate.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentAssemblySheets/AssemblyConnections/FacetDelegate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ProvidedRequestPortDelegate_Impl::metaname = "ProvidedRequestPortDelegate";

  //
  // ProvidedRequestPortDelegate_Impl
  //
  ProvidedRequestPortDelegate_Impl::ProvidedRequestPortDelegate_Impl (void)
  {
  }

  //
  // ProvidedRequestPortDelegate_Impl
  //
  ProvidedRequestPortDelegate_Impl::ProvidedRequestPortDelegate_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~ProvidedRequestPortDelegate_Impl
  //
  ProvidedRequestPortDelegate_Impl::~ProvidedRequestPortDelegate_Impl (void)
  {
  }

  //
  // accept
  //
  void ProvidedRequestPortDelegate_Impl::accept (Visitor * v)
  {
    v->visit_ProvidedRequestPortDelegate (this);
  }

  //
  // in_FacetDelegate_connections
  //
  size_t ProvidedRequestPortDelegate_Impl::in_FacetDelegate_connections (std::vector <FacetDelegate> & conns) const
  {
    return this->in_connections (conns);
  }
}

