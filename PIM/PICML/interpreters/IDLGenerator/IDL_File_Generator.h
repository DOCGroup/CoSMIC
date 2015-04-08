// -*- C++ -*-

//=============================================================================
/**
 * @file      IDL_Generator_Visitor.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _IDL_FILE_GENERATOR_H_
#define _IDL_FILE_GENERATOR_H_

#include "PICML/PICML.h"
#include "PICML/Visitor.h"

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

  virtual void visit_File (PICML::File_in file);
  virtual void visit_Package (PICML::Package_in package);
  virtual void visit_Enum (PICML::Enum_in e);
  virtual void visit_EnumValue (PICML::EnumValue_in v);

  virtual void visit_Alias (PICML::Alias_in a);
  virtual void visit_TemplatePackageInstance (PICML::TemplatePackageInstance_in p);

  virtual void visit_Constant (PICML::Constant_in c);
  virtual void visit_Collection (PICML::Collection_in c);
  virtual void visit_NameParameter (PICML::NameParameter_in c);
  virtual void visit_CollectionParameter (PICML::CollectionParameter_in c);
  virtual void visit_TypeParameter (PICML::TypeParameter_in c);
  virtual void visit_Aggregate (PICML::Aggregate_in a);
  virtual void visit_SwitchedAggregate (PICML::SwitchedAggregate_in a);

  virtual void visit_Member (PICML::Member_in a);
  virtual void visit_ArrayMember (PICML::ArrayMember_in m);

  virtual void visit_LabelConnection (PICML::LabelConnection_in c);
  virtual void visit_Exception (PICML::Exception_in e);
  virtual void visit_Object (PICML::Object_in o);
  virtual void visit_Inherits (PICML::Inherits_in i);
  virtual void visit_Attribute (PICML::Attribute_in a);
  virtual void visit_ReadonlyAttribute (PICML::ReadonlyAttribute_in a);
  virtual void visit_AttributeMember (PICML::AttributeMember_in m);
  virtual void visit_PortType (PICML::PortType_in p);

  virtual void visit_OnewayOperation (PICML::OnewayOperation_in op);
  virtual void visit_TwowayOperation (PICML::TwowayOperation_in op);
  virtual void visit_InParameter (PICML::InParameter_in p);
  virtual void visit_OutParameter (PICML::OutParameter_in p);
  virtual void visit_InoutParameter (PICML::InoutParameter_in p);

  virtual void visit_Event (PICML::Event_in e);
  virtual void visit_ValueObject (PICML::ValueObject_in e);

  virtual void visit_Component (PICML::Component_in c);
  virtual void visit_ConnectorObject (PICML::ConnectorObject_in c);
  virtual void visit_ComponentFactory (PICML::ComponentFactory_in f);

  virtual void visit_ProvidedRequestPort (PICML::ProvidedRequestPort_in p);
  virtual void visit_RequiredRequestPort (PICML::RequiredRequestPort_in p);
  virtual void visit_InEventPort (PICML::InEventPort_in p);
  virtual void visit_OutEventPort (PICML::OutEventPort_in p);
  virtual void visit_ExtendedPort (PICML::ExtendedPort_in p);
  virtual void visit_MirrorPort (PICML::MirrorPort_in p);

  virtual void visit_Byte (PICML::Byte_in b);

  virtual void visit_Char (PICML::Char_in b);
  virtual void visit_WideChar (PICML::WideChar_in b);

  virtual void visit_Boolean (PICML::Boolean_in b);

  virtual void visit_String (PICML::String_in s);
  virtual void visit_WideString (PICML::WideString_in b);

  virtual void visit_UnsignedShortInteger (PICML::UnsignedShortInteger_in s);
  virtual void visit_UnsignedLongInteger (PICML::UnsignedLongInteger_in l);
  virtual void visit_UnsignedLongLongInteger (PICML::UnsignedLongLongInteger_in );

  virtual void visit_ShortInteger (PICML::ShortInteger_in s);
  virtual void visit_LongInteger (PICML::LongInteger_in l);
  virtual void visit_LongLongInteger (PICML::LongLongInteger_in );

  virtual void visit_DoubleNumber (PICML::DoubleNumber_in d);
  virtual void visit_FloatNumber (PICML::FloatNumber_in f);
  virtual void visit_LongDoubleNumber (PICML::LongDoubleNumber_in);

  virtual void visit_GenericObject (PICML::GenericObject_in f);
  virtual void visit_GenericValue (PICML::GenericValue_in f);
  virtual void visit_GenericValueObject (PICML::GenericValueObject_in v);
  virtual void visit_TypeEncoding (PICML::TypeEncoding_in t);
  virtual void visit_TypeKind (PICML::TypeKind_in t);

  virtual void visit_LookupOperation (PICML::LookupOperation_in op);
  virtual void visit_FactoryOperation (PICML::FactoryOperation_in op);

private:
  void visit_MemberType (PICML::MemberType_in mt);
  void visit_ConstantType (PICML::ConstantType_in ct);
  void visit_ParameterType (PICML::ParameterType_in pt);
  void visit_Provideable (PICML::Provideable_in p);
  void visit_EventType (PICML::EventType_in e);
  void visit_ObjectByValue (PICML::ObjectByValue_in obv);
  void visit_TemplateParameterValueType (PICML::TemplateParameterValueType_in);
  void visit_ExceptionType (const PICML::ExceptionType &);

  /// The source dependency graph.
  IDL_File_Dependency_Processor & depends_graph_;

  /// Target output stream for the IDL.
  IDLStream & idl_;

  bool templates_only_;

  bool in_event_;
};

#endif  // !defined _IDL_FILE_GENERATOR_H_
