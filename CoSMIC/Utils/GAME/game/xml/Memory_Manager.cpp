// $Id$

#include "Memory_Manager.h"
#include "ace/OS_NS_stdlib.h"

namespace GAME
{
namespace Xml
{

//
// Memory_Manager
//
Memory_Manager::Memory_Manager (void)
{

}

//
// ~Memory_Manager
//
Memory_Manager::~Memory_Manager (void)
{

}

//
// getExceptionMemoryManager
//
::xercesc::MemoryManager * Memory_Manager::getExceptionMemoryManager (void)
{
  return this;
}

//
// allocate
//
void * Memory_Manager::allocate (XMLSize_t size)
{
  return ACE_OS::malloc (size);
}

//
// deallocate
//
void Memory_Manager::deallocate (void * p)
{
  ACE_OS::free (p);
}

}
}
