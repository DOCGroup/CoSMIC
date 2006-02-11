#ifndef _CUTS_PIR_METHOD_H_
#define _CUTS_PIR_METHOD_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"
#include <queue>

namespace CUTS_PIR
{
  class Worker_Action;

  class CUTS_Export Method :
    virtual public Element,
    public Visitor_Element_T <Visitor, Method, &Visitor::visit_method>
  {
  public:
    /// Type definition for the actions of the method.
    typedef std::queue <Worker_Action *> Worker_Actions;

    /// Constructor.
    Method (void);

    /// Destructor.
    virtual ~Method (void);

    /// Get the actions performed by this method.
    Worker_Actions & actions (void);

    /// Get the actions performed by this method.
    const Worker_Actions & actions (void) const;

  private:
    /// Actions performed my this method.
    Worker_Actions actions_;

    Method (const Method &);
    const Method & operator = (const Method &);
  };
}

#endif  // !defined _CUTS_PIR_METHOD_H_
