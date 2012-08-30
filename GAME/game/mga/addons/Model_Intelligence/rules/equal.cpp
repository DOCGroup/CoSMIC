#include "StdAfx.h"
#include "equal_impl.hpp"

void instantiate_equal_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  equal <iterator_type> g;
}
