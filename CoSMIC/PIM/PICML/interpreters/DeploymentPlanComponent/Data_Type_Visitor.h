// -*- C++ -*-

//=============================================================================
/**
 * @file      Data_Type_Visitor.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_DATA_TYPE_VISITOR_H_
#define _PICML_DATA_TYPE_VISITOR_H_

#include "PICML/PICML.h"
#include "XML_Document.h"

/**
 * @class PICML_Data_Type_Visitor
 */
class PICML_Data_Type_Visitor :
  public PICML::Visitor,
  public XML_Document
{
public:
  PICML_Data_Type_Visitor (xercesc::DOMElement * parent);

  virtual ~PICML_Data_Type_Visitor (void);

  virtual void Visit_Boolean (const PICML::Boolean & b);

  virtual void Visit_Byte (const PICML::Byte & b);

  virtual void Visit_String (const PICML::String & s);

  virtual void Visit_FloatNumber (const PICML::FloatNumber & fn);

  virtual void Visit_DoubleNumber (const PICML::DoubleNumber & dn);

  virtual void Visit_ShortInteger (const PICML::ShortInteger & si);

  virtual void Visit_LongInteger (const PICML::LongInteger & li);

  virtual void Visit_Enum (const PICML::Enum & e);

  virtual void Visit_EnumValue (const PICML::EnumValue & ev);
};

#include "Data_Type_Visitor.inl"

#endif  // !defined _PICML_DATA_TYPE_VISITOR_H_
