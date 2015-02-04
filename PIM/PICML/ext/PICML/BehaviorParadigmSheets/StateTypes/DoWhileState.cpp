// $Id$

#include "StdAfx.h"
#include "DoWhileState.h"

#if !defined (__GAME_INLINE__)
#include "DoWhileState.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string DoWhileState_Impl::metaname ("DoWhileState");

  //
  // is_abstract
  //
  const bool DoWhileState_Impl::is_abstract = false;

  //
  // _create (const BehaviorModel_in)
  //
  DoWhileState DoWhileState_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create < DoWhileState > (parent, DoWhileState_Impl::metaname);
  }

  //
  // accept
  //
  void DoWhileState_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DoWhileState (this);
    else
      v->visit_Atom (this);
  }
}

