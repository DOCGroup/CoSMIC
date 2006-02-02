#ifndef _CUTS_PIR_WORKER_TYPE_H_
#define _CUTS_PIR_WORKER_TYPE_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  class CUTS_Export Worker_Type :
    public Reference_Element,
    public Element,
    public Visitor_Element_T <Visitor, Worker_Type, Visitor::visit_worker_type>
  {
  public:
    Worker_Type (void);

    virtual ~Worker_Type (void);
  };
}

#endif  // !defined _CUTS_WORKRER_TYPE_H_
