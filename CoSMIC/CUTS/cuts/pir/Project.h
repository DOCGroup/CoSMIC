#ifndef _CUTS_PIR_PROJECT_H_
#define _CUTS_PIR_PROJECT_H_

#include "cuts/pir/Element.h"
#include "cuts/pir/Visitor.h"
#include "cuts/pir/EventManager.h"
#include "cuts/pir/Worker_Manager.h"
#include <set>

namespace CUTS_PIR
{
  class CUTS_Export Project :
    public Element,
    public Visitor_Element_T <Visitor, Project, &Visitor::visit_project>
  {
  public:
    /// Type definition for the collection of files.
    typedef std::set <File *> Files;

    /// Singleton instance of the project.
    static Project * instance (void);

    /// Close the singleton project instance.
    static void close (void);

    /// Get the list of files in the project.
    Files & files (void);

    /// Get the list of files in the project.
    const Files & files (void) const;

    /// Get the event manager for the project.
    Event_Manager & event_manager (void);

    /// Get the event manager for the project.
    const Event_Manager & event_manager (void) const;

    Worker_Manager & worker_manager (void);

    const Worker_Manager & worker_manager (void) const;

  private:
    /// Constructor.
    Project (void);

    /// Destructor.
    virtual ~Project (void);

    /// Files contained in this project.
    Files files_;

    /// Singleton instance of the project.
    static Project * instance_;

    /// The event manger for the project.
    Event_Manager event_manager_;

    /// The worker manager for the project.
    Worker_Manager worker_manager_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/Project.inl"
#endif

#endif  // !defined _CUTS_PIR_PROJECT_H_
