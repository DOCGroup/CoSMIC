#ifndef _RAISES_EXPR_IMPL_H_
#define _RAISES_EXPR_IMPL_H_

#include "raises_expr.hpp"
#include "t3/runtime/actors.hpp"

template <typename IteratorT>
const char * raises_expr <IteratorT>::strlit_ [] =
{
  "ExceptionRef"
};

template <typename IteratorT>
raises_expr <IteratorT>::raises_expr (void)
: base_type (raises_expr_)
{
  this->raises_expr_ =
    qi::lit ("raises") >>
    qi::lit ('(') >>
    this->scoped_name_[T3::new_unique_reference (this->strlit_[0])] >>
    * (qi::lit (',') >> this->scoped_name_[T3::new_unique_reference (this->strlit_[0])]) >>
    qi::lit (')');
}


#endif
