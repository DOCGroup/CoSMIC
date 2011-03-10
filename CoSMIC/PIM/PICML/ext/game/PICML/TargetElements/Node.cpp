// $Id$

#include "stdafx.h"
#include "Node.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Resource.h"
#include "PICML/TargetElements/NodeReference.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Node_Impl::metaname = "Node";

  //
  // Node_Impl
  //
  Node_Impl::Node_Impl (void)
  {
  }

  //
  // Node_Impl
  //
  Node_Impl::Node_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Node_Impl
  //
  Node_Impl::~Node_Impl (void)
  {
  }

  //
  // accept
  //
  void Node_Impl::accept (Visitor * v)
  {
    v->visit_Node (this);
  }

  //
  // get_Resources
  //
  size_t Node_Impl::get_Resources (std::vector <Resource> & items) const
  {
    return this->children (items);
  }
}

