// -*- C++ -*-

//=============================================================================
/**
 * @file        Static_Configuration.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _STATIC_CONFIGURATION_H_
#define _STATIC_CONFIGURATION_H_

#include "ace/Singleton.h"
#include "ace/Thread_Mutex.h"
#include "Memory_Manager.h"
#include "Xml_export.h"

namespace GAME
{
namespace Xml
{
/**
 * @class Static_Configuration
 *
 * Static configuration for the Xml backend. This will also initialize
 * Xerces-C for the current project/executable.
 */
class GAME_XML_Export Static_Configuration
{
public:
  /// Default constuctor
  Static_Configuration (void);

  /// Destructor
  virtual ~Static_Configuration (void);

  /// Get the memory manager.
  ::xercesc::MemoryManager * memory_manager (void);

private:
  /// The allocator for the configuration.
  Memory_Manager allocator_;
};

typedef ACE_Singleton <Static_Configuration, ACE_Null_Mutex> STATIC_CONFIGURATION_SINGLETON;

}
}

GAME_XML_SINGLETON_DECLARE (ACE_Singleton,
                            GAME::Xml::Static_Configuration,
                            ACE_Thread_Mutex);

#endif  // _STATIC_CONFIGURATION_H_

