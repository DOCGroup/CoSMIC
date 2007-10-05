// $Id$

//
// definition
//
template <typename BE_STRATEGY>
template <typename ScannerT>
CUTS_BE_Condition_Parser_T <BE_STRATEGY>::
definition <ScannerT>::definition (const CUTS_BE_Condition_Parser_T & self)
{
  this->comp_op_ =
    boost::spirit::str_p ("==") | boost::spirit::str_p ("!=") |
    boost::spirit::str_p (">") | boost::spirit::str_p (">=") |
    boost::spirit::str_p ("<") | boost::spirit::str_p ("<=");

  this->variable_ =
    boost::spirit::lexeme_d [
      (boost::spirit::alpha_p | boost::spirit::ch_p ('_')) >>
        *(boost::spirit::alnum_p | boost::spirit::ch_p ('_'))];

  this->number_ =
    boost::spirit::lexeme_d [*(boost::sprirt::digit_p)];

  this->string_ =
    boost::spirit::ch_p ('"') >> *(boost::spirit::anychar_p) >>
    boost::spirit::ch_p ('"');

  this->char_ =
    boost::spirit::ch_p ('\'') >> boost::spirit::anychar_p >>
    boost::spirit::ch_p ('\'');

  this->ident_ =
    this->variable_ | this->number_ | this->char_ | this->string_ ;

  this->expr_ =
    this->ident_ |
    this->ident_ >> this->comp_op_ >> this->ident_ >>
      *(this->comp_op_ >> this->expr_);

  this->group_ =
    boost::spirit::ch_p ('(') >> this->expr_ >> boost::spirit::ch_p (')');

  this->condition_ =
    this->expr_ |
    this->group_ >> *(this->comp_op_ >> this->condition_);


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
