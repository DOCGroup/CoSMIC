#ifndef _RULE_VALUE_SUB_H_
#define _RULE_VALUE_SUB_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Value_SubExpr.h"
#include "methodcall.hpp"
#include "constant_value.hpp"
#include "local_value.hpp"
#include "attribute.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

/**
 * @class Value_Sub_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class value_sub :
  public qi::grammar <IteratorT, Value_SubExpr * (), ascii::space_type>
{
public:
  value_sub ();

private:
  qi::rule <IteratorT,
            Value_SubExpr * (),
            ascii::space_type> value_subexpr_;

  ::methodcall <IteratorT> method_call_;

  ::constant_value <IteratorT> cv_expr_;

  ::local_value <IteratorT> lv_expr_;

  ::attribute <IteratorT> attribute_expr_;
};

#endif
