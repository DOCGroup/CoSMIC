// $Id$

#include "StdAfx.h"
#include "RequestAction.h"

#if !defined (__GAME_INLINE__)
#include "RequestAction.inl"
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
  const std::string RequestAction_Impl::metaname ("RequestAction");

  //
  // _create (const BehaviorModel_in)
  //
  RequestAction RequestAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < RequestAction > (parent, RequestAction_Impl::metaname);
  }

  //
  // _create (const ActionBase_in)
  //
  RequestAction RequestAction_Impl::_create (const ActionBase_in parent)
  {
    return ::GAME::Mga::create_object < RequestAction > (parent, RequestAction_Impl::metaname);
  }

  //
  // accept
  //
  void RequestAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_RequestAction (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Model (this);
    }
  }
}

