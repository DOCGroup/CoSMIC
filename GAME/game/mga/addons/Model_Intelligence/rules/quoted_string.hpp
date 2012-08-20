#ifndef _RULE_QUOTED_STRING_H_
#define _RULE_QUOTED_STRING_H_

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
 * @class Quoted_String_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class quoted_string : public qi::grammar <IteratorT,
                                          std::string (),
                                          ascii::space_type>
{  
public:
  quoted_string ();

private:
  qi::rule <IteratorT,
            std::string (),
            ascii::space_type> quoted_string_;
};
#endif