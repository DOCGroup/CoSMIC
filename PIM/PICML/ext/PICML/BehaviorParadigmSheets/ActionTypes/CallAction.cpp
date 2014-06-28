// $Id$

#include "StdAfx.h"
#include "CallAction.h"

#if !defined (__GAME_INLINE__)
#include "CallAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/TargetRequiredRequestPort.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string CallAction_Impl::metaname ("CallAction");

  //
  // _create (const BehaviorModel_in)
  //
  CallAction CallAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < CallAction > (parent, CallAction_Impl::metaname);
  }

  //
  // accept
  //
  void CallAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_CallAction (this);
    else
      v->visit_Model (this);
  }

  //
  // has_TargetRequiredRequestPort
  //
  bool CallAction_Impl::has_TargetRequiredRequestPort (void) const
  {
    return this->children <TargetRequiredRequestPort> ().count () == 1;
  }

  //
  // get_TargetRequiredRequestPort
  //
  TargetRequiredRequestPort CallAction_Impl::get_TargetRequiredRequestPort (void) const
  {
    return this->children <TargetRequiredRequestPort> ().first ();
  }
}

