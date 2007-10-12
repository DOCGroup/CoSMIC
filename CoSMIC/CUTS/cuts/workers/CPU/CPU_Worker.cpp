// $Id$

#include "CPU_Worker.h"

CUTS_WORKER_FACTORY_EXPORT_IMPL (CUTS_CPU_Worker);

//
// CUTS_CPU_Worker
//
CUTS_CPU_Worker::CUTS_CPU_Worker (void)
: CUTS_CPU_Worker_T <CUTS_Basic_CPU_Worker> (CUTS_Basic_CPU_Worker ())
{

}

//
// ~CUTS_CPU_Worker
//
CUTS_CPU_Worker::~CUTS_CPU_Worker (void)
{

}
