// $Id$

#include "StdAfx.h"
#include "Finish.h"

#if !defined (__GAME_INLINE__)
#include "Finish.inl"
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
  const std::string Finish_Impl::metaname ("Finish");

  //
  // _create (const BehaviorModel_in)
  //
  Finish Finish_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < Finish > (parent, Finish_Impl::metaname);
  }

  //
  // accept
  //
  void Finish_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Finish (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Connection (this);
    }
  }

  //
  // StateBase
  //
  StateBase Finish_Impl::src_StateBase (void) const
  {
    return StateBase::_narrow (this->src ());
  }

  //
  // BehaviorInputAction
  //
  BehaviorInputAction Finish_Impl::dst_BehaviorInputAction (void) const
  {
    return BehaviorInputAction::_narrow (this->dst ());
  }
}

