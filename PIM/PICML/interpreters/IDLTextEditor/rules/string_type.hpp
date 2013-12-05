#ifndef _RULE_STRING_TYPE_H_
#define _RULE_STRING_TYPE_H_

#include "t3/runtime/grammar.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

template <typename IteratorT>
class string_type : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  string_type (void);

private:
  start_rule string_type_;

  static const char * strlit_[];
};

#endif
