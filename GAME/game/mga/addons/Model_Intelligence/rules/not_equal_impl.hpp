#ifndef _NOT_EQUAL_IMPL_H_
#define _NOT_EQUAL_IMPL_H_

#include "not_equal.hpp"

template <typename IteratorT>
not_equal <IteratorT>::not_equal (void)
: not_equal::base_type (not_equal_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

    this->not_equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<>") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Not_Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<>") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Not_Equal_Expr> (qi::_a, qi::_1)]); 
}

#endif