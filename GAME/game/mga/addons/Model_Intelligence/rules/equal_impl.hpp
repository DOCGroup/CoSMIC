#ifndef _EQUAL_IMPL_H_
#define _EQUAL_IMPL_H_

#include "equal.hpp"

template <typename IteratorT>
equal <IteratorT>::equal (void)
: equal::base_type (equal_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

  this->equal_expr_ = ((qi::lit ("(")) >>
    this->value_expr_ [qi::_a = qi::_1] >> qi::lit ("=") >> 
    this->value_expr_ [qi::_val = phoenix::new_<Equal_Expr> (qi::_a, qi::_1)] >>
    (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >> 
    qi::lit ("=") >> this->value_expr_ [qi::_val = phoenix::new_<Equal_Expr> (qi::_a, qi::_1)]);
}

#endif