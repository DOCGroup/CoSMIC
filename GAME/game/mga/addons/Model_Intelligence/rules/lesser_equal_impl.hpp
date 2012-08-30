#ifndef _LESSER_EQUAL_IMPL_H_
#define _LESSER_EQUAL_IMPL_H_

#include "lesser_equal.hpp"

template <typename IteratorT>
lesser_equal <IteratorT>::lesser_equal (void)
: lesser_equal::base_type (lesser_equal_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->lesser_equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Equal_Expr> (qi::_a, qi::_1)]);
 
}

#endif