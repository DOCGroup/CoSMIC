// $Id$

#include "cuts/MemoryWorker.h"

#define CUTS_MEMORY_ALLOC_SIZE 1024

//
// CUTS_Memory_Worker
//
CUTS_Memory_Worker::CUTS_Memory_Worker (void)
{

}

//
// ~CUTS_Memory_Worker
//
CUTS_Memory_Worker::~CUTS_Memory_Worker (void)
{
  // delete all the remaining memory in the container
  Memory_Allocations::container_type::iterator iter;

  for ( iter = this->memory_.c.begin ();
        iter != this->memory_.c.end ();
        iter ++)
  {
    delete [] (*iter);
  }
}

//
// allocate
//
void CUTS_Memory_Worker::allocate (size_t kilobytes)
{
  while (kilobytes -- > 0)
  {
    char * allocation = new char [CUTS_MEMORY_ALLOC_SIZE];
    this->memory_.push (allocation);
  }
}

//
// deallocate
//
void CUTS_Memory_Worker::deallocate (size_t kilobytes)
{
  // Make sure we are not trying to deallocate more memory
  // that what is currently allocated.
  if (kilobytes > this->memory_.size ())
    kilobytes = this->memory_.size ();

  while (kilobytes -- > 0)
  {
    // get the next allocation on the <memory_> stack
    char * memory = this->memory_.front ();
    this->memory_.pop ();

    // delete the piece of
    delete [] memory;
  }
}
