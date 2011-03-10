// $Id$

#include "stdafx.h"
#include "Finish.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/StateTypes/StateBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/BehaviorInputAction.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Finish_Impl::metaname = "Finish";

  //
  // Finish_Impl
  //
  Finish_Impl::Finish_Impl (void)
  {
  }

  //
  // Finish_Impl
  //
  Finish_Impl::Finish_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Finish_Impl
  //
  Finish_Impl::~Finish_Impl (void)
  {
  }

  //
  // accept
  //
  void Finish_Impl::accept (Visitor * v)
  {
    v->visit_Finish (this);
  }

  //
  // src_StateBase
  //
  StateBase Finish_Impl::src_StateBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return StateBase::_narrow (target);
  }

  //
  // dst_BehaviorInputAction
  //
  BehaviorInputAction Finish_Impl::dst_BehaviorInputAction (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return BehaviorInputAction::_narrow (target);
  }
}

