// $Id$

#include "StdAfx.h"
#include "LongInteger.h"

#if !defined (__GAME_INLINE__)
#include "LongInteger.inl"
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
  const std::string LongInteger_Impl::metaname ("LongInteger");

  //
  // is_abstract
  //
  const bool LongInteger_Impl::is_abstract (0);

  //
  // _create (const PredefinedTypes_in)
  //
  LongInteger LongInteger_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < LongInteger > (parent, LongInteger_Impl::metaname);
  }

  //
  // accept
  //
  void LongInteger_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LongInteger (this);
    else
      v->visit_Atom (this);
  }
}

