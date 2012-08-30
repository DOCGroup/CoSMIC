#ifndef _RULE_ITERATOR_H_
#define _RULE_ITERATOR_H_

#include <boost/config/warning_disable.hpp>
#include "boost/spirit/include/qi.hpp"
#include "boost/spirit/repository/include/qi_confix.hpp"

#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix_core.hpp"
#include "boost/spirit/include/phoenix_operator.hpp"
#include "boost/spirit/include/phoenix_bind.hpp"
#include "boost/spirit/include/phoenix.hpp"
#include "boost/spirit/include/phoenix_container.hpp"

#include "../Iterator.h"
#include "../ForAll_Iterator.h"
#include "../Exists_Iterator.h"
#include "../IsUnique_Iterator.h"
#include "../One_Iterator.h"

#include <vector>
#include <string>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii; 

/**
 * @class Iterator_Parser_Grammar
 *
 * Underlying grammer for the ocl expression parser.
 */
template <typename IteratorT>
class iterator : public qi::grammar <IteratorT,
                                     Iterator * (),
                                     ascii::space_type>
{  
public:
  iterator ();

private:
  qi::rule <IteratorT,
            Iterator * (),
            ascii::space_type> iterator_;

  qi::rule <IteratorT,
            ForAll_Iterator * (),
            ascii::space_type> forall_iterator_;

  qi::rule <IteratorT,
            IsUnique_Iterator * (),
            ascii::space_type> isunique_iterator_;

  qi::rule <IteratorT,
            Exists_Iterator * (),
            ascii::space_type> exists_iterator_;

  qi::rule <IteratorT,
            One_Iterator * (),
            ascii::space_type> one_iterator_;

};
#endif