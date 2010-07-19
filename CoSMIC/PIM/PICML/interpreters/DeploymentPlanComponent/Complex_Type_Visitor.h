// -*- C++ -*-

//=============================================================================
/**
 * @file      Complex_Type_Visitor.h
 *
 * $Id: Complex_Type_Visitor.h 2261 2010-07-10 16:47:55Z alhad $
 *
 * @author    Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_COMPLEX_TYPE_VISITOR_H_
#define _PICML_COMPLEX_TYPE_VISITOR_H_

#include "PICML/PICML.h"
#include "XML_Document.h"
#include "Data_Type_Visitor.h"

#include "DeploymentPlanVisitor.h"
#include "Data_Type_Dispatcher.h"

/**
 * @class PICML_Complex_Type_Visitor
 */
class PICML_Complex_Type_Visitor :
  public PICML::Visitor,
  public XML_Document
{
public:
  PICML_Complex_Type_Visitor (xercesc::DOMElement * parent);

  virtual ~PICML_Complex_Type_Visitor (void);

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

  virtual void Visit_EnumValue (const PICML::EnumValue & ev);

  virtual void Visit_Aggregate (const PICML::Aggregate & ag);

  virtual void process_aggregate_type (const PICML::Aggregate &);

  virtual void Visit_Collection (const PICML::Collection & ag);

  virtual void process_collection_type (const PICML::Collection &);
private:

  xercesc::DOMElement * curr_;

  PICML_Data_Type_Dispatcher datatypes_;
};

#include "Complex_Type_Visitor.inl"

#endif  // !defined _PICML_Complex_Type_Visitor_H_
