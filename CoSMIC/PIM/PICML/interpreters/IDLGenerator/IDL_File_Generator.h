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
class IDLStream;

// Forward decl.
class IDL_File_Processor;

/**
 * @class PredefinedType_Dispatcher
 */
template <typename T>
class PredefinedType_Dispatcher : public UDM_Abstract_Type_Dispatcher_T <T>
{
public:
  PredefinedType_Dispatcher (void)
  {
    this->insert <PICML::Boolean> ();
    
    this->insert <PICML::Byte> ();

    this->insert <PICML::Char> ();
    this->insert <PICML::WideChar> ();

    this->insert <PICML::String> ();
    this->insert <PICML::WideString> ();

    this->insert <PICML::ShortInteger> ();
    this->insert <PICML::LongInteger> ();
    this->insert <PICML::LongLongInteger> ();

    this->insert <PICML::UnsignedShortInteger> ();
    this->insert <PICML::UnsignedLongInteger> ();
    this->insert <PICML::UnsignedLongLongInteger> ();

    this->insert <PICML::FloatNumber> ();
    this->insert <PICML::DoubleNumber> ();
    this->insert <PICML::LongDoubleNumber> ();

    this->insert <PICML::GenericObject> ();
    this->insert <PICML::GenericValue> ();
    this->insert <PICML::GenericValueObject> ();
  }
};

/**
 * @class PredefinedType_Dispatcher
 */
template <typename T>
class TemplateParameter_Dispatcher : public UDM_Abstract_Type_Dispatcher_T <T>
{
public:
  TemplateParameter_Dispatcher (void)
  {
    this->insert <PICML::NameParameter> ();
    this->insert <PICML::CollectionParameter> ();
    this->insert <PICML::TypeParameter> ();
  }
};

/**
 * @class ReadonlyAttribute_Dispatcher
 */
template <typename T>
class ReadonlyAttribute_Dispatcher : public UDM_Abstract_Type_Dispatcher_T <T>
{
public:
  ReadonlyAttribute_Dispatcher (void)
  {
    this->insert <PICML::ReadonlyAttribute> ();
    this->insert <PICML::Attribute> ();
  }
};

/**
 * @class ExtendedPort_Dispatcher
 */
template <typename T>
class ExtendedPort_Dispatcher : public UDM_Abstract_Type_Dispatcher_T <T>
{
public:
  ExtendedPort_Dispatcher (void)
  {
    this->insert <PICML::ExtendedPort> ();
    this->insert <PICML::MirrorPort> ();
  }
};

/**
 * @class ParameterType_Dispatcher
 */
template <typename T>
class ParameterType_Dispatcher : public UDM_Abstract_Type_Dispatcher_T <T>
{
public:
  ParameterType_Dispatcher (void)
  {
    this->insert <PICML::InParameter> ();
    this->insert <PICML::InoutParameter> ();
    this->insert <PICML::OutParameter> ();
  }
};

/**
 * @class Port_Dispatcher
 */
template <typename T>
class Port_Dispatcher : public UDM_Abstract_Type_Dispatcher_T <T>
{
public:
  Port_Dispatcher (void)
  {
    this->insert <PICML::InEventPort> ();
    this->insert <PICML::OutEventPort> ();
    this->insert <PICML::ProvidedRequestPort> ();
    this->insert <PICML::RequiredRequestPort> ();
    this->insert <PICML::ExtendedPort> ();
  }
};

/**
 * @class Port_Dispatcher
 */
template <typename T>
class Member_Dispatcher : public UDM_Abstract_Type_Dispatcher_T <T>
{
public:
  Member_Dispatcher (void)
  {
    this->insert <PICML::Member> ();
    this->insert <PICML::ArrayMember> ();
  }
};

/**
 * @class IDL_File_Generator
 *
 * Visitor that is responsible for generating the IDL file.
 */
class IDL_File_Generator : public PICML::Visitor
{
public:
  IDL_File_Generator (IDLStream & idl);

  virtual ~IDL_File_Generator (void);

  virtual void Visit_File (const PICML::File & file);
  virtual void Visit_Package (const PICML::Package & package);
  virtual void Visit_Enum (const PICML::Enum & e);
  virtual void Visit_EnumValue (const PICML::EnumValue & v);

  virtual void Visit_Alias (const PICML::Alias & a);
  virtual void Visit_TemplatePackageInstance (const PICML::TemplatePackageInstance & p);

  virtual void Visit_Constant (const PICML::Constant & c);
  virtual void Visit_Collection (const PICML::Collection & c);
  virtual void Visit_NameParameter (const PICML::NameParameter & c);
  virtual void Visit_CollectionParameter (const PICML::CollectionParameter & c);
  virtual void Visit_TypeParameter (const PICML::TypeParameter & c);
  virtual void Visit_Aggregate (const PICML::Aggregate & a);
  virtual void Visit_SwitchedAggregate (const PICML::SwitchedAggregate & a);

  virtual void Visit_Member (const PICML::Member & a);
  virtual void Visit_ArrayMember (const PICML::ArrayMember & m);

  virtual void Visit_LabelConnection (const PICML::LabelConnection & c);
  virtual void Visit_Exception (const PICML::Exception & e);
  virtual void Visit_Object (const PICML::Object & o);
  virtual void Visit_Inherits (const PICML::Inherits & i);
  virtual void Visit_Attribute (const PICML::Attribute & a);
  virtual void Visit_ReadonlyAttribute (const PICML::ReadonlyAttribute & a);
  virtual void Visit_AttributeMember (const PICML::AttributeMember & m);
  virtual void Visit_PortType (const PICML::PortType & p);

  virtual void Visit_OnewayOperation (const PICML::OnewayOperation & op);
  virtual void Visit_TwowayOperation (const PICML::TwowayOperation & op);
  virtual void Visit_InParameter (const PICML::InParameter & p);
  virtual void Visit_OutParameter (const PICML::OutParameter & p);
  virtual void Visit_InOutParameter (const PICML::InoutParameter & p);

  virtual void Visit_Event (const PICML::Event & e);
  virtual void Visit_ValueObject (const PICML::ValueObject & e);

  virtual void Visit_Component (const PICML::Component & c);
  virtual void Visit_ConnectorObject (const PICML::ConnectorObject & c);
  virtual void Visit_ComponentFactory (const PICML::ComponentFactory & f);

  virtual void Visit_ProvidedRequestPort (const PICML::ProvidedRequestPort & p);
  virtual void Visit_RequiredRequestPort (const PICML::RequiredRequestPort & p);
  virtual void Visit_InEventPort (const PICML::InEventPort & p);
  virtual void Visit_OutEventPort (const PICML::OutEventPort & p);
  virtual void Visit_ExtendedPort (const PICML::ExtendedPort & p);
  virtual void Visit_MirrorPort (const PICML::MirrorPort & p);

  virtual void Visit_Byte (const PICML::Byte & b);

  virtual void Visit_Char (const PICML::Char & b);
  virtual void Visit_WideChar (const PICML::WideChar & b);

  virtual void Visit_Boolean (const PICML::Boolean & b);

  virtual void Visit_String (const PICML::String & s);
  virtual void Visit_WideString (const PICML::WideString & b);

  virtual void Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger & s);
  virtual void Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger & l);
  virtual void Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger & );

  virtual void Visit_ShortInteger (const PICML::ShortInteger & s);
  virtual void Visit_LongInteger (const PICML::LongInteger & l);
  virtual void Visit_LongLongInteger (const PICML::LongLongInteger & );

  virtual void Visit_DoubleNumber (const PICML::DoubleNumber & d);
  virtual void Visit_FloatNumber (const PICML::FloatNumber & f);
  virtual void Visit_LongDoubleNumber (const PICML::LongDoubleNumber &);

  virtual void Visit_GenericObject (const PICML::GenericObject & f);
  virtual void Visit_GenericValue (const PICML::GenericValue & f);
  virtual void Visit_GenericValueObject (const PICML::GenericValueObject & v);
  virtual void Visit_TypeEncoding (const PICML::TypeEncoding & t);
  virtual void Visit_TypeKind (const PICML::TypeKind & t);

  virtual void Visit_LookupOperation (const PICML::LookupOperation & op);
  virtual void Visit_FactoryOperation (const PICML::FactoryOperation & op);

private:
  void Visit_FilePackage (const Udm::Object & object);
  void Visit_MemberType (const PICML::MemberType & mt);
  void Visit_ConstantType (const PICML::ConstantType & ct);
  void Visit_ParameterType (const PICML::ParameterType & pt);
  void Visit_Provideable (const PICML::Provideable & p);
  void Visit_EventType (const PICML::EventType & e);
  void Visit_ObjectByValue (const PICML::ObjectByValue & obv);

  /// Target output stream for the IDL.
  IDLStream & idl_;

  bool templates_only_;

  PredefinedType_Dispatcher <IDL_File_Generator> pt_dispatcher_;
  TemplateParameter_Dispatcher <IDL_File_Generator> tp_dispatcher_;
  ParameterType_Dispatcher <IDL_File_Generator> param_dispatcher_;
  ReadonlyAttribute_Dispatcher <IDL_File_Generator> ro_dispatcher_;
  Port_Dispatcher <IDL_File_Generator> port_dispatcher_;
  ExtendedPort_Dispatcher <IDL_File_Generator> extended_dispatcher_;
  Member_Dispatcher <IDL_File_Generator> member_dispatcher_;
};

#endif  // !defined _IDL_FILE_GENERATOR_H_
