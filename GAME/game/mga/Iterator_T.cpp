// $Id$

#if !defined (__GAME_INLINE__)
#include "Iterator_T.inl"
#endif

namespace GAME
{
namespace Mga
{

//
// Iterator
//
template <typename T>
Iterator <T>::Iterator (iterator_type * iter)
: iter_ (iter),
  index_ (1),
  count_ (0)
{
  VERIFY_HRESULT (this->iter_->get_Count (&this->count_));
}

//
// operator =
//
template <typename T>
const Iterator <T> & Iterator <T>::operator = (const Iterator <T> & rhs)
{
  if (this == &rhs)
    return *this;

  this->iter_ = rhs.iter_;
  this->count_ = rhs.count_;
  this->index_ = rhs.index_;
  return *this;
}

//
// item
//
template <typename T>
T Iterator <T>::item (void) const
{
  ATL::CComPtr <typename collection_traits <iterator_type *>::interface_type> temp;
  VERIFY_HRESULT (this->iter_->get_Item (this->index_, &temp));

  return temp.p;
}

//
// operator ++
//
template <typename T>
Iterator <T> & Iterator <T>::operator ++ (void)
{
  ++ this->index_;

  return *this;
}

//
// operator ++
//
template <typename T>
Iterator <T> Iterator <T>::operator ++ (int)
{
  Iterator dup (*this);
  ++ this->index_;

  return dup;
}

//
// operator ==
//
template <typename T>
bool Iterator <T>::operator == (const Iterator <T> & rhs) const
{
  if (this == &rhs)
    return true;

  return this->iter_.p == rhs.iter_.p && this->index_ == rhs.index_;
}

//
// operator !=
//
template <typename T>
bool Iterator <T>::operator != (const Iterator <T> & rhs) const
{
  if (this != &rhs)
    return true;

  return this->iter_.p != rhs.iter_.p || this->index_ == rhs.index_;
}

}
}
