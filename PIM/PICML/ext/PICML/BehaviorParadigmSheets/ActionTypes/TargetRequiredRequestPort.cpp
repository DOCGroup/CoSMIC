// $Id$

#include "StdAfx.h"
#include "TargetRequiredRequestPort.h"

#if !defined (__GAME_INLINE__)
#include "TargetRequiredRequestPort.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/ComponentParadigmSheets/ComponentType/RequiredRequestPort.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/CallAction.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string TargetRequiredRequestPort_Impl::metaname ("TargetRequiredRequestPort");

  //
  // is_abstract
  //
  const bool TargetRequiredRequestPort_Impl::is_abstract (0);

  //
  // _create (const CallAction_in)
  //
  TargetRequiredRequestPort TargetRequiredRequestPort_Impl::_create (const CallAction_in parent)
  {
    return ::GAME::Mga::create < TargetRequiredRequestPort > (parent, TargetRequiredRequestPort_Impl::metaname);
  }

  //
  // accept
  //
  void TargetRequiredRequestPort_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_TargetRequiredRequestPort (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_CallAction
  //
  CallAction TargetRequiredRequestPort_Impl::parent_CallAction (void)
  {
    return CallAction::_narrow (this->parent ());
  }

  //
  // RequiredRequestPort_is_nil
  //
  bool TargetRequiredRequestPort_Impl::RequiredRequestPort_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_RequiredRequestPort
  //
  void TargetRequiredRequestPort_Impl::refers_to_RequiredRequestPort (RequiredRequestPort_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_RequiredRequestPort
  //
  RequiredRequestPort TargetRequiredRequestPort_Impl::refers_to_RequiredRequestPort (void) const
  {
    return RequiredRequestPort::_narrow (this->refers_to ());
  }
}

