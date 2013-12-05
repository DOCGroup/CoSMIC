#ifndef _RULE_PARAM_TYPE_SPEC_H_
#define _RULE_PARAM_TYPE_SPEC_H_

#include "base_type_spec.hpp"
#include "string_type.hpp"
#include "wide_string_type.hpp"
#include "scoped_name.hpp"

template <typename IteratorT>
class param_type_spec : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  param_type_spec (void);

private:
  start_rule param_type_spec_;

  base_type_spec <IteratorT> base_type_spec_;

  string_type <IteratorT> string_type_;

  wide_string_type <IteratorT> wide_string_type_;

  scoped_name <IteratorT> scoped_name_;
};

#endif  // !defined _RULE_PARAM_TYPE_SPEC_H_
