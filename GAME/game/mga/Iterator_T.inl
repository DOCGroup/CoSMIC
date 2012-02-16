// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

///////////////////////////////////////////////////////////////////////////////
// Iterator

//
// Iterator
//
template <typename T>
GAME_INLINE
Iterator <T>::Iterator (void)
: index_ (1),
  count_ (0)
{
}

//
// Iterator
//
template <typename T>
GAME_INLINE
Iterator <T>::Iterator (iterator_type * iter, long index, long count)
: iter_ (iter),
  index_ (index),
  count_ (count)
{
}

//
// Iterator
//
template <typename T>
GAME_INLINE
Iterator <T>::Iterator (const Iterator <T> & copy)
: iter_ (copy.iter_),
  index_ (copy.index_),
  count_ (copy.count_),
  item_ (copy.item_)
{
}

//
// Iterator
//
template <typename T>
GAME_INLINE
Iterator <T>::~Iterator (void)
{
}

//
// is_done
//
template <typename T>
GAME_INLINE
bool Iterator <T>::is_done (void) const
{
  return this->index_ > this->count_;
}

//
// count
//
template <typename T>
GAME_INLINE
long Iterator <T>::count (void) const
{
  return this->count_;
}

//
// count
//
template <typename T>
GAME_INLINE
long Iterator <T>::index (void) const
{
  return this->index_;
}

//
// make_end
//
template <typename T>
GAME_INLINE
Iterator <T> Iterator <T>::make_end (void) const
{
  return Iterator (this->iter_.p, this->count_ + 1, this->count_);
}

//
// reset
//
template <typename T>
GAME_INLINE
void Iterator <T>::reset (void)
{
  this->index_ = 1;
}

//
// operator *
//
template <typename T>
GAME_INLINE
T & Iterator <T>::operator * (void) const
{
  return this->item ();
}

//
// operator ->
//
template <typename T>
GAME_INLINE
T * Iterator <T>::operator -> (void) const
{
  return &this->item ();
}

//
// items
//
template <typename T>
GAME_INLINE
void Iterator <T>::items (std::vector <T> & out) const
{
  iter_to_collection (this->iter_.p, out);
}

///////////////////////////////////////////////////////////////////////////////
// Impl_Iterator

//
// Impl_Iterator
//
template <typename BASE>
GAME_INLINE
Impl_Iterator <BASE>::Impl_Iterator (void)
{

}

//
// Impl_Iterator
//
template <typename BASE>
GAME_INLINE
Impl_Iterator <BASE>::Impl_Iterator (const BASE & copy)
: BASE (copy)
{

}

//
// Impl_Iterator
//
template <typename BASE>
GAME_INLINE
Impl_Iterator <BASE>::Impl_Iterator (const Impl_Iterator & copy)
: BASE (copy)
{

}

//
// ~Impl_Iterator
//
template <typename BASE>
GAME_INLINE
Impl_Iterator <BASE>::~Impl_Iterator (void)
{

}

//
// operator *
//
template <typename BASE>
GAME_INLINE
typename Impl_Iterator <BASE>::impl_type *
Impl_Iterator <BASE>::operator * (void)
{
  BASE & base = *this;
  return *base;
}

//
// make_impl_iter
//
template <typename BASE>
GAME_INLINE
Impl_Iterator <BASE> make_impl_iter (const BASE & iter)
{
  return Impl_Iterator <BASE> (iter);
}

//
// operator ==
//
template <typename T>
GAME_INLINE
bool Iterator <T>::operator == (const Iterator <T> & rhs) const
{
  return this == &rhs || (this->iter_.p == rhs.iter_.p && this->index_ == rhs.index_);
}

//
// operator !=
//
template <typename T>
GAME_INLINE
bool Iterator <T>::operator != (const Iterator <T> & rhs) const
{
  return !(*this == rhs);
}

}
}

