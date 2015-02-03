// $Id$

#include "StdAfx.h"
#include "ShortInteger.h"

#if !defined (__GAME_INLINE__)
#include "ShortInteger.inl"
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
  const std::string ShortInteger_Impl::metaname ("ShortInteger");

  //
  // is_abstract
  //
  const bool ShortInteger_Impl::is_abstract (0);

  //
  // _create (const PredefinedTypes_in)
  //
  ShortInteger ShortInteger_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < ShortInteger > (parent, ShortInteger_Impl::metaname);
  }

  //
  // accept
  //
  void ShortInteger_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ShortInteger (this);
    else
      v->visit_Atom (this);
  }
}

