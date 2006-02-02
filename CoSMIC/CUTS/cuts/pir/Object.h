#ifndef _CUTS_PIR_OBJECT_H_
#define _CUTS_PIR_OBJECT_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"

namespace CUTS_PIR
{
  class CUTS_Export Object :
    public Module_Element,
    public Visitor_Element_T <Visitor, Object, &Visitor::visit_object>
  {
  public:
    /// Constructor.
    Object (Module * module);

    /// Destructor.
    virtual ~Object (void);
  };
}

#endif  // !defined _CUTS_PIR_OBJECT_H_
