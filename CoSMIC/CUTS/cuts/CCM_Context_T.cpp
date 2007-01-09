// $Id$

#if !defined (__CUTS_INLINE__)
#include "CCM_Context_T.inl"
#endif

//
// CUTS_CCM_Context_T
//
template <typename T>
CUTS_CCM_Context_T <T>::
CUTS_CCM_Context_T (::Components::SessionContext::_ptr_type ctx,
                    CUTS_Benchmark_Agent * agent)
: ctx_ (T::_narrow (ctx)),
  agent_ (agent)
{

}

