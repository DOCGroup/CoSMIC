#ifndef _RULE_EQUALITY_H_
#define _RULE_EQUALITY_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Equality_Expr.h"
#include "../And_Expr.h"
#include "../Or_Expr.h"

#include "conjunction.hpp"
#include "comparison.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Constant_Value_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class equality : public qi::grammar <IteratorT,
                                     Equality_Expr * (),
                                     ascii::space_type,
                                     qi::locals <std::deque <std::string>, 
                                                 std::deque <Equality_Expr *> > >
{  
public:
  equality ();

private:
  qi::rule <IteratorT,
            Equality_Expr * (),
            ascii::space_type,
            qi::locals <std::deque <std::string>, 
                        std::deque <Equality_Expr *> > > eq_expr_;

  comparison <IteratorT> comp_expr_;

  conjunction <IteratorT> conjunction_;
};
#endif