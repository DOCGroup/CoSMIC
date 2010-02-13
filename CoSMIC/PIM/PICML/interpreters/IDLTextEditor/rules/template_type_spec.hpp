#ifndef _RULE_TEMPLATE_TYPE_SPEC_H_
#define _RULE_TEMPLATE_TYPE_SPEC_H_

#include "string_type.hpp"
#include "wide_string_type.hpp"

template <typename IteratorT>
class template_type_spec : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  template_type_spec (void);

private:
  start_rule template_type_spec_;

  string_type <IteratorT> string_type_;

  wide_string_type <IteratorT> wide_string_type_;

  noreturn_rule fixed_pt_type_;
};


#endif  // !defined _RULE_SIMPLE_TYPE_SPEC_H_
