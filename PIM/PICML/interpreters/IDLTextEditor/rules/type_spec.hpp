#ifndef _RULE_TYPE_SPEC_H_
#define _RULE_TYPE_SPEC_H_

#include "simple_type_spec.hpp"
#include "../Symbols.h"

template <typename IteratorT>
class type_spec : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  type_spec (void);

  typename model_rule & member_rule (void)
  {
    return this->member_;
  }

  model_rule & struct_type (void)
  {
    return this->struct_type_;
  }

  model_rule & union_type (void)
  {
    return this->union_type_;
  }

  model_rule & enum_type (void)
  {
    return this->enum_type_;
  }

private:
  start_rule type_spec_;

  simple_type_spec <IteratorT> simple_type_spec_;

  integer_type <IteratorT> integer_type_;

  boolean_type <IteratorT> boolean_type_;

  char_type <IteratorT> char_type_;

  noreturn_rule constr_type_spec_;

  noreturn_rule member_list_;

  model_rule member_;

  model_rule struct_type_;

  model_rule union_type_;

  model_rule enum_type_;

  model_rule enumerator_;

  noreturn_rule switch_type_spec_;

  noreturn_rule switch_body_;

  noreturn_rule case_;

  scoped_name <IteratorT> scoped_name_;

  ident <IteratorT> ident_;

  fq_name fq_name_;

  static const char * strlit_[];
};

#endif  // !defined _RULE_COMPONENT_EXPORT_H_
