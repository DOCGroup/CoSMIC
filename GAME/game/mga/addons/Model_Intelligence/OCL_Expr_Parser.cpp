#include "StdAfx.h"
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
#include "Collection_Expr.h"
#include "Local_Value_Assignment_Expr.h"
#include "Parts_Method_Expr.h"
#include "Value_Expr.h"
#include "Size_Method_Expr.h"
#include "And_Expr.h"
#include "Comparison_Expr.h"
#include "Conjunction_Expr.h"

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
    : OCL_Expression_Parser_Grammar::base_type (ocl_expr_)
  {
    namespace qi = boost::spirit::qi;
    namespace phoenix = boost::phoenix;
    namespace ascii = boost::spirit::ascii;
    namespace repo = boost::spirit::repository;
    
    // The base rule
    this->ocl_expr_ %= +(this->bool_expr_);

    // Boolean expressions
    this->bool_expr_ %= this->lv_assgn_expr_ | this->eq_expr_;

    this->lv_assgn_expr_ = qi::lit ("let") >>
      this->ident_[qi::_a = qi::_1] >>
      qi::lit ("=") >>
      this->value_expr_ [qi::_val = phoenix::new_<Local_Value_Assignment_Expr> 
                (qi::_a, qi::_1)] >>
      qi::lit ("in");

    this->value_expr_ %= this->size_expr_ | this->lv_expr_ | this->cv_expr_;

    this->size_expr_ = 
      this->collection_expr_[qi::_val = phoenix::new_ <Size_Method_Expr> (qi::_1)] >>
      qi::lit ("->") >>
      qi::lit ("size");

    this->collection_expr_ %= qi::omit [this->object_ident_] >>
      qi::lit (".") >>
      this->parts_expr_;

    this->parts_expr_ = qi::lit ("parts") >>
      qi::lit ("(") >>
      this->quoted_string_ [qi::_val = phoenix::new_ <Parts_Method_Expr> (qi::_1)] >>
      qi::lit (")");

    this->eq_expr_ =
      ((this->comp_expr_[phoenix::push_back (qi::_b, qi::_1)] | 
        repo::confix ('(', ')')[this->eq_expr_[phoenix::push_back (qi::_b, qi::_1)]]) >>
      (*(this->conjunction_[phoenix::push_back (qi::_a, qi::_1)] >> 
          this->eq_expr_[phoenix::push_back (qi::_b, qi::_1)])[phoenix::bind (&operate, qi::_a, qi::_b)]))[qi::_val = phoenix::back (qi::_b)];

    this->comp_expr_ %= 
      this->equal_expr_ | 
      this->greater_equal_expr_ | 
      this->lesser_equal_expr_;

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
      qi::lit ("=") >> 
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

    this->lv_expr_ = this->ident_[qi::_val = phoenix::new_ <Local_Value_Expr> (qi::_1)];

    this->cv_expr_ = this->integer_[qi::_val = phoenix::new_ <Constant_Value_Expr> (qi::_1)];

    this->ident_ %= 
      qi::lexeme[ (ascii::char_('_') | qi::alpha) >>
      *(ascii::char_('_') | qi::alnum)];

    this->integer_ %= qi::uint_;

    this->object_ident_ %= ascii::string ("self");

    this->quoted_string_ %= qi::lexeme[qi::lit ('"') >> *(qi::char_ - '"') >> qi::lit ('"')];

  }
private:
  qi::rule <IteratorT,
            std::vector <Boolean_Expr *> (),
            ascii::space_type> ocl_expr_;

  qi::rule <IteratorT,
            Boolean_Expr * (),
            ascii::space_type> bool_expr_;

  qi::rule <IteratorT,
            Equality_Expr * (),
            ascii::space_type,
            qi::locals <std::deque <std::string>, 
                        std::deque <Equality_Expr *> > > eq_expr_;

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
            Size_Method_Expr * (),
            ascii::space_type> size_expr_;

  qi::rule <IteratorT,
            Collection_Expr * (),
            ascii::space_type> collection_expr_;

  qi::rule <IteratorT,
            Parts_Method_Expr * (),
            ascii::space_type> parts_expr_;

  qi::rule <IteratorT,
            Comparison_Expr * (),
            ascii::space_type> comp_expr_;

  qi::rule <IteratorT,
            Value_Expr * (),
            ascii::space_type> value_expr_;

  qi::rule <IteratorT,
            Local_Value_Expr * (),
            ascii::space_type> lv_expr_;

  qi::rule <IteratorT,
            Constant_Value_Expr * (),
            ascii::space_type> cv_expr_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> ident_;

  qi::rule <IteratorT,
            unsigned int (),
            ascii::space_type> integer_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> object_ident_;

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
parse_string(std::string str, std::vector <Boolean_Expr*> &ocl)
{
  namespace spirit = boost::spirit;

  std::string::const_iterator begin_iter = str.begin();
  std::string::const_iterator end_iter = str.end();

  OCL_Expression_Parser_Grammar <std::string::const_iterator> g;

  bool retval = qi::phrase_parse (begin_iter,
                                  end_iter,
                                  g,
                                  ascii::space,
                                  ocl);
  return retval;
}

