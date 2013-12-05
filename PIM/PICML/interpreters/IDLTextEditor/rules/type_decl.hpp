#ifndef _RULE_TYPE_DECL_H_
#define _RULE_TYPE_DECL_H_

#include "type_spec.hpp"

template <typename IteratorT>
class type_decl : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  type_decl (void);

private:
  noreturn_rule type_decl_;

  model_rule typedef_type_;

  model_rule sequence_type_;

  model_rule constr_forward_decl_;

  simple_type_spec <IteratorT> simple_type_spec_;

  type_spec <IteratorT> type_spec_;

  ident <IteratorT> ident_;

  static const char * strlit_ [];

  fq_name fq_name_;
};

#endif  // !defined _RULE_TYPE_DECL_H_
