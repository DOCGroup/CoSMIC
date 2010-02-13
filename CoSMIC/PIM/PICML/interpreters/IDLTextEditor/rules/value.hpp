#ifndef _RULE_VALUE_H_
#define _RULE_VALUE_H_

#include "value_element.hpp"

template <typename IteratorT>
class value : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  value (void);

private:
  value_element <IteratorT> value_element_;

  idl_export <IteratorT> export_;

  ident <IteratorT> ident_;

  scoped_name <IteratorT> scoped_name_;

  noreturn_rule value_;

  model_rule value_decl_;

  model_rule value_abs_decl_;

  model_rule value_box_decl_;

  model_rule value_fwd_decl_;

  noreturn_rule value_inheritance_spec_;

  static const char * strlit_ [];

  fq_name fq_name_;
};

#endif  // !defined _RULE_VALUE_H_
