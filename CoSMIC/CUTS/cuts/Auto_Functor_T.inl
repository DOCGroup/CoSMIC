// -*- C++ -*-
// $Id$

//
// CUTS_Auto_Functor_T
//
template <typename T>
CUTS_INLINE
CUTS_Auto_Functor_T <T>::
CUTS_Auto_Functor_T (T * ptr, void (T::*method) (void))
: ptr_ (ptr),
  method_ (method)
{

}

//
// ~CUTS_Auto_Functor_T
//
template <typename T>
CUTS_INLINE
CUTS_Auto_Functor_T <T>::~CUTS_Auto_Functor_T (void)
{
  this->reset ();
}

//
// detach
//
template <typename T>
CUTS_INLINE
T * CUTS_Auto_Functor_T <T>::get (void)
{
  return this->ptr_;
}

//
// operator ->
//
template <typename T>
CUTS_INLINE
T * CUTS_Auto_Functor_T <T>::operator -> (void)
{
  return this->ptr_;
}

//
// operator *
//
template <typename T>
CUTS_INLINE
T & CUTS_Auto_Functor_T <T>::operator * (void)
{
  return *this->ptr_;
}
