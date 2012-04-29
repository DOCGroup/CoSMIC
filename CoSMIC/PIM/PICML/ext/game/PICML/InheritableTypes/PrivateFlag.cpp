// $Id$

#include "StdAfx.h"
#include "PrivateFlag.h"

#if !defined (__GAME_INLINE__)
#include "PrivateFlag.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string PrivateFlag_Impl::metaname ("PrivateFlag");

  //
  // _create (const ObjectByValue_in)
  //
  PrivateFlag PrivateFlag_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create_object < PrivateFlag > (parent, PrivateFlag_Impl::metaname);
  }

  //
  // accept
  //
  void PrivateFlag_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_PrivateFlag (this);
    else
      v->visit_Atom (this);
  }

  //
  // dst_MakeMemberPrivate
  //
  size_t PrivateFlag_Impl::dst_MakeMemberPrivate (std::vector <MakeMemberPrivate> & items) const
  {
    return this->in_connections <MakeMemberPrivate> (items);
  }
}

