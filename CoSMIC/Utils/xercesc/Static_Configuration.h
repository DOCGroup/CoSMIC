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
#include "ace/Null_Mutex.h"
#include "Memory_Manager.h"
#include "Xerces_Utils_export.h"

namespace cosmic
{
namespace xercesc
{
namespace utils
{
/**
 * @class Memory_Manager
 */
class COSMIC_XERCES_UTILS_Export Static_Configuration
{
public:
  Static_Configuration (void);

  virtual ~Static_Configuration (void);

  ::xercesc::MemoryManager * memory_manager (void);

private:
  Memory_Manager allocator_;  
};
}
}
}

#define STATIC_CONFIGURATION_SINGLETON \
  ACE_Singleton <::cosmic::xercesc::utils::Static_Configuration, ACE_Null_Mutex>

COSMIC_XERCES_UTILS_SINGLETON_DECLARATION (STATIC_CONFIGURATION_SINGLETON);

#endif  // _STATIC_CONFIGURATION_H_

