#ifndef _RULE_ATTRIBUTE_H_
#define _RULE_ATTRIBUTE_H_

#include <fstream>

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include <string>
#include <stack>
#include <functional>

#include "../Attribute_Expr.h"
#include "ident.hpp"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Attribute_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class attribute : public qi::grammar <IteratorT,
                                      Attribute_Expr * (),
                                      ascii::space_type,
	                                    qi::locals <std::string>>
{
public:
  attribute ();
    
private:
  qi::rule <IteratorT,
            Attribute_Expr * (),
            ascii::space_type,
            qi::locals <std::string>> attribute_expr_;

  ident <IteratorT> ident_;
};
#endif