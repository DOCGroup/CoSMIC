// -*- C++ -*-

//=============================================================================
/**
 * @file      IDL_Generator_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_FILE_GENERATOR_H_
#define _IDL_FILE_GENERATOR_H_

#include "PICML/PICML.h"
#include "Utils/UDM/Abstract_Type_Dispatcher_T.h"

// Forward decl.
class IDL_File_Dependency_Processor;

// Forward decl.
class IDLStream;

/**
 * @class IDL_File_Generator
 *
 * Visitor that is responsible for generating the IDL file.
 */
class IDL_File_Generator : public PICML::Visitor
{
public:
  IDL_File_Generator (IDL_File_Dependency_Processor & depends_graph,
                      IDLStream & idl);

  virtual ~IDL_File_Generator (void);

  virtual void Visit_File (const PICML::File_in file);
  virtual void Visit_Package (const PICML::Package_in package);
  virtual void Visit_Enum (const PICML::Enum_in e);
  virtual void Visit_EnumValue (const PICML::EnumValue_in v);

  virtual void Visit_Alias (const PICML::Alias_in a);
  virtual void Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance_in p);

  virtual void Visit_Constant (const PICML::Constant_in c);
  virtual void Visit_Collection (const PICML::Collection_in c);
  virtual void Visit_NameParameter (const PICML::NameParameter_in c);
  virtual void Visit_CollectionParameter (const PICML::CollectionParameter_in c);
  virtual void Visit_TypeParameter (const PICML::TypeParameter_in c);
  virtual void Visit_Aggregate (const PICML::Aggregate_in a);
  virtual void Visit_SwitchedAggregate (const PICML::SwitchedAggregate_in a);

  virtual void Visit_Member (const PICML::Member_in a);
  virtual void Visit_ArrayMember (const PICML::ArrayMember_in m);

  virtual void Visit_LabelConnection (const PICML::LabelConnection_in c);
  virtual void Visit_Exception (const PICML::Exception_in e);
  virtual void Visit_Object (const PICML::Object_in o);
  virtual void Visit_Inherits (const PICML::Inherits_in i);
  virtual void Visit_Attribute (const PICML::Attribute_in a);
  virtual void Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute_in a);
  virtual void Visit_AttributeMember (const PICML::AttributeMember_in m);
  virtual void Visit_PortType (const PICML::PortType_in p);

  virtual void Visit_OnewayOperation (const PICML::OnewayOperation_in op);
  virtual void Visit_TwowayOperation (const PICML::TwowayOperation_in op);
  virtual void Visit_InParameter (const PICML::InParameter_in p);
  virtual void Visit_OutParameter (const PICML::OutParameter_in p);
  virtual void Visit_InoutParameter (const PICML::InoutParameter_in p);

  virtual void Visit_Event (const PICML::Event_in e);
  virtual void Visit_ValueObject (const PICML::ValueObject_in e);

  virtual void Visit_Component (const PICML::Component_in c);
  virtual void Visit_ConnectorObject (const PICML::ConnectorObject_in c);
  virtual void Visit_ComponentFactory (const PICML::ComponentFactory_in f);

  virtual void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort_in p);
  virtual void Visit_RequiredRequestPort (const PICML::RequiredRequestPort_in p);
  virtual void Visit_InEventPort (const PICML::InEventPort_in p);
  virtual void Visit_OutEventPort (const PICML::OutEventPort_in p);
  virtual void Visit_ExtendedPort (const PICML::ExtendedPort_in p);
  virtual void Visit_MirrorPort (const PICML::MirrorPort_in p);

  virtual void Visit_Byte (const PICML::Byte_in b);

  virtual void Visit_Char (const PICML::Char_in b);
  virtual void Visit_WideChar (const PICML::WideChar_in b);

  virtual void Visit_Boolean (const PICML::Boolean_in b);

  virtual void Visit_String (const PICML::String_in s);
  virtual void Visit_WideString (const PICML::WideString_in b);

  virtual void Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger_in s);
  virtual void Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger_in l);
  virtual void Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger_in );

  virtual void Visit_ShortInteger (const PICML::ShortInteger_in s);
  virtual void Visit_LongInteger (const PICML::LongInteger_in l);
  virtual void Visit_LongLongInteger (const PICML::LongLongInteger_in );

  virtual void Visit_DoubleNumber (const PICML::DoubleNumber_in d);
  virtual void Visit_FloatNumber (const PICML::FloatNumber_in f);
  virtual void Visit_LongDoubleNumber (const PICML::LongDoubleNumber_in);

  virtual void Visit_GenericObject (const PICML::GenericObject_in f);
  virtual void Visit_GenericValue (const PICML::GenericValue_in f);
  virtual void Visit_GenericValueObject (const PICML::GenericValueObject_in v);
  virtual void Visit_TypeEncoding (const PICML::TypeEncoding_in t);
  virtual void Visit_TypeKind (const PICML::TypeKind_in t);

  virtual void Visit_LookupOperation (const PICML::LookupOperation_in op);
  virtual void Visit_FactoryOperation (const PICML::FactoryOperation_in op);

private:
  void Visit_MemberType (const PICML::MemberType_in mt);
  void Visit_ConstantType (const PICML::ConstantType_in ct);
  void Visit_ParameterType (const PICML::ParameterType_in pt);
  void Visit_Provideable (const PICML::Provideable_in p);
  void Visit_EventType (const PICML::EventType_in e);
  void Visit_ObjectByValue (const PICML::ObjectByValue_in obv);
  void Visit_TemplateParameterValueType (const PICML::TemplateParameterValueType_in);
  void Visit_ExceptionType (const PICML::ExceptionType_in);

  /// The source dependency graph.
  IDL_File_Dependency_Processor & depends_graph_;

  /// Target output stream for the IDL.
  IDLStream & idl_;

  bool templates_only_;

  bool in_event_;
};

#endif  // !defined _IDL_FILE_GENERATOR_H_
