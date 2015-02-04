// $Id$

#include "StdAfx.h"
#include "String.h"

#if !defined (__GAME_INLINE__)
#include "String.inl"
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
  const std::string String_Impl::metaname ("String");

  //
  // is_abstract
  //
  const bool String_Impl::is_abstract = false;

  //
  // _create (const PredefinedTypes_in)
  //
  String String_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < String > (parent, String_Impl::metaname);
  }

  //
  // accept
  //
  void String_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_String (this);
    else
      v->visit_Atom (this);
  }
}

