// $Id$

//=============================================================================
/**
 * @file      Iterator_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_ITERATOR_T_H_
#define _GAME_MGA_ITERATOR_T_H_

#include <iterator>
#include "Collection_T.h"

namespace GAME
{
namespace Mga
{

template <typename T>
struct iterator_type;

template < >
struct iterator_type <IMgaObject>
{
  typedef IMgaObjects result_type;
};

template < >
struct iterator_type <IMgaFolder>
{
  typedef IMgaFolders result_type;
};

template < >
struct iterator_type <IMgaFCO>
{
  typedef IMgaFCOs result_type;
};

template < >
struct iterator_type <IMgaAtom>
{
  typedef IMgaFCOs result_type;
};

template < >
struct iterator_type <IMgaModel>
{
  typedef IMgaFCOs result_type;
};

template < >
struct iterator_type <IMgaSet>
{
  typedef IMgaFCOs result_type;
};

template < >
struct iterator_type <IMgaConnection>
{
  typedef IMgaFCOs result_type;
};

template < >
struct iterator_type <IMgaReference>
{
  typedef IMgaFCOs result_type;
};

/**
 * @class Iterator
 *
 * Wrapper class for COM iterator that is STL-compliant. The iterator
 * implements the input iterator iterface contract.
 */
template <typename T>
class Iterator :
  public std::iterator <std::input_iterator_tag, T, int, T *, T &>
{
public:
  /// Type definition of the iterator's element type.
  typedef T type;

  /// Type definition of the iterator's element interface type.
  typedef typename T::interface_type interface_type;

  /// Type definition of the COM iterator interface.
  typedef typename iterator_type <interface_type>::result_type iterator_type;

  /// Default constructor.
  Iterator (void);

  /**
   * Initializing constructor.
   *
   * @param[in]       iter          COM iterator pointer
   */
  Iterator (iterator_type * iter);

  /**
   * Copy constructor
   *
   * @param[in]       copy          Iterator to copy
   */
  Iterator (const Iterator & copy);

  /// Destructor.
  ~Iterator (void);

  /// Test if the iterator is done.
  bool is_done (void) const;

  /// Move the iterator to the next element.
  void advance (void);

  /// Reset the iterator to the first element
  void reset (void);

  /// Number of elements in collection.
  long count (void) const;

  /// Current 1-based index of iterator.
  long index (void) const;

  /// Make an STL end iterator.
  Iterator make_end (void) const;

  /// Get the current item.
  T item (void) const;

  /// Get all the items in the collection.
  void items (std::vector <T> & out) const;

  /// Assignment/copy operator
  const Iterator & operator = (const Iterator & rhs);

  /// Dereference the current item.
  T operator * (void) const;

  /// Dereference the current item.
  T * operator -> (void) const;

  Iterator & operator ++ (void);
  Iterator operator ++ (int);

  /// Test the equality of two iterators.
  bool operator == (const Iterator & rhs) const;

  /// Test then inequality of two iterators.
  bool operator != (const Iterator & rhs) const;

private:
  /// Help constructor.
  Iterator (iterator_type * iter, long index, long count);

  /// The underlying COM pointer.
  ::ATL::CComPtr <iterator_type> iter_;

  /// Current index for the iterator.
  long index_;

  /// Number of elements in the collection.
  long count_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Iterator_T.inl"
#endif

#include "Iterator_T.cpp"

#endif  // !defined _GAME_MGA_ERRORS_H_