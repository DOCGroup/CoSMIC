// $Id$

#include "cuts/CPUWorker.h"
#include "ace/OS_NS_stdlib.h"

#define CUTS_CPU_CYCLES 10000

//
// CUTS_CPU_Worker
//
CUTS_CPU_Worker::CUTS_CPU_Worker (void)
{
}

//
// ~CUTS_CPU_Worker
//
CUTS_CPU_Worker::~CUTS_CPU_Worker (void)
{

}

//
// process
//
void CUTS_CPU_Worker::process (void)
{
  for (int cycle = 0; cycle < CUTS_CPU_CYCLES; cycle ++)
  {
    ACE_OS::rand ();
  }
}
