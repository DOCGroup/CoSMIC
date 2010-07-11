// -*- C++ -*-

//=============================================================================
/**
 * @file      Value_Visitor.h
 *
 * $Id: Value_Visitor.h 2261 2010-06-16 16:47:55Z alhad $
 *
 * @author    Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_VALUE_VISITOR_H_
#define _PICML_VALUE_VISITOR_H_

#include "PICML/PICML.h"
#include "XML_Document.h"

#include "DeploymentPlanVisitor.h"

class PICML_Value_Visitor :
  public PICML::Visitor,
  public XML_Document
{
public:
  PICML_Value_Visitor (xercesc::DOMElement * parent,
                            const std::string value);

  virtual ~PICML_Value_Visitor (void);

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

private:

  const std::string datavalue_;

  xercesc::DOMElement * curr;
};

#include "Value_Visitor.inl"

#endif  // !defined _PICML_Value_Visitor_H_
