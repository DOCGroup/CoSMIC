// -*- C++ -*-
// $Id$

namespace GAME
{
namespace Mga
{

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
  count_ (copy.count_)
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
// reset
//
template <typename T>
GAME_INLINE
void Iterator <T>::advance (void)
{
  ++ this->index_;
}

//
// operator *
//
template <typename T>
GAME_INLINE
T Iterator <T>::operator * (void) const
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

}
}

