#include "StdAfx.h"
#include "greater_impl.hpp"

void instantiate_greater_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  greater <iterator_type> g;
}
