#ifndef _RULE_EVENT_H_
#define _RULE_EVENT_H_

#include "export.hpp"
#include "value_element.hpp"

template <typename IteratorT>
class idl_event : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  idl_event (void);

private:
  start_rule event_;

  model_rule event_decl_;

  model_rule event_fwd_decl_;

  model_rule event_abs_decl_;

  idl_export <IteratorT> export_;

  value_element <IteratorT> value_element_;

  ident <IteratorT> ident_;

  static const char * strlit_ [];

  fq_name fq_name_;
};

#endif  // !defined _RULE_EVENT_H_
