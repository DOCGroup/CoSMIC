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

namespace GAME
{
namespace Xml
{

/**
 * @class Memory_Manager
 */
class Memory_Manager : public ::xercesc::MemoryManager
{
public:
  Memory_Manager (void);

  virtual ~Memory_Manager (void);

  virtual ::xercesc::MemoryManager * getExceptionMemoryManager (void);

  virtual void * allocate (XMLSize_t size);

  virtual void deallocate (void * p);
};

}
}

#endif /* _XERCESSTRING_H */
