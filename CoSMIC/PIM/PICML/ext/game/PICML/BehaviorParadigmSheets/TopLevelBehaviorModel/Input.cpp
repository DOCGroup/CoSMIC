// $Id$

#include "stdafx.h"
#include "Input.h"

#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/Functional_T.h"

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/SingleInputBase.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/InputAction.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string Input_Impl::metaname = "Input";

  //
  // Input_Impl
  //
  Input_Impl::Input_Impl (void)
  {
  }

  //
  // Input_Impl
  //
  Input_Impl::Input_Impl (IMgaConnection * ptr)
  {
    this->object_ = ptr;
  }

  //
  // ~Input_Impl
  //
  Input_Impl::~Input_Impl (void)
  {
  }

  //
  // accept
  //
  void Input_Impl::accept (Visitor * v)
  {
    v->visit_Input (this);
  }

  //
  // _create
  //
  Input Input_Impl::_create (const TopLevelBehavior_in parent)
  {
    return ::GAME::Mga::create_object <Input> (parent, Input_Impl::metaname);
  }

  //
  // src_SingleInputBase
  //
  SingleInputBase Input_Impl::src_SingleInputBase (void)
  {
    GAME::Mga::FCO target = this->connection_point ("src")->target ();
    return SingleInputBase::_narrow (target);
  }

  //
  // dst_InputAction
  //
  InputAction Input_Impl::dst_InputAction (void)
  {
    GAME::Mga::FCO target = this->connection_point ("dst")->target ();
    return InputAction::_narrow (target);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior Input_Impl::parent_TopLevelBehavior (void) const
  {
    return ::GAME::Mga::get_parent <TopLevelBehavior> (this->object_.p);
  }
}

