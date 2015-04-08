#include "StdAfx.h"
#include "scoped_name_impl.hpp"

void instantiate_scoped_name_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  scoped_name <iterator_type> g;
}
