#ifndef _RULE_ATTRIBUTE_DECL_H_
#define _RULE_ATTRIBUTE_DECL_H_

#include "param_type_spec.hpp"

template <typename IteratorT>
class attribute_decl : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  attribute_decl (void);

private:
  start_rule attribute_decl_;

  noreturn_rule readonly_attr_spec_;

  noreturn_rule attr_spec_;

  model_rule attr_declarator_;

  model_rule readonly_attr_declarator_;

  noreturn_rule raises_expr_;

  noreturn_rule attr_raises_expr_;

  param_type_spec <IteratorT> param_type_spec_;

  scoped_name <IteratorT> scoped_name_;

  ident <IteratorT> ident_;

  static const char * strlit_ [];
};

#endif  // !defined _RULE_COMPONENT_EXPORT_H_