// $Id$

#include "Data_Value_Parser.h"
#include "Data_Value.h"

//
// PICML_Data_Value_Parser
//
PICML_Data_Value_Parser::
PICML_Data_Value_Parser (PICML_Data_Value * const value)
: value_ (value)
{

}

//
// aggregate_member
//
void PICML_Data_Value_Parser::
aggregate_member (const char * start, const char * end) const
{
  this->member_ = std::string (start, end);
}

//
// aggregate_member_value
//
void PICML_Data_Value_Parser::
aggregate_member_value (const char * start, const char * end) const
{
  PICML_Aggregate_Data_Value * value =
    dynamic_cast <PICML_Aggregate_Data_Value *> (this->value_);

  PICML_Data_Value * member = 0;

  if (value->find_member (this->member_, member))
    member->value (std::string (start, end));
}

//
// event_member_value
//
void PICML_Data_Value_Parser::
event_member_value (const char * start, const char * end) const
{
  PICML_Event_Data_Value * value =
    dynamic_cast <PICML_Event_Data_Value *> (this->value_);

  PICML_Data_Value * member = 0;

  if (value->find_member (this->member_, member))
    member->value (std::string (start, end));
}

//
// insert_sequence_value
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
