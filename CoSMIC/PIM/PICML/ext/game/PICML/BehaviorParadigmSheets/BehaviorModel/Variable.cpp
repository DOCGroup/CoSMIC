// $Id$

#include "StdAfx.h"
#include "Variable.h"

#if !defined (__GAME_INLINE__)
#include "Variable.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/PredefinedTypes/PredefinedType.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Variable_Impl::metaname ("Variable");

  //
  // _create (const BehaviorModel_in)
  //
  Variable Variable_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create_object < Variable > (parent, Variable_Impl::metaname);
  }

  //
  // accept
  //
  void Variable_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Variable (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // PredefinedType_is_nil
  //
  bool Variable_Impl::PredefinedType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_PredefinedType
  //
  PredefinedType Variable_Impl::get_PredefinedType (void) const
  {
    return PredefinedType::_narrow (this->refers_to ());
  }
}

