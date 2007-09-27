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
struct item_traits <Object>
{
  typedef IMgaObjects _collection_type;
};

template < >
struct item_traits <FCO>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <Atom>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <Model>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <Set>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <Reference>
{
  typedef IMgaFCOs _collection_type;
};

template < >
struct item_traits <Folder>
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

  /// Type definition for the container type.
  typedef std::vector <T> _container_type;

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
   * Get the collection of items.
   *
   * @return        The collection of items.
   */
  typename _container_type & items (void);

  /**
   * Get the collection of items.
   *
   * @return        The collection of items.
   */
  const typename _container_type & items (void) const;

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
