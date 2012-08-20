#ifndef _RULE_DECLARATORLIST_H_
#define _RULE_DECLARATORLIST_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "ident.hpp"
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
class declaratorlist : public qi::grammar <IteratorT,
                                           std::vector <std::string> (),
                                           ascii::space_type>
{  
public:
  declaratorlist ();

private:
  qi::rule <IteratorT,
            std::vector <std::string> (),
            ascii::space_type> declarator_list_;

  ident <IteratorT> ident_;
};
#endif