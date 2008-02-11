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

  this->ident_ =
    lexeme_d [alpha_p >> *(alnum_p | '_')];

  this->operators_ =
    boost::spirit::ch_p (';') | ']' | '}';

  this->string_ =
    confix_p ('\"', *boost::spirit::anychar_p, '\"');

  this->struct_value_ =
    confix_p ('{', *boost::spirit::anychar_p, '}');

  this->sequence_value_ =
    confix_p ('[', *boost::spirit::anychar_p, ']');

  this->value_ = boost::spirit::longest_d [
    this->struct_value_ | this->sequence_value_ |
    this->string_ | *(anychar_p - this->operators_)];

  this->member_name_ =
    this->ident_[boost::bind (&PICML_Data_Value_Parser::aggregate_member,
                              boost::ref (self), _1, _2)];

  this->member_value_ =
    this->value_[boost::bind (&PICML_Data_Value_Parser::aggregate_member_value,
                              boost::ref (self), _1, _2)];

  this->member_ =
    this->member_name_ >> "=" >> this->member_value_;

  this->member_list_ =
    list_p (this->member_, ';');

  this->sequence_item_ =
    this->value_[boost::bind (&PICML_Data_Value_Parser::insert_sequence_value,
                              boost::ref (self), _1, _2)];

  this->sequence_list_ =
    list_p (this->sequence_item_, ';');

  this->sequence_ =
    boost::spirit::confix_p ('[', this->sequence_list_, ']');

  this->struct_ =
    boost::spirit::confix_p ('{', this->member_list_, '}');

  this->start_parsers (this->struct_, this->sequence_);
}
