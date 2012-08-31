// -*- C++ -*-

//=============================================================================
/**
 * @file        Windows_Registry.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_WINDOWS_REGISTRY_H_
#define _CUTS_WINDOWS_REGISTRY_H_

#include "ace/Auto_Ptr.h"
#include "game/config.h"

#include <map>
#include <string>

#include "game/mga/GME_fwd.h"
#include "GAME_Utils_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Windows_Registry
 *
 * Utility class for interacting with the Windows registry.
 */
class GAME_UTILS_Export Windows_Registry
{
public:
  static void get_registered_interpreters (const Project & proj, std::map <std::string, std::string> & list);
};

// Forward decl.
class Windows_Registry_Value_Iterator;

/**
 * @class Windows_Registry_Key
 */
class GAME_UTILS_Export Windows_Registry_Key
{
public:
  // Friend class decl.
  friend class Windows_Registry_Key_Iterator;

  // Friend class decl.
  friend class Windows_Registry_Value_Iterator;

  /// Type definition of the iterator type.
  typedef Windows_Registry_Value_Iterator ITERATOR;

  /// Default constructor.
  Windows_Registry_Key (void);

  /**
   * Create a registry key, and open it.
   *
   * @param[in]         key           Top-level registry key
   * @param[in]         subkey        Subkey in top-level key
   */
  Windows_Registry_Key (HKEY key, const char * subkey);

  /// Destructor.
  ~Windows_Registry_Key (void);

  /**
   * Open the registry key.
   *
   * @param[in]         key           Top-level registry key
   * @param[in]         subkey        Subkey in top-level key
   */
  int open (HKEY key, const char * subkey);

  /**
   * Open a registry key.
   *
   * @param[in]         key           Already open registry key
   * @param[in]         subkey        Subkey in open key
   */
  int open (const Windows_Registry_Key & key, const char * subkey);

  /// Test if the registry key is valid.
  bool is_valid (void) const;

  /// Close the registry key.
  void close (void);

  /**
   * Get a value in the registry key.
   *
   * @param[in]         name            Name of value to read
   * @param[out]        buffer          Pointer to buffer that receives value
   * @param[in]         bufsize         Size of buffer
   */
  int get_value (const char * name, char * buffer = 0, unsigned long bufsize = 0);

  /**
   * @overload
   *
   * @param[in]         name            Name of value to read
   * @param[out]        value           Read value
   */
  int get_value (const char * name, long & value);

private:
  /// Implementation of the close method.
  void close_i (void);

  /// Registry key.
  HKEY key_;

  /// Close the handle on destruction.
  bool requires_close_;

  Windows_Registry_Key (const Windows_Registry_Key &);
  const Windows_Registry_Key & operator = (const Windows_Registry_Key &);
};

/**
 * @class Windows_Registry_Key_Iterator
 *
 * Class that iterates over all the keys in a Windows registry. It
 * is assumed that the register has been open to the desired folder
 * and is ready for iteration.
 */
class GAME_UTILS_Export Windows_Registry_Key_Iterator
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]         key         Parent registry key
   */
  Windows_Registry_Key_Iterator (const Windows_Registry_Key & key);

  /// Destructor.
  ~Windows_Registry_Key_Iterator (void);

  /// Get the name of the current key.
  const char * name (void) const;

  void advance (void);

  bool done (void) const;

private:
  /// Reference to the registry key.
  const Windows_Registry_Key & key_;

  /// Current index of the iterator.
  unsigned long index_;

  /// Current state of the iterator.
  unsigned long count_;

  /// Size of the buffer.
  unsigned long bufsize_;

  /// Storage location for the name
  ACE_Auto_Array_Ptr <char> buffer_;
};

/**
 * @class CUTS_Windows_Registry_Value_Iterator
 *
 * Class that iterates over all the values for a Windows registry
 * key. It is assumed the Windows registry key is already open.
 */
class GAME_UTILS_Export Windows_Registry_Value_Iterator
{
public:
  /**
   * Initializing constructor. The \a key must already be open.
   *
   * @param[in]         reg         Target registry key.
   */
  Windows_Registry_Value_Iterator (const Windows_Registry_Key & key,
                                   u_char * buffer,
                                   u_long bufsize);

  /// Destructor.
  ~Windows_Registry_Value_Iterator (void);

  int advance (void);

  int advance (u_char * buffer, u_long & bufsize);

  bool done (void);

private:
  const Windows_Registry_Key & key_;

  bool is_done_;

  size_t index_;

  /// @todo We should update this so that it has a buffer that grows
  ///       on demand with the value.
  char data_[16383];

  u_long value_type_;

  u_char * buffer_;

  const u_long bufsize_;

  u_long datasize_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Windows_Registry.inl"
#endif

#endif  // !defined _CUTS_WINDOWS_REGISTRY_H_
