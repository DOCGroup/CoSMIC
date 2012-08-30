#ifndef _RULE_LESSER_H_
#define _RULE_LESSER_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Lesser_Expr.h"
#include "value.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Lesser_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class lesser : public qi::grammar <IteratorT,
                                   Lesser_Expr * (),
                                   ascii::space_type,
                                   qi::locals <Value_Expr *>>
{  
public:
  lesser ();

private:
   qi::rule <IteratorT,
             Lesser_Expr * (),
             ascii::space_type,
             qi::locals <Value_Expr *>> lesser_expr_;

  value <IteratorT> value_expr_;
};
#endif