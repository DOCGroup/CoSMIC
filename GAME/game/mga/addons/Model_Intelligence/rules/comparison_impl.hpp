#ifndef _COMPARISON_IMPL_H_
#define _COMPARISON_IMPL_H_

#include "comparison.hpp"

template <typename IteratorT>
comparison <IteratorT>::comparison (void)
: comparison::base_type (comp_expr_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->comp_expr_ %= this->equal_expr_ | this->greater_equal_expr_ | 
    this->lesser_equal_expr_ | this->not_equal_expr_ | this->greater_expr_ | this->lesser_expr_;
}

#endif