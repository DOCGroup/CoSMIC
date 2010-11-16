// -*- C++ -*-

//=============================================================================
/**
 * @file      Auto_Model_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_AUTO_MODEL_T_H_
#define _GAME_XME_AUTO_MODEL_T_H_

#include <set>
#include "FCO.h"

namespace GAME
{
namespace XME
{
/**
 * @class Auto_Model_T
 *
 * Implementation of the Auto_Model pattern. The value of the
 * template parameter can be either a XME::Model or XME::Folder.
 */
template <typename T>
class Auto_Model_T
{
public:
  /// Type definition of the model type.
  typedef T type;

  /// Collection of the current children.
  typedef std::vector <FCO> collection_type;

  typedef typename collection_type::iterator iterator;
  typedef typename collection_type::const_iterator const_iterator;

  /// Default constructor.
  Auto_Model_T (void);

  /**
   * Initializing constructor
   *
   * @param[in]     obj       The source object.
   */
  Auto_Model_T (T model);

  /**
   * Initializing constructor. This defines the purge set for the
   * auto model to be concerned with.
   *
   */
  Auto_Model_T (T model, const collection_type & purge_set);

  /**
   * Initializing constructor. This defines the purge set for the
   * auto model to be concerned with.
   *
   */
  Auto_Model_T (T model, iterator begin, iterator end);

  /// Destructor.
  ~Auto_Model_T (void);

  /**
   * Assignment operator. This object will take ownership of the
   * contained modeling element.
   *
   * @param[in]     obj       The right side of the operator
   */

  /**
   * Release ownership of the contained model element.
   *
   * @return        The contained element.
   */
  T release (void);

  /**
   * Get a reference to the contained model.
   *
   * @return        The model
   */
  T & get (void);

  /**
   * Access the contained model as it was a pointer. This will
   * all the client to invoke methods on the contained model.
   */
  T * operator -> (void);

  /**
   * Reset the value of this model element. This object will
   * take ownership of the supplied \a model.
   *
   * @param[in]     model       The new model element.
   */
  void attach (T & model);

  collection_type & children (void);
  const collection_type & children (void) const;

  template <typename T1, typename META>
  bool create (const META & metaname, T1 & element);

  template <typename T1, typename META, typename PRED>
  bool create_if (const META & metaname,
                  T1 collection,
                  typename T1::value_type & element,
                  PRED predicate);

  template <typename T1, typename META, typename PRED>
  bool create_if_not (const META & metaname,
                      T1 & element,
                      PRED predicate);

  template <typename T1, typename META, typename PRED>
  bool create_if_not (const META & metaname,
                      const T1 & collection,
                      typename T1::value_type & element,
                      PRED predicate);

private:
  void purge_models (void);

  /// The actual model element.
  T model_;

  collection_type purge_set_;

  collection_type children_;

  Auto_Model_T (const Auto_Model_T & model);
  const Auto_Model_T & operator = (const Auto_Model_T &);
};

}
}

#if defined (__GAME_INLINE__)
#include "Auto_Model_T.inl"
#endif

#include "Auto_Model_T.cpp"

#endif  // !defined _GAME_XME_ATOM_H_
