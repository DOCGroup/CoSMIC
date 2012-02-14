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
  this->item_ = rhs.item_;

  return *this;
}

//
// item
//
template <typename T>
T & Iterator <T>::item (void) const
{
  if (!this->item_.is_nil ())
    return this->item_;

  ATL::CComPtr <typename collection_traits <iterator_type *>::interface_type> temp;
  VERIFY_HRESULT (this->iter_->get_Item (this->index_, &temp));

  // Store the members in a collection.
  ATL::CComPtr <typename T::interface_type> item;
  VERIFY_HRESULT (temp.QueryInterface (&item));

  this->item_ = item.p;
  return this->item_;
}

//
// advance
//
template <typename T>
GAME_INLINE
void Iterator <T>::advance (void)
{
  ++ this->index_;

  if (!this->item_.is_nil ())
    this->item_ = 0;
}


//
// operator ++
//
template <typename T>
Iterator <T> Iterator <T>::operator ++ (int)
{
  Iterator iter (*this);
  ++ this->index_;

  if (!this->item_.is_nil ())
    this->item_ = 0;

  return iter;
}

//
// operator ++
//
template <typename T>
GAME_INLINE
Iterator <T> & Iterator <T>::operator ++ (void)
{
  ++ this->index_;

  if (!this->item_.is_nil ())
    this->item_ = 0;

  return *this;
}


}
}
