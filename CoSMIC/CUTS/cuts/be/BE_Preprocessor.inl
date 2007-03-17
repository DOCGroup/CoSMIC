// $Id$

//
// CUTS_BE_Preprocessor
//
CUTS_INLINE
CUTS_BE_Preprocessor::CUTS_BE_Preprocessor (void)
: current_impl_ (0)
{

}

//
// ~CUTS_BE_Preprocessor
//
CUTS_INLINE
CUTS_BE_Preprocessor::~CUTS_BE_Preprocessor (void)
{

}

//
// stubs
//
CUTS_INLINE
const CUTS_BE_IDL_Graph &
CUTS_BE_Preprocessor::stubs (void) const
{
  return this->idl_graph_;
}

//
// impls
//
CUTS_INLINE
const CUTS_BE_Impl_Graph &
CUTS_BE_Preprocessor::impls (void) const
{
  return this->impl_graph_;
}

//
// remove
//
CUTS_INLINE
void CUTS_BE_Preprocessor::
remove (const PICML::ComponentImplementationContainer & container)
{
  this->impl_graph_.remove (container.name ());
}
