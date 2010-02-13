// $Id$

#include "floating_pt_type_impl.hpp"

void instantiate_floating_pt_type_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  floating_pt_type <iterator_type> g;
}
