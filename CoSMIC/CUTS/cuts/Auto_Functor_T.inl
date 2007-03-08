// -*- C++ -*-
// $Id$

//
// CUTS_Auto_Functor_T
//
template <typename TYPE, typename METHOD>
CUTS_INLINE
CUTS_Auto_Functor_T <TYPE, METHOD>::
CUTS_Auto_Functor_T (TYPE * ptr, METHOD method)
: ptr_ (ptr),
  method_ (method)
{

}

//
// CUTS_Auto_Functor_T
//
template <typename TYPE, typename METHOD>
CUTS_INLINE
CUTS_Auto_Functor_T <TYPE, METHOD>::
CUTS_Auto_Functor_T (const CUTS_Auto_Functor_T & rhs)
: ptr_ (rhs.ptr_),
  method_ (rhs.method_)
{
  rhs.ptr_ = 0;
}

//
// ~CUTS_Auto_Functor_T
//
template <typename TYPE, typename METHOD>
CUTS_INLINE
CUTS_Auto_Functor_T <TYPE, METHOD>::~CUTS_Auto_Functor_T (void)
{
  this->reset ();
}

//
// detach
//
template <typename TYPE, typename METHOD>
CUTS_INLINE
TYPE * CUTS_Auto_Functor_T <TYPE, METHOD>::get (void)
{
  return this->ptr_;
}

//
// operator ->
//
template <typename TYPE, typename METHOD>
CUTS_INLINE
TYPE * CUTS_Auto_Functor_T <TYPE, METHOD>::operator -> (void)
{
  return this->ptr_;
}

//
// operator *
//
template <typename TYPE, typename METHOD>
CUTS_INLINE
TYPE & CUTS_Auto_Functor_T <TYPE, METHOD>::operator * (void)
{
  return *this->ptr_;
}
