#include "StdAfx.h"
#include "local_value_assgn_impl.hpp"

void instantiate_local_value_assgn_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  local_value_assgn <iterator_type> g;
}
