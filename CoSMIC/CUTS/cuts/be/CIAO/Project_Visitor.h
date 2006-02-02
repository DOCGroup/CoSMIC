#ifndef _CUTS_BE_CIAO_PROJECT_VISITOR_H_
#define _CUTS_BE_CIAO_PROJECT_VISITOR_H_

#include "cuts/pir/Visitor.h"
#include <string>

namespace CUTS_CIAO
{
  //===========================================================================
  /**
   *
   */
  //===========================================================================

  class CUTS_Export Project_Visitor :
    public CUTS_PIR::Visitor
  {
  public:
    /// Constructor.
    Project_Visitor (const char * outdir);

    /// Destructor.
    virtual ~Project_Visitor (void);

    /// Visit a project.
    void visit_project (const CUTS_PIR::Project & project);

  private:
    /// Output directory for the project.
    std::string outdir_;
  };
}

#endif  // !defined _CUTS_BE_CIAO_PROJECT_VISITOR_H_
