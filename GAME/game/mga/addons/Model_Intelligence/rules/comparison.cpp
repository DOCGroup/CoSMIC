#include "StdAfx.h"
#include "comparison_impl.hpp"

void instantiate_comparison_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  comparison <iterator_type> g;
}
