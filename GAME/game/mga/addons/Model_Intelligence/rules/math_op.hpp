#ifndef _RULE_MATH_OP_H_
#define _RULE_MATH_OP_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Math_Op_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class math_op : public qi::grammar <IteratorT,
                                    std::string (),
                                    ascii::space_type>
{  
public:
  math_op ();

private:
  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> math_op_;

};
#endif