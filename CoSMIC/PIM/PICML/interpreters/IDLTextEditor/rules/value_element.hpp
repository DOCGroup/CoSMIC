#ifndef _RULE_VALUE_ELEMENT_H_
#define _RULE_VALUE_ELEMENT_H_

#include "export.hpp"
#include "type_spec.hpp"
#include "raises_expr.hpp"
#include "init_params_decl.hpp"

template <typename IteratorT>
class value_element : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  value_element (void);

private:
  start_rule value_element_;

  idl_export <IteratorT> export_;

  type_spec <IteratorT> type_spec_;

  raises_expr <IteratorT> raises_expr_;

  ident <IteratorT> ident_;

  model_rule state_member_;

  model_rule init_decl_;

  init_params_decls <IteratorT> init_params_decls_;

  model_rule init_params_decl_;

  static const char * strlit_ [];

  fq_name fq_name_;
};


#endif  // !defined _RULE_VALUE_H_
