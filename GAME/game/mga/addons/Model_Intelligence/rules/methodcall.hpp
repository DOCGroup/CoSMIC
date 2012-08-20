#ifndef _RULE_METHODCALL_H_
#define _RULE_METHODCALL_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Method_Call.h"
#include "../Self_Method_Call.h"
#include "../Local_Value_Method_Call.h"
#include "ident.hpp"
#include "method.hpp"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class MethodCall_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class methodcall : public qi::grammar <IteratorT,
                                       Method_Call * (),
                                       ascii::space_type>
{  
public:
  methodcall ();

private:
  qi::rule <IteratorT,
            Method_Call * (),
            ascii::space_type> method_call_;

	qi::rule <IteratorT,
            Self_Method_Call * (),
            ascii::space_type> self_method_call_;

	qi::rule <IteratorT,
            Local_Value_Method_Call * (),
            ascii::space_type,
            qi::locals <std::string>> lv_method_call_;

	qi::rule <IteratorT,
            std::vector <Method *> (),
            ascii::space_type> method_list_;

  ident <IteratorT> ident_;

  method <IteratorT> method_;
};
#endif