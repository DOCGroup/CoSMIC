// $Id$

#include "StdAfx.h"
#include "Byte.h"

#if !defined (__GAME_INLINE__)
#include "Byte.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/PredefinedTypes/PredefinedTypes.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Byte_Impl::metaname ("Byte");

  //
  // _create (const PredefinedTypes_in)
  //
  Byte Byte_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < Byte > (parent, Byte_Impl::metaname);
  }

  //
  // accept
  //
  void Byte_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Byte (this);
    else
      v->visit_Atom (this);
  }
}

