// -*- C++ -*-

//=============================================================================
/**
 *  @file       Event_Config.h
 *
 *  $Id:        Event_Handler_Config.h 2453 2010-08-24 12:00:00Z alhad $
 *
 *  @author     Alhad Mokashi
 */
//=============================================================================

#ifndef _PICML_MI_EVENT_HANDLER_CONFIG_H_
#define _PICML_MI_EVENT_HANDLER_CONFIG_H_

#include "ace/Singleton.h"
#include "ace/Thread_Mutex.h"
#include <string>

namespace PICML
{
namespace MI
{

/**
* @class Event_Handler_Config
*
*
*/
struct Event_Handler_Config
{
public:
  /// Default constructor.
  Event_Handler_Config (void);

  /// Reset the configuration.
  void reset (void);

  std::string impl_folder_;

  std::string artifact_folder_;
};

typedef ACE_Singleton <Event_Handler_Config,
                       ACE_Thread_Mutex>
                       Global_Configuration;

}
}

#endif