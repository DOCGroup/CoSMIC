#ifndef _RULE_FLOATINT_PT_TYPE_H_
#define _RULE_FLOATINT_PT_TYPE_H_

#include "t3/runtime/grammar.hpp"
#include "t3/runtime/actors.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

/**
 * @class floating_pt_type
 */
template <typename IteratorT>
class floating_pt_type : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  floating_pt_type (void);

private:
  start_rule floating_pt_type_;

  static const char * strlit_ [];
};

#endif  // !defined _RULE_INTEGER_TYPE_H_

