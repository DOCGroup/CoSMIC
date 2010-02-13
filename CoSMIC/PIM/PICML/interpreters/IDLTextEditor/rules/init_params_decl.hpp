#ifndef _RULE_INIT_PARAMS_DECL_H_
#define _RULE_INIT_PARAMS_DECL_H_

#include "param_type_spec.hpp"

template <typename IteratorT>
class init_params_decls : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  init_params_decls (void);

private:
  start_rule init_params_decls_;

  noreturn_rule init_param_decl_;

  param_type_spec <IteratorT> param_type_spec_;

  ident <IteratorT> ident_;

  static const char * strlit_ [];
};


#endif  // !defined _RULE_INIT_PARAMS_DECL_H_
