#ifndef _RULE_HOME_DECL_H_
#define _RULE_HOME_DECL_H_

#include "init_params_decl.hpp"
#include "export.hpp"
#include "raises_expr.hpp"

template <typename IteratorT>
class home_decl : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  home_decl (void);

private:
  start_rule home_decl_;

  model_rule home_decl_inner_;

  model_rule home_inheritance_spec_;

  model_rule primary_key_spec_;

  noreturn_rule home_body_;

  noreturn_rule home_export_;

  model_rule factory_decl_;

  model_rule finder_decl_;

  model_rule primary_key_;

  noreturn_rule supported_interface_spec_;

  scoped_name <IteratorT> scoped_name_;

  init_params_decls <IteratorT> init_param_decls_;

  ident <IteratorT> ident_;

  idl_export <IteratorT> export_;

  raises_expr <IteratorT> raises_expr_;

  static const char * strlit_ [];

  fq_name fq_name_;
};

#endif  // !defined _RULE_COMPONENT_EXPORT_H_