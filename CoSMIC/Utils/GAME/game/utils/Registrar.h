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

#ifndef _GME_UTILS_REGISTRAR_H_
#define _GME_UTILS_REGISTRAR_H_

#include <atlcomcli.h>
#include <string>
#include "GAME_Utils_export.h"
#include "game/config.h"

// Forward decl.
struct IMgaRegistrar;

namespace GAME
{
namespace utils
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

  std::string icon_path (ACCESS_MODE mode);

  std::string get_paradigm_connstr (const std::string & name, ACCESS_MODE mode);

private:
  /// Pointer to the implementation.
  IMgaRegistrar * impl_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Registrar.inl"
#endif

#endif  // !defined _GME_UTILS_REGISTRAR_H_
