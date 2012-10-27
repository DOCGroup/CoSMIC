#ifndef _MATH_OP_IMPL_H_
#define _MATH_OP_IMPL_H_

#include "math_op.hpp"

template <typename IteratorT>
math_op <IteratorT>::math_op (void)
: math_op::base_type (math_op_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->math_op_ = ascii::string ("+");
}

#endif