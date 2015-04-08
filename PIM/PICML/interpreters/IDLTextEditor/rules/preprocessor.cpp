#include "StdAfx.h"
#include "preprocessor_impl.hpp"

void instantiate_preprocessor_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  preprocessor <iterator_type> g;
}
