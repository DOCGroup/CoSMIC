// $Id$

#if !defined (__CUTS_INLINE__)
#include "modelgen.inl"
#endif

#include "BE_algorithm.h"
#include <algorithm>
#include <vector>
#include <iterator>
#include "UdmBase.h"

namespace Udm
{
  //
  // contains_t::operator ()
  //
  template <typename PRED>
  template <typename P, typename T>
  bool contains_t <PRED>::operator () (const P & parent, T & element)
  {
    // Get the children of the parent.
    typedef std::vector <T> T_set;
    T_set children = Udm::ChildrenAttr <T> (parent.__impl (), Udm::NULLCHILDROLE);

    return (*this) (children, element);
  }

  //
  // find_i
  //
  template <typename PRED>
  template <typename T>
  bool contains_t <PRED>::
  find_i (T iter_begin, T iter_end,
          typename std::iterator_traits <T>::value_type & element)
  {
    T iter = std::find_if (iter_begin, iter_end, this->predicate_);

    if (iter == iter_end)
      return false;

    element = *iter;
    return true;
  }

  //
  // create_if
  //
  template <typename P, typename T, typename PRED>
  bool create_if (P & parent, T & element, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does contain such an element then we need to
    // create one for the caller.
    if (!predicate (parent, element))
      return false;

    element = T::Create (parent);
    return true;
  }

  //
  // create_if
  //
  template <typename P, typename C, typename T, typename PRED>
  bool create_if (P & parent, const C & container, T & element, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does not contain such an element then we need to
    // create one for the caller.
    if (!predicate (container, element))
      return false;

    element = T::Create (parent);
    return true;
  }

  //
  // create_if_not
  //
  template <typename P, typename T, typename PRED>
  bool create_if_not (P & parent, T & element, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does not contain such an element then we need to
    // create one for the caller.
    if (predicate (parent, element))
      return false;

    element = T::Create (parent);
    return true;
  }

  //
  // create_if_not
  //
  template <typename P, typename C, typename T, typename PRED>
  bool create_if_not (P & parent, const C & container, T & element, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does not contain such an element then we need to
    // create one for the caller.
    if (predicate (container, element))
      return false;

    element = T::Create (parent);
    return true;
  }

  //
  // create_subtype_if
  //
  template <typename P, typename T, typename PRED>
  bool create_subtype_if (P & parent, T & element, T & subtype, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does contain such an element then we need to
    // create one for the caller.
    if (!predicate (parent, subtype))
      return false;

    subtype = element.CreateDerived (parent);
    return true;
  }

  //
  // create_subtype_if
  //
  template <typename P, typename C, typename T, typename PRED>
  bool create_subtype_if (P & parent, const C & container,
                          T & element, T & subtype, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does not contain such an element then we need to
    // create one for the caller.
    if (!predicate (container, subtype))
      return false;

    subtype = element.CreateDerived (parent);
    return true;
  }

  //
  // create_subtype_if_not
  //
  template <typename P, typename T, typename PRED>
  bool create_subtype_if_not (P & parent, T & element, T & subtype, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does contain such an element then we need to
    // create one for the caller.
    if (predicate (parent, subtype))
      return false;

    subtype = element.CreateDerived (parent);
    return true;
  }

  //
  // create_subtype_if_not
  //
  template <typename P, typename C, typename T, typename PRED>
  bool create_subtype_if_not (P & parent, const C & container,
                              T & element, T & subtype, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does not contain such an element then we need to
    // create one for the caller.
    if (predicate (container, subtype))
      return false;

    subtype = element.CreateDerived (parent);
    return true;
  }

  //
  // create_instance_if
  //
  template <typename P, typename T, typename PRED>
  bool create_instance_if (P & parent, T & element,
                           T & instance, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does contain such an element then we need to
    // create one for the caller.
    if (!predicate (parent, instance))
      return false;

    instance = element.CreateInstance (parent);
    return true;
  }

  //
  // create_instance_if
  //
  template <typename P, typename C, typename T, typename PRED>
  bool create_instance_if (P & parent, const C & container,
                           T & element, T & instance, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does not contain such an element then we need to
    // create one for the caller.
    if (!predicate (container, instance))
      return false;

    instance = element.CreateInstance (parent);
    return true;
  }

  //
  // create_instance_if_not
  //
  template <typename P, typename T, typename PRED>
  bool create_instance_if_not (P & parent, T & element,
                               T & instance, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does contain such an element then we need to
    // create one for the caller.
    if (predicate (parent, instance))
      return false;

    instance = element.CreateInstance (parent);
    return true;
  }

  //
  // create_instance_if_not
  //
  template <typename P, typename C, typename T, typename PRED>
  bool create_instance_if_not (P & parent, const C & container,
                               T & element, T & instance, PRED predicate)
  {
    // Determine if the parent has an element that matches the specified
    // predicate. If it does not contain such an element then we need to
    // create one for the caller.
    if (predicate (container, instance))
      return false;

    instance = element.CreateInstance (parent);
    return true;
  }
}
