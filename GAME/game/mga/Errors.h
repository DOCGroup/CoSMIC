// $Id$

//=============================================================================
/**
 * @file      Errors.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_ERRORS_H_
#define _GAME_MGA_ERRORS_H_

#include <string>

#include "ace/Hash_Map_Manager_T.h"
#include "ace/Null_Mutex.h"
#include "ace/Singleton.h"

#include "game/config.h"

#include "Mga_export.h"

namespace GAME
{
namespace Mga
{
/**
 * @class Errors
 *
 * Wrapper class for converting error codes to error messages.
 */
class GAME_MGA_Export Errors
{
public:
  /// Default constructor.
  Errors (void);

  /// Destructor.
  ~Errors (void);

  /**
   * Lookup an error message given an error code.
   *
   * @param[in]       error_code          Source error code
   * @return          Error message
   */
  void lookup (size_t error_code, std::string & msg) const;

private:
  /// Initialize the hash map.
  void init (void);

  /// Mapping of error codes to error strings.
  ACE_Hash_Map_Manager < size_t, std::string, ACE_Null_Mutex > errors_;
};

/// Type definition of the Errors singleton.
typedef ACE_Singleton <Errors, ACE_Null_Mutex> ERRORS;

GAME_MGA_SINGLETON_DECLARE (ACE_Singleton, Errors, ACE_Null_Mutex);

}
}

#if defined (__GAME_INLINE__)
#include "Errors.inl"
#endif

#endif  // !defined _GAME_MGA_ERRORS_H_
