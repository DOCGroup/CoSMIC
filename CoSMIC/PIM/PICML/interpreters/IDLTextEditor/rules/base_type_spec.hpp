#ifndef _RULE_BASE_TYPE_SPEC_H_
#define _RULE_BASE_TYPE_SPEC_H_

#include "boolean_type.hpp"
#include "char_type.hpp"
#include "integer_type.hpp"
#include "floating_pt_type.hpp"
#include "octet.hpp"

/**
 * @class base_type_spec
 */
template <typename IteratorT>
class base_type_spec : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  base_type_spec (void);

private:
  start_rule base_type_spec_;

  floating_pt_type <IteratorT> floating_pt_type_;

  integer_type <IteratorT> integer_type_;

  char_type <IteratorT> char_type_;

  boolean_type <IteratorT> boolean_type_;

  noreturn_rule wide_char_type_;

  octet <IteratorT> octet_type_;

  noreturn_rule any_type_;

  noreturn_rule object_type_;

  noreturn_rule value_base_type_;

  static const char * strlit_ [];
};

#endif  // !defined _RULE_PARAM_TYPE_SPEC_H_
