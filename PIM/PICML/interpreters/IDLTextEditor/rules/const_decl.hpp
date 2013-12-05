#ifndef _RULE_CONST_DECL_H_
#define _RULE_CONST_DECL_H_

#include "t3/runtime/grammar.hpp"

#include "integer_type.hpp"
#include "char_type.hpp"
#include "string_type.hpp"
#include "wide_string_type.hpp"
#include "floating_pt_type.hpp"
#include "scoped_name.hpp"
#include "octet.hpp"
#include "scoped_name.hpp"
#include "boolean_type.hpp"

template <typename IteratorT>
class const_decl : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  const_decl (void);

private:
  start_rule const_;

  model_rule const_decl_;

  noreturn_rule const_type_;

  integer_type <IteratorT> integer_type_;

  char_type <IteratorT> char_type_;

  boolean_type <IteratorT> boolean_type_;

  floating_pt_type <IteratorT> floating_pt_type_;

  string_type <IteratorT> string_type_;

  wide_string_type <IteratorT> wide_string_type_;

  scoped_name <IteratorT> scoped_name_;

  ident <IteratorT> ident_;

  octet <IteratorT> octet_;

  qi::rule <IteratorT,
            std::string (),
            ascii::space_type>
            const_value_;

  static const char * strlit_ [];
};

#endif
