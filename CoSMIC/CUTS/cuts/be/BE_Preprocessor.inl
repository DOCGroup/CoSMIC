// $Id$

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
