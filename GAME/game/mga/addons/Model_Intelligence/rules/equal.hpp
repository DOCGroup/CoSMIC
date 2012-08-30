#ifndef _RULE_EQUAL_H_
#define _RULE_EQUAL_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Equal_Expr.h"
#include "value.hpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Equal_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class equal : public qi::grammar <IteratorT,
                                  Equal_Expr * (),
                                  ascii::space_type,
                                  qi::locals <Value_Expr *>>
{  
public:
  equal ();

private:
  qi::rule <IteratorT,
            Equal_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> equal_expr_;

  value <IteratorT> value_expr_;
};
#endif