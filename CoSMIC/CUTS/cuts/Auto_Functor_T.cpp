// $Id$

#if !defined (__CUTS_INLINE__)
#include "cuts/Auto_Functor_T.inl"
#endif

//
// reset
//
template <typename T>
void CUTS_Auto_Functor_T <T>::reset (T * ptr)
{
  if (this->ptr_ != 0)
    (this->ptr_->*this->method_) ();

  this->ptr_ = ptr;
}

//
// detach
//
template <typename T>
T * CUTS_Auto_Functor_T <T>::detach (void)
{
  T * old_ptr = this->ptr_;
  this->ptr_ = 0;

  return old_ptr;
}
