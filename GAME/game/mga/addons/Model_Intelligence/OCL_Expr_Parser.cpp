// $Id: OCL_Expr_Parser.cpp 2908 2012-06-10 18:21:53Z tpati $

#include "StdAfx.h"

#include <fstream>

#include "OCL_Expr_Parser.h"
#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include <string>
#include <stack>
#include <functional>

#include "Equality_Expr.h"
#include "Local_Value_Expr.h"
#include "Equal_Expr.h"
#include "Not_Equal_Expr.h"
#include "Greater_Equal_Expr.h"
#include "Greater_Expr.h"
#include "Lesser_Equal_Expr.h"
#include "Lesser_Expr.h"
#include "Constant_Value_Expr.h"
#include "Local_Value_Assignment_Expr.h"
#include "If_Then_Else_Expr.h"
#include "IteratorCall_Expr.h"
#include "Value_Expr.h"
#include "Comparison_Expr.h"
#include "Conjunction_Expr.h"
#include "And_Expr.h"
#include "Or_Expr.h"

#include "Method_Call.h"
#include "Self_Method_Call.h"
#include "Local_Value_Method_Call.h"

#include "Iterator.h"
#include "ForAll_Iterator.h"
#include "Exists_Iterator.h"
#include "IsUnique_Iterator.h"
#include "One_Iterator.h"

#include "Attribute_Expr.h"

#include "Math_Operation_Expr.h"
#include "Addition_Operation.h"
#include "Value_SubExpr.h"

#include "Method_Parser.cpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 


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

/**
 * @class OCL_Expression_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
struct OCL_Expression_Parser_Grammar :
  public qi::grammar <IteratorT,
                      std::vector <Boolean_Expr *> (),
                      ascii::space_type>
{
  OCL_Expression_Parser_Grammar (void)
    : OCL_Expression_Parser_Grammar::base_type (ocl_statements_),
			ocl_statements_ (std::string ("ocl_statements"))
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

    this->lv_assgn_expr_ = qi::lit ("let") >>
			this->ident_[qi::_a = qi::_1] >>
			-(qi::lit (":") >> this->ident_) >>
      qi::lit ("=") >>
			this->value_expr_[qi::_val = phoenix::new_<Local_Value_Assignment_Expr> (qi::_a, qi::_1)] >>
      qi::lit ("in");	

		this->if_then_else_expr_ = qi::lit ("if") >>
			repo::confix ('(',')')[this->eq_expr_[qi::_a = qi::_1]] >> 
			qi::lit ("then") >> this->ocl_statements_[qi::_b = qi::_1] >> 
			qi::lit("else") >> 
			this->ocl_statements_[qi::_val = phoenix::new_<If_Then_Else_Expr> (qi::_a, qi::_b, qi::_1)] >>
			qi::lit ("endif");

    this->eq_expr_ =
      ((this->comp_expr_[phoenix::push_back (qi::_b, qi::_1)] | 
        repo::confix ('(', ')')[this->eq_expr_[phoenix::push_back (qi::_b, qi::_1)]]) >>
      (*(this->conjunction_[phoenix::push_back (qi::_a, qi::_1)] >> 
          this->eq_expr_[phoenix::push_back (qi::_b, qi::_1)])
          [phoenix::bind (&operate, qi::_a, qi::_b)]))[qi::_val = phoenix::back (qi::_b)];

    /*this->value_expr_ %=   this->method_call_ | this->cv_expr_
			| this->attribute_expr_ | this->lv_expr_;*/

    this->value_expr_ =  (this->value_subexpr_[phoenix::push_back (qi::_b, qi::_1)] >>
			(*(this->math_op_[phoenix::push_back (qi::_a, qi::_1)] >>
			this->value_subexpr_[phoenix::push_back (qi::_b, qi::_1)])[phoenix::bind (&solve, qi::_a, qi::_b)]))
			[qi::_val = phoenix::back (qi::_b)];

    this->value_subexpr_ %=   this->method_call_ | this->cv_expr_
			| this->attribute_expr_ | this->lv_expr_;

    this->comp_expr_ %= 
      this->equal_expr_ | this->greater_equal_expr_ | this->lesser_equal_expr_ |
      this->not_equal_expr_ | this->greater_expr_ | this->lesser_expr_;
     
    this->equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Equal_Expr> (qi::_a, qi::_1)]);

    this->not_equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<>") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Not_Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<>") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Not_Equal_Expr> (qi::_a, qi::_1)]);

		this->greater_equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Equal_Expr> (qi::_a, qi::_1)]);

    this->greater_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Expr> (qi::_a, qi::_1)]);

		this->lesser_equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Equal_Expr> (qi::_a, qi::_1)]);

    this->lesser_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Expr> (qi::_a, qi::_1)]);

    this->conjunction_ = ascii::string ("and") | ascii::string ("or");

    this->math_op_ = ascii::string ("+");

		this->method_call_ = this->self_method_call_ | this->lv_method_call_;

		this->self_method_call_ = qi::lit ("self")>>
			(qi::lit (".") | qi::lit ("->")) >>
			this->method_ [qi::_val = phoenix::new_ <Self_Method_Call> (qi::_1)] >>
			this->method_list_ [phoenix::bind (&Method_Call::set_next, qi::_val, qi::_1)];

		this->lv_method_call_ = this->ident_ [qi::_a = qi::_1] >>
			(qi::lit (".") | qi::lit ("->")) >>
			this->method_ [qi::_val = phoenix::new_ <Local_Value_Method_Call> (qi::_a, qi::_1)] >>
			this->method_list_ [phoenix::bind (&Method_Call::set_next, qi::_val, qi::_1)];

		this->method_list_ = *( (qi::lit ("->") | qi::lit (".")) >>
			                       this->method_[phoenix::push_back (qi::_val, qi::_1)] );

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

    this->iterator_ %= this->forall_iterator_ | this->isunique_iterator_ | this->exists_iterator_ |
      this->one_iterator_;

    this->forall_iterator_ = qi::lit ("forAll")[qi::_val = phoenix::new_ <ForAll_Iterator> ()];

    this->isunique_iterator_ = qi::lit ("isUnique")[qi::_val = phoenix::new_ <IsUnique_Iterator> ()];

    this->exists_iterator_ = qi::lit ("exists")[qi::_val = phoenix::new_ <Exists_Iterator> ()];

    this->one_iterator_ = qi::lit ("one")[qi::_val = phoenix::new_ <One_Iterator> ()];

    this->declarator_list_ = (this->ident_[phoenix::push_back (qi::_val, qi::_1)] >>
      *(qi::lit(",") >> this->ident_[phoenix::push_back (qi::_val, qi::_1)]));

    this->lv_expr_ = this->ident_[qi::_val = phoenix::new_ <Local_Value_Expr> (qi::_1)];

    this->cv_expr_ = this->integer_[qi::_val = phoenix::new_ <Constant_Value_Expr> (qi::_1)] | 
			this->quoted_string_[qi::_val = phoenix::new_ <Constant_Value_Expr> (qi::_1)];

		this->attribute_expr_ = this->ident_[qi::_a = qi::_1] >>
			qi::lit (".") >>
			this->ident_[qi::_val = phoenix::new_<Attribute_Expr> (qi::_a, qi::_1)];

    this->ident_ %= 
			qi::lexeme[(ascii::char_('_') | qi::alpha) >>
			*(ascii::char_('_') | qi::alnum)];

    this->integer_ %= qi::uint_;

    this->quoted_string_ %= qi::lexeme[qi::lit ('"') >> *(qi::char_ - '"') >> qi::lit ('"')];
  }

	void enable_debugging (void)
	{
		debug (ocl_statements_);
	}

private:
  qi::rule <IteratorT,
            std::vector <Boolean_Expr *> (),
            ascii::space_type> ocl_statements_;

  qi::rule <IteratorT,
            Boolean_Expr * (),
            ascii::space_type> bool_expr_;

  qi::rule <IteratorT,
            Equality_Expr * (),
            ascii::space_type,
            qi::locals <std::deque <std::string>, 
                        std::deque <Equality_Expr *> > > eq_expr_;

	qi::rule <IteratorT,
            If_Then_Else_Expr * (),
            ascii::space_type,
            qi::locals <Equality_Expr *, 
                        std::vector <Boolean_Expr *>,
						            std::vector <Boolean_Expr *> > > if_then_else_expr_;

  qi::rule <IteratorT,
            Local_Value_Assignment_Expr * (),
            ascii::space_type,
            qi::locals <std::string>> lv_assgn_expr_;

  qi::rule <IteratorT,
            Equal_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> equal_expr_;

   qi::rule <IteratorT,
            Not_Equal_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> not_equal_expr_;

	qi::rule <IteratorT,
            Greater_Equal_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> greater_equal_expr_;

  qi::rule <IteratorT,
            Greater_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> greater_expr_;

	qi::rule <IteratorT,
            Lesser_Equal_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> lesser_equal_expr_;

  qi::rule <IteratorT,
            Lesser_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> lesser_expr_;

  qi::rule <IteratorT,
            Comparison_Expr * (),
            ascii::space_type> comp_expr_;

  qi::rule <IteratorT,
            Value_Expr * (),
            ascii::space_type,
	          qi::locals <std::deque <std::string>, 
                        std::deque <Value_Expr *> >> value_expr_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> math_op_;

  qi::rule <IteratorT,
            Value_SubExpr * (),
            ascii::space_type> value_subexpr_;

  qi::rule <IteratorT,
            Local_Value_Expr * (),
            ascii::space_type> lv_expr_;

  qi::rule <IteratorT,
            Constant_Value_Expr * (),
            ascii::space_type> cv_expr_;

	qi::rule <IteratorT,
            Attribute_Expr * (),
            ascii::space_type,
	          qi::locals <std::string>> attribute_expr_;

	qi::rule <IteratorT,
            Method_Call * (),
            ascii::space_type> method_call_;

	qi::rule <IteratorT,
            Self_Method_Call * (),
            ascii::space_type> self_method_call_;

	qi::rule <IteratorT,
            Local_Value_Method_Call * (),
            ascii::space_type,
            qi::locals <std::string>> lv_method_call_;

	qi::rule <IteratorT,
            std::vector <Method *> (),
            ascii::space_type> method_list_;

  qi::rule <IteratorT,
            IteratorCall_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *, 
                        Iterator *,
						            Boolean_Expr *,
                        std::vector <std::string>,
                        std::string,
                        Value_Expr *> > iteratorcall_expr_;

  qi::rule <IteratorT,
            Iterator * (),
            ascii::space_type> iterator_;

  qi::rule <IteratorT,
            std::vector <std::string> (),
            ascii::space_type> declarator_list_;

  qi::rule <IteratorT,
            ForAll_Iterator * (),
            ascii::space_type> forall_iterator_;

  qi::rule <IteratorT,
            IsUnique_Iterator * (),
            ascii::space_type> isunique_iterator_;

  qi::rule <IteratorT,
            Exists_Iterator * (),
            ascii::space_type> exists_iterator_;

  qi::rule <IteratorT,
            One_Iterator * (),
            ascii::space_type> one_iterator_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> ident_;

  Method_Parser_Grammar <IteratorT> method_;

  qi::rule <IteratorT,
            unsigned int (),
            ascii::space_type> integer_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> conjunction_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> quoted_string_;
};


///////////////////////////////////////////////////////////////////////////////
// class OASIS_Expr_Parser

OCL_Expr_Parser::OCL_Expr_Parser(void)
{
}

OCL_Expr_Parser::~OCL_Expr_Parser(void)
{
}

bool OCL_Expr_Parser::
parse_string (std::string str, std::vector <Boolean_Expr*> &ocl)
{
  namespace spirit = boost::spirit;

  std::string::const_iterator begin_iter = str.begin();
  std::string::const_iterator end_iter = str.end();

	OCL_Expression_Parser_Grammar <std::string::const_iterator> g;
	g.enable_debugging ();

  bool retval = qi::phrase_parse (begin_iter,
                                  end_iter,
                                  g,
                                  ascii::space,
                                  ocl);
  return retval;
}

