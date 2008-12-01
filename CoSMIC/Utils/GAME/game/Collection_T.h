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

#if !defined (__ComponentLib_h__)
#include "Mga.h"
#endif

#include "GME_export.h"
#include "GME_fwd.h"
#include <atlcomcli.h>
#include <vector>

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
  typedef IMgaObject interface_type;
};

template < >
struct collection_traits <IMgaFCOs>
{
  typedef IMgaFCO interface_type;
};

template < >
struct collection_traits <IMgaFolders>
{
  typedef IMgaFolder interface_type;
};

template < >
struct collection_traits <IMgaAttributes>
{
  typedef IMgaAttribute interface_type;
};

template < >
struct collection_traits <IMgaConnPoints>
{
  typedef IMgaConnPoint interface_type;
};

template < >
struct collection_traits <IMgaRegNodes>
{
  typedef IMgaRegNode interface_type;
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
  typedef IMgaObjects collection_type;
};

template < >
struct item_traits <FCO>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Atom>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Model>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Set>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Reference>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Connection>
{
  typedef IMgaFCOs collection_type;
};

template < >
struct item_traits <Folder>
{
  typedef IMgaFolders collection_type;
};

template < >
struct item_traits <Attribute>
{
  typedef IMgaAttributes collection_type;
};

template < >
struct item_traits <ConnectionPoint>
{
  typedef IMgaConnPoints collection_type;
};

template < >
struct item_traits <RegistryNode>
{
  typedef IMgaRegNodes collection_type;
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
  typedef T type;

  /// Type definition for the collection type.
  typedef typename item_traits <T>::collection_type collection_type;

  /// Type definition for the container type.
  typedef std::vector <T> container_type;

  /// Type definition for the interator type.
  typedef typename container_type::iterator iterator;

  /// Type definition for the const iterator type.
  typedef typename container_type::const_iterator const_iterator;

  /// Type definition for the size type.
  typedef typename container_type::size_type size_type;

  /// Type definition for the value type.
  typedef typename container_type::value_type value_type;

  /// Default constructor.
  Collection_T (void);

  /**
   * Initializing constructor.
   *
   * @param[in]     collection      The source collection.
   */
  Collection_T (typename collection_type * collection);

  /// Destructor.
  ~Collection_T (void);

  /**
   * Attach to the specified collection.
   *
   * @param[in]     collection      The source collection.
   */
  void attach (typename collection_type * collection);

  /**
   * Get the collection of items.
   *
   * @return        The collection of items.
   */
  typename container_type & items (void);

  /**
   * Get the collection of items.
   *
   * @return        The collection of items.
   */
  const typename container_type & items (void) const;

  /**
   * Get the number of items in the collection.
   *
   * @return        Number of items in the collection.
   */
  typename size_type size (void) const;

  /**
   * Determine if the collection is empty.
   *
   * @retval        true      The collection is empty.
   * @retval        false     The collection is not empty.
   */
  bool empty (void) const;

  /**
   * Get the underlying implementation.
   *
   * @return        Pointer to the implementation.
   */
  typename collection_type * impl (void) const;

  /// Clear the collection.
  void clear (void);

  /**
   * @name iterators
   *
   * Standard Template Library (STL) iterator methods.
   */
  // @{

  typename iterator begin (void);
  typename iterator end (void);

  typename const_iterator begin (void) const;
  typename const_iterator end (void) const;
  // @}

private:
  /// Populate the collection object with the items.
  void populate (void);

  /// The underlying collection.
  ATL::CComPtr <typename collection_type> collection_;

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
