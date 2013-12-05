#ifndef _PREPROCESSOR_IMPL_H_
#define _PREPROCESSOR_IMPL_H_

#include "preprocessor.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
preprocessor <IteratorT>::preprocessor (void)
: base_type (preprocessor_)
{
  this->preprocessor_ =
    this->include_stmt_ (qi::_r1) |
    this->pragma_stmt_ (qi::_r1) |
    this->hashdef_ (qi::_r1);

  this->include_stmt_ =
    (qi::lit ("#include") >> qi::lit ('"') >> this->usr_filepath_[T3::preprocess ()] >> qi::lit ('"')) |
    (qi::lit ("#include") >> qi::lit ('<') >> this->sys_filepath_[T3::preprocess ()] >> qi::lit ('>'));

  this->hashdef_ =
    (qi::lit ("#ifndef") >> this->ident_) |
    (qi::lit ("#define") >> this->ident_) |
     qi::lit ("#endif");

  this->usr_filepath_ %=
    qi::lexeme[*(qi::char_ - '"')];

  this->sys_filepath_ %=
    qi::lexeme[*(qi::char_ - '>')];
}

#endif  // !defined _STRING_TYPE_IMPL_H_
