#ifndef _CUTS_PIR_WORKER_ACTION_H_
#define _CUTS_PIR_WORKER_ACTION_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"
#include <queue>

namespace CUTS_PIR
{
  class Action_Property;

  //===========================================================================
  /**
   * @class Worker_Action
   *
   * This class defines the bare minimal information needed to represent a
   * worker action. A worker action is an action that can be performed by a
   * worker object. It also has properties that define the parameters of the
   * worker action.
   */
  //===========================================================================

  class CUTS_Export Worker_Action :
    public Element,
    public Visitor_Element_T <
      Visitor, Worker_Action, &Visitor::visit_worker_action>
  {
  public:
    /// Type definition for properties associated with an action.
    typedef std::queue <Action_Property *> Properties;

    /// Constructor.
    Worker_Action (const Worker_Type * parent);

    /// Destructor.
    virtual ~Worker_Action (void);

    /// Get the parent of the action.
    const Worker_Type * parent (void) const;

    /// Get the number of repetitions.
    size_t repetitions (void) const;

    /// Set the number of repetitions.
    void repetitions (size_t reps);

    /// Get the logging flag.
    bool log_action (void) const;

    /// Set the logging flag.
    void log_action (bool log);

    /// Get the properties for the action.
    Properties & properties (void);

    /// Get the properties for the action.
    const Properties & properties (void) const;

  private:
    /// The parent of the action.
    const Worker_Type * parent_;

    /// Logging flag.
    bool log_action_;

    /// The number of repetitions to perform.
    size_t repetitions_;

    /// Properties associated with the action.
    Properties properties_;

    Worker_Action (const Worker_Action & action);
    const Worker_Action & operator = (const Worker_Action & action);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Worker_Action.inl"
#endif

#endif  // !defined _CUTS_PIR_WORKER_ACTION_H_
