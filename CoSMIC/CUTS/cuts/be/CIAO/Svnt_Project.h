// -*- C++ -*-

//=============================================================================
/**
 * @file    Svnt_Project.h
 *
 * $Id$
 *
 * @author James H. Hill <hillj@isis.vanderbilt.edu>
 */
//=============================================================================

#ifndef _CUTS_CIAO_SVNT_PROJECT_H_
#define _CUTS_CIAO_SVNT_PROJECT_H_

#include "cuts/pir/Visitor.h"
#include <fstream>

namespace CUTS_CIAO
{
  //===========================================================================
  /**
   * @class Svnt_Project
   *
   * This class generates a CIAO CoWorkEr servant project for a MPC
   * file
   */
  //===========================================================================

  class CUTS_Export Svnt_Project :
    public CUTS_PIR::Visitor
  {
  public:
    /// Constructor.
    Svnt_Project (std::ofstream & outfile);

    /// Destructor.
    virtual ~Svnt_Project (void);

    /// Visit the file.
    void visit_file (const CUTS_PIR::File & file);

  private:
    /// Output stream for the svnt project.
    std::ofstream & outfile_;
  };
}

#endif  // !defined _CUTS_CIAO_SVNT_PROJECT_H_
