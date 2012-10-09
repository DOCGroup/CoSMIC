// $Id$

#include "StdAfx.h"
#include "UnsignedShortInteger.h"

#if !defined (__GAME_INLINE__)
#include "UnsignedShortInteger.inl"
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
  const std::string UnsignedShortInteger_Impl::metaname ("UnsignedShortInteger");

  //
  // _create (const PredefinedTypes_in)
  //
  UnsignedShortInteger UnsignedShortInteger_Impl::_create (const PredefinedTypes_in parent)
  {
    return ::GAME::Mga::create_root_object < UnsignedShortInteger > (parent, UnsignedShortInteger_Impl::metaname);
  }

  //
  // accept
  //
  void UnsignedShortInteger_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_UnsignedShortInteger (this);
    else
      v->visit_Atom (this);
  }
}

