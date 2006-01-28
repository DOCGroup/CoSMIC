#ifndef _CUTS_CIAO_MWC_VISITOR_H_
#define _CUTS_CIAO_MWC_VISITOR_H_

#include "cuts/pir/Visitor.h"
#include <string>

namespace CUTS_CIAO
{
  class CUTS_Export MWC_Visitor :
    public CUTS_PIR::Visitor
  {
  public:
    MWC_Visitor (const char * outdir);

    virtual ~MWC_Visitor (void);

    void visit_project (const CUTS_PIR::Project & project);

  private:
    std::string outdir_;
  };
}

#endif  // !defined _CUTS_CIAO_MWC_VISITOR_H_
