#include "StdAfx.h"
#include "ident_impl.hpp"

void instantiate_ident_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  ident <iterator_type> g;
}
