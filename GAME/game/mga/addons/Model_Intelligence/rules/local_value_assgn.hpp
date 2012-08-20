#ifndef _RULE_LOCAL_VALUE_ASSGN_H_
#define _RULE_LOCAL_VALUE_ASSGN_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Local_Value_Assignment_Expr.h"
#include "value.hpp"
#include "ident.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Local_Value_Assgn_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class local_value_assgn : public qi::grammar <IteratorT,
                                              Local_Value_Assignment_Expr * (),
                                              ascii::space_type,
                                              qi::locals <std::string>>
{  
public:
  local_value_assgn ();

private:
   qi::rule <IteratorT,
             Local_Value_Assignment_Expr * (),
             ascii::space_type,
             qi::locals <std::string>> lv_assgn_expr_;

  value <IteratorT> value_expr_;

  ident <IteratorT> ident_;
};
#endif