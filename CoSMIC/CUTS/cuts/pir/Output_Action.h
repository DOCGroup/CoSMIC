#ifndef _CUTS_PIR_OUTPUT_ACTION_H_
#define _CUTS_PIR_OUTPUT_ACTION_H_

#include "cuts/pir/Worker_Action.h"

namespace CUTS_PIR
{
  class CUTS_Export Output_Action :
    public Worker_Action,
    public Visitor_Element_T <
      Visitor, Output_Action, &Visitor::visit_output_action>
  {
  public:
    Output_Action (void);

    virtual ~Output_Action (void);

    const Event_Source * event_source (void) const;

    void event_source (const Event_Source * event_source);

    size_t size (void) const;

    void size (size_t size);

  private:
    using Worker_Action::parent;

    /// Event source associated w/ this output action.
    const Event_Source * event_source_;

    /// Size of the output action.
    size_t size_;

    Output_Action (const Output_Action &);
    const Output_Action & operator = (const Output_Action &);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Output_Action.inl"
#endif

#endif  // !defined _CUTS_PIR_OUTPUT_ACTION_H_
