// $Id$

#include "StdAfx.h"
#include "UnsignedLongLongInteger.h"

#if !defined (__GAME_INLINE__)
#include "UnsignedLongLongInteger.inl"
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
  const std::string UnsignedLongLongInteger_Impl::metaname ("UnsignedLongLongInteger");

  //
  // _create (const PredefinedTypes_in)
  //
  UnsignedLongLongInteger UnsignedLongLongInteger_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create < UnsignedLongLongInteger > (parent, UnsignedLongLongInteger_Impl::metaname);
  }

  //
  // accept
  //
  void UnsignedLongLongInteger_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_UnsignedLongLongInteger (this);
    else
      v->visit_Atom (this);
  }
}

