#ifndef _CUTS_PIR_WORKER_MANAGER_H_
#define _CUTS_PIR_WORKER_MANAGER_H_

#include "cuts/config.h"
#include <map>
#include <string>

namespace CUTS_PIR
{
  class Worker;

  class CUTS_Export Worker_Manager :
    public std::map <std::string, Worker *>
  {
  public:
    Worker_Manager (void);

    ~Worker_Manager (void);
  };
}

#endif // !defined _CUTS_PIR_WORKER_MANAGER_H_
