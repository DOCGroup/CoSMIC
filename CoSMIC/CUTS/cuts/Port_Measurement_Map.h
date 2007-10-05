// -*- C++ -*-

//=============================================================================
/**
 * @file      Port_Measurement_Map.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_PORT_MEASUREMENT_MAP_H_
#define _CUTS_PORT_MEASUREMENT_MAP_H_

#include "cuts/Port_Measurement.h"
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"

//=============================================================================
/**
 * @class CUTS_Port_Measurement_Map
 *
 * Container that simplifies storing CUTS_Port_Measurement_Map
 * based on an unique id.
 */
//=============================================================================

class CUTS_Export CUTS_Port_Measurement_Map
{
public:
  /// Type definition for the hash map container.
  typedef ACE_Hash_Map_Manager <size_t,
                                CUTS_Port_Measurement *,
                                ACE_Null_Mutex> hash_map_t;

  /// Type definition for the iterator.
  typedef hash_map_t::ITERATOR ITERATOR;

  /// Type definition for the const iterator.
  typedef hash_map_t::CONST_ITERATOR CONST_ITERATOR;

  /// Default constructor.
  CUTS_Port_Measurement_Map (void);

  /// Destructor.
  ~CUTS_Port_Measurement_Map (void);

  /**
   * Get the port measurement for \a id. If the port measurement does
   * not exist, then a new one is created and stored in the map. If
   * the return value is 0, then something is seriously wrong.
   *
   * @param[in]         id          The id of the port measurement.
   * @return            Pointer to the port measurement.
   */
  int find (size_t id,
            CUTS_Port_Measurement * & measure,
            bool auto_create = true);

  /**
   * Get the size of the mapping.
   *
   * @return      The number of elements in the map.
   */
  size_t size (void) const;

  /// Empty the contents of the map.
  void empty (void);

  /**
   * Get a reference to the underlying map.
   *
   * @return      Reference to the underlying map.
   */
  const hash_map_t & hash_map (void) const;

  /// Reset the mapping.
  void reset (void);

  int register_endpoint (size_t endpoint);

private:
  /// The hash map that holds the elements.
  hash_map_t hash_map_;

  /// The template port measurment.
  CUTS_Port_Measurement template_;
};

#if defined (__CUTS_INLINE__)
#include "cuts/Port_Measurement_Map.inl"
#endif

#endif
