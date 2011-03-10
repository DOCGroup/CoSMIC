// $Id$

#include "stdafx.h"
#include "MirrorPortInstance.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/MirrorPort.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string MirrorPortInstance_Impl::metaname = "MirrorPortInstance";

  //
  // MirrorPortInstance_Impl
  //
  MirrorPortInstance_Impl::MirrorPortInstance_Impl (void)
  {
  }

  //
  // MirrorPortInstance_Impl
  //
  MirrorPortInstance_Impl::MirrorPortInstance_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~MirrorPortInstance_Impl
  //
  MirrorPortInstance_Impl::~MirrorPortInstance_Impl (void)
  {
  }

  //
  // accept
  //
  void MirrorPortInstance_Impl::accept (Visitor * v)
  {
    v->visit_MirrorPortInstance (this);
  }
}

