// $Id$

#include "stdafx.h"
#include "Throughput.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Throughput_Impl::metaname = "Throughput";

  //
  // Throughput_Impl
  //
  Throughput_Impl::Throughput_Impl (void)
  {
  }

  //
  // Throughput_Impl
  //
  Throughput_Impl::Throughput_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Throughput_Impl
  //
  Throughput_Impl::~Throughput_Impl (void)
  {
  }

  //
  // accept
  //
  void Throughput_Impl::accept (Visitor * v)
  {
    v->visit_Throughput (this);
  }
}

