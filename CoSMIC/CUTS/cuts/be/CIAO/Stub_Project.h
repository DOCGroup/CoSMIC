// -*- C++ -*-

//=============================================================================
/**
 * @file    Stub_Project.h
 *
 * $Id$
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_CIAO_STUB_PROJECT_H_
#define _CUTS_CIAO_STUB_PROJECT_H_

#include "cuts/pir/Visitor.h"
#include <fstream>

namespace CUTS_CIAO
{
  //===========================================================================
  /**
   * @class Stub_Project
   *
   * This class generates a CIAO CoWorkEr stub project for a MPC
   * file.
   */
  //===========================================================================

  class CUTS_Export Stub_Project :
    public CUTS_PIR::Visitor
  {
  public:
    /// Constructor.
    Stub_Project (std::ofstream & outfile);

    /// Destructor.
    virtual ~Stub_Project (void);

    /// Visit the specified file.
    void visit_file (const CUTS_PIR::File & file);

  private:
    /// Output stream for the stub project.
    std::ofstream & outfile_;
  };
}

#endif  // !defined _CUTS_CIAO_STUB_PROJECT_H_
