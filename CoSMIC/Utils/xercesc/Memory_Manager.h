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

#ifndef _XERCESSTRING_H
#define _XERCESSTRING_H

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "xercesc/framework/MemoryManager.hpp"

namespace Utils
{
/**
 * @class Memory_Manager
 */
class Memory_Manager : public xercesc::MemoryManager
{
public:
  Memory_Manager (void);

  virtual ~Memory_Manager (void);

  virtual MemoryManager * getExceptionMemoryManager (void);

  virtual void * allocate (XMLSize_t size);

  virtual void deallocate (void * p);
};

typedef ACE_Singleton <Memory_Manager, ACE_Null_Mutex> Global_Memory_Manager;

}

#endif /* _XERCESSTRING_H */
