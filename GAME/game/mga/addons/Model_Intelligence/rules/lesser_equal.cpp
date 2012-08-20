#include "StdAfx.h"
#include "lesser_equal_impl.hpp"

void instantiate_lesser_equal_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  lesser_equal <iterator_type> g;
}
