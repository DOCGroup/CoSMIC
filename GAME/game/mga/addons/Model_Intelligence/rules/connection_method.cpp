#include "StdAfx.h"
#include "connection_method_impl.hpp"

void instantiate_connection_method_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  ::connection_method <iterator_type> g;
}


