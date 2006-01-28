// -*- C++ -*-

//=============================================================================
/**
 * @file    Exec_Project.h
 *
 * $Id$
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_CIAO_EXEC_PROJECT_H_
#define _CUTS_CIAO_EXEC_PROJECT_H_

#include "cuts/pir/Visitor.h"
#include <fstream>

namespace CUTS_CIAO
{
  //===========================================================================
  /**
   * @class Exec_Project
   *
   * This class generates a CIAO CoWorkEr executor project for a MPC
   * file.
   */
  //===========================================================================

  class CUTS_Export Exec_Project :
    public CUTS_PIR::Visitor
  {
  public:
    /// Constructor.
    Exec_Project (std::ofstream & outfile);

    /// Destructor.
    virtual ~Exec_Project (void);

    /// Visit the specified file.
    void visit_file (const CUTS_PIR::File & file);

  private:
    /// Output stream for the executor project.
    std::ofstream & outfile_;
  };
}

#endif  // !defined _CUTS_CIAO_EXEC_PROJECT_H_
