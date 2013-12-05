// $Id$

#include "StdAfx.h"
#include "param_type_spec_impl.hpp"

void instantiate_param_type_spec_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  param_type_spec <iterator_type> g;
}
