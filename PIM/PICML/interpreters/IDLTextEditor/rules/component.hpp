#ifndef _RULE_COMPONENT_H_
#define _RULE_COMPONENT_H_

#include "attribute_decl.hpp"
#include "../Symbols.h"

template <typename IteratorT>
class component : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  component (void);

private:
  start_rule component_;

  model_rule component_decl_;

  model_rule component_forward_decl_;

  model_rule component_inheritance_spec_;

  model_rule supported_interface_spec_;

  noreturn_rule component_body_;

  noreturn_rule component_export_;

  model_rule provides_decl_;

  model_rule uses_decl_;

  model_rule emits_decl_;

  model_rule publishes_decl_;

  model_rule consumes_decl_;

  attribute_decl <IteratorT> attr_decl_;

  scoped_name <IteratorT> scoped_name_;

  ident <IteratorT> ident_;

  static const char * strlit_ [];

  fq_name fq_name_;
};

#endif  // !defined _RULE_COMPONENT_EXPORT_H_