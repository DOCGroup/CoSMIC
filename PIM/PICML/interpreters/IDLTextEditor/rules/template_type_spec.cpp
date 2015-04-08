#include "StdAfx.h"
#include "template_type_spec_impl.hpp"

void instantiate_template_type_spec_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  template_type_spec <iterator_type> g;
}
