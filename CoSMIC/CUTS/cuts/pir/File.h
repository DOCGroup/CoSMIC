#ifndef _CUTS_PIR_FILE_H_
#define _CUTS_PIR_FILE_H_

#include "cuts/pir/Module.h"
#include "cuts/pir/Visitor.h"
#include <string>

namespace CUTS_PIR
{
  //===========================================================================
  /**
   * @class File
   */
  //===========================================================================

  class CUTS_Export File :
    public Module,
    public Visitor_Element_T <Visitor, File, &Visitor::visit_file>
  {
  public:
    /// Type definition for the file includes.
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

    /// Get the <has_events_> flag.
    bool has_events (void) const;

    /// Set the <has_events_> flag.
    void has_events (bool has_events);

  private:
    /// Listing of include files.
    Includes includes_;

    /// Flags specifying if the file has events.
    bool has_events_;

    File (const File &);
    const File & operator = (const File &);
  };
}

#if defined (__CUTS_INLINE__)
#include "cuts/pir/File.inl"
#endif

#endif  // !defined _CUTS_PIR_FILE_H_
