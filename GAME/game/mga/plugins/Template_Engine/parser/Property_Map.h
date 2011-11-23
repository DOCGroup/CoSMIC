// -*- C++ -*-

//=============================================================================
/**
 * @file        Property_Map.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_PROPERTY_MAP_H_
#define _CUTS_PROPERTY_MAP_H_

#include <string>
#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "game/config.h"

#include "../Template_Engine_export.h"

/**
 * @class Property_Map
 */
class GAME_TEMPLATE_ENGINE_Export Property_Map
{
public:
  /// Type definition of the internal hash map.
  typedef ACE_Hash_Map_Manager <std::string,
                                std::string,
                                ACE_Null_Mutex> map_type;

  /// Type definition of the iterator type.
  typedef map_type::iterator iterator;

  /// Type definition of the const iterator type.
  typedef map_type::const_iterator const_iterator;

  /// Default constructor
  Property_Map (void);

  /**
   * Copy consturctor.
   *
   * @param[in]     copy        Source property map.
   */
  Property_Map (const Property_Map & copy);

  /// Destructor.
  ~Property_Map (void);

  /**
   * Get the value of a key. If the key is not found, then it is
   * inserted into the map with an empty string value.
   *
   * @param[in]        key            Key of interest
   */
  std::string & operator [] (const std::string & key);

  /**
   * Get the value of a key. If the key exists in the property map, then
   * \a value will contain the value of \a key. If the key does not exist,
   * then nothing will happen.
   *
   * @param[in]         key           Key of interest
   * @param[out]        value         Value of the key
   * @retval            0             Key was found
   * @retval            -1            Key was not found.
   */
  int get (const std::string & key, std::string & value) const;

  /**
   * Set the value of a key. If the key does not exist, then it will
   * be inserted into the property map. If the key already exists, then
   * its value will be overwritten.
   *
   * @param[in]         key           Key of interest
   * @param[in]         value         New value of the key.
   * @retval            0             Successfully set the key's value
   * @retval            -1            Failed to set the key's value
   */
  int set (const std::string & key, const std::string & value);

  int set (const std::pair <std::string, std::string> & entry);

  /**
   * Get the size of the property map.
   *
   * @return            Size of the map
   */
  size_t size (void) const;

  /**
   * Determine if the property map contains the specified key.
   *
   * @retval            true          The map contains the key.
   * @retval
   */
  bool contains (const std::string & name) const;

  /**
   * Get an iterator to the beginning of the property map.
   *
   * @return            Iterator object
   */
  iterator begin (void);

  /**
   * Get an read-only iterator to the beginning of the property map.
   *
   * @return            Read-only iterator object
   */
  const_iterator begin (void) const;

  /**
   * Get an iterator to the end of the property map.
   *
   * @return            Iterator object
   */
  iterator end (void);

  /**
   * Get a read-only iterator to the end of the property map.
   *
   * @return            Read-only iterator object
   */
  const_iterator end (void) const;

  const map_type & map (void) const;

  size_t join (const Property_Map & map, bool overwrite);

  /// Clear all the item in the map.
  void clear (void);

  bool empty (void) const;

private:
  /// Internal hash map of the property list.
  map_type map_;
};

#if defined (__GAME_INLINE__)
#include "Property_Map.inl"
#endif

#endif  // !defined _CUTS_PROPERTY_MAP_H_
