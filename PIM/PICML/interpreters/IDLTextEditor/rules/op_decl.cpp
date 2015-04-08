#include "StdAfx.h"
#include "op_decl_impl.hpp"

void instantiate_op_decl_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  op_decl <iterator_type> g;
}
