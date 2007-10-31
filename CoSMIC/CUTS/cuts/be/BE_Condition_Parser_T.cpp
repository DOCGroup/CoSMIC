// $Id$

#include "BE_Generators_T.h"
#include "boost/spirit/utility/confix.hpp"

//
// definition
//
template <typename BE_STRATEGY>
template <typename ScannerT>
CUTS_BE_Condition_Parser_T <BE_STRATEGY>::
definition <ScannerT>::definition (const CUTS_BE_Condition_Parser_T & self)
{
  this->comp_op_ =
    boost::spirit::str_p ("==") [&CUTS_BE_Equal_To_T <BE_STRATEGY>::generate] |
    boost::spirit::str_p ("!=") [&CUTS_BE_Not_Equal_To_T <BE_STRATEGY>::generate] |
    boost::spirit::str_p (">") [&CUTS_BE_Greater_Than_T <BE_STRATEGY>::generate] |
    boost::spirit::str_p (">=") [&CUTS_BE_Greater_Than_Equal_To_T <BE_STRATEGY>::generate] |
    boost::spirit::str_p ("<") [&CUTS_BE_Less_Than_T <BE_STRATEGY>::generate] |
    boost::spirit::str_p ("<=") [&CUTS_BE_Less_Than_Equal_To_T <BE_STRATEGY>::generate];

  this->join_op_ =
    boost::spirit::as_lower_d["and"][&CUTS_BE_And_T <BE_STRATEGY>::generate] |
    boost::spirit::as_lower_d["or"][&CUTS_BE_Or_T <BE_STRATEGY>::generate];

  this->variable_ =
    boost::spirit::lexeme_d [
      (boost::spirit::alpha_p | boost::spirit::ch_p ('_')) >>
        *(boost::spirit::alnum_p | boost::spirit::ch_p ('_'))];

  this->number_ =
    boost::spirit::lexeme_d [*boost::spirit::digit_p];

  this->string_ =
    boost::spirit::confix_p ('\"', *boost::spirit::anychar_p, '\"');

  // This part of the entire parser is broken. I still haven't
  // figured out how to parse characters.
  this->char_ =
    boost::spirit::confix_p ('\'', boost::spirit::anychar_p, '\'');

  this->ident_ =
      this->variable_ [&CUTS_BE_Identifier_T <BE_STRATEGY>::generate] |
      this->string_ [&CUTS_BE_Transcribe_Text_T <BE_STRATEGY>::generate] |
      this->number_ [&CUTS_BE_Transcribe_Text_T <BE_STRATEGY>::generate] |
      this->char_ [&CUTS_BE_Transcribe_Text_T <BE_STRATEGY>::generate];

  this->expr_ =
    this->ident_ >> this->comp_op_ >> this->ident_;

  this->group_ =
    boost::spirit::ch_p ('(')[&CUTS_BE_Transcribe_Char_T <BE_STRATEGY>::generate] >>
    this->condition_ >>
    boost::spirit::ch_p (')')[&CUTS_BE_Transcribe_Char_T <BE_STRATEGY>::generate];

  this->condition_ =
    (this->group_ | this->expr_) >> *(this->join_op_ >> this->condition_);
}

//
// start
//
template <typename BE_STRATEGY>
template <typename ScannerT>
const boost::spirit::rule <ScannerT> &
CUTS_BE_Condition_Parser_T <BE_STRATEGY>::
definition <ScannerT>::start (void) const
{
  return this->condition_;
}
