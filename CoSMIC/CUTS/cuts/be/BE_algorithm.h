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

template <true, typename TRUE_STMT, typename FALSE_STMT>
struct if_then_else
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

template <false, typename TRUE_STMT, typename FALSE_STMT>
struct if_then_else
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
  static bool result_type = true;
};

//=============================================================================
/**
 * @struct iterate_all
 *
 * Implementation of the std::for_each method. This functor conforms it
 * to the function signature expected by the metaprogrammable templates.
 */
//=============================================================================

template <typename COLLECTION, typename FUNCTOR>
struct iterate_all
{
  /**
   * Execute the functor's logic.
   *
   * @param[in]     coll        The target collection.
   * @param[in]     func        The functor.
   */
  static inline void execute (COLLECTION & coll, FUNCTOR func)
  {
    std::for_each (coll.begin (), coll.end (), func);
  }
};

//=============================================================================
/**
 * @struct generate_if
 *
 * Metaprogrammable template that determines if a \a STRATEGY_GENERATOR
 * should be invoked. If the \a STRATEGY_GENERATOR is not NIL,
 * then it will be invoked. Otherwise, it will be ignored (or suppressed).
 */
//=============================================================================

template <typename STRATEGY_GENERATOR>
struct generate_if
{
  /// Result type for this metaprogrammable template.
  typedef typename
    CUTS_BE::if_then <CUTS_BE::not_is_nil <STRATEGY_GENERATOR>,
                      STRATEGY_GENERATOR>::result_type result_type;
};

}
#endif  // !defined _CUTS_BE_ALGORITHM_H_
