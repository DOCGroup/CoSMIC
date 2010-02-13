// $Id$

#include "const_decl_impl.hpp"

void instantiate_const_decl_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  const_decl <iterator_type> g;
}
