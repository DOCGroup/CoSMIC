// $Id: Auto_Release_Ptr.inl,v 1.1.2.1 2006/05/25 22:18:33 hillj Exp $

//
// detach
//
template <typename TYPE>
CUTS_INLINE
TYPE * CUTS_Auto_Release_Ptr <TYPE>::detach (void)
{
  TYPE * ptr = this->ptr_;
  this->ptr_ = 0;
  return ptr;
}

//
// detach
//
template <typename TYPE>
CUTS_INLINE
TYPE * CUTS_Auto_Release_Ptr <TYPE>::get (void)
{
  return this->ptr_;
}

//
// operator ->
//
template <typename TYPE>
CUTS_INLINE
TYPE * CUTS_Auto_Release_Ptr <TYPE>::operator -> (void)
{
  return this->ptr_;
}

//
// operator *
//
template <typename TYPE>
CUTS_INLINE
TYPE & CUTS_Auto_Release_Ptr <TYPE>::operator * (void)
{
  return *this->ptr_;
}
