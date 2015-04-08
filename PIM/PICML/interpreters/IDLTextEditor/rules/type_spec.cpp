#include "StdAfx.h"
#include "type_spec_impl.hpp"

void instantiate_type_spec_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  type_spec <iterator_type> g;
}
