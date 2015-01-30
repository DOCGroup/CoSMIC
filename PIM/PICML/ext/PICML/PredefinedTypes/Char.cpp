// $Id$

#include "StdAfx.h"
#include "Char.h"

#if !defined (__GAME_INLINE__)
#include "Char.inl"
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
  const std::string Char_Impl::metaname ("Char");

  //
  // _create (const PredefinedTypes_in)
  //
  Char Char_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < Char > (parent, Char_Impl::metaname);
  }

  //
  // accept
  //
  void Char_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Char (this);
    else
      v->visit_Atom (this);
  }
}

