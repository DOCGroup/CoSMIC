// $Id$

namespace GME
{
//
// Collection_T
//
template <typename T>
GME_INLINE
Collection_T <T>::Collection_T (void)
{

}

//
// Collection_T
//
template <typename T>
GME_INLINE
Collection_T <T>::Collection_T (typename _collection_type * collection)
: collection_ (collection)
{
  this->populate ();
}

//
// Collection_T
//
template <typename T>
GME_INLINE
Collection_T <T>::~Collection_T (void)
{

}

//
// impl
//
template <typename T>
GME_INLINE
typename Collection_T <T>::_collection_type *
Collection_T <T>::impl (void) const
{
  return this->collection_.p;
}

//
// operator []
//
template <typename T>
GME_INLINE
T & Collection_T <T>::operator [] (size_t i)
{
  return this->items_[i];
}

//
// operator []
//
template <typename T>
GME_INLINE
const T & Collection_T <T>::operator [] (size_t i) const
{
  return this->items_[i];
}

//
// size
//
template <typename T>
GME_INLINE
size_t Collection_T <T>::size (void) const
{
  return this->items_.size ();
}

//
// attach
//
template <typename T>
GME_INLINE
void Collection_T <T>::attach (typename _collection_type * collection)
{
  this->collection_.Attach (collection);
  this->populate ();
}

}
