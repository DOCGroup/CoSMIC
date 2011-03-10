// $Id$

#include "stdafx.h"
#include "Latency.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Latency_Impl::metaname = "Latency";

  //
  // Latency_Impl
  //
  Latency_Impl::Latency_Impl (void)
  {
  }

  //
  // Latency_Impl
  //
  Latency_Impl::Latency_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Latency_Impl
  //
  Latency_Impl::~Latency_Impl (void)
  {
  }

  //
  // accept
  //
  void Latency_Impl::accept (Visitor * v)
  {
    v->visit_Latency (this);
  }
}

