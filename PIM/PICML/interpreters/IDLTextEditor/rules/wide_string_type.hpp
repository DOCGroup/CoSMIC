#ifndef _RULE_WIDE_STRING_TYPE_H_
#define _RULE_WIDE_STRING_TYPE_H_

#include "t3/runtime/grammar.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

template <typename IteratorT>
class wide_string_type : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  wide_string_type (void);

private:
  start_rule wide_string_type_;

  static const char * strlit_[];
};

#endif
