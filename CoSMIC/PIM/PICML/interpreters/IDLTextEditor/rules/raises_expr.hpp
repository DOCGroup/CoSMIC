#ifndef _RULE_RAISES_EXPR_H_
#define _RULE_RAISES_EXPR_H_

#include "scoped_name.hpp"

template <typename IteratorT>
class raises_expr : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  raises_expr (void);

private:
  start_rule raises_expr_;

  scoped_name <IteratorT> scoped_name_;

  static const char * strlit_ [];
};

#endif  // !defined _RULE_VALUE_H_
