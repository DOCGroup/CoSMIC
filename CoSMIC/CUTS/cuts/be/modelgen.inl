// -*- C++ -*-
// $Id$

namespace Udm
{
  //
  // contains_t
  //
  template <typename PRED>
  CUTS_INLINE
  contains_t <PRED>::contains_t (PRED predicate)
  : predicate_ (predicate)
  {

  }

  //
  // contains_t::operator ()
  //
  template <typename PRED>
  template <typename T>
  CUTS_INLINE
  bool contains_t <PRED>::
  operator () (const std::set <T> & container, T & element)
  {
    return this->find_i (container.begin (), container.end (), element);
  }

  //
  // contains_t::operator ()
  //
  template <typename PRED>
  template <typename T>
  CUTS_INLINE
  bool contains_t <PRED>::
  operator () (const std::vector <T> & container, T & element)
  {
    return this->find_i (container.begin (), container.end (), element);
  }

  //
  // contains
  //
  template <typename PRED>
  CUTS_INLINE
  contains_t <PRED> contains (PRED predicate)
  {
    return contains_t <PRED> (predicate);
  }
}
