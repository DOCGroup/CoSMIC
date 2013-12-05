// $Id$

#include "StdAfx.h"
#include "integer_type_impl.hpp"

void instantiate_integer_type_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  integer_type <iterator_type> g;
}
