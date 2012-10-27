#ifndef _LESSER_IMPL_H_
#define _LESSER_IMPL_H_

#include "lesser.hpp"

template <typename IteratorT>
lesser <IteratorT>::lesser (void)
: lesser::base_type (lesser_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->lesser_expr_ =
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<") >>
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<") >>
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Expr> (qi::_a, qi::_1)]);

}

#endif