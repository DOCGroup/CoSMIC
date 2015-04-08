// -*- C++ -*-

//=============================================================================
/**
 * @file      Data_Type_Visitor.h
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_DATA_TYPE_VISITOR_H_
#define _PICML_DATA_TYPE_VISITOR_H_

#include "game/xml/Fragment.h"

#include "PICML/Visitor.h"
#include "PICML_Xml_export.h"

namespace PICML
{
namespace Xml
{

/**
 * @class Data_Type_Visitor
 *
 * Visitor that generates the type information for a PICML::DataType
 * element. The type information is captured in the <type><kind></kind></type>
 * XML tag.
 */
class PICML_XML_Export Data_Type_Visitor : public PICML::Visitor
{
public:
  Data_Type_Visitor (GAME::Xml::Fragment parent);

  virtual ~Data_Type_Visitor (void);

  virtual void visit_Boolean (PICML::Boolean_in b);

  virtual void visit_Byte (PICML::Byte_in b);

  virtual void visit_Char (PICML::Char_in );
  virtual void visit_WideChar (PICML::WideChar_in );

  virtual void visit_String (PICML::String_in s);
  virtual void visit_WideString (PICML::WideString_in s);

  virtual void visit_FloatNumber (PICML::FloatNumber_in fn);
  virtual void visit_DoubleNumber (PICML::DoubleNumber_in dn);
  virtual void visit_LongDoubleNumber (PICML::LongDoubleNumber_in dn);

  virtual void visit_ShortInteger (PICML::ShortInteger_in si);
  virtual void visit_LongInteger (PICML::LongInteger_in li);
  virtual void visit_LongLongInteger (PICML::LongLongInteger_in li);

  virtual void visit_UnsignedShortInteger (PICML::UnsignedShortInteger_in si);
  virtual void visit_UnsignedLongInteger (PICML::UnsignedLongInteger_in li);
  virtual void visit_UnsignedLongLongInteger (PICML::UnsignedLongLongInteger_in li);

  virtual void visit_Enum (PICML::Enum_in e);
  virtual void visit_EnumValue (PICML::EnumValue_in ev);

  virtual void visit_Collection (PICML::Collection_in c);
  virtual void visit_Aggregate (PICML::Aggregate_in a);

  virtual void visit_Member (PICML::Member_in m);
 
  virtual void visit_SimpleProperty (PICML::SimpleProperty_in prop);
  virtual void visit_ComplexProperty (PICML::ComplexProperty_in prop);

private:
  GAME::Xml::Fragment fragment_;
};

}
}

#include "Data_Type_Visitor.inl"

#endif  // !defined _PICML_DATA_TYPE_VISITOR_H_
