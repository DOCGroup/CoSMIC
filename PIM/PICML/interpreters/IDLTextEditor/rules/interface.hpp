#ifndef _RULE_INTERFACE_H_
#define _RULE_INTERFACE_H_

#include "export.hpp"

template <typename IteratorT>
class idl_interface : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  idl_interface (void);

private:
  noreturn_rule interface_;

  model_rule interface_decl_;

  model_rule forward_decl_;

  noreturn_rule interface_inheritance_spec_;

  noreturn_rule interface_body_;

  idl_export <IteratorT> export_;

  scoped_name <IteratorT> scoped_name_;

  ident <IteratorT> ident_;

  static const char * strlit_ [];

  fq_name fq_name_;
};

#endif  // !defined _RULE_COMPONENT_EXPORT_H_
