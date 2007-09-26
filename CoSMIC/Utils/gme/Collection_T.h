// -*- C++ -*-

//=============================================================================
/**
 * @file        Collection_T.h
 *
 * Defines the collection container
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GME_COLLECTION_T_H_
#define _GME_COLLECTION_T_H_

#include <vector>

#if !defined (__ComponentLib_h__)
#include "Mga.h"
#endif

namespace GME
{
//=============================================================================
/**
 * @struct collection_traits
 *
 * Trait class that determines the GME item type of a collection.
 */
//=============================================================================

template <typename T>
struct collection_traits
{

};

template < >
struct collection_traits <IMgaObjects>
{
  typedef IMgaObject _item_type;
};

template < >
struct collection_traits <IMgaFCOs>
{
  typedef IMgaFCO _item_type;
};

template < >
struct collection_traits <IMgaFolders>
{
  typedef IMgaFolder _item_type;
};

//=============================================================================
/**
 * @struct item_traits
 *
 * Trait class that determines the GME collection type of an object.
 */
//=============================================================================

template <typename T>
struct item_traits
{

};

template < >
struct item_traits <GME::Object>
{
  typedef IMgaObjects _collection_type;
};

template < >
struct item_traits <GME::FCO>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <GME::Atom>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <GME::Model>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <GME::Set>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <GME::Reference>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <GME::Folder>
{
  typedef IMgaFolders _collection_type;
};

//=============================================================================
/**
 * @class Collection_T
 *
 * Default container class for managing GME collections.
 */
//=============================================================================

template <typename T>
class Collection_T
{
public:
  /// Type definition for the item type.
  typedef T _item_type;

  /// Type definition for the collection type.
  typedef typename item_traits <T>::_collection_type _collection_type;

  /// Default constructor.
  Collection_T (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     collection      The source collection.
   */
  Collection_T (typename _collection_type * collection);

  /// Destructor.
  ~Collection_T (void);

  /**
   * Attach to the specified collection.
   *
   * @param[in]     collection      The source collection.
   */
  void attach (typename _collection_type * collection);

  /**
   * Get the item at the specified index.
   *
   * @param[in]     i               The target index.
   * @return        The target item.
   */
  T & operator [] (size_t i);

  /**
   * Get the item at the specified index.
   *
   * @param[in]     i               The target index.
   * @return        The target item.
   */
  const T & operator [] (size_t i) const;

  /**
   * Get the size of the collection.
   *
   * @return        Number of elements in the collection.
   */
  size_t size (void) const;

  /**
   * Get the underlying implementation.
   *
   * @return        Pointer to the implementation.
   */
  typename _collection_type * impl (void) const;

private:
  /// Populate the collection object with the items.
  void populate (void);

  /// The underlying collection.
  CComPtr <typename _collection_type> collection_;

  /// The collection of items.
  std::vector <T> items_;

  // prevent the following operations
  Collection_T (const Collection_T &);
  const Collection_T & operator = (const Collection_T &);
};

}

#if defined (__GME_INLINE__)
#include "Collection_T.inl"
#endif

#include "Collection_T.cpp"

#endif  // !defined _GME_COLLECTION_T_H_
