// $Id$

#include "stdafx.h"
#include "PrivateFlag.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"
#include "PICML/InheritableTypes/ObjectByValue.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string PrivateFlag_Impl::metaname = "PrivateFlag";

  //
  // PrivateFlag_Impl
  //
  PrivateFlag_Impl::PrivateFlag_Impl (void)
  {
  }

  //
  // PrivateFlag_Impl
  //
  PrivateFlag_Impl::PrivateFlag_Impl (IMgaAtom * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~PrivateFlag_Impl
  //
  PrivateFlag_Impl::~PrivateFlag_Impl (void)
  {
  }

  //
  // accept
  //
  void PrivateFlag_Impl::accept (Visitor * v)
  {
    v->visit_PrivateFlag (this);
  }

  //
  // _create
  //
  PrivateFlag PrivateFlag_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create_object <PrivateFlag> (parent, PrivateFlag_Impl::metaname);
  }

  //
  // in_MakeMemberPrivate_connections
  //
  size_t PrivateFlag_Impl::in_MakeMemberPrivate_connections (std::vector <MakeMemberPrivate> & conns) const
  {
    return this->in_connections (conns);
  }

  //
  // parent_ObjectByValue
  //
  ObjectByValue PrivateFlag_Impl::parent_ObjectByValue (void) const
  {
    return ::GAME::Mga::get_parent <ObjectByValue> (this->object_.p);
  }
}

