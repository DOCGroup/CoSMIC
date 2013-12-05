// $Id$

#include "StdAfx.h"
#include "init_params_decl_impl.hpp"

void instantiate_init_params_decl_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  init_params_decls <iterator_type> g;
}
