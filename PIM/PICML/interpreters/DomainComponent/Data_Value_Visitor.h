// -*- C++ -*-

//==============================================================================
/**
 *  @file        Data_Value_Visitor.h
 *
 *  $Id: generate_cpp_class.py 3685 2012-09-26 14:45:04Z dfeiock $
 */
//==============================================================================

#ifndef _DATA_VALUE_VISITOR_H_
#define _DATA_VALUE_VISITOR_H_

#include "game/xml/Fragment.h"
#include "PICML/Visitor.h"

class Data_Value_Visitor : public PICML::Visitor
{
public:
  /// Default constructor.
  Data_Value_Visitor (const GAME::Xml::Fragment & parent, const std::string & value);

  /// Destructor.
  virtual ~Data_Value_Visitor (void);     

  virtual void visit_DataType (PICML::DataType_in dt);
  virtual void visit_Boolean (PICML::Boolean_in boolean);
  virtual void visit_Byte (PICML::Byte_in byte);
  virtual void visit_String (PICML::String_in str);
  virtual void visit_FloatNumber (PICML::FloatNumber_in real);
  virtual void visit_DoubleNumber (PICML::DoubleNumber_in real);
  virtual void visit_ShortInteger (PICML::ShortInteger_in type);
  virtual void visit_LongInteger (PICML::LongInteger_in type);

private:
  GAME::Xml::Fragment fragment_;

  std::string value_;
};

#endif  // _DATA_VALUE_VISITOR_H_
