// $Id$

#include "type_decl_impl.hpp"

void instantiate_type_decl_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  type_decl <iterator_type> g;
}
