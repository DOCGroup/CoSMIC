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

#include "Component_export.h"

namespace GAME
{
namespace Mga
{

/**
 * @class Console_Service
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
  void initialize (Project proj);

  /// Test if the console has been initialized.
  bool is_initialized (void) const;

  /**
   * Log a message to the console service.
   *
   * @param[in]       type          The type of message
   * @param[in]       message       The message to log
   */
  void log (int type, const std::string & message);

  /// Clear the current console.
  void clear (void);

private:
  /// Host project of the console service.
  Project project_;

  /// The GME application.
  ATL::CComPtr <IGMEOLEApp> gmeapp_;
};

}
}

// Helper macro for accessing the console service.
#define GME_CONSOLE_SERVICE \
  ACE_Singleton <GAME::Mga::Console_Service, ACE_Null_Mutex>::instance ()

GAME_MGA_COMPONENT_SINGLETON_DECLARE (ACE_Singleton,
                                      GAME::Mga::Console_Service,
                                      ACE_Null_Mutex)


#if defined (__GAME_INLINE__)
#include "Console_Service.inl"
#endif

#endif  // !defined _GAME_MGA_CONSOLE_SERVICE_H_
