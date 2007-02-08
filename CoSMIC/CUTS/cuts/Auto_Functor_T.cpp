// $Id$

#if !defined (__CUTS_INLINE__)
#include "cuts/Auto_Functor_T.inl"
#endif

//
// reset
//
template <typename TYPE, typename METHOD>
void CUTS_Auto_Functor_T <TYPE, METHOD>::reset (TYPE * ptr)
{
  if (this->ptr_ != 0)
    (this->ptr_->*this->method_) ();

  this->ptr_ = ptr;
}

//
// detach
//
template <typename TYPE, typename METHOD>
TYPE * CUTS_Auto_Functor_T <TYPE, METHOD>::detach (void)
{
  TYPE * ptr = this->ptr_;
  this->ptr_ = 0;
  return ptr;
}

//
// CUTS_Auto_Functor_T
//
template <typename TYPE, typename METHOD>
const CUTS_Auto_Functor_T <TYPE, METHOD> &
CUTS_Auto_Functor_T <TYPE, METHOD>::
operator = (const CUTS_Auto_Functor_T & rhs)
{
  // Save the pointer.
  this->ptr_ = rhs.ptr_;
  this->method_ = rhs.method_;

  // Release the right-hand side's pointer.
  rhs.ptr_ = 0;

  return *this;
}
