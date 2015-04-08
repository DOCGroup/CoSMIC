#include "StdAfx.h"
#include "wide_string_type_impl.hpp"

void instantiate_wide_string_type_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  wide_string_type <iterator_type> g;
}
