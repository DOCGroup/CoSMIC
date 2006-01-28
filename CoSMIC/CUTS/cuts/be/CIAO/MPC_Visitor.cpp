#include "cuts/be/CIAO/MPC_Visitor.h"
#include "cuts/be/CIAO/Stub_Project.h"
#include "cuts/be/CIAO/Svnt_Project.h"
#include "cuts/be/CIAO/Exec_Project.h"
#include "cuts/pir/File.h"

namespace CUTS_CIAO
{
  MPC_Visitor::MPC_Visitor (std::ofstream & outfile)
    : outfile_ (outfile)
  {

  }

  MPC_Visitor::~MPC_Visitor (void)
  {

  }

  void MPC_Visitor::visit_file (const CUTS_PIR::File & file)
  {
    // Write the header for the file.
    this->outfile_
      << "// This project file was generate by" << std::endl
      << "// $Id$" << std::endl
      << std::endl;

    // Write the stub project.
    Stub_Project stub_project (this->outfile_);
    file.accept (&stub_project);
    this->outfile_ << std::endl;

    // Write the svnt project.
    Svnt_Project svnt_project (this->outfile_);
    file.accept (&svnt_project);
    this->outfile_ << std::endl;

    // Write the exec project.
    Exec_Project exec_project (this->outfile_);
    file.accept (&exec_project);
  }
};
