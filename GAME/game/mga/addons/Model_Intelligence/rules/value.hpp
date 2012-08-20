#ifndef _RULE_VALUE_H_
#define _RULE_VALUE_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Value_Expr.h"
#include "../Addition_Operation.h"
#include "value_sub.hpp"
#include "math_op.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Value_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class value : public qi::grammar <IteratorT,
                                  Value_Expr * (),
                                  ascii::space_type,
	                                qi::locals <std::deque <std::string>, 
                                              std::deque <Value_Expr *> >>
{  
public:
  value ();

private:
  qi::rule <IteratorT,
            Value_Expr * (),
            ascii::space_type,
	          qi::locals <std::deque <std::string>, 
                        std::deque <Value_Expr *> >> value_expr_;

  value_sub <IteratorT> value_subexpr_;

  math_op <IteratorT> math_op_;

};
#endif