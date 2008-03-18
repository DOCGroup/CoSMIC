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
Collection_T <T>::Collection_T (typename collection_type * collection)
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
typename Collection_T <T>::collection_type *
Collection_T <T>::impl (void) const
{
  return this->collection_.p;
}

//
// items
//
template <typename T>
GME_INLINE
typename Collection_T <T>::container_type &
Collection_T <T>::items (void)
{
  return this->items_;
}

//
// operator []
//
template <typename T>
GME_INLINE
const typename Collection_T <T>::container_type &
Collection_T <T>::items (void) const
{
  return this->items_;
}

//
// attach
//
template <typename T>
GME_INLINE
void Collection_T <T>::attach (typename collection_type * collection)
{
  this->collection_.Attach (collection);
  this->populate ();
}

//
// begin
//
template <typename T>
GME_INLINE
typename Collection_T <T>::iterator Collection_T <T>::begin (void)
{
  return this->items_.begin ();
}

//
// end
//
template <typename T>
GME_INLINE
typename Collection_T <T>::iterator Collection_T <T>::end (void)
{
  return this->items_.end ();
}

//
// begin
//
template <typename T>
GME_INLINE
typename Collection_T <T>::const_iterator
Collection_T <T>::begin (void) const
{
  return this->items_.begin ();
}

//
// begin
//
template <typename T>
GME_INLINE
typename Collection_T <T>::const_iterator
Collection_T <T>::end (void) const
{
  return this->items_.end ();
}

//
// size
//
template <typename T>
GME_INLINE
typename Collection_T <T>::size_type Collection_T <T>::size (void) const
{
  return this->items_.size ();
}

//
// empty
//
template <typename T>
GME_INLINE
bool Collection_T <T>::empty (void) const
{
  return this->items_.empty ();
}

//
// clear
//
template <typename T>
GME_INLINE
void Collection_T <T>::clear (void)
{
  this->items_.clear ();
}

}
