// $Id$

#include "StdAfx.h"
#include "Alias.h"

#if !defined (__GAME_INLINE__)
#include "Alias.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/MemberType.h"
#include "PICML/NamedTypes/NamedType.h"
#include "PICML/InheritableTypes/Inheritable.h"
#include "PICML/InheritableTypes/HasOperations.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/NamedTypes/Collection.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ConnectorParadigmSheets/ConnectorInterface/ConnectorObject.h"
#include "PICML/NamedTypes/Boxed.h"
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
#include "PICML/InterfaceDefinition/TemplateParameterReference.h"
#include "PICML/InterfaceDefinition/TemplateParameter.h"
#include "PICML/InterfaceDefinition/CollectionParameter.h"
#include "PICML/InterfaceDefinition/TypeParameter.h"
#include "PICML/InterfaceDefinition/NameParameter.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/InterfaceDefinition/Package.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Alias_Impl::metaname ("Alias");

  //
  // _create (const HasOperations_in)
  //
  Alias Alias_Impl::_create (const HasOperations_in parent)
  {
    return ::GAME::Mga::create_object < Alias > (parent, Alias_Impl::metaname);
  }

  //
  // _create (const File_in)
  //
  Alias Alias_Impl::_create (const File_in parent)
  {
    return ::GAME::Mga::create_object < Alias > (parent, Alias_Impl::metaname);
  }

  //
  // _create (const Package_in)
  //
  Alias Alias_Impl::_create (const Package_in parent)
  {
    return ::GAME::Mga::create_object < Alias > (parent, Alias_Impl::metaname);
  }

  //
  // accept
  //
  void Alias_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Alias (this);
    else
      v->visit_Reference (this);
  }

  //
  // MemberType_is_nil
  //
  bool Alias_Impl::MemberType_is_nil (void) const
  {
    return !this->refers_to ().is_nil ();
  }

  //
  // set_MemberType
  //
  void Alias_Impl::set_MemberType (MemberType_in item)
  {
    this->refers_to (item);
  }

  //
  // get_MemberType
  //
  MemberType Alias_Impl::get_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

