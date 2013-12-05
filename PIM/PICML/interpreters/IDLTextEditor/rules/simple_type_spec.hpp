#ifndef _RULE_SIMPLE_TYPE_SPEC_H_
#define _RULE_SIMPLE_TYPE_SPEC_H_

#include "base_type_spec.hpp"
#include "template_type_spec.hpp"
#include "scoped_name.hpp"

template <typename IteratorT>
class simple_type_spec : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  simple_type_spec (void);

private:
  start_rule simple_type_spec_;

  base_type_spec <IteratorT> base_type_spec_;

  template_type_spec <IteratorT> template_type_spec_;

  scoped_name <IteratorT> scoped_name_;
};


#endif  // !defined _RULE_SIMPLE_TYPE_SPEC_H_
