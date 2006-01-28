#include "cuts/be/CIAO/Stub_Project.h"
#include "cuts/pir/File.h"

namespace CUTS_CIAO
{
  Stub_Project::Stub_Project (std::ofstream & outfile)
    : outfile_ (outfile)
  {

  }

  Stub_Project::~Stub_Project (void)
  {

  }

  void Stub_Project::visit_file (const CUTS_PIR::File & file)
  {
    this->outfile_
      << "// $Id$" << std::endl
      << "project (" << file.name ()
      << "_CoWorkEr_stub) : cuts_coworker_stub {" << std::endl
      << "  sharedname = " << file.name () << "_CoWorkEr_stub" << std::endl
      << std::endl
      << "  IDL_Files {" << std::endl
      << "    " << file.name () << ".idl" << std::endl
      << "  }" << std::endl
      << std::endl
      << "  Source_Files {" << std::endl
      << "    " << file.name () << "C.cpp" << std::endl
      << "  }" << std::endl
      << "}" << std::endl;
  }
}
