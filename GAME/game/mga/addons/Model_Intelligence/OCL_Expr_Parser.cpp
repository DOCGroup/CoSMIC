// $Id$

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
#include "Greater_Equal_Expr.h"
#include "Lesser_Equal_Expr.h"
#include "Constant_Value_Expr.h"
#include "Local_Value_Assignment_Expr.h"
#include "If_Then_Else_Expr.h"
#include "Value_Expr.h"
#include "Comparison_Expr.h"
#include "Conjunction_Expr.h"
#include "And_Expr.h"

#include "Method_Call.h"
#include "Self_Method_Call.h"
#include "Local_Value_Method_Call.h"

#include "Method.h"
#include "Parts_Method.h"
#include "Size_Method.h"
#include "Refers_to_Method.h"
#include "Name_Method.h"
#include "KindName_Method.h"
#include "Parent_Method.h"
#include "ChildFolders_Method.h"
#include "RoleName_Method.h"

#include "Attribute_Expr.h"

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
    this->bool_expr_ %= this->lv_assgn_expr_ | this->eq_expr_ | this->if_then_else_expr_;

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
          this->eq_expr_[phoenix::push_back (qi::_b, qi::_1)])[phoenix::bind (&operate, qi::_a, qi::_b)]))[qi::_val = phoenix::back (qi::_b)];

    this->comp_expr_ %= 
      this->equal_expr_ | this->greater_equal_expr_ | this->lesser_equal_expr_;
     
    this->equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Equal_Expr> (qi::_a, qi::_1)]);

		this->greater_equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit (">=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Greater_Equal_Expr> (qi::_a, qi::_1)]);

		this->lesser_equal_expr_ = 
      ((qi::lit ("(")) >>
      this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Equal_Expr> (qi::_a, qi::_1)] >>
      (qi::lit (")"))) | (this->value_expr_ [qi::_a = qi::_1] >>
      qi::lit ("<=") >> 
      this->value_expr_ [qi::_val = phoenix::new_<Lesser_Equal_Expr> (qi::_a, qi::_1)]);

    this->conjunction_ = ascii::string ("and");

		this->value_expr_ %=   this->method_call_ | this->cv_expr_
			| this->attribute_expr_ | this->lv_expr_;

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

		this->method_ %= this->parts_method_ | this->size_method_ | this->refers_to_method_ |
			this->name_method_ | this->kindname_method_ | this->parent_method_ | this->childfolders_method_ |
			this->rolename_method_;

    this->lv_expr_ = this->ident_[qi::_val = phoenix::new_ <Local_Value_Expr> (qi::_1)];

    this->cv_expr_ = this->integer_[qi::_val = phoenix::new_ <Constant_Value_Expr> (qi::_1)] | 
			this->quoted_string_[qi::_val = phoenix::new_ <Constant_Value_Expr> (qi::_1)];

		this->attribute_expr_ = this->ident_[qi::_a = qi::_1] >>
			qi::lit (".") >>
			this->ident_[qi::_val = phoenix::new_<Attribute_Expr> (qi::_a, qi::_1)];

		this->parts_method_ = qi::lit("parts") >>
			qi::lit ("(") >>
      this->quoted_string_ [qi::_val = phoenix::new_ <Parts_Method> (qi::_1)] >>
      qi::lit (")");

		this->size_method_ = qi::lit("size")[qi::_val = phoenix::new_ <Size_Method> ()];

		this->refers_to_method_ = qi::lit ("refersTo") >>
			qi::lit ("(") >>
			qi::lit (")")[qi::_val = phoenix::new_ <Refers_to_Method> ()];

		// GME Object specific methods

		this->name_method_ = qi::lit ("name") >> -(qi::lit ("(") >> qi::lit (")"))
			[qi::_val = phoenix::new_ <Name_Method> ()];

		this->kindname_method_ = qi::lit ("kindName") >> -(qi::lit ("(") >> qi::lit (")"))
			[qi::_val = phoenix::new_ <KindName_Method> ()];

		this->parent_method_ = qi::lit ("parent") >> (qi::lit ("(") >> qi::lit (")"))
			[qi::_val = phoenix::new_ <Parent_Method> ()];

		// GME Folder specific methods
		this->childfolders_method_ = qi::lit ("childFolders") >> (qi::lit ("(") >> qi::lit (")"))
			[qi::_val = phoenix::new_ <ChildFolders_Method> ()];

		// GME FCO specific methods

		this->rolename_method_ = qi::lit ("roleName") >> -(qi::lit ("(") >> qi::lit (")"))
			[qi::_val = phoenix::new_ <RoleName_Method> ()];

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
            Greater_Equal_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> greater_equal_expr_;

	qi::rule <IteratorT,
            Lesser_Equal_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> lesser_equal_expr_;

  qi::rule <IteratorT,
            Comparison_Expr * (),
            ascii::space_type> comp_expr_;

  qi::rule <IteratorT,
            Value_Expr * (),
            ascii::space_type,
	          qi::locals <std::deque <std::string>, 
                        std::deque <Value_Expr *> >> value_expr_;

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
            Method * (),
            ascii::space_type> method_;

	qi::rule <IteratorT,
            std::vector <Method *> (),
            ascii::space_type> method_list_;

	qi::rule <IteratorT,
            Parts_Method * (),
            ascii::space_type> parts_method_;

	qi::rule <IteratorT,
            Size_Method * (),
            ascii::space_type> size_method_;

	qi::rule <IteratorT,
            Name_Method * (),
            ascii::space_type> name_method_;

	qi::rule <IteratorT,
            KindName_Method * (),
            ascii::space_type> kindname_method_;

	qi::rule <IteratorT,
            Parent_Method * (),
            ascii::space_type> parent_method_;

	qi::rule <IteratorT,
            ChildFolders_Method * (),
            ascii::space_type> childfolders_method_;

	qi::rule <IteratorT,
            RoleName_Method * (),
            ascii::space_type> rolename_method_;

	qi::rule <IteratorT,
            Refers_to_Method * (),
            ascii::space_type> refers_to_method_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> ident_;

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

