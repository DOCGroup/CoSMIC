#include "StdAfx.h"
#include "except_decl_impl.hpp"

void instantiate_except_decl_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  except_decl <iterator_type> g;
}
