// -*- C++ -*-

//=============================================================================
/**
 * @file        Console_Service.h
 *
 * Defines the Connection_Impl object.
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_MGA_CONSOLE_SERVICE_H_
#define _GAME_MGA_CONSOLE_SERVICE_H_

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include "game/mga/Project.h"

#include "Singleton_Adapter_T.h"
#include "Component_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Console_Service
 *
 * Wrapper class for using the Console in the GME application.
 */
class GAME_MGA_COMPONENT_Export Console_Service
{
public:
  /// Default constructor.
  Console_Service (void);

  /// Destructor.
  ~Console_Service (void);

  /**
   * Initialize the console service.
   *
   * @param[in]       proj          Target project
   */
  void initialize (const Project & proj);

  /// Test if the console has been initialized.
  bool is_initialized (void) const;

  /**
   * Log an error message to the console service.
   *
   * @param[in]       message       The message to log
   */
  void error (const std::string & message);

  /**
   * Log an info message to the console service.
   *
   * @param[in]       message       The message to log
   */
  void info (const std::string & message);

  /**
   * Log a normal message to the console service.
   *
   * @param[in]       message       The message to log
   */
  void message (const std::string & message);

  /**
   * Log a warning message to the console service.
   *
   * @param[in]       message       The message to log
   */
  void warning (const std::string & message);

  /// Clear the current console.
  void clear (void);

private:
  /// Log a message to the console.
  void log (msgtype_enum type, const std::string & message);

  /// The GME application.
  ATL::CComPtr <IGMEOLEApp> gmeapp_;
};

}
}

/// Declare the singleton using ACE_DLL_Singleton_T since there is
/// good chance this library is used by GME components that are loaded
/// dynamically at runtime.
typedef ACE_DLL_Singleton_T < GAME::Mga::Singleton_Adapter_T <GAME::Mga::Console_Service> ,
                              ACE_Null_Mutex>
                              CONSOLE_SERVICE_SINGLETON;

GAME_MGA_COMPONENT_SINGLETON_DECLARE (ACE_DLL_Singleton_T,
                                      GAME::Mga::Singleton_Adapter_T <GAME::Mga::Console_Service>,
                                      ACE_Null_Mutex);

// Helper macro for accessing the console service.
#define GME_CONSOLE_SERVICE \
  ACE_DLL_Singleton_T < GAME::Mga::Singleton_Adapter_T <GAME::Mga::Console_Service>, ACE_Null_Mutex>::instance ()

#if defined (__GAME_INLINE__)
#include "Console_Service.inl"
#endif

#endif  // !defined _GAME_MGA_CONSOLE_SERVICE_H_
