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
#include "game/config.h"
#include <string>
#include "GAME_Utils_export.h"

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

  std::string icon_path (int mode);

private:
  /// Pointer to the implementation.
  ATL::CComPtr <IMgaRegistrar> impl_;
};

}
}

#if defined (__GAME_INLINE__)
#include "Registrar.inl"
#endif

#endif  // !defined _GME_UTILS_REGISTRAR_H_
