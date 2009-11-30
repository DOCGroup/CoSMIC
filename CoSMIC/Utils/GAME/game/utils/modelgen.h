// -*- C++ -*-

//=============================================================================
/**
 * @file      modelgen.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _PICML_UDM_UTILS_MODELGEN_H_
#define _PICML_UDM_UTILS_MODELGEN_H_

#include <iterator>

namespace GAME
{
/**
 * @class contains_t
 *
 * Functor that determines if a container contains an element that
 * matches the specified predicate.
 */
template <typename PRED>
class contains_t
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]        predicate          The target predicate.
   */
  contains_t (PRED predicate);

  /**
   * Determine if a parent contains an element that matches the
   * specified predicate. This version of the functor will choose
   * the defualt container type, which is a std::vector.
   *
   * @param[in]         parent            The parent of interest.
   * @param[in]         metaname          Metaname of the \a element.
   * @param[out]        element           The child element.
   */
  template <typename P, typename T>
  bool operator () (P parent,
                    const std::string & metaname,
                    T & element);

  /**
   * @overloaded
   */
  template <typename T>
  bool operator () (const GME::Collection_T <T> & parent,
                    T & element);

private:
  /**
   * Helper method that will locate an element in a container.
   *
   * @param[in]       iter_begin        First location to look.
   * @param[in]       iter_end          Last location to look.
   * @param[out]      element           Contains to found element.
   */
  template <typename T>
  bool find_i (T iter_begin, T iter_end,
               typename std::iterator_traits <T>::value_type & element);

  /// The predicate of interest.
  PRED predicate_;
};

/**
 * Factory function that generates the contains_t objects.
 *
 * @param[in]     predicate          The predicate for comparison.
 * @return        The contain_t functor.
 */
template <typename PRED>
contains_t <PRED> contains (PRED predicate);

template <typename P, typename T, typename PRED>
bool find (P & parent, const std::string & metaname, T & element, PRED predicate);

/**
 * Create an element if a child that satifies the specified predicate can
 * not be found in the current child set. This version of the creation
 * method selects all the children of type T in the \a parent.
 *
 * @param[in]       parent      The parent of the child element.
 * @param[out]      element     Target storage for child element.
 * @param[in]       predicate    Predicate to search for.
 */
template <typename P, typename T, typename PRED>
bool create_if (P & parent, const std::string & metaname, T & element, PRED predicate);

/**
 * Create an element if a child that satifies the specified predicate can
 * not be found in the \a container. This version of the creation
 * method selects all the children of type T in the \a parent.
 *
 * @param[in]       parent        The parent of the child element.
 * @param[out]      element       Target storage for child element.
 * @param[in]       predicate     Predicate to search for.
 */
template <typename P, typename C, typename T, typename PRED>
bool create_if (P & parent,
                const std::string & metaname,
                const GME::Collection_T <T> & collection,
                T & element,
                PRED predicate);

template <typename P, typename T, typename PRED>
bool create_if_not (P parent,
                    const std::string & metaname,
                    T & element,
                    PRED predicate);

template <typename P, typename T, typename PRED>
bool create_if_not (P & parent,
                    const std::string & metaname,
                    const GME::Collection_T <T> & collection,
                    T & element,
                    PRED predicate);

/**
 * Create an subtype if a child that satifies the specified predicate can
 * not be found in the current child set. This version of the creation
 * method selects all the children of type T in the \a parent.
 *
 * @param[in]       parent      The parent of the child element.
 * @param[out]      element     Target storage for child element.
 * @param[in]       predicate    Predicate to search for.
 */
template <typename P, typename T, typename PRED>
bool create_subtype_if (P & parent, T & element, T & subtype, PRED predicate);

template <typename P, typename T, typename PRED>
bool create_subtype_if_not (P & parent, T & element, T & subtype, PRED predicate);

/**
 *
 */
template <typename P, typename T, typename PRED>
bool create_instance_if (P & parent, T & element, T & instance, PRED predicate);

template <typename P, typename T, typename PRED>
bool create_instance_if_not (P & parent, T & element, T & instance, PRED predicate);
}

#include "modelgen.inl"
#include "modelgen.cpp"

#endif  // !defined _PICML_UDM_UTILS_MODELGEN_H_