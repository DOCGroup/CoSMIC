/* -*- C++ -*- */

//=============================================================================
/**
 * @file          Data_Value_XML_Visitor.h
 *
 * Generates XML for data types. 
 *
 * $Id: Data_Value_Visitor.h 1744 2008-02-10 21:49:16Z hillj $
 *
 * @author        William R. Otte <wotte@dre.vanderbilt.edu>
 */
//=============================================================================

#ifndef _DATA_VALUE_XML_VISITOR_H_
#define _DATA_VALUE_XML_VISITOR_H_

#include "Data_Value.h"

// Xerces includes
#include <xercesc/util/PlatformUtils.hpp>
#include <xercesc/util/XMLString.hpp>
#include <xercesc/dom/DOM.hpp>
#include <xercesc/framework/LocalFileFormatTarget.hpp>

// Utility includes
//#include "Utils/XercesString.h"
//#include "Utils/Utils.h"

// STL Includes
#include <stack>
//=============================================================================
/**
 * @class PICML_Data_Value_Visitor
 *
 * INSERT CLASS DESCRIPTION HERE
 */
//=============================================================================
#include "Data_Value_Visitor.h"


class PICML_Export PICML_Data_Value_XML_Visitor : public virtual PICML_Data_Value_Visitor
{
 public:
  PICML_Data_Value_XML_Visitor (void) {};
  /// Default constructor.
  PICML_Data_Value_XML_Visitor (xercesc::DOMElement *root, xercesc::DOMDocument *doc);

  /// Destructor.
  virtual ~PICML_Data_Value_XML_Visitor (void);

  virtual void visit_PICML_Char_Data_Value (const PICML_Char_Data_Value &);

  virtual void visit_PICML_String_Data_Value (const PICML_String_Data_Value &);

  virtual void visit_PICML_Short_Data_Value (const PICML_Short_Data_Value &);

  virtual void visit_PICML_UShort_Data_Value (const PICML_UShort_Data_Value &);

  virtual void visit_PICML_Long_Data_Value (const PICML_Long_Data_Value &);

  virtual void visit_PICML_ULong_Data_Value (const PICML_ULong_Data_Value &);

  virtual void visit_PICML_Enum_Data_Value (const PICML_Enum_Data_Value &);

  virtual void visit_PICML_Boolean_Data_Value (const PICML_Boolean_Data_Value &);

  virtual void visit_PICML_Aggregate_Data_Value (const PICML_Aggregate_Data_Value &);

  virtual void visit_PICML_Sequence_Data_Value (const PICML_Sequence_Data_Value &);
  
 private:
  void push();
  void pop();
  xercesc::DOMElement* createSimpleContent (const std::string& name,
					    const std::string& value);

  xercesc::DOMElement*         root_;
  xercesc::DOMElement*         curr_;
  xercesc::DOMDocument *       doc_;

  std::stack<xercesc::DOMElement*> curr_stack_;
};

#endif  /* !defined _DATA_VALUE_VISITOR_H_ */
