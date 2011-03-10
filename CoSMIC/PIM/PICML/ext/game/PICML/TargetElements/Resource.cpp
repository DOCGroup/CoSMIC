// $Id$

#include "stdafx.h"
#include "Resource.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Bridge.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/Interconnect.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Resource_Impl::metaname = "Resource";

  //
  // Resource_Impl
  //
  Resource_Impl::Resource_Impl (void)
  {
  }

  //
  // Resource_Impl
  //
  Resource_Impl::Resource_Impl (IMgaModel * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Resource_Impl
  //
  Resource_Impl::~Resource_Impl (void)
  {
  }

  //
  // accept
  //
  void Resource_Impl::accept (Visitor * v)
  {
    v->visit_Resource (this);
  }

  //
  // _create
  //
  Resource Resource_Impl::_create (const Bridge_in parent)
  {
    return ::GAME::Mga::create_object <Resource> (parent, Resource_Impl::metaname);
  }

  //
  // _create
  //
  Resource Resource_Impl::_create (const Node_in parent)
  {
    return ::GAME::Mga::create_object <Resource> (parent, Resource_Impl::metaname);
  }

  //
  // _create
  //
  Resource Resource_Impl::_create (const Interconnect_in parent)
  {
    return ::GAME::Mga::create_object <Resource> (parent, Resource_Impl::metaname);
  }

  //
  // parent_Bridge
  //
  Bridge Resource_Impl::parent_Bridge (void) const
  {
    return ::GAME::Mga::get_parent <Bridge> (this->object_.p);
  }

  //
  // parent_Node
  //
  Node Resource_Impl::parent_Node (void) const
  {
    return ::GAME::Mga::get_parent <Node> (this->object_.p);
  }

  //
  // parent_Interconnect
  //
  Interconnect Resource_Impl::parent_Interconnect (void) const
  {
    return ::GAME::Mga::get_parent <Interconnect> (this->object_.p);
  }
}

