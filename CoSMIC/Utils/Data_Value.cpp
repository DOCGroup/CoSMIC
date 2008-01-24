// $Id$

#include "Data_Value.h"
#include "Data_Value_Visitor.h"
#include "Data_Value_Parser.h"

///////////////////////////////////////////////////////////////////////////////
// class PICML_Data_Value

//
// PICML_Data_Value
//
PICML_Data_Value::PICML_Data_Value (void)
{

}

//
// PICML_Data_Value
//
PICML_Data_Value::~PICML_Data_Value (void)
{

}

//
// value
//
void PICML_Data_Value::value (const std::string & v)
{
  this->value_ = v;
}

//
// value
//
const std::string & PICML_Data_Value::value (void) const
{
  return this->value_;
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_String_Data_Value

//
// PICML_String_Data_Value
//
PICML_String_Data_Value::PICML_String_Data_Value (void)
{

}

//
// ~PICML_String_Data_Value
//
PICML_String_Data_Value::~PICML_String_Data_Value (void)
{

}

void PICML_String_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_String_Data_Value (*this);
}

PICML_Data_Value * PICML_String_Data_Value::_create (void) const
{
  return new PICML_String_Data_Value ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Char_Data_Value

//
// PICML_Char_Data_Value
//
PICML_Char_Data_Value::PICML_Char_Data_Value (void)
{

}

//
// ~PICML_String_Data_Value
//
PICML_Char_Data_Value::~PICML_Char_Data_Value (void)
{

}

void PICML_Char_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_Char_Data_Value (*this);
}

PICML_Data_Value * PICML_Char_Data_Value::_create (void) const
{
  return new PICML_Char_Data_Value ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Short_Data_Value

//
// PICML_Short_Data_Value
//
PICML_Short_Data_Value::PICML_Short_Data_Value (void)
{

}

//
// ~PICML_Short_Data_Value
//
PICML_Short_Data_Value::~PICML_Short_Data_Value (void)
{

}

void PICML_Short_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_Short_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value * PICML_Short_Data_Value::_create (void) const
{
  return new PICML_Short_Data_Value ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_UShort_Data_Value

//
// PICML_UShort_Data_Value
//
PICML_UShort_Data_Value::PICML_UShort_Data_Value (void)
{

}

//
// ~PICML_Short_Data_Value
//
PICML_UShort_Data_Value::~PICML_UShort_Data_Value (void)
{

}

void PICML_UShort_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_UShort_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value * PICML_UShort_Data_Value::_create (void) const
{
  return new PICML_UShort_Data_Value ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Long_Data_Value

//
// PICML_Long_Data_Value
//
PICML_Long_Data_Value::PICML_Long_Data_Value (void)
{

}

//
// ~PICML_Short_Data_Value
//
PICML_Long_Data_Value::~PICML_Long_Data_Value (void)
{

}

void PICML_Long_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_Long_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value * PICML_Long_Data_Value::_create (void) const
{
  return new PICML_Long_Data_Value ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_ULong_Data_Value

//
// PICML_ULong_Data_Value
//
PICML_ULong_Data_Value::PICML_ULong_Data_Value (void)
{

}

//
// ~PICML_ULong_Data_Value
//
PICML_ULong_Data_Value::~PICML_ULong_Data_Value (void)
{

}

void PICML_ULong_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_ULong_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value * PICML_ULong_Data_Value::_create (void) const
{
  return new PICML_ULong_Data_Value ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Boolean_Data_Value

//
// PICML_Boolean_Data_Value
//
PICML_Boolean_Data_Value::PICML_Boolean_Data_Value (void)
{

}

//
// ~PICML_Boolean_Data_Value
//
PICML_Boolean_Data_Value::~PICML_Boolean_Data_Value (void)
{

}

void PICML_Boolean_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_Boolean_Data_Value (*this);
}

//
// _create
//
PICML_Data_Value * PICML_Boolean_Data_Value::_create (void) const
{
  return new PICML_Boolean_Data_Value ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Enum_Data_Value

//
// PICML_Enum_Data_Value
//
PICML_Enum_Data_Value::PICML_Enum_Data_Value (void)
{

}

//
// ~PICML_Enum_Data_Value
//
PICML_Enum_Data_Value::~PICML_Enum_Data_Value (void)
{

}

void PICML_Enum_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_Enum_Data_Value (*this);
}

//
// insert_option
//
void PICML_Enum_Data_Value::insert_option (const std::string & opt)
{
  this->options_.insert (opt);
}

//
// options
//
const PICML_Enum_Data_Value::container_type &
PICML_Enum_Data_Value::options (void) const
{
  return this->options_;
}

//
// _create
//
PICML_Data_Value * PICML_Enum_Data_Value::_create (void) const
{
  PICML_Enum_Data_Value * value = new PICML_Enum_Data_Value ();

  container_type::const_iterator
    iter = this->options_.begin (),
    iter_end = this->options_.end ();

  for (; iter != iter_end; iter ++)
    value->insert_option (*iter);

  return value;
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Aggregate_Data_Value

//
// PICML_Aggregate_Data_Value
//
PICML_Aggregate_Data_Value::PICML_Aggregate_Data_Value (void)
{

}

//
// ~PICML_Aggregate_Data_Value
//
PICML_Aggregate_Data_Value::~PICML_Aggregate_Data_Value (void)
{
  container_type::iterator
    iter = this->members_.begin (),
    iter_end = this->members_.end ();

  for ( ; iter != iter_end; iter ++)
    delete iter->second;
}

//
// _create
//
PICML_Data_Value * PICML_Aggregate_Data_Value::_create (void) const
{
  PICML_Aggregate_Data_Value * value = new PICML_Aggregate_Data_Value ();

  const_iterator
    iter = this->members_.begin (),
    iter_end = this->members_.end ();

  for (; iter != iter_end; iter ++)
    value->insert_member (iter->first, iter->second->_create ());

  return value;
}

//
// accept
//
void PICML_Aggregate_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_Aggregate_Data_Value (*this);
}

//
// value
//
void PICML_Aggregate_Data_Value::value (const std::string & value)
{
  this->PICML_Data_Value::value (value);

  PICML_Data_Value_Parser parser (this, PICML_Data_Value_Parser::PARSER_STRUCT);
  boost::spirit::parse (value.c_str (), parser, boost::spirit::space_p);
}

//
// insert_member
//
void PICML_Aggregate_Data_Value::
insert_member (const std::string & name, PICML_Data_Value * value)
{
  PICML_Data_Value * temp = 0;

  if (this->find_member (name, temp))
  {
    // Delete the old data value.
    delete temp;

    this->members_[name] = value;
  }
  else
    this->members_.insert (std::make_pair (name, value));
}

//
// remove_member
//
void PICML_Aggregate_Data_Value::
remove_member (const std::string & name)
{
  container_type::iterator iter = this->members_.find (name);

  if (iter != this->members_.end ())
  {
    // Delete the data value.
    delete iter->second;

    // Remove the member for the collection.
    this->members_.erase (iter);
  }
}

//
// find_member
//
bool PICML_Aggregate_Data_Value::
find_member (const std::string & name, PICML_Data_Value * & member) const
{
  container_type::const_iterator iter = this->members_.find (name);

  if (iter != this->members_.end ())
  {
    member = iter->second;
    return true;
  }

  return false;
}

//
// operator []
//
PICML_Data_Value * PICML_Aggregate_Data_Value::
operator [] (const std::string & name)
{
  return this->members_[name];
}

//
// begin
//
PICML_Aggregate_Data_Value::iterator
PICML_Aggregate_Data_Value::begin (void)
{
  return this->members_.begin ();
}

//
// begin
//
PICML_Aggregate_Data_Value::const_iterator
PICML_Aggregate_Data_Value::begin (void) const
{
  return this->members_.begin ();
}

//
// end
//
PICML_Aggregate_Data_Value::iterator
PICML_Aggregate_Data_Value::end (void)
{
  return this->members_.end ();
}

//
// end
//
PICML_Aggregate_Data_Value::const_iterator
PICML_Aggregate_Data_Value::end (void) const
{
  return this->members_.end ();
}

///////////////////////////////////////////////////////////////////////////////
// class PICML_Sequence_Data_Value

//
// PICML_Sequence_Data_Value
//
PICML_Sequence_Data_Value::
PICML_Sequence_Data_Value (PICML_Data_Value * type)
: type_ (type)
{

}

//
// ~PICML_Sequence_Data_Value
//
PICML_Sequence_Data_Value::~PICML_Sequence_Data_Value (void)
{
  container_type::iterator
    iter = this->sequence_.begin (),
    iter_end = this->sequence_.end ();

  for ( ; iter != iter_end; iter ++)
    delete *iter;
}

void PICML_Sequence_Data_Value::
accept (PICML_Data_Value_Visitor & visitor)
{
  visitor.visit_PICML_Sequence_Data_Value (*this);
}

//
// operator []
//
PICML_Data_Value * PICML_Sequence_Data_Value::
operator [] (int index)
{
  return this->sequence_[index];
}

//
// operator []
//
const PICML_Data_Value * PICML_Sequence_Data_Value::
operator [] (int index) const
{
  return this->sequence_[index];
}

//
// begin
//
PICML_Sequence_Data_Value::iterator
PICML_Sequence_Data_Value::begin (void)
{
  return this->sequence_.begin ();
}

//
// begin
//
PICML_Sequence_Data_Value::const_iterator
PICML_Sequence_Data_Value::begin (void) const
{
  return this->sequence_.begin ();
}

//
// end
//
PICML_Sequence_Data_Value::iterator
PICML_Sequence_Data_Value::end (void)
{
  return this->sequence_.end ();
}

//
// end
//
PICML_Sequence_Data_Value::const_iterator
PICML_Sequence_Data_Value::end (void) const
{
  return this->sequence_.end ();
}

//
// size
//
size_t PICML_Sequence_Data_Value::size (void) const
{
  return this->sequence_.size ();
}

//
// _create
//
PICML_Data_Value * PICML_Sequence_Data_Value::_create (void) const
{
  PICML_Sequence_Data_Value * value =
    new PICML_Sequence_Data_Value (this->type_);

  return value;
}

//
// new_element
//
PICML_Data_Value * PICML_Sequence_Data_Value::new_element (void)
{
  PICML_Data_Value * value = this->type_->_create ();
  this->sequence_.push_back (value);

  return value;
}

//
// value
//
void PICML_Sequence_Data_Value::value (const std::string & value)
{
  this->PICML_Data_Value::value (value);

  PICML_Data_Value_Parser parser (this, PICML_Data_Value_Parser::PARSER_SEQUENCE);
  boost::spirit::parse (value.c_str (), parser, boost::spirit::space_p);
}
