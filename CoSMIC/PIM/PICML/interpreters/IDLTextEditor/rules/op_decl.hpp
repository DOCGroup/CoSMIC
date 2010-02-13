#ifndef _RULE_OP_DECL_H_
#define _RULE_OP_DECL_H_

#include "param_type_spec.hpp"
#include "raises_expr.hpp"

template <typename IteratorT>
class op_decl : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  op_decl (void);

private:
  param_type_spec <IteratorT> param_type_spec_;

  raises_expr <IteratorT> raises_expr_;

  start_rule op_decl_;

  model_rule oneway_decl_;

  model_rule twoway_decl_;

  model_rule twoway_void_decl_;

  noreturn_rule parameter_decls_;

  noreturn_rule param_decl_;

  model_rule in_param_;

  model_rule out_param_;

  model_rule inout_param_;

  ident <IteratorT> ident_;

  static const char * strlit_ [];
};

#endif  // !defined _RULE_EVENT_H_
