// $Id$

#include "StdAfx.h"
#include "ECBehavior.h"

#if !defined (__GAME_INLINE__)
#include "ECBehavior.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/EventChannelRequirements/ECRequirements.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string ECBehavior_Impl::metaname ("ECBehavior");

  //
  // _create (const ECRequirements_in)
  //
  ECBehavior ECBehavior_Impl::_create (const ECRequirements_in parent)
  {
    return ::GAME::Mga::create_object < ECBehavior > (parent, ECBehavior_Impl::metaname);
  }

  //
  // accept
  //
  void ECBehavior_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_ECBehavior (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Atom (this);
    }
  }
}

