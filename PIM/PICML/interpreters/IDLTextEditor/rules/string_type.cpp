// $Id$

#include "StdAfx.h"
#include "string_type_impl.hpp"

void instantiate_string_type_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  string_type <iterator_type> g;
}
