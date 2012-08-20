#include "StdAfx.h"
#include "iterator_impl.hpp"

void instantiate_iterator_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  iterator <iterator_type> g;
}
