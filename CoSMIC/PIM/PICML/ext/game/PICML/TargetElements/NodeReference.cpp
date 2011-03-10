// $Id$

#include "stdafx.h"
#include "NodeReference.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Node.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string NodeReference_Impl::metaname = "NodeReference";

  //
  // NodeReference_Impl
  //
  NodeReference_Impl::NodeReference_Impl (void)
  {
  }

  //
  // NodeReference_Impl
  //
  NodeReference_Impl::NodeReference_Impl (IMgaReference * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~NodeReference_Impl
  //
  NodeReference_Impl::~NodeReference_Impl (void)
  {
  }

  //
  // accept
  //
  void NodeReference_Impl::accept (Visitor * v)
  {
    v->visit_NodeReference (this);
  }

  //
  // refers_to_Node
  //
  Node NodeReference_Impl::refers_to_Node (void) const
  {
    return ::GAME::Mga::get_refers_to <Node> (this);
  }
}

