#include "cuts/pir/Worker_Manager.h"
#include "cuts/pir/Worker.h"

namespace CUTS_PIR
{
  //
  // Worker_Manager
  //
  Worker_Manager::Worker_Manager (void)
  {

  }

  //
  // ~Worker_Manager
  //
  Worker_Manager::~Worker_Manager (void)
  {
    for (iterator iter = begin (); iter != end (); iter ++)
    {
      delete iter->second;
    }
  }
}
