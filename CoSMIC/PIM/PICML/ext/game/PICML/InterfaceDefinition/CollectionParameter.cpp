// $Id$

#include "stdafx.h"
#include "CollectionParameter.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/NameParameter.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string CollectionParameter_Impl::metaname = "CollectionParameter";

  //
  // CollectionParameter_Impl
  //
  CollectionParameter_Impl::CollectionParameter_Impl (void)
  {
  }

  //
  // CollectionParameter_Impl
  //
  CollectionParameter_Impl::CollectionParameter_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~CollectionParameter_Impl
  //
  CollectionParameter_Impl::~CollectionParameter_Impl (void)
  {
  }

  //
  // accept
  //
  void CollectionParameter_Impl::accept (Visitor * v)
  {
    v->visit_CollectionParameter (this);
  }

  //
  // refers_to_NameParameter
  //
  NameParameter CollectionParameter_Impl::refers_to_NameParameter (void) const
  {
    return ::GAME::Mga::get_refers_to <NameParameter> (this);
  }
}

