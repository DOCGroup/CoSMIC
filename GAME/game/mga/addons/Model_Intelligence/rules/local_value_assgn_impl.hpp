#ifndef _LOCAL_VALUE_ASSGN_IMPL_H_
#define _LOCAL_VALUE_ASSGN_IMPL_H_

#include "local_value_assgn.hpp"

template <typename IteratorT>
local_value_assgn <IteratorT>::local_value_assgn (void)
: local_value_assgn::base_type (lv_assgn_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

  this->lv_assgn_expr_ = qi::lit ("let") >>
			this->ident_[qi::_a = qi::_1] >>
			-(qi::lit (":") >> this->ident_) >>
      qi::lit ("=") >>
			this->value_expr_[qi::_val = phoenix::new_<Local_Value_Assignment_Expr> (qi::_a, qi::_1)] >>
      qi::lit ("in");	 
}

#endif