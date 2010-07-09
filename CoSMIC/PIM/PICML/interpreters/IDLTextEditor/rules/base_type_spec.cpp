// $Id$

#include "StdAfx.h"
#include "base_type_spec_impl.hpp"

void instantiate_base_type_spec_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  base_type_spec <iterator_type> g;
}
