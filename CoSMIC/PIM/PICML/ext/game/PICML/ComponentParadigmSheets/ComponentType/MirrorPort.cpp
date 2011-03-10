// $Id$

#include "stdafx.h"
#include "MirrorPort.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPort_Impl::metaname = "MirrorPort";

  //
  // MirrorPort_Impl
  //
  MirrorPort_Impl::MirrorPort_Impl (void)
  {
  }

  //
  // MirrorPort_Impl
  //
  MirrorPort_Impl::MirrorPort_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MirrorPort_Impl
  //
  MirrorPort_Impl::~MirrorPort_Impl (void)
  {
  }

  //
  // accept
  //
  void MirrorPort_Impl::accept (Visitor * v)
  {
    v->visit_MirrorPort (this);
  }
}

