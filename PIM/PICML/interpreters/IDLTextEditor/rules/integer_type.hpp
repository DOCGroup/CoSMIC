#ifndef _RULE_INTEGER_TYPE_H_
#define _RULE_INTEGER_TYPE_H_

#include "t3/runtime/grammar.hpp"
#include "t3/runtime/actors.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

/**
 * @class integer_type
 */
template <typename IteratorT>
class integer_type : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  integer_type (void);

private:
  start_rule integer_type_;

  noreturn_rule signed_int_;

  noreturn_rule unsigned_int_;

  noreturn_rule signed_short_int_;

  noreturn_rule signed_long_int_;

  noreturn_rule signed_longlong_int_;

  noreturn_rule unsigned_short_int_;

  noreturn_rule unsigned_long_int_;

  noreturn_rule unsigned_longlong_int_;

  static const char * strlit_ [];
};

#endif  // !defined _RULE_INTEGER_TYPE_H_

