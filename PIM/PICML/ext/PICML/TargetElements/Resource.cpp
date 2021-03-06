#include "StdAfx.h"
#include "Resource.h"

#if !defined (__GAME_INLINE__)
#include "Resource.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/TargetElements/Bridge.h"
#include "PICML/TargetElements/Node.h"
#include "PICML/TargetElements/Interconnect.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Resource_Impl::metaname ("Resource");

  //
  // is_abstract
  //
  const bool Resource_Impl::is_abstract = false;

  //
  // _create (const Bridge_in)
  //
  Resource Resource_Impl::_create (const Bridge_in parent)
  {
    return ::GAME::Mga::create < Resource > (parent, Resource_Impl::metaname);
  }

  //
  // _create (const Node_in)
  //
  Resource Resource_Impl::_create (const Node_in parent)
  {
    return ::GAME::Mga::create < Resource > (parent, Resource_Impl::metaname);
  }

  //
  // _create (const Interconnect_in)
  //
  Resource Resource_Impl::_create (const Interconnect_in parent)
  {
    return ::GAME::Mga::create < Resource > (parent, Resource_Impl::metaname);
  }

  //
  // accept
  //
  void Resource_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Resource (this);
    else
      v->visit_Model (this);
  }

  //
  // parent_Bridge
  //
  Bridge Resource_Impl::parent_Bridge (void)
  {
    return Bridge::_narrow (this->parent ());
  }

  //
  // parent_Node
  //
  Node Resource_Impl::parent_Node (void)
  {
    return Node::_narrow (this->parent ());
  }

  //
  // parent_Interconnect
  //
  Interconnect Resource_Impl::parent_Interconnect (void)
  {
    return Interconnect::_narrow (this->parent ());
  }
}

