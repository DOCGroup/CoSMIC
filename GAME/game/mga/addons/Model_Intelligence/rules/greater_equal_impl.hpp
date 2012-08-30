#ifndef _GREATER_EQUAL_IMPL_H_
#define _GREATER_EQUAL_IMPL_H_

#include "greater_equal.hpp"

template <typename IteratorT>
greater_equal <IteratorT>::greater_equal (void)
: greater_equal::base_type (greater_equal_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

		this->greater_equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Equal_Expr> (qi::_a, qi::_1)]);
}

#endif