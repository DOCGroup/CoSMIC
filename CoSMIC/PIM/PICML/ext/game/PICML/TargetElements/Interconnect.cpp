// $Id$

#include "stdafx.h"
#include "Interconnect.h"

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
  const std::string Interconnect_Impl::metaname = "Interconnect";

  //
  // Interconnect_Impl
  //
  Interconnect_Impl::Interconnect_Impl (void)
  {
  }

  //
  // Interconnect_Impl
  //
  Interconnect_Impl::Interconnect_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Interconnect_Impl
  //
  Interconnect_Impl::~Interconnect_Impl (void)
  {
  }

  //
  // accept
  //
  void Interconnect_Impl::accept (Visitor * v)
  {
    v->visit_Interconnect (this);
  }

  //
  // get_Resources
  //
  size_t Interconnect_Impl::get_Resources (std::vector <Resource> & items) const
  {
    return this->children (items);
  }
}

