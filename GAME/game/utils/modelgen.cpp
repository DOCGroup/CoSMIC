// $Id$

#include <algorithm>
#include <vector>

namespace GAME
{
//
// contains_t::operator ()
//
template <typename PRED>
template <typename P, typename T, typename META>
bool contains_t <PRED>::
operator () (P parent, const META & metaname, T & element)
{
  // Get the children of the parent.
  std::vector <T> children;

  if (0 != parent->children (metaname, children))
    return this->find_i (children.begin (), children.end (), element);

  return false;
}

//
// find_i
//
template <typename PRED>
template <typename T>
bool contains_t <PRED>::
find_i (T iter_begin,
        T iter_end,
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
template <typename P, typename T, typename META, typename PRED>
bool create_if (P parent, const META & metaname, T & element, PRED predicate)
{
  // Determine if the parent has an element that matches the specified
  // predicate. If it does contain such an element then we need to
  // create one for the caller.
  if (!predicate (parent, metaname, element))
    return false;

  element = T::_create (parent, metaname);
  return true;
}

//
// create_if
//
template <typename P, typename T, typename PRED>
bool create_if (P parent,
                const std::string & metaname,
                const T & collection,
                typename T::value_type & element,
                PRED predicate)
{
  // Determine if the parent has an element that matches the specified
  // predicate. If it does not contain such an element then we need to
  // create one for the caller.
  if (!predicate (collection, element))
    return false;

  element = T::_create (parent, metaname);
  return true;
}

//
// create_if_not
//
template <typename P, typename T, typename META, typename PRED>
bool create_if_not (P parent,
                    const META & metaname,
                    T & element,
                    PRED predicate)
{
  // Determine if the parent has an element that matches the specified
  // predicate. If it does not contain such an element then we need to
  // create one for the caller.
  if (predicate (parent, metaname, element))
    return false;

  typedef typename T::impl_type impl_type;
  element = impl_type::_create (parent, metaname);
  return true;
}

//
// create_if_not
//
template <typename P, typename T, typename META, typename PRED>
bool create_if_not (P parent,
                    const META & metaname,
                    const T & collection,
                    typename T::value_type & element,
                    PRED predicate)
{
  // Determine if the parent has an element that matches the specified
  // predicate. If it does not contain such an element then we need to
  // create one for the caller.
  if (predicate (collection, element))
    return false;

  element = T::value_type::_create (parent, metaname);
  return true;
}

//
// create_subtype_if
//
template <typename P, typename T, typename PRED>
bool create_subtype_if (P parent,
                        T & element,
                        T & subtype,
                        PRED predicate)
{
  // Determine if the parent has an element that matches the specified
  // predicate. If it does contain such an element then we need to
  // create one for the caller.
  if (!predicate (parent, element.meta ().name (), subtype))
    return false;

  subtype = element.create_subtype (parent);
  return true;
}

//
// create_subtype_if_not
//
template <typename P, typename T, typename PRED>
bool create_subtype_if_not (P parent, T & element, T & subtype, PRED predicate)
{
  // Determine if the parent has an element that matches the specified
  // predicate. If it does contain such an element then we need to
  // create one for the caller.
  if (predicate (parent, element.meta ().name (), subtype))
    return false;

  subtype = element.create_subtype (parent);
  return true;
}

//
// create_instance_if
//
template <typename P, typename T, typename PRED>
bool create_instance_if (P parent, T & element,
                         T & instance, PRED predicate)
{
  // Determine if the parent has an element that matches the specified
  // predicate. If it does contain such an element then we need to
  // create one for the caller.
  if (!predicate (parent, element.meta ().name (), instance))
    return false;

  instance = element.create_instance (parent);
  return true;
}

//
// create_instance_if_not
//
template <typename P, typename T, typename PRED>
bool create_instance_if_not (P parent, T & element,
                             T & instance, PRED predicate)
{
  // Determine if the parent has an element that matches the specified
  // predicate. If it does contain such an element then we need to
  // create one for the caller.
  if (predicate (parent, element.meta ().name (), instance))
    return false;

  instance = element.create_instance (parent);
  return true;
}
}
