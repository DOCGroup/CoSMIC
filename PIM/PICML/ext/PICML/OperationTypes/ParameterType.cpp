#include "StdAfx.h"
#include "ParameterType.h"

#if !defined (__GAME_INLINE__)
#include "ParameterType.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/WorkloadParadigmSheets/WML/Operation.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/TemplateParameterReference.h"
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
#include "PICML/NamedTypes/NamedType.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/NamedTypes/Boxed.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/NamedTypes/Collection.h"

namespace PICML
{
  //
  // metaname
  //
  const std::string ParameterType_Impl::metaname ("ParameterType");

  //
  // is_abstract
  //
  const bool ParameterType_Impl::is_abstract = true;

  //
  // parent_Operation
  //
  Operation ParameterType_Impl::parent_Operation (void)
  {
    return Operation::_narrow (this->parent ());
  }

  //
  // MemberType_is_nil
  //
  bool ParameterType_Impl::MemberType_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_MemberType
  //
  void ParameterType_Impl::refers_to_MemberType (MemberType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_MemberType
  //
  MemberType ParameterType_Impl::refers_to_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

