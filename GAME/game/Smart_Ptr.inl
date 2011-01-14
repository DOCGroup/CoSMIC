// -*- C++ -*-
// $Id$

#include "Impl_Factory.h"

namespace GAME
{

///////////////////////////////////////////////////////////////////////////////
// Smart_Ptr_Base

//
// Smart_Ptr_Base
//
template <typename T>
GAME_INLINE
Smart_Ptr_Base <T>::Smart_Ptr_Base (void)
: impl_ (0)
{

}

//
// Smart_Ptr_Base
//
template <typename T>
GAME_INLINE
Smart_Ptr_Base <T>::Smart_Ptr_Base (T * impl)
: impl_ (impl)
{

}

//
// Smart_Ptr_Base
//
template <typename T>
template <typename T1>
GAME_INLINE
Smart_Ptr_Base <T>::Smart_Ptr_Base (T1 * impl)
: impl_ (impl)
{

}

//
// Smart_Ptr_Base
//
template <typename T>
GAME_INLINE
Smart_Ptr_Base <T>::Smart_Ptr_Base (const Smart_Ptr_Base & copy)
: impl_ (copy.impl_)
{

}

//
// Smart_Ptr_Base
//
template <typename T>
template <typename T1>
GAME_INLINE
Smart_Ptr_Base <T>::Smart_Ptr_Base (const Smart_Ptr_Base <T1> & copy)
: impl_ (copy.get ())
{

}

//
// ~Smart_Ptr_Base
//
template <typename T>
GAME_INLINE
Smart_Ptr_Base <T>::~Smart_Ptr_Base (void)
{

}

//
// hash
//
template <typename T>
GAME_INLINE
unsigned long Smart_Ptr_Base <T>::hash (void) const
{
  return this->impl_->hash ();
}

//
// operator ->
//
template <typename T>
GAME_INLINE
T * Smart_Ptr_Base <T>::operator -> (void)
{
  return this->impl_;
}

//
// operator ->
//
template <typename T>
GAME_INLINE
const T * Smart_Ptr_Base <T>::operator -> (void) const
{
  return this->impl_;
}

//
// operator *
//
template <typename T>
GAME_INLINE
T & Smart_Ptr_Base <T>::operator * (void)
{
  return *this->impl_;
}

//
// operator *
//
template <typename T>
GAME_INLINE
const T & Smart_Ptr_Base <T>::operator * (void) const
{
  return *this->impl_;
}

//
// get
//
template <typename T>
GAME_INLINE
T * Smart_Ptr_Base <T>::get (void)
{
  return this->impl_;
}

//
// get
//
template <typename T>
GAME_INLINE
const T * Smart_Ptr_Base <T>::get (void) const
{
  return this->impl_;
}

//
// operator T *
//
template <typename T>
GAME_INLINE
Smart_Ptr_Base <T>::operator T * (void)
{
  return this->impl_;
}

//
// is_nil
//
template <typename T>
GAME_INLINE
bool Smart_Ptr_Base <T>::is_nil (void) const
{
  return this->impl_ == 0;
}

///////////////////////////////////////////////////////////////////////////////
// Smart_Ptr

//
// Smart_Ptr
//
template <typename T>
GAME_INLINE
Smart_Ptr <T>::Smart_Ptr (void)
{

}

//
// Smart_Ptr
//
template <typename T>
GAME_INLINE
Smart_Ptr <T>::Smart_Ptr (const Smart_Ptr <T> & ptr)
: Smart_Ptr_Base (ptr)
{
  if (0 != this->impl_)
    this->impl_->increment ();
}

//
// Smart_Ptr
//
template <typename T>
template <typename T1>
GAME_INLINE
Smart_Ptr <T>::Smart_Ptr (const Smart_Ptr <T1> & ptr)
: Smart_Ptr_Base (const_cast <T1 *> (ptr.get ()))
{
  if (0 != this->impl_)
    this->impl_->increment ();
}

//
// Smart_Ptr
//
template <typename T>
template <typename T1>
GAME_INLINE
Smart_Ptr <T>::Smart_Ptr (T1 * impl)
: Smart_Ptr_Base (impl)
{
  if (0 != this->impl_)
    this->impl_->increment ();
}

//
// Smart_Ptr
//
template <typename T>
GAME_INLINE
Smart_Ptr <T>::Smart_Ptr (typename T::interface_type * impl)
: Smart_Ptr_Base (Smart_Ptr::_narrow (GLOBAL_IMPL_FACTORY::instance ()->allocate (impl)))
{
  if (0 != this->impl_)
    this->impl_->increment ();
}

//
// ~Smart_Ptr
//
template <typename T>
GAME_INLINE
Smart_Ptr <T>::~Smart_Ptr (void)
{
  if (0 != this->impl_)
    this->impl_->decrement ();
}

//
// operator =
//
template <typename T>
GAME_INLINE
const Smart_Ptr <T> & Smart_Ptr <T>::operator = (T * impl)
{
  this->reset (impl);
  return *this;
}

//
// operator =
//
template <typename T>
template <typename T1>
GAME_INLINE
const Smart_Ptr <T> & Smart_Ptr <T>::operator = (const Smart_Ptr <T1> & obj)
{
  this->reset (const_cast <T1 *> (obj.get ()));
  return *this;
}

//
// operator <
//
template <typename T>
bool Smart_Ptr <T>::operator < (const Smart_Ptr <T> & ptr) const
{
  if (this->impl_ == ptr.impl_)
    return false;

  return
    this->impl_ == 0 ||
    (!this->impl_->is_equal_to (ptr.impl_) && this->impl_ < ptr.impl_);
}

//
// operator >
//
template <typename T>
bool Smart_Ptr <T>::operator > (const Smart_Ptr <T> & ptr) const
{
  if (this->impl_ == ptr.impl_)
    return false;

  return
    ptr.impl_ == 0 ||
    (!this->impl_->is_equal_to (ptr.impl_) && this->impl_ > ptr.impl_);
}

//
// operator ==
//
template <typename T>
template <typename T1>
bool Smart_Ptr <T>::operator == (const Smart_Ptr <T1> & rhs) const
{
  if (this->impl_ == rhs.impl_)
    return true;

  return 0 != this->impl_ && this->impl_->is_equal_to (rhs.impl_);
}

//
// operator !=
//
template <typename T>
template <typename T1>
GAME_INLINE
bool Smart_Ptr <T>::operator != (const Smart_Ptr <T1> & rhs) const
{
  return !(*this == rhs);
}

//
// _narrow
//
template <typename T>
template <typename T1>
GAME_INLINE
static T * Smart_Ptr <T>::_narrow (const Smart_Ptr <T1> & impl)
{
  return Smart_Ptr <T>::_narrow (const_cast <T1 *> (impl.get ()));
}

}
