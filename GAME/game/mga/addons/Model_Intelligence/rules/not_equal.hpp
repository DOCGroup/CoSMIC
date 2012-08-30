#ifndef _RULE_NOT_EQUAL_H_
#define _RULE_NOT_EQUAL_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Not_Equal_Expr.h"
#include "value.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Not_Equal_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class not_equal : public qi::grammar <IteratorT,
                                      Not_Equal_Expr * (),
                                      ascii::space_type,
                                      qi::locals <Value_Expr *>>
{  
public:
  not_equal ();

private:
  qi::rule <IteratorT,
            Not_Equal_Expr * (),
            ascii::space_type,
            qi::locals <Value_Expr *>> not_equal_expr_;

  value <IteratorT> value_expr_;
};
#endif