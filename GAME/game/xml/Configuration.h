// -*- C++ -*-

//=============================================================================
/**
 * @file        Configuration.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _GAME_XML_CONFIGURATION_H_
#define _GAME_XML_CONFIGURATION_H_

#include "ace/Singleton.h"
#include "ace/Thread_Mutex.h"

#include "Memory_Manager.h"
#include "Singleton_Adapter_T.h"

#include "Xml_export.h"

namespace GAME
{
namespace Xml
{

/**
 * @class Configuration
 *
 * Static configuration for the Xml backend. This will also initialize
 * Xerces-C for the current project/executable.
 */
class GAME_XML_Export Configuration
{
public:
  /// Default constuctor
  Configuration (Memory_Manager * allocator = 0);

  /// Destructor
  virtual ~Configuration (void);

  /// Get the memory manager.
  Memory_Manager * memory_manager (void);
  void memory_manager (Memory_Manager * allocator);

private:
  /// The allocator for the configuration.
  Memory_Manager * allocator_;

  /// The global memory manager.
  static Memory_Manager global_allocator_;
};

/// Declare the singleton using ACE_DLL_Singleton_T since there is
/// good chance this library is used by GME components that are loaded
/// dynamically at runtime.
typedef ACE_DLL_Singleton_T < Singleton_Adapter_T <Configuration> ,
                              ACE_Thread_Mutex>
                              GLOBAL_CONFIGURATION;

GAME_XML_SINGLETON_DECLARE (ACE_DLL_Singleton_T,
                            Singleton_Adapter_T <Configuration>,
                            ACE_Thread_Mutex);

}
}

#if defined (__GAME_INLINE__)
#include "Configuration.inl"
#endif

#endif  // _STATIC_CONFIGURATION_H_

