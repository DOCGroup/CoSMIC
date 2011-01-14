// $Id$

#if !defined (__GAME_INLINE__)
#include "Auto_Model_T.inl"
#endif

#include "game/xme/modelgen.h"
#include "boost/bind.hpp"

namespace GAME
{
namespace XME
{
//
// release
//
template <typename T>
T Auto_Model_T <T>::release (void)
{
  T temp = this->model_;

  this->model_.release ();
  this->purge_set_.clear ();
  this->children_.clear ();

  return temp;
}

//
// attach
//
template <typename T>
void Auto_Model_T <T>::attach (T & model)
{
  this->model_ = model;
  this->model_.children (this->purge_set_);
  this->children_.clear ();
}

//
// purge_models
//
template <typename T>
void Auto_Model_T <T>::purge_models (void)
{
  using GAME::XME::Object;

  std::for_each (this->purge_set_.begin (),
                 this->purge_set_.end (),
                 boost::bind (&Object::destroy, _1));
}

//
// create
//
template <typename T>
template <typename T1, typename META>
bool Auto_Model_T <T>::create (const META & metaname, T1 & element)
{
  // Create the element and store it for later.
  element = T1::_create (this->model_, metaname);
  this->children_.push_back (element);

  // Remove the element from the purge list.
  collection_type::iterator iter =
    std::find (this->purge_set_.begin (),
               this->purge_set_.end (),
               element);

  if (iter != this->purge_set_.end ())
    this->purge_set_.erase (iter);

  return true;
}

//
// create_if
//
template <typename T>
template <typename T1, typename META, typename PRED>
bool Auto_Model_T <T>::
create_if (const META & metaname,
           T1 collection,
           typename T1::value_type & element,
           PRED predicate)
{
  // First, let's create the requested element.
  bool retval = GAME::create_if (this->model_, metaname, collection, element, predicate);

  if (!retval)
  {
    // Since the element already existed, we need to remove
    // it from the purge set. This will ensure the element is
    // not deleted when this object goes out of scope.
    collection_type::iterator iter =
      std::find (this->purge_set_.begin (),
                 this->purge_set_.end (),
                 element);

    if (iter != this->purge_set_.end ())
      this->purge_set_.erase (iter);
  }

  // Save this element.
  this->children_.push_back (element);

  return retval;
}

template <typename T>
template <typename T1, typename META, typename PRED>
bool Auto_Model_T <T>::
create_if_not (const META & metaname,
               T1 & element,
               PRED predicate)
{
  using GAME::Xme_t;

  // Attempt to create the requested element.
  bool retval =
    GAME::create_if_not <Xme_t> (this->model_,
                                 metaname,
                                 element,
                                 predicate);

  if (!retval)
  {
    // Since the element already existed, we need to remove
    // it from the purge set. This will ensure the element is
    // not deleted when this object goes out of scope.
    collection_type::iterator iter =
      std::find (this->purge_set_.begin (),
                 this->purge_set_.end (),
                 element);

    if (iter != this->purge_set_.end ())
      this->purge_set_.erase (iter);
  }

  // Save this element.
  this->children_.push_back (element);

  return retval;
}

//
// create_if_not
//
template <typename T>
template <typename T1, typename META, typename PRED>
bool Auto_Model_T <T>::
create_if_not (const META & metaname,
               const T1 & collection,
               typename T1::value_type & element,
               PRED predicate)
{
  // First, let's create the requested element.
  bool retval = GAME::create_if_not (this->model_, metaname, collection, element, predicate);

  if (!retval)
  {
    // Since the element already existed, we need to remove
    // it from the purge set. This will ensure the element is
    // not deleted when this object goes out of scope.
    collection_type::iterator iter =
      std::find (this->purge_set_.begin (),
                 this->purge_set_.end (),
                 element);

    if (iter != this->purge_set_.end ())
      this->purge_set_.erase (iter);
  }

  // Save this element.
  this->children_.push_back (element);

  return retval;
}

}
}
