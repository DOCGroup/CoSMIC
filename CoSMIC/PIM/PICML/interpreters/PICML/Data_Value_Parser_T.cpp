// $Id$

#include "boost/spirit/utility/confix.hpp"
#include "boost/bind.hpp"

//
// definition
//
template <typename ScannerT>
PICML_Data_Value_Parser::
definition <ScannerT>::definition (PICML_Data_Value_Parser const & self)
{
  this->name_ =
    boost::spirit::lexeme_d [
      (boost::spirit::alpha_p | boost::spirit::ch_p ('_')) >>
        *(boost::spirit::alnum_p | boost::spirit::ch_p ('_'))];

  this->string_ =
    boost::spirit::confix_p ('\"', *boost::spirit::anychar_p, '\"');

  this->value_ =
    this->string_ | *(boost::spirit::anychar_p - ';') |
    this->sequence_ | this->struct_;

  this->member_ =
    this->name_[boost::bind (&PICML_Data_Value_Parser::select_member,
                             boost::ref (self), _1, _2)] >>
    '=' >>
    this->value_[boost::bind (&PICML_Data_Value_Parser::set_member_value,
                              boost::ref (self), _1, _2)];

  this->member_list_ =
    this->member_ >> *(';' >> this->member_);

  this->struct_ =
    boost::spirit::confix_p ('{', this->member_list_, '}');

  this->sequence_list_ =
    this->value_ >> *(';' >> this->value_);

  this->sequence_ =
    boost::spirit::confix_p ('[', this->sequence_list_, ']');

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
