// $Id$

#include "StdAfx.h"
#include "UnsignedShortInteger.h"

#if !defined (__GAME_INLINE__)
#include "UnsignedShortInteger.inl"
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
  const std::string UnsignedShortInteger_Impl::metaname ("UnsignedShortInteger");

  //
  // accept
  //
  void UnsignedShortInteger_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_UnsignedShortInteger (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

