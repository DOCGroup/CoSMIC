// $Id$

#include "StdAfx.h"
#include "WideChar.h"

#if !defined (__GAME_INLINE__)
#include "WideChar.inl"
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
  const std::string WideChar_Impl::metaname ("WideChar");

  //
  // is_abstract
  //
  const bool WideChar_Impl::is_abstract = false;

  //
  // _create (const PredefinedTypes_in)
  //
  WideChar WideChar_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < WideChar > (parent, WideChar_Impl::metaname);
  }

  //
  // accept
  //
  void WideChar_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WideChar (this);
    else
      v->visit_Atom (this);
  }
}

