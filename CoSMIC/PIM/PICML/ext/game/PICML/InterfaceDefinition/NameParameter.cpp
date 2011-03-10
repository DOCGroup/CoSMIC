// $Id$

#include "stdafx.h"
#include "NameParameter.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string NameParameter_Impl::metaname = "NameParameter";

  //
  // NameParameter_Impl
  //
  NameParameter_Impl::NameParameter_Impl (void)
  {
  }

  //
  // NameParameter_Impl
  //
  NameParameter_Impl::NameParameter_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~NameParameter_Impl
  //
  NameParameter_Impl::~NameParameter_Impl (void)
  {
  }

  //
  // accept
  //
  void NameParameter_Impl::accept (Visitor * v)
  {
    v->visit_NameParameter (this);
  }
}

