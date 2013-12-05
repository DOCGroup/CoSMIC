// $Id$

#include "StdAfx.h"
#include "export_impl.hpp"

void instantiate_idl_export_grammar (void)
{
  typedef std::string::const_iterator iterator_type;
  idl_export <iterator_type> g;
}
