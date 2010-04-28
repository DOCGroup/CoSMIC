// -*- C++ -*-
// $Id$

namespace GME
{
namespace XME
{
//
// Auto_Model_T
//
template <typename T>
GME_INLINE
Auto_Model_T <T>::Auto_Model_T (void)
{

}

//
// Auto_Model_T
//
template <typename T>
GME_INLINE
Auto_Model_T <T>::Auto_Model_T (T & model)
: model_ (model)
{
  this->model_.children (this->purge_set_);
}

//
// Auto_Model_T
//
template <typename T>
GME_INLINE
Auto_Model_T <T>::~Auto_Model_T (void)
{
  this->purge_models ();
}

//
// get
//
template <typename T>
GME_INLINE
T & Auto_Model_T <T>::get (void)
{
  return this->model_;
}

//
// operator ->
//
template <typename T>
GME_INLINE
T * Auto_Model_T <T>::operator -> (void)
{
  return &this->model_;
}

//
// children
//
template <typename T>
GME_INLINE
const typename Auto_Model_T <T>::collection_type &
Auto_Model_T <T>::children (void) const
{
  return this->children_;
}

//
// children
//
template <typename T>
GME_INLINE
typename Auto_Model_T <T>::collection_type & Auto_Model_T <T>::children (void)
{
  return this->children_;
}

}
}
