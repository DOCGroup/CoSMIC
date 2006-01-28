#ifndef _CUTS_CIAO_MPC_VISITOR_H_
#define _CUTS_CIAO_MPC_VISITOR_H_

#include "cuts/pir/Visitor.h"
#include <fstream>

namespace CUTS_CIAO
{
  class CUTS_Export MPC_Visitor :
    public CUTS_PIR::Visitor
  {
  public:
    MPC_Visitor (std::ofstream & outfile);

    virtual ~MPC_Visitor (void);

    void visit_file (const CUTS_PIR::File & file);

  private:
    /// Output directory for the MPC file.
    std::ofstream & outfile_;
  };
}
#endif  // !defined _CUTS_CIAO_MPC_VISITOR_H_
