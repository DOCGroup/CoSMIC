#include "StdAfx.h"
#include "value_impl.hpp"

void instantiate_value_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  value <iterator_type> g;
}
