// $Id$

#include "stdafx.h"
#include "Bridge.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Resource.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Bridge_Impl::metaname = "Bridge";

  //
  // Bridge_Impl
  //
  Bridge_Impl::Bridge_Impl (void)
  {
  }

  //
  // Bridge_Impl
  //
  Bridge_Impl::Bridge_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Bridge_Impl
  //
  Bridge_Impl::~Bridge_Impl (void)
  {
  }

  //
  // accept
  //
  void Bridge_Impl::accept (Visitor * v)
  {
    v->visit_Bridge (this);
  }

  //
  // get_Resources
  //
  size_t Bridge_Impl::get_Resources (std::vector <Resource> & items) const
  {
    return this->children (items);
  }
}

