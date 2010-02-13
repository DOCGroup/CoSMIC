// $Id$

#include "boolean_type_impl.hpp"

void instantiate_boolean_type_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  boolean_type <iterator_type> g;
}
