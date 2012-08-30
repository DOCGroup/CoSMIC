#ifndef _RULE_LOCAL_VALUE_H_
#define _RULE_LOCAL_VALUE_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Local_Value_Expr.h"
#include "ident.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Local_Value_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class local_value : public qi::grammar <IteratorT,
                                        Local_Value_Expr * (),
                                        ascii::space_type>
{  
public:
  local_value ();

private:
   qi::rule <IteratorT,
             Local_Value_Expr * (),
             ascii::space_type> lv_expr_;


  ident <IteratorT> ident_;
};
#endif