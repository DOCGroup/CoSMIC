#ifndef _GREATER_IMPL_H_
#define _GREATER_IMPL_H_

#include "greater.hpp"

template <typename IteratorT>
greater <IteratorT>::greater (void)
: greater::base_type (greater_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->greater_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Expr> (qi::_a, qi::_1)]);
 
}

#endif