#ifndef _VALUE_IMPL_H_
#define _VALUE_IMPL_H_

#include "value.hpp"

template <typename IteratorT>
value <IteratorT>::value (void)
: value::base_type (value_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->value_expr_ =  (this->value_subexpr_[phoenix::push_back (qi::_b, qi::_1)] >>
			(*(this->math_op_[phoenix::push_back (qi::_a, qi::_1)] >>
			this->value_subexpr_[phoenix::push_back (qi::_b, qi::_1)])[phoenix::bind (&solve, qi::_a, qi::_b)]))
			[qi::_val = phoenix::back (qi::_b)]; 
}

//
// solve
//
void solve (std::deque <std::string>& math_, std::deque <Value_Expr *>& val_)
{
	if (math_.back () == "+")
  {
    math_.pop_back ();
    Value_Expr * val1 = val_.back ();
    val_.pop_back ();
    Value_Expr * val2 = val_.back ();
    val_.pop_back ();
    val_.push_back (new Addition_Operation (val2, val1));
  }
}

#endif