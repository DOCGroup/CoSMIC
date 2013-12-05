// $Id$

#include "StdAfx.h"
#include "raises_expr_impl.hpp"

void instantiate_raises_expr_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  raises_expr <iterator_type> g;
}
