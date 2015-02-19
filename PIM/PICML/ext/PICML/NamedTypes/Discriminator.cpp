// $Id$

#include "StdAfx.h"
#include "Discriminator.h"

#if !defined (__GAME_INLINE__)
#include "Discriminator.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/InterfaceDefinition/ConstantType.h"
#include "PICML/PredefinedTypes/CharType.h"
#include "PICML/PredefinedTypes/Char.h"
#include "PICML/PredefinedTypes/WideChar.h"
#include "PICML/PredefinedTypes/StringType.h"
#include "PICML/PredefinedTypes/WideString.h"
#include "PICML/PredefinedTypes/String.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/PredefinedTypes/IntegerType.h"
#include "PICML/PredefinedTypes/UnsignedIntegerType.h"
#include "PICML/PredefinedTypes/UnsignedShortInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongLongInteger.h"
#include "PICML/PredefinedTypes/SignedIntegerType.h"
#include "PICML/PredefinedTypes/LongLongInteger.h"
#include "PICML/PredefinedTypes/LongInteger.h"
#include "PICML/PredefinedTypes/ShortInteger.h"
#include "PICML/PredefinedTypes/FloatingPointType.h"
#include "PICML/PredefinedTypes/LongDoubleNumber.h"
#include "PICML/PredefinedTypes/DoubleNumber.h"
#include "PICML/PredefinedTypes/FloatNumber.h"
#include "PICML/PredefinedTypes/Boolean.h"
#include "PICML/PredefinedTypes/Byte.h"
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
  // is_abstract
  //
  const bool Discriminator_Impl::is_abstract = false;

  //
  // _create (const SwitchedAggregate_in)
  //
  Discriminator Discriminator_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create < Discriminator > (parent, Discriminator_Impl::metaname);
  }

  //
  // accept
  //
  void Discriminator_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Discriminator (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_SwitchedAggregate
  //
  SwitchedAggregate Discriminator_Impl::parent_SwitchedAggregate (void)
  {
    return SwitchedAggregate::_narrow (this->parent ());
  }

  //
  // ConstantType_is_nil
  //
  bool Discriminator_Impl::ConstantType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_ConstantType
  //
  void Discriminator_Impl::refers_to_ConstantType (ConstantType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_ConstantType
  //
  ConstantType Discriminator_Impl::refers_to_ConstantType (void) const
  {
    return ConstantType::_narrow (this->refers_to ());
  }
}

