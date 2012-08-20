#ifndef _LOCAL_VALUE_IMPL_H_
#define _LOCAL_VALUE_IMPL_H_

#include "local_value.hpp"

template <typename IteratorT>
local_value <IteratorT>::local_value (void)
: local_value::base_type (lv_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

  this->lv_expr_ = this->ident_[qi::_val = phoenix::new_ <Local_Value_Expr> (qi::_1)];
}

#endif