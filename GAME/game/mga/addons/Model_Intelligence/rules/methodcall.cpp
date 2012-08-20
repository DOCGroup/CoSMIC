#include "StdAfx.h"
#include "methodcall_impl.hpp"

void instantiate_methodcall_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  methodcall <iterator_type> g;
}
