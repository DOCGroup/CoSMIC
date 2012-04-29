// $Id$

#include "StdAfx.h"
#include "ECRole.h"

#if !defined (__GAME_INLINE__)
#include "ECRole.inl"
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
  const std::string ECRole_Impl::metaname ("ECRole");

  //
  // _create (const ECRequirements_in)
  //
  ECRole ECRole_Impl::_create (const ECRequirements_in parent)
  {
    return ::GAME::Mga::create_object < ECRole > (parent, ECRole_Impl::metaname);
  }

  //
  // accept
  //
  void ECRole_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_ECRole (this);
    else
      v->visit_Atom (this);
  }
}

