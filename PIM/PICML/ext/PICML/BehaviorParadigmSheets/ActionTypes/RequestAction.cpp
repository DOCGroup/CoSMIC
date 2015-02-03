// $Id$

#include "StdAfx.h"
#include "RequestAction.h"

#if !defined (__GAME_INLINE__)
#include "RequestAction.inl"
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
  const std::string RequestAction_Impl::metaname ("RequestAction");

  //
  // is_abstract
  //
  const bool RequestAction_Impl::is_abstract (0);

  //
  // _create (const BehaviorModel_in)
  //
  RequestAction RequestAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create < RequestAction > (parent, RequestAction_Impl::metaname);
  }

  //
  // accept
  //
  void RequestAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_RequestAction (this);
    else
      v->visit_Model (this);
  }
}

