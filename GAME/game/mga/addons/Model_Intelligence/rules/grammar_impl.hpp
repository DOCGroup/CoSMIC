#ifndef _GRAMMAR_IMPL_H_
#define _GRAMMAR_IMPL_H_

#include "grammar.hpp"

template <typename IteratorT>
OCL_Expression_Parser_Grammar <IteratorT>::OCL_Expression_Parser_Grammar (void)
: OCL_Expression_Parser_Grammar::base_type (ocl_statements_)
{
    namespace qi = boost::spirit::qi;
    namespace phoenix = boost::phoenix;
    namespace ascii = boost::spirit::ascii;
    namespace repo = boost::spirit::repository;
    
    // The base rule
    this->ocl_statements_ %= +(this->bool_expr_);

    // Boolean expressions
    this->bool_expr_ %= this->lv_assgn_expr_ | this->eq_expr_ | this->if_then_else_expr_
      | this->iteratorcall_expr_;

    this->if_then_else_expr_ = qi::lit ("if") >>
			repo::confix ('(',')')[this->eq_expr_[qi::_a = qi::_1]] >> 
			qi::lit ("then") >> this->ocl_statements_[qi::_b = qi::_1] >> 
			qi::lit("else") >> 
			this->ocl_statements_[qi::_val = phoenix::new_<If_Then_Else_Expr> (qi::_a, qi::_b, qi::_1)] >>
			qi::lit ("endif");

     this->iteratorcall_expr_ = this->value_expr_ [qi::_a = qi::_1][qi::_e = ""] >> 
      qi::lit ("->") >> this->iterator_ [qi::_b = qi::_1] >> qi::lit("(") >>
      -(this->declarator_list_[qi::_d = qi::_1] >>
      qi::lit (":") >> this->ident_[qi::_e = qi::_1] >>
      qi::lit ("|")) >> 
      ((this->bool_expr_[qi::_c = qi::_1] >>
         qi::lit(")")[qi::_val = phoenix::new_ <IteratorCall_Expr> (qi::_a, qi::_b, qi::_c)]) |
       (this->value_expr_[qi::_f = qi::_1] >>
         qi::lit(")")[qi::_val = phoenix::new_ <IteratorCall_Expr> (qi::_a, qi::_b, qi::_f)]))
      [phoenix::bind (&IteratorCall_Expr::set_declarators, qi::_val, qi::_d)]
      [phoenix::bind (&IteratorCall_Expr::set_dec_type, qi::_val, qi::_e)];    
  }

#endif