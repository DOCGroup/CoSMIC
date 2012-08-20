#ifndef _ATTRIBUTE_IMPL_H_
#define _ATTRIBUTE_IMPL_H_

#include "attribute.hpp"

template <typename IteratorT>
attribute <IteratorT>::attribute (void)
: attribute::base_type (attribute_expr_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;
  namespace ascii = boost::spirit::ascii;
  namespace repo = boost::spirit::repository;

  this->attribute_expr_ = this->ident_[qi::_a = qi::_1] >>
    qi::lit (".") >>
    this->ident_[qi::_val = phoenix::new_<Attribute_Expr> (qi::_a, qi::_1)];
}

#endif