// $Id$

#include "StdAfx.h"
#include "FloatNumber.h"

#if !defined (__GAME_INLINE__)
#include "FloatNumber.inl"
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
  const std::string FloatNumber_Impl::metaname ("FloatNumber");

  //
  // accept
  //
  void FloatNumber_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_FloatNumber (this);
    else
      v->visit_Atom (this);
  }
}

