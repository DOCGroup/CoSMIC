// -*- C++ -*-

//=============================================================================
/**
 * @file      Collection.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_XME_COLLECTION_H_
#define _GME_XME_COLLECTION_H_

#include "xercesc/dom/DOM.hpp"
#include "XME_export.h"

namespace GME
{
namespace XME
{
// Forward decl.
template <typename T> class Collection_Iterator;

// Forard decl.
template <typename T> class Collection_Const_Iterator;

/**
 * @class Collection
 *
 * Generic class for a collection of elements in the model. This
 * class is used by Model, Folder, and Set. The type for the class
 * is the type of the child elements in the collection.
 */
template <typename T>
class Collection
{
public:
  /// Type definition of the type.
  typedef T type;

  /// Type definition of the type.
  typedef T value_type;

  /// Default constructor.
  Collection (void);

  /**
   * Initialize collection with specified list.
   *
   * @param[in]     list        Source list
   */
  Collection (xercesc::DOMNodeList * list);

  /**
   * Copy constructor.
   *
   * @param[in]     coll        Source collection
   */
  Collection (const Collection & coll);

  /// Destructor.
  ~Collection (void);

  /**
   * Assignment operator
   *
   * @param[in]     rhs         Right side of operator.
   */
  const Collection & operator = (const Collection & rhs);

  /**
   * Attach to the specific list.
   *
   * @param[in]     list        Pointer to the new list.
   */
  void attach (xercesc::DOMNodeList * list);

  /// Release the contain node list.
  xercesc::DOMNodeList * release (void);

  /**
   * Get the size of the collection
   *
   * @return        Number of element in collection.
   */
  size_t size (void) const;

  /**
   * Get the element at the specified index. Because elements in the
   * collection are governed by the parent, it is not possible to use
   * the index operator to assign a value to individual elements and
   * have it reflected in the parent model.
   *
   */
  T operator [] (size_t n) const;

private:
  /// Pointer to the collection of elements.
  xercesc::DOMNodeList * list_;
};

}
}

#if defined (__GME_INLINE__)
#include "Collection.inl"
#endif

#include "Collection.cpp"

#endif  // !defined _GME_XME_COLLECTION_H_
