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

}
