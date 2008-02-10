/* -*- C++ -*- */

//=============================================================================
/**
 * @file          Data_Value_Visitor.h
 *
 * INSERT FILE DESCRIPTION HERE
 *
 * $Id$
 *
 * @author        James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _DATA_VALUE_VISITOR_H_
#define _DATA_VALUE_VISITOR_H_

#include "Data_Value.h"

//=============================================================================
/**
 * @class PICML_Data_Value_Visitor
 *
 * INSERT CLASS DESCRIPTION HERE
 */
//=============================================================================

class PICML_Export PICML_Data_Value_Visitor
{
public:
  /// Default constructor.
  PICML_Data_Value_Visitor (void);

  /// Destructor.
  virtual ~PICML_Data_Value_Visitor (void);

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
};

#endif  /* !defined _DATA_VALUE_VISITOR_H_ */
