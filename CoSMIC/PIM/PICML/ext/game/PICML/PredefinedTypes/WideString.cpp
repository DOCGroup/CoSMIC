// $Id$

#include "StdAfx.h"
#include "WideString.h"

#if !defined (__GAME_INLINE__)
#include "WideString.inl"
#endif

#include "PICML/Visitor.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string WideString_Impl::metaname ("WideString");

  //
  // accept
  //
  void WideString_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_WideString (this);
    else
      v->visit_Atom (this);
  }
}

