// -*- C++ -*-

//=============================================================================
/**
 * @file        Memory_Manager.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _MEMORY_MANAGER_H_
#define _MEMORY_MANAGER_H_

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "xercesc/framework/MemoryManager.hpp"
#include "game/config.h"

namespace GAME
{
namespace Xml
{

/**
 * @class Memory_Manager
 *
 * Implementation of the memory manager interface.
 */
class Memory_Manager : public ::xercesc::MemoryManager
{
public:
  /// Default constructor.
  Memory_Manager (void);

  /// Destructor.
  virtual ~Memory_Manager (void);

  /// Get a pointer to the exception memory manager. This method
  /// returns a pointer to itself.
  virtual ::xercesc::MemoryManager * getExceptionMemoryManager (void);

  /// Allocate memory of the specified size.
  virtual void * allocate (XMLSize_t size);

  /// Deallocate the specified memory.
  virtual void deallocate (void * p);
};

}
}

#endif /* _XERCESSTRING_H */
