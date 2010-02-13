#ifndef _RULE_EXPORT_H_
#define _RULE_EXPORT_H_

#include "attribute_decl.hpp"
#include "type_decl.hpp"
#include "except_decl.hpp"
#include "op_decl.hpp"
#include "const_decl.hpp"

template <typename IteratorT>
class idl_export : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  idl_export (void);

private:
  start_rule idl_export_;

  attribute_decl <IteratorT> attr_decl_;

  type_decl <IteratorT> type_decl_;

  except_decl <IteratorT> except_decl_;

  op_decl <IteratorT> op_decl_;

  const_decl <IteratorT> const_decl_;
};


#endif  // !defined _RULE_EVENT_H_
