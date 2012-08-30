#ifndef _RULE_COMPARISON_H_
#define _RULE_COMPARISON_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Comparison_Expr.h"

#include "equal.hpp"
#include "greater_equal.hpp"
#include "not_equal.hpp"
#include "lesser_equal.hpp"
#include "greater.hpp"
#include "lesser.hpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Comparison_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class comparison : public qi::grammar <IteratorT,
                                       Comparison_Expr * (),
                                       ascii::space_type>
{
public:
  comparison ();

private:
  qi::rule <IteratorT,
            Comparison_Expr * (),
            ascii::space_type> comp_expr_;

  equal <IteratorT> equal_expr_;

  greater_equal <IteratorT> greater_equal_expr_;

  greater <IteratorT> greater_expr_;

  not_equal <IteratorT> not_equal_expr_;

  lesser_equal <IteratorT> lesser_equal_expr_;

  lesser <IteratorT> lesser_expr_;
};
#endif