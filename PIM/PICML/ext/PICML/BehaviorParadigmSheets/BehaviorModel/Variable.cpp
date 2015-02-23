// $Id$

#include "StdAfx.h"
#include "Variable.h"

#if !defined (__GAME_INLINE__)
#include "Variable.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/BehaviorParadigmSheets/BehaviorModel/BehaviorModel.h"
#include "PICML/BehaviorParadigmSheets/TopLevelBehaviorModel/TopLevelBehavior.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/PredefinedTypes/PredefinedType.h"
#include "PICML/PredefinedTypes/CharType.h"
#include "PICML/PredefinedTypes/Char.h"
#include "PICML/PredefinedTypes/WideChar.h"
#include "PICML/PredefinedTypes/StringType.h"
#include "PICML/PredefinedTypes/WideString.h"
#include "PICML/PredefinedTypes/String.h"
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
#include "PICML/PredefinedTypes/TypeKind.h"
#include "PICML/PredefinedTypes/TypeEncoding.h"
#include "PICML/PredefinedTypes/GenericValue.h"
#include "PICML/PredefinedTypes/GenericValueObject.h"
#include "PICML/PredefinedTypes/GenericObject.h"
#include "PICML/PredefinedTypes/Boolean.h"
#include "PICML/PredefinedTypes/Byte.h"
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
  // is_abstract
  //
  const bool Variable_Impl::is_abstract = false;

  //
  // _create (const BehaviorModel_in)
  //
  Variable Variable_Impl::_create (const BehaviorModel_in parent)
  {
    return ::GAME::Mga::create < Variable > (parent, Variable_Impl::metaname);
  }

  //
  // accept
  //
  void Variable_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Variable (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_BehaviorModel
  //
  BehaviorModel Variable_Impl::parent_BehaviorModel (void)
  {
    return BehaviorModel::_narrow (this->parent ());
  }

  //
  // PredefinedType_is_nil
  //
  bool Variable_Impl::PredefinedType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_PredefinedType
  //
  void Variable_Impl::refers_to_PredefinedType (PredefinedType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_PredefinedType
  //
  PredefinedType Variable_Impl::refers_to_PredefinedType (void) const
  {
    return PredefinedType::_narrow (this->refers_to ());
  }
}

