#ifndef _IDL_GRAMMAR_H_
#define _IDL_GRAMMAR_H_

#include "interface.hpp"
#include "event.hpp"
#include "component.hpp"
#include "value.hpp"
#include "type_decl.hpp"
#include "except_decl.hpp"
#include "const_decl.hpp"
#include "preprocessor.hpp"
#include "home_decl.hpp"

namespace qi = ::boost::spirit::qi;
namespace ascii = ::boost::spirit::ascii;

template <typename IteratorT>
class idl_grammar : public T3::grammar <IteratorT>
{
public:
  typedef T3::grammar <IteratorT> base_type;

  idl_grammar (void);

private:
  start_rule specification_;

  /// (2)
  noreturn_rule definition_;

  /// (3)
  model_rule module_;

  idl_export <IteratorT> export_;

  idl_interface <IteratorT> interface_;

  idl_event <IteratorT> event_;

  component <IteratorT> component_;

  value <IteratorT> value_;

  type_decl <IteratorT> type_decl_;

  except_decl <IteratorT> except_decl_;

  const_decl <IteratorT> const_decl_;

  ident <IteratorT> ident_;

  preprocessor <IteratorT> preprocessor_;

  home_decl <IteratorT> home_decl_;

  static const char * strlit_ [];
};


#endif
