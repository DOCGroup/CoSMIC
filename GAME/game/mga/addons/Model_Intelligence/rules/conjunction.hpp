#ifndef _RULE_CONJUNCTION_H_
#define _RULE_CONJUNCTION_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Conjunction_Expr.h"

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Conjunction_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class conjunction : public qi::grammar <IteratorT,
                                        std::string (),
                                        ascii::space_type>
{
public:
  conjunction ();

private:
  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> conjunction_;
};
#endif