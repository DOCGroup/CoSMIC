#ifndef _VALUE_SUB_IMPL_H_
#define _VALUE_SUB_IMPL_H_

#include "value_sub.hpp"

template <typename IteratorT>
value_sub <IteratorT>::value_sub (void)
: value_sub::base_type (value_subexpr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

  this->value_subexpr_ %=   this->method_call_ | this->cv_expr_
			| this->attribute_expr_ | this->lv_expr_;
}

#endif