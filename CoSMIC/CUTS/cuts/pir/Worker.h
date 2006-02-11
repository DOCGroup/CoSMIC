#ifndef _CUTS_PIR_WORKER_H_
#define _CUTS_PIR_WORKER_H_

#include "cuts/pir/Element.h"

namespace CUTS_PIR
{
  class CUTS_Export Worker :
    public Element
  {
  public:
    Worker (void);

    virtual ~Worker (void);
  };
}

#endif  // !defined _CUTS_PIR_WORKER_H_
