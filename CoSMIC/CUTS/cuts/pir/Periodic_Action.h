#ifndef _CUTS_PIR_PERIODIC_ACTION_H_
#define _CUTS_PIR_PERIODIC_ACTION_H_

#include "cuts/pir/Method.h"

namespace CUTS_PIR
{
  class CUTS_Export Periodic_Action :
    public Method,
    public Visitor_Element_T <
      Visitor, Periodic_Action, &Visitor::visit_periodic_action>
  {
  public:
    Periodic_Action (void);

    virtual ~Periodic_Action (void);

    double probability (void) const;

    void probability (double probability);

    long period (void) const;

    void period (long period);

    using Visitor_Element_T <
      Visitor, Periodic_Action, &Visitor::visit_periodic_action>::accept;

  private:
    /// The period for the action.
    long period_;

    /// The probability of the action occurring.
    double probability_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Periodic_Action.inl"
#endif

#endif  // !defined _CUTS_PIR_PERIODIC_ACTION_H_
