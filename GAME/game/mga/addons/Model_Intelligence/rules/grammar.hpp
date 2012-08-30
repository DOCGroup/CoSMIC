#ifndef _IDL_GRAMMAR_H_
#define _IDL_GRAMMAR_H_

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

#include "../Boolean_Expr.h"
#include "../If_Then_Else_Expr.h"
#include "../IteratorCall_Expr.h"
#include "local_value_assgn.hpp"
#include "value.hpp"
#include "equality.hpp"
#include "declaratorlist.hpp"
#include "iterator.hpp"
#include "ident.hpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class OCL_Expression_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class OCL_Expression_Parser_Grammar :
  public qi::grammar <IteratorT,
                      std::vector <Boolean_Expr *> (),
                      ascii::space_type>
{
public:
  OCL_Expression_Parser_Grammar (void);

private:
  qi::rule <IteratorT,
            std::vector <Boolean_Expr *> (),
            ascii::space_type> ocl_statements_;

  qi::rule <IteratorT,
            Boolean_Expr * (),
            ascii::space_type> bool_expr_;

  qi::rule <IteratorT,
             If_Then_Else_Expr * (),
             ascii::space_type,
             qi::locals <Equality_Expr *, 
                         std::vector <Boolean_Expr *>,
						             std::vector <Boolean_Expr *> > > if_then_else_expr_;

  qi::rule <IteratorT,
            IteratorCall_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *, 
                        Iterator *,
						            Boolean_Expr *,
                        std::vector <std::string>,
                        std::string,
                        Value_Expr *> > iteratorcall_expr_;  

	local_value_assgn <IteratorT> lv_assgn_expr_; 
  
  equality <IteratorT> eq_expr_;

  value <IteratorT> value_expr_;

  iterator <IteratorT> iterator_;

  declaratorlist <IteratorT> declarator_list_;

  ident <IteratorT> ident_;
};

#endif