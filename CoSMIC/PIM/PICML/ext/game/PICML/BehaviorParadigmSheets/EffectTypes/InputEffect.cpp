// $Id$

#include "StdAfx.h"
#include "InputEffect.h"

#if !defined (__GAME_INLINE__)
#include "InputEffect.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InputEffect_Impl::metaname ("InputEffect");

  //
  // _create (const BehaviorModel_in)
  //
  InputEffect InputEffect_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < InputEffect > (parent, InputEffect_Impl::metaname);
  }

  //
  // accept
  //
  void InputEffect_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InputEffect (this);
    else
      v->visit_Connection (this);
  }

  //
  // BehaviorInputAction
  //
  BehaviorInputAction InputEffect_Impl::src_BehaviorInputAction (void) const
  {
    return BehaviorInputAction::_narrow (this->src ());
  }

  //
  // StateBase
  //
  StateBase InputEffect_Impl::dst_StateBase (void) const
  {
    return StateBase::_narrow (this->dst ());
  }
}

