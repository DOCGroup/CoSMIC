// $Id$

#include "BE_Preprocessor.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Preprocessor.inl"
#endif

#include "Uml.h"

//
// preprocess
//
bool CUTS_BE_Preprocessor::
preprocess (const PICML::ComponentImplementationContainer & container)
{
  PICML::ComponentImplementationContainer (container).
    Accept (this->impl_graph_);

  return true;
}

//
// preprocess
//
bool CUTS_BE_Preprocessor::
preprocess (const PICML::File & file)
{
  PICML::File (file).
    Accept (this->idl_graph_);

  return true;
}
