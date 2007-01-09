// $Id$


//
// generate
//
template <typename IMPL_STRATEGY>
CUTS_INLINE
void CUTS_BE_Impl_Generator_T <IMPL_STRATEGY>::
generate (const PICML::RootFolder & root)
{
  root.Accept (*this);
}

