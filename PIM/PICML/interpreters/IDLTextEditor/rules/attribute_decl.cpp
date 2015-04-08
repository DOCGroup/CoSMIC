#include "StdAfx.h"
#include "attribute_decl_impl.hpp"

void instantiate_attribute_decl_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  attribute_decl <iterator_type> g;
}
