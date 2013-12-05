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
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ECBehavior (this);
    else
      v->visit_Atom (this);
  }

  //
  // parent_ECRequirements
  //
  ECRequirements ECBehavior_Impl::parent_ECRequirements (void)
  {
    return ECRequirements::_narrow (this->parent ());
  }
}

