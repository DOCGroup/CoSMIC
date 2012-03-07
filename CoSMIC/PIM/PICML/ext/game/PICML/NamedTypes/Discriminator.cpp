// $Id$

#include "StdAfx.h"
#include "Discriminator.h"

#if !defined (__GAME_INLINE__)
#include "Discriminator.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/ConstantType.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Discriminator_Impl::metaname ("Discriminator");

  //
  // _create (const SwitchedAggregate_in)
  //
  Discriminator Discriminator_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create_object < Discriminator > (parent, Discriminator_Impl::metaname);
  }

  //
  // accept
  //
  void Discriminator_Impl::accept (::GAME::Mga::Visitor * v)
  {
    try
    {
      // See if this is a visitor we know.
      Visitor * this_visitor = dynamic_cast <Visitor *> (v);
      this_visitor->visit_Discriminator (this);
    }

    catch (const std::bad_cast & )
    {
      // Fallback to the standard visit method.
      v->visit_Reference (this);
    }
  }

  //
  // ConstantType_is_nil
  //
  bool Discriminator_Impl::ConstantType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // get_ConstantType
  //
  ConstantType Discriminator_Impl::get_ConstantType (void) const
  {
    return ConstantType::_narrow (this->refers_to ());
  }
}

