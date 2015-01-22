// $Id$

#include "StdAfx.h"
#include "Boolean.h"

#if !defined (__GAME_INLINE__)
#include "Boolean.inl"
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
  const std::string Boolean_Impl::metaname ("Boolean");

  //
  // _create (const PredefinedTypes_in)
  //
  Boolean Boolean_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < Boolean > (parent, Boolean_Impl::metaname);
  }

  //
  // accept
  //
  void Boolean_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Boolean (this);
    else
      v->visit_Atom (this);
  }
}

