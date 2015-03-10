// $Id$

#include "StdAfx.h"
#include "Member.h"

#if !defined (__GAME_INLINE__)
#include "Member.inl"
#endif

#include "PICML/Visitor.h"
#include "PICML/NamedTypes/Aggregate.h"
#include "PICML/InheritableTypes/ObjectByValue.h"
#include "PICML/InheritableTypes/Event.h"
#include "PICML/InheritableTypes/ValueObject.h"
#include "PICML/NamedTypes/SwitchedAggregate.h"
#include "PICML/InterfaceDefinition/Exception.h"
#include "PICML/InheritableTypes/MakeMemberPrivate.h"
#include "PICML/NamedTypes/LabelConnection.h"
#include "PICML/NamedTypes/KeyMember.h"
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
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentFactory.h"
#include "PICML/InheritableTypes/Object.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/NamedTypes/NoInheritable.h"
#include "PICML/NamedTypes/Alias.h"
#include "PICML/NamedTypes/Enum.h"
#include "PICML/ComponentParadigmSheets/ComponentType/PortType.h"
#include "PICML/NamedTypes/Collection.h"
#include "game/mga/Functional_T.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"


namespace PICML
{
  //
  // metaname
  //
  const std::string Member_Impl::metaname ("Member");

  //
  // is_abstract
  //
  const bool Member_Impl::is_abstract = false;

  //
  // _create (const Aggregate_in)
  //
  Member Member_Impl::_create (const Aggregate_in parent)
  {
    return ::GAME::Mga::create < Member > (parent, Member_Impl::metaname);
  }

  //
  // _create (const ObjectByValue_in)
  //
  Member Member_Impl::_create (const ObjectByValue_in parent)
  {
    return ::GAME::Mga::create < Member > (parent, Member_Impl::metaname);
  }

  //
  // _create (const SwitchedAggregate_in)
  //
  Member Member_Impl::_create (const SwitchedAggregate_in parent)
  {
    return ::GAME::Mga::create < Member > (parent, Member_Impl::metaname);
  }

  //
  // _create (const Exception_in)
  //
  Member Member_Impl::_create (const Exception_in parent)
  {
    return ::GAME::Mga::create < Member > (parent, Member_Impl::metaname);
  }

  //
  // accept
  //
  void Member_Impl::accept (::GAME::Mga::Visitor * v)
  {
    // See if this is a visitor we know.
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_Member (this);
    else
      v->visit_Reference (this);
  }

  //
  // parent_Aggregate
  //
  Aggregate Member_Impl::parent_Aggregate (void)
  {
    return Aggregate::_narrow (this->parent ());
  }

  //
  // parent_ObjectByValue
  //
  ObjectByValue Member_Impl::parent_ObjectByValue (void)
  {
    return ObjectByValue::_narrow (this->parent ());
  }

  //
  // parent_SwitchedAggregate
  //
  SwitchedAggregate Member_Impl::parent_SwitchedAggregate (void)
  {
    return SwitchedAggregate::_narrow (this->parent ());
  }

  //
  // parent_Exception
  //
  Exception Member_Impl::parent_Exception (void)
  {
    return Exception::_narrow (this->parent ());
  }

  //
  // src_of_MakeMemberPrivate
  //
  size_t Member_Impl::src_of_MakeMemberPrivate (std::vector <MakeMemberPrivate> & items) const
  {
    return this->in_connections <MakeMemberPrivate> (items);
  }

  //
  // has_src_of_MakeMemberPrivate
  //
  bool Member_Impl::has_src_of_MakeMemberPrivate (void) const
  {
    return this->in_connections <MakeMemberPrivate> ("src").count () == 1;
  }

  //
  // src_of_MakeMemberPrivate
  //
  MakeMemberPrivate Member_Impl::src_of_MakeMemberPrivate (void) const
  {
    return this->in_connections <MakeMemberPrivate> ("src").first ();
  }

  //
  // src_of_LabelConnection
  //
  size_t Member_Impl::src_of_LabelConnection (std::vector <LabelConnection> & items) const
  {
    return this->in_connections <LabelConnection> (items);
  }

  //
  // src_of_LabelConnection
  //
  GAME::Mga::Collection_T <LabelConnection> Member_Impl::src_of_LabelConnection (void) const
  {
    return this->in_connections <LabelConnection> ("src");
  }

  //
  // dst_of_KeyMember
  //
  size_t Member_Impl::dst_of_KeyMember (std::vector <KeyMember> & items) const
  {
    return this->in_connections <KeyMember> (items);
  }

  //
  // has_dst_of_KeyMember
  //
  bool Member_Impl::has_dst_of_KeyMember (void) const
  {
    return this->in_connections <KeyMember> ("dst").count () == 1;
  }

  //
  // dst_of_KeyMember
  //
  KeyMember Member_Impl::dst_of_KeyMember (void) const
  {
    return this->in_connections <KeyMember> ("dst").first ();
  }

  //
  // MemberType_is_nil
  //
  bool Member_Impl::MemberType_is_nil (void) const
  {
    return this->refers_to ().is_nil ();
  }

  //
  // refers_to_MemberType
  //
  void Member_Impl::refers_to_MemberType (MemberType_in item)
  {
    this->refers_to (item);
  }

  //
  // refers_to_MemberType
  //
  MemberType Member_Impl::refers_to_MemberType (void) const
  {
    return MemberType::_narrow (this->refers_to ());
  }
}

