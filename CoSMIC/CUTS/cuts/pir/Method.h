#ifndef _CUTS_PIR_METHOD_H_
#define _CUTS_PIR_METHOD_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  class CUTS_Export Method :
    public Element,
    public Visitor_Element_T <Visitor, Method, &Visitor::visit_method>
  {
  public:
    /// Constructor.
    Method (void);

    /// Destructor.
    virtual ~Method (void);
  };
}

#endif  // !defined _CUTS_PIR_METHOD_H_
