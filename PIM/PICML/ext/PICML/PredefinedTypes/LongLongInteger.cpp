// $Id$

#include "StdAfx.h"
#include "LongLongInteger.h"

#if !defined (__GAME_INLINE__)
#include "LongLongInteger.inl"
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
  const std::string LongLongInteger_Impl::metaname ("LongLongInteger");

  //
  // is_abstract
  //
  const bool LongLongInteger_Impl::is_abstract (0);

  //
  // _create (const PredefinedTypes_in)
  //
  LongLongInteger LongLongInteger_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < LongLongInteger > (parent, LongLongInteger_Impl::metaname);
  }

  //
  // accept
  //
  void LongLongInteger_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LongLongInteger (this);
    else
      v->visit_Atom (this);
  }
}

