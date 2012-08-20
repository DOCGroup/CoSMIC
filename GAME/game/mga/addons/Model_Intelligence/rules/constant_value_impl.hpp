#ifndef _CONSTANT_VALUE_IMPL_H_
#define _CONSTANT_VALUE_IMPL_H_

#include "constant_value.hpp"

template <typename IteratorT>
constant_value <IteratorT>::constant_value (void)
: constant_value::base_type (cv_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

  this->cv_expr_ = this->integer_[qi::_val = phoenix::new_ <Constant_Value_Expr> (qi::_1)] |
    this->quoted_string_[qi::_val = phoenix::new_ <Constant_Value_Expr> (qi::_1)];

  this->integer_ %= qi::uint_;
}

#endif