#ifndef _RULE_EXCEPT_DECL_H_
#define _RULE_EXCEPT_DECL_H_

#include "type_spec.hpp"

template <typename IteratorT>
class except_decl : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  except_decl (void);

private:
  noreturn_rule except_;

  model_rule except_decl_;

  type_spec <IteratorT> type_spec_;

  ident <IteratorT> ident_;

  static const char * strlit_ [];

  fq_name fq_name_;
};

#include "type_spec.hpp"

#endif  // !defined _RULE_EXCEPT_DECL_H_
