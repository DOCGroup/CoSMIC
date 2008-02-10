// $Id$

#include "Data_Value_Parser.h"
#include "Data_Value.h"

//
// PICML_Data_Value_Parser
//
PICML_Data_Value_Parser::
PICML_Data_Value_Parser (PICML_Data_Value * const value,
                         PICML_Data_Value_Parser::parser_type type)
: value_ (value),
  type_ (type)
{

}

//
// type
//
PICML_Data_Value_Parser::parser_type
PICML_Data_Value_Parser::type (void) const
{
  return this->type_;
}

//
// select_member
//
void PICML_Data_Value_Parser::
select_member (const char * start, const char * end) const
{
  this->token_ = std::string (start, end);
}

//
// select_member
//
void PICML_Data_Value_Parser::
set_member_value (const char * start, const char * end) const
{
  PICML_Aggregate_Data_Value * value =
    dynamic_cast <PICML_Aggregate_Data_Value *> (this->value_);

  PICML_Data_Value * member = 0;

  if (value->find_member (this->token_, member))
    member->value (std::string (start, end));
}

//
// select_member
//
void PICML_Data_Value_Parser::
insert_sequence_value (const char * start, const char * end) const
{
  PICML_Sequence_Data_Value * value =
    dynamic_cast <PICML_Sequence_Data_Value *> (this->value_);

  // Create a new element in the sequence and set its value.
  PICML_Data_Value * element = value->new_element ();
  element->value (std::string (start, end));
}
