// $Id$

#include "StdAfx.h"
#include "QueryAction.h"

#if !defined (__GAME_INLINE__)
#include "QueryAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/ActionBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string QueryAction_Impl::metaname ("QueryAction");

  //
  // _create (const BehaviorModel_in)
  //
  QueryAction QueryAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < QueryAction > (parent, QueryAction_Impl::metaname);
  }

  //
  // _create (const ActionBase_in)
  //
  QueryAction QueryAction_Impl::_create (const ActionBase_in parent)
  {
    return ::GAME::Mga::create_object < QueryAction > (parent, QueryAction_Impl::metaname);
  }

  //
  // accept
  //
  void QueryAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_QueryAction (this);
    else
      v->visit_Model (this);
  }
}

