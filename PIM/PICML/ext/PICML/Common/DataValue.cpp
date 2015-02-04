// $Id$

#include "StdAfx.h"
#include "DataValue.h"

#if !defined (__GAME_INLINE__)
#include "DataValue.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/Common/SimpleType.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/PredefinedTypes/PredefinedType.h"
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
#include "PICML/PredefinedTypes/CharType.h"
#include "PICML/PredefinedTypes/Char.h"
#include "PICML/PredefinedTypes/WideChar.h"
#include "PICML/PredefinedTypes/StringType.h"
#include "PICML/PredefinedTypes/String.h"
#include "PICML/PredefinedTypes/WideString.h"
#include "PICML/PredefinedTypes/IntegerType.h"
#include "PICML/PredefinedTypes/UnsignedIntegerType.h"
#include "PICML/PredefinedTypes/UnsignedShortInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongInteger.h"
#include "PICML/PredefinedTypes/UnsignedLongLongInteger.h"
#include "PICML/PredefinedTypes/SignedIntegerType.h"
#include "PICML/PredefinedTypes/LongInteger.h"
#include "PICML/PredefinedTypes/ShortInteger.h"
#include "PICML/PredefinedTypes/LongLongInteger.h"
#include "PICML/Common/ComplexProperty.h"
#include "PICML/Common/DataValueContainer.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string DataValue_Impl::metaname ("DataValue");

  //
  // is_abstract
  //
  const bool DataValue_Impl::is_abstract = false;

  //
  // _create (const ComplexProperty_in)
  //
  DataValue DataValue_Impl::_create (const ComplexProperty_in parent)
  {
    return ::GAME::Mga::create < DataValue > (parent, DataValue_Impl::metaname);
  }

  //
  // _create (const DataValueContainer_in)
  //
  DataValue DataValue_Impl::_create (const DataValueContainer_in parent)
  {
    return ::GAME::Mga::create < DataValue > (parent, DataValue_Impl::metaname);
  }

  //
  // accept
  //
  void DataValue_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_DataValue (this);
    else
      v->visit_Reference (this);
  }

  //
  // SimpleType_is_nil
  //
  bool DataValue_Impl::SimpleType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // refers_to_SimpleType
  //
  void DataValue_Impl::refers_to_SimpleType (SimpleType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_SimpleType
  //
  SimpleType DataValue_Impl::refers_to_SimpleType (void) const
  {
    return SimpleType::_narrow (this->refers_to ());
  }
}

