// -*- C++ -*-
// $Id$

namespace GAME
{
//
// find
//
template <typename P, typename T, typename META, typename PRED>
inline
bool find (P & parent, const META & metaname, T & element, PRED predicate)
{
  contains_t <PRED> c (predicate);
  return c (parent, metaname, element);
}

//
// contains_t
//
template <typename PRED>
inline
contains_t <PRED>::contains_t (PRED predicate)
: predicate_ (predicate)
{

}

//
// contains_t::operator ()
//
template <typename PRED>
template <typename T>
inline
bool contains_t <PRED>::
operator () (const T & collection, typename T::value_type & element)
{
  return this->find_i (collection.begin (), collection.end (), element);
}

//
// contains
//
template <typename PRED>
inline
contains_t <PRED> contains (PRED predicate)
{
  return contains_t <PRED> (predicate);
}
}
