// $Id$

#include "StdAfx.h"
#include "UnsignedLongInteger.h"

#if !defined (__GAME_INLINE__)
#include "UnsignedLongInteger.inl"
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
  const std::string UnsignedLongInteger_Impl::metaname ("UnsignedLongInteger");

  //
  // _create (const PredefinedTypes_in)
  //
  UnsignedLongInteger UnsignedLongInteger_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < UnsignedLongInteger > (parent, UnsignedLongInteger_Impl::metaname);
  }

  //
  // accept
  //
  void UnsignedLongInteger_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_UnsignedLongInteger (this);
    else
      v->visit_Atom (this);
  }
}

