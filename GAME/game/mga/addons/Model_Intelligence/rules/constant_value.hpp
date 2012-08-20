#ifndef _RULE_CONSTANT_VALUE_H_
#define _RULE_CONSTANT_VALUE_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Constant_Value_Expr.h"
#include "quoted_string.hpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Constant_Value_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class constant_value : public qi::grammar <IteratorT,
                                           Constant_Value_Expr * (),
                                           ascii::space_type>
{  
public:
  constant_value ();

private:
  qi::rule <IteratorT,
            Constant_Value_Expr * (),
            ascii::space_type> cv_expr_;

  qi::rule <IteratorT,
            unsigned int (),
            ascii::space_type> integer_;

  quoted_string <IteratorT> quoted_string_;
};
#endif