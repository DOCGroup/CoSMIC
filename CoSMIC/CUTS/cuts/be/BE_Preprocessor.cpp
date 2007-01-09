// $Id$

#include "BE_Preprocessor.h"

#if !defined (__CUTS_INLINE__)
#include "BE_Preprocessor.inl"
#endif

#include "Uml.h"

//
// instance_
//
CUTS_BE_Preprocessor * CUTS_BE_Preprocessor::instance_ = 0;

//
// instance
//
CUTS_BE_Preprocessor * CUTS_BE_Preprocessor::instance (void)
{
  if (CUTS_BE_Preprocessor::instance_ == 0)
    CUTS_BE_Preprocessor::instance_ = new CUTS_BE_Preprocessor ();

  return CUTS_BE_Preprocessor::instance_;
}

//
// close_singleton
//
void CUTS_BE_Preprocessor::close_singleton (void)
{
  if (CUTS_BE_Preprocessor::instance_ != 0)
  {
    delete CUTS_BE_Preprocessor::instance_;
    CUTS_BE_Preprocessor::instance_ = 0;
  }
}

//
// CUTS_BE_Preprocessor
//
CUTS_BE_Preprocessor::CUTS_BE_Preprocessor (void)
: current_impl_ (0)
{

}

//
// ~CUTS_BE_Preprocessor
//
CUTS_BE_Preprocessor::~CUTS_BE_Preprocessor (void)
{

}

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
