// $Id: Action_T.cpp,v 1.1.2.1.2.1 2006/05/24 05:22:24 hillj Exp $

#if !defined (__CUTS_INLINE__)
#include "cuts/Action_T.inl"
#endif

//
// CUTS_Action_T
//
template <typename WORKER_TYPE>
CUTS_Action_T <WORKER_TYPE>::CUTS_Action_T (WORKER_TYPE & parent)
: parent_ (parent)
{

}

//
// ~CUTS_Action_T
//
template <typename WORKER_TYPE>
CUTS_Action_T <WORKER_TYPE>::~CUTS_Action_T (void)
{

}
