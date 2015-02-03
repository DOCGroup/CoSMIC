// $Id$

#include "StdAfx.h"
#include "Input.h"

#if !defined (__GAME_INLINE__)
#include "Input.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/SingleInputBase.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/ApplicationTask.h"
#include "PICML/BehaviorParadigmSheets/InputHooks/PeriodicEvent.h"
#include "PICML/ComponentParadigmSheets/ComponentType/InEventPort.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/BehaviorParadigmSheets/ActionTypes/InputAction.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Input_Impl::metaname ("Input");

  //
  // is_abstract
  //
  const bool Input_Impl::is_abstract (0);

  //
  // _create (const TopLevelBehavior_in, SingleInputBase_in src, InputAction_in dst)
  //
  Input Input_Impl::_create (const TopLevelBehavior_in parent, SingleInputBase_in src, InputAction_in dst)
  {
    return ::GAME::Mga::Connection_Impl::_create (parent, Input_Impl::metaname, src, dst);
  }

  //
  // accept
  //
  void Input_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Input (this);
    else
      v->visit_Connection (this);
  }

  //
  // parent_TopLevelBehavior
  //
  TopLevelBehavior Input_Impl::parent_TopLevelBehavior (void)
  {
    return TopLevelBehavior::_narrow (this->parent ());
  }

  //
  // SingleInputBase
  //
  SingleInputBase Input_Impl::src_SingleInputBase (void) const
  {
    return SingleInputBase::_narrow (this->src ());
  }

  //
  // InputAction
  //
  InputAction Input_Impl::dst_InputAction (void) const
  {
    return InputAction::_narrow (this->dst ());
  }
}

