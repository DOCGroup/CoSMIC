// $Id$

#include "StdAfx.h"
#include "InputAction.h"

#if !defined (__GAME_INLINE__)
#include "InputAction.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/Input.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string InputAction_Impl::metaname ("InputAction");

  //
  // _create (const BehaviorModel_in)
  //
  InputAction InputAction_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create < InputAction > (parent, InputAction_Impl::metaname);
  }

  //
  // accept
  //
  void InputAction_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_InputAction (this);
    else
      v->visit_Model (this);
  }

  //
  // dst_of_Input
  //
  size_t InputAction_Impl::dst_of_Input (std::vector <Input> & items) const
  {
    return this->in_connections <Input> (items);
  }

  //
  // dst_of_Input
  //
  GAME::Mga::Collection_T <Input> InputAction_Impl::dst_of_Input (void) const
  {
    return this->in_connections <Input> ("dst");
  }
}

