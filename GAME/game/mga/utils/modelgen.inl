// -*- C++ -*-
// $Id$

namespace GAME
{

//
// find
//
template <typename ARCH, typename P, typename T, typename META, typename PRED>
inline
bool find (P parent, const META & metaname, T & element, PRED predicate)
{
  contains_t <ARCH, PRED> c (predicate);
  return c (parent, metaname, element);
}

//
// contains_t
//
template <typename ARCH, typename PRED>
inline
contains_t <ARCH, PRED>::contains_t (PRED predicate)
: predicate_ (predicate)
{

}

//
// contains_t::operator ()
//
template <typename ARCH, typename PRED>
template <typename COLLECTION>
inline
bool contains_t <ARCH, PRED>::
operator () (const COLLECTION & collection, typename COLLECTION::value_type & element)
{
  return this->find_i (collection.begin (), collection.end (), element);
}

//
// contains
//
template <typename ARCH, typename PRED>
inline
contains_t <ARCH, PRED> contains (PRED predicate)
{
  return contains_t <ARCH, PRED> (predicate);
}

}
