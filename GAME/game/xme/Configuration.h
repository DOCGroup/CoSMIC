// -*- C++ -*-

//=============================================================================
/**
 * @file      Configuration.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _GAME_XME_CONFIGURATION_H_
#define _GAME_XME_CONFIGURATION_H_

#include "ace/Thread_Mutex.h"
#include "ace/Singleton.h"
#include "game/xml/String.h"
#include "XME_export.h"

namespace GAME
{
namespace XME
{
/**
 * @class Configuration
 *
 * Configuration for the XME backend.
 */
class GAME_XME_Export Configuration
{
public:
  /// Default construction (configuration).
  Configuration (void);

  GAME::Xml::String schema_path_;
};

typedef ACE_Singleton <Configuration, ACE_Thread_Mutex> GLOBAL_CONFIG;
GAME_XME_SINGLETON_DECLARE (ACE_Singleton, Configuration, ACE_Thread_Mutex);

}
}


#endif
