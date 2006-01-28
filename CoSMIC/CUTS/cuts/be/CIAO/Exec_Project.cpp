#include "cuts/be/CIAO/Exec_Project.h"
#include "cuts/pir/File.h"

namespace CUTS_CIAO
{
  Exec_Project::Exec_Project (std::ofstream & outfile)
    : outfile_ (outfile)
  {

  }

  Exec_Project::~Exec_Project (void)
  {

  }

  void Exec_Project::visit_file (const CUTS_PIR::File & file)
  {
    this->outfile_
      << "// $Id$" << std::endl
      << "project (" << file.name ()
      << "_CoWorkEr_exec) : cuts_coworker_exec {" << std::endl
      << "  after     += " << file.name () << "_CoWorkEr_svnt" << std::endl
      << "  sharedname = " << file.name () << "_CoWorkEr_exec" << std::endl
      << "  libs      += " << file.name () << "_CoWorkEr_stub "
      << file.name () << "_CoWorkEr_svnt" << std::endl
      << std::endl
      << "  Source_Files {" << std::endl
      << "    " << file.name () << "_CoWorkEr.cpp" << std::endl
      << "  }" << std::endl
      << "}" << std::endl;
  }
}
