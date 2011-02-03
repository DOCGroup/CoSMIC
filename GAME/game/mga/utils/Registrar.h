// -*- C++ -*-

//=============================================================================
/**
 * @file      Registrar.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GME_MGA_UTILS_REGISTRAR_H_
#define _GME_MGA_UTILS_REGISTRAR_H_

#include <string>
#include <vector>

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "game/config.h"
#include "GAME_Utils_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Registrar
 *
 * Wrapper class for the IMgaRegistrar interface in GME.
 */
class GAME_UTILS_Export Registrar
{
public:
  enum ACCESS_MODE
  {
    ACCESS_NONE       = 0,
    ACCESS_USER       = 1,
    ACCESS_SYSTEM     = 2,
    ACCESS_BOTH       = 3,
    ACCESS_PRIORITY   = 5,
    ACCESS_TEST       = 8,
  };

  /// Default constructor
  Registrar (void);

  /**
   * Copy constructor
   *
   * @param[in]       r       Source registrar.
   */
  Registrar (const Registrar & r);

  /// Destructor
  ~Registrar (void);

  std::string icon_path (ACCESS_MODE mode) const;

  std::string get_paradigm_connstr (const std::string & name, ACCESS_MODE mode) const;

  const Registrar & operator = (const Registrar & r);

private:
  /// Pointer to the implementation.
  IMgaRegistrar * impl_;

  std::vector <std::string> paths_;
};

typedef ACE_Singleton <Registrar, ACE_RW_Thread_Mutex> GLOBAL_REGISTRAR;

GAME_UTILS_SINGLETON_DECLARE (ACE_Singleton, Registrar, ACE_RW_Thread_Mutex);

}
}

#if defined (__GAME_INLINE__)
#include "Registrar.inl"
#endif

#endif  // !defined _GME_MGA_UTILS_REGISTRAR_H_
