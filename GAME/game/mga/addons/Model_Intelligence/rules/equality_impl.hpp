#ifndef _EQUALITY_IMPL_H_
#define _EQUALITY_IMPL_H_

#include "equality.hpp"

template <typename IteratorT>
equality <IteratorT>::equality (void)
: equality::base_type (eq_expr_)
{
   namespace qi = boost::spirit::qi;
   namespace phoenix = boost::phoenix;
   namespace ascii = boost::spirit::ascii;
   namespace repo = boost::spirit::repository;

   this->eq_expr_ =
      ((this->comp_expr_[phoenix::push_back (qi::_b, qi::_1)] | 
        repo::confix ('(', ')')[this->eq_expr_[phoenix::push_back (qi::_b, qi::_1)]]) >>
      (*(this->conjunction_[phoenix::push_back (qi::_a, qi::_1)] >> 
          this->eq_expr_[phoenix::push_back (qi::_b, qi::_1)])
          [phoenix::bind (&operate, qi::_a, qi::_b)]))[qi::_val = phoenix::back (qi::_b)];
 
}

//
// operate 
//
void operate (std::deque <std::string>& op_, std::deque <Equality_Expr *>& eq_)
{
  namespace qi = boost::spirit::qi;
  namespace phoenix = boost::phoenix;

  if (op_.back () == "and")
  {
    op_.pop_back ();
    Equality_Expr * eq1 = eq_.back ();
    eq_.pop_back ();
    Equality_Expr * eq2 = eq_.back ();
    eq_.pop_back ();
    eq_.push_back (new And_Expr (eq2, eq1));
  }
  else if (op_.back () == "or")
  {
    op_.pop_back ();
    Equality_Expr * eq1 = eq_.back ();
    eq_.pop_back ();
    Equality_Expr * eq2 = eq_.back ();
    eq_.pop_back ();
    eq_.push_back (new Or_Expr (eq2, eq1));
  }
}


#endif