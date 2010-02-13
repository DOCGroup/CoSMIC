// $Id$

#include "char_type_impl.hpp"

void instantiate_char_type_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  char_type <iterator_type> g;
}
