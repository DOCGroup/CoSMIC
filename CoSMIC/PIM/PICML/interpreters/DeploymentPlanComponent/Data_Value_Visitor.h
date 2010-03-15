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
#include "XML_Document.h"

class PICML_Data_Value_Visitor :
  public PICML::Visitor,
  public XML_Document
{
public:
  PICML_Data_Value_Visitor (xercesc::DOMElement * parent,
                            const PICML::Property & prop);

  virtual ~PICML_Data_Value_Visitor (void);

  virtual void Visit_Boolean (const PICML::Boolean & b);

  virtual void Visit_Byte (const PICML::Byte & b);

  virtual void Visit_String (const PICML::String & s);

  virtual void Visit_FloatNumber (const PICML::FloatNumber & fn);

  virtual void Visit_DoubleNumber (const PICML::DoubleNumber & dn);

  virtual void Visit_ShortInteger (const PICML::ShortInteger & si);

  virtual void Visit_LongInteger (const PICML::LongInteger & li);

  virtual void Visit_Enum (const PICML::Enum & e);

private:
  const PICML::Property & prop_;
};

#include "Data_Value_Visitor.inl"

#endif  // !defined _PICML_DATA_VALUE_VISITOR_H_
