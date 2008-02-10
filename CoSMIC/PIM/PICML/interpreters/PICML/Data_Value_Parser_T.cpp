// $Id$

#include "boost/bind.hpp"
#include "boost/spirit/utility/confix.hpp"
#include "boost/spirit/utility/lists.hpp"

//
// definition
//
template <typename ScannerT>
PICML_Data_Value_Parser::
definition <ScannerT>::definition (PICML_Data_Value_Parser const & self)
{
  using namespace boost::spirit;

  this->operators_ =
    ch_p (';') | '[' | ']' | '{' | '}';

  this->name_ =
    lexeme_d [alpha_p >> *(alnum_p | '_')];

  this->string_ =
    confix_p ('\"', *boost::spirit::anychar_p, '\"');

  this->value_ =
    longest_d [this->sequence_ | this->struct_ |
      this->string_ | *(anychar_p - this->operators_)];

  this->member_name_ =
    this->name_[boost::bind (&PICML_Data_Value_Parser::select_member, boost::ref (self), _1, _2)];

  this->member_value_ =
    this->value_[boost::bind (&PICML_Data_Value_Parser::set_member_value, boost::ref (self), _1, _2)];

  this->member_ =
    this->member_name_ >> "=" >> this->member_value_;

  this->member_list_ = list_p (this->member_, ';');

  this->sequence_value_ =
    this->value_[boost::bind (&PICML_Data_Value_Parser::insert_sequence_value, boost::ref (self), _1, _2)];

  this->sequence_list_ = list_p (this->sequence_value_, ';');

  this->sequence_ = confix_p ('[', this->sequence_list_, ']');

  this->struct_ = confix_p ('{', this->member_list_, '}');

  switch (self.type ())
  {
  case PICML_Data_Value_Parser::PARSER_SEQUENCE:
    this->start_ = this->sequence_;
    break;

  case PICML_Data_Value_Parser::PARSER_STRUCT:
    this->start_ = this->struct_;
    break;
  }
}

//
// start
//
template <typename ScannerT>
const boost::spirit::rule <ScannerT> &
PICML_Data_Value_Parser::definition <ScannerT>::start (void) const
{
  return this->start_;
}
