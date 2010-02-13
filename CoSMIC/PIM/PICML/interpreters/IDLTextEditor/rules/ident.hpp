#ifndef _RULE_IDENT_H_
#define _RULE_IDENT_H_

#include "t3/runtime/grammar.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

template <typename IteratorT>
class ident :
  public qi::grammar < IteratorT, std::string (), ascii::space_type >
{
public:
  ident (void);

private:
  qi::rule <IteratorT,
            std::string (),
            ascii::space_type>
            ident_;
};

#endif  // !defined _RULE_IDENT_H_
