// $Id$

#include "StdAfx.h"
#include "home_decl_impl.hpp"

void instanstiate_home_decl_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  home_decl <iterator_type> g;
}
