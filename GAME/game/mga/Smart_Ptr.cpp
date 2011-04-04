// $Id$

#if !defined (__GAME_INLINE__)
#include "Smart_Ptr.inl"
#endif

#include "Exception.h"

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// Smart_Ptr_Base

//
// _narrow
//
template <typename T>
template <typename T1>
static T * Smart_Ptr_Base <T>::_narrow (T1 * impl)
{
  // Make sure we are not narrowing on a nil pointer.
  if (impl == 0)
    return 0;

  // Try to cast the implementation.
  T * temp = dynamic_cast <T *> (impl);

  if (0 != temp)
    return temp;

  throw Invalid_Cast ();
}

///////////////////////////////////////////////////////////////////////////////
// Smart_Ptr

//
// operator =
//
template <typename T>
const Smart_Ptr <T> & Smart_Ptr <T>::operator = (const Smart_Ptr <T> & rhs)
{
  if (this == &rhs)
    return *this;

  this->reset (rhs.impl_);
  return *this;
}

//
// reset
//
template <typename T>
void Smart_Ptr <T>::reset (T * impl)
{
  // First, we increment the other object's reference count just in
  // case we contain a reference to the same element. We don't want
  // to accidently delete it.
  if (0 != impl)
    impl->increment ();

  // We can now decrement the reference count of our implementation,
  // which may cause it to be deleted, and store the other object's
  // implementation in ours.
  if (0 != this->impl_)
    this->impl_->decrement ();

  this->impl_ = impl;
}

//
// release
//
template <typename T>
T * Smart_Ptr <T>::_retn (void)
{
  // Swap out the current implementation pointer.
  T * impl = 0;
  std::swap (impl, this->impl_);

  return impl;
}


}
}
