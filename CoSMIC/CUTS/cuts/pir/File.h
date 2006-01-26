#ifndef _CUTS_PIR_FILE_H_
#define _CUTS_PIR_FILE_H_

#include "cuts/pir/Module.h"
#include "cuts/pir/Visitor.h"
#include <string>

namespace CUTS_PIR
{
  class CUTS_Export File :
    public Visitor_Element_T <Visitor, File, &Visitor::visit_file>,
    public Module
  {
  public:
    typedef std::set <std::string> Includes;

    /// Constructor.
    File (void);

    /// Destructor.
    virtual ~File (void);

    /// Get the include files for this file.
    const Includes & includes (void) const;

    /// Get the include files for this file.
    Includes & includes (void);

    /// Resolves the ambiguity with the base classes.
    using Visitor_Element_T <
      Visitor, File, &Visitor::visit_file>::accept;

    bool has_events (void) const;

    void has_events (bool has_events);

  private:
    /// Listing of include files.
    Includes includes_;

    /// Flags specifying if the file has events.
    bool has_events_;
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/File.inl"
#endif

#endif  // !defined _CUTS_PIR_FILE_H_
