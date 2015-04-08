#include "StdAfx.h"
#include "simple_type_spec_impl.hpp"

void instantiate_simple_type_spec_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  simple_type_spec <iterator_type> g;
}
