// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_algorithm.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_ALGORITHM_H_
#define _CUTS_BE_ALGORITHM_H_

#include "BE_nil.h"
#include <algorithm>

namespace CUTS_BE
{
  //=============================================================================
  /**
   * @struct if_then_else
   *
   * Metaprogrammable template for execute if...then...else statements. This
   * template really has no implementation, and only exist because of the
   * specializations.
   */
  //=============================================================================

  template <bool CONDITION, typename TRUE_STMT, typename FALSE_STMT>
  struct if_then_else
  {

  };

  //=============================================================================
  /**
   * @struct if_then_else
   *
   * Metaprogrammable template for execute if...then...else statements. This
   * is a specialization of the generalized template for when the CONDITION
   * parameter is \a true.
   */
  //=============================================================================

  template <typename TRUE_STMT, typename FALSE_STMT>
  struct if_then_else <true, TRUE_STMT, FALSE_STMT>
  {
    /// The result type for this specialization.
    typedef TRUE_STMT result_type;
  };

  //=============================================================================
  /**
   * @struct if_then_else
   *
   * Metaprogrammable template for execute if...then...else statements. This
   * is a specialization of the generalized template for when the CONDITION
   * parameter is \a false.
   */
  //=============================================================================

  template <typename TRUE_STMT, typename FALSE_STMT>
  struct if_then_else <false, TRUE_STMT, FALSE_STMT>
  {
    /// The result type for this specialization.
    typedef FALSE_STMT result_type;
  };

  //=============================================================================
  /**
   * @struct if_then_else
   *
   * Metaprogrammable template for execute if...then statements. This
   * trait utilizes the if_then_else trait for compile-time evaluation.
   */
  //=============================================================================

  template <bool CONDITION, typename TRUE_STMT>
  struct if_then
  {
    /// Result type for this metaprogrammable template.
    typedef typename if_then_else <CONDITION,
                                   TRUE_STMT,
                                   CUTS_BE::NIL>::result_type result_type;
  };

  //=============================================================================
  /**
   * @struct visit_type
   *
   * Trait that determines if a strategy will (or will not) visit an
   * object. The default behavior is to visit all the elements handled
   * by the interpretation-logic. To alter this behavior, this class
   * must be specialized by the \a STRATEGY for each \a TYPE it does
   * not want to visit.
   */
  //=============================================================================

  template <typename STRATEGY, typename TYPE>
  struct visit_type
  {
    /// The result type for the visitation.
    static const bool result_type = true;
  };

  template <typename T>
  struct is_container
  {
    static const bool result_type = false;
  };

  template <typename T, typename A>
  struct is_container <std::vector <T, A> >
  {
    static const bool result_type = true;
  };

  template <typename K, typename T, typename A>
  struct is_container <std::set <K, T, A> >
  {
    static const bool result_type = true;
  };

  template <typename T, bool is_a_container>
  struct get_type { };

  template <typename T>
  struct get_type <T, false>
  {
    typedef T result_type;
  };

  template <typename T>
  struct get_type <T, true>
  {
    typedef typename T::value_type result_type;
  };

/// Helper macro for defining the trait to ingore a single type
/// when parsing the model.
#define CUTS_BE_NOT_VISIT(strategy, type) \
  template < > \
  struct visit_type <strategy, type> \
  { \
    static const bool result_type = false; \
  }

/// Helper macro for defining the trait to ingore all types
/// when parsing the model.
#define CUTS_BE_NOT_VISIT_ALL(strategy) \
  template <typename TYPE> \
  struct visit_type <strategy, TYPE> \
  { \
    static const bool result_type = false; \
  }

  //=============================================================================
  /**
   * @struct visit_all_t
   *
   * Implementation of the std::for_each method. This functor conforms it
   * to the function signature expected by the metaprogrammable templates.
   */
  //=============================================================================

  template <typename STRATEGY, typename CONTAINER, typename FUNCTOR>
  struct visit_all_t
  {
    static inline bool execute (CONTAINER container, FUNCTOR func)
    {
      std::for_each (container.begin (), container.end (), func);
      return true;
    }
  };

  //=============================================================================
  /**
   * @struct visit_single_t
   */
  //=============================================================================

  template <typename STRATEGY, typename TYPE, typename FUNCTOR>
  struct visit_single_t
  {
    static inline bool execute (TYPE type, FUNCTOR func)
    {
      func (type);
      return true;
    }
  };

  //=============================================================================
  /**
   * @struct visit_t
   *
   * Trait class that determines the default iteration method. The
   * default method is to iterate over all the element in the container
   * using the iterate_all_t functor.
   */
  //=============================================================================

  template <typename STRATEGY, typename CONTAINER, typename FUNCTOR>
  struct visit_t
  {
    typedef typename
      if_then_else <is_container <CONTAINER>::result_type,
      visit_all_t <STRATEGY, CONTAINER, FUNCTOR>,
      visit_single_t <STRATEGY, CONTAINER, FUNCTOR> >::result_type
      result_type;
  };

  //=============================================================================
  /**
   * @function iterate
   *
   * Factory function that generates the correct iteration method. The
   * iteration method is defined by the trait iterate_t. This factory
   * also uses the visit_type trait class to determine if the elements
   * in \a container are visitable.
   */
  //=============================================================================

  template <typename STRATEGY, typename TYPE, typename FUNCTOR>
  inline bool visit (TYPE type, FUNCTOR func)
  {
    typedef typename CUTS_BE::if_then <
      CUTS_BE::visit_type <STRATEGY,
        get_type <TYPE, is_container <TYPE>::result_type>::
        result_type>::result_type,
      CUTS_BE::visit_t <STRATEGY, TYPE, FUNCTOR>::result_type>::
      result_type result_type;

    return result_type::execute (type, func);
  }
}

#endif  // !defined _CUTS_BE_ALGORITHM_H_
