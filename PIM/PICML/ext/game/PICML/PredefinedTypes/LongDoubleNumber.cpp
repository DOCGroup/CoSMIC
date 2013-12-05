// $Id$

#include "StdAfx.h"
#include "LongDoubleNumber.h"

#if !defined (__GAME_INLINE__)
#include "LongDoubleNumber.inl"
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
  const std::string LongDoubleNumber_Impl::metaname ("LongDoubleNumber");

  //
  // _create (const PredefinedTypes_in)
  //
  LongDoubleNumber LongDoubleNumber_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create_root_object < LongDoubleNumber > (parent, LongDoubleNumber_Impl::metaname);
  }

  //
  // accept
  //
  void LongDoubleNumber_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_LongDoubleNumber (this);
    else
      v->visit_Atom (this);
  }
}

