#ifndef _RULE_OCTET_H_
#define _RULE_OCTET_H_

#include "t3/runtime/grammar.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

template <typename IteratorT>
class octet : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  octet (void);

private:
  start_rule octet_;

  static const char * strlit_[];
};

#endif
