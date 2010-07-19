// -*- C++ -*-

//=============================================================================
/**
 * @file      Data_Value_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_DATA_VALUE_VISITOR_H_
#define _PICML_DATA_VALUE_VISITOR_H_

#include "PICML/PICML.h"
#include "Data_Type_Dispatcher.h"
#include "XML_Document.h"

/**
 * @class DataValueBase_Dispatcher
 */
class DataValueBase_Dispatcher :
  public UDM_Abstract_Type_Dispatcher_T <PICML::Visitor>
{
public:
  DataValueBase_Dispatcher (void)
  {
    this->insert <PICML::DataValue> ();
    this->insert <PICML::DataValueContainer> ();
  }
};

/**
 * @class PICML_Data_Value_Visitor
 */
class PICML_Data_Value_Visitor :
  public PICML::Visitor,
  public XML_Document
{
public:
  PICML_Data_Value_Visitor (xercesc::DOMElement * parent);

  virtual ~PICML_Data_Value_Visitor (void);

  virtual void Visit_Boolean (const PICML::Boolean & b);

  virtual void Visit_Byte (const PICML::Byte & b);

  virtual void Visit_Char (const PICML::Char & );
  virtual void Visit_WideChar (const PICML::WideChar & );

  virtual void Visit_String (const PICML::String & s);
  virtual void Visit_WideString (const PICML::WideString & s);

  virtual void Visit_FloatNumber (const PICML::FloatNumber & fn);
  virtual void Visit_DoubleNumber (const PICML::DoubleNumber & dn);
  virtual void Visit_LongDoubleNumber (const PICML::LongDoubleNumber & dn);

  virtual void Visit_ShortInteger (const PICML::ShortInteger & si);
  virtual void Visit_LongInteger (const PICML::LongInteger & li);
  virtual void Visit_LongLongInteger (const PICML::LongLongInteger & li);

  virtual void Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger & si);
  virtual void Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger & li);
  virtual void Visit_UnsignedLongLongInteger (const PICML::UnsignedLongLongInteger & li);

  virtual void Visit_Enum (const PICML::Enum & e);

  virtual void Visit_DataValueContainer (const PICML::DataValueContainer & c);
  virtual void Visit_DataValue (const PICML::DataValue & v);
  virtual void Visit_Property (const PICML::Property & prop);

private:
  enum container_t
  {
    NONE          = 0,
    AGGREGATE     = 1,
    SEQUENCE      = 2
  };

  container_t container_;

  static const char * envelopes_[3];
  const char * envelope_;

  DataValueBase_Dispatcher dvb_dispatcher_;
  PICML_Data_Type_Dispatcher dt_dispatcher_;

  PICML::DataValue value_;
};

#include "Data_Value_Visitor.inl"

#endif  // !defined _PICML_DATA_VALUE_VISITOR_H_
