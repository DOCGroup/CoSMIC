// $Id$

#include "stdafx.h"
#include "Key.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/KeyMember.h"
#include "PICML/NamedTypes/Aggregate.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Key_Impl::metaname = "Key";

  //
  // Key_Impl
  //
  Key_Impl::Key_Impl (void)
  {
  }

  //
  // Key_Impl
  //
  Key_Impl::Key_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Key_Impl
  //
  Key_Impl::~Key_Impl (void)
  {
  }

  //
  // accept
  //
  void Key_Impl::accept (Visitor * v)
  {
    v->visit_Key (this);
  }

  //
  // _create
  //
  Key Key_Impl::_create (const Aggregate_in parent)
  {
    return ::GAME::Mga::create_object <Key> (parent, Key_Impl::metaname);
  }

  //
  // in_KeyMember_connections
  //
  size_t Key_Impl::in_KeyMember_connections (std::vector <KeyMember> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_Aggregate
  //
  Aggregate Key_Impl::parent_Aggregate (void) const
  {
    return ::GAME::Mga::get_parent <Aggregate> (this->object_.p);
  }
}

