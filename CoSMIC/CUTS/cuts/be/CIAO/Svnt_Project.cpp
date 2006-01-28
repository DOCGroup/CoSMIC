#include "cuts/be/CIAO/Svnt_Project.h"
#include "cuts/pir/File.h"

namespace CUTS_CIAO
{
  Svnt_Project::Svnt_Project (std::ofstream & outfile)
    : outfile_ (outfile)
  {

  }

  Svnt_Project::~Svnt_Project (void)
  {

  }

  void Svnt_Project::visit_file (const CUTS_PIR::File & file)
  {
    this->outfile_
      << "// $Id$" << std::endl
      << "project (" << file.name ()
      << "_CoWorkEr_svnt) : cuts_coworker_svnt {" << std::endl
      << "  after     += " << file.name () << "_CoWorkEr_stub" << std::endl
      << "  sharedname = " << file.name () << "_CoWorkEr_svnt" << std::endl
      << "  libs      += " << file.name () << "_CoWorkEr_stub" << std::endl
      << std::endl
      << "  CIDL_Files {" << std::endl
      << "    " << file.name () << ".cidl" << std::endl
      << "  }" << std::endl
      << std::endl
      << "  IDL_Files {" << std::endl
      << "    " << file.name () << "E.idl" << std::endl
      << "  }" << std::endl
      << std::endl
      << "  Source_Files {" << std::endl
      << "    " << file.name () << "EC.cpp" << std::endl
      << "    " << file.name () << "S.cpp" << std::endl
      << "    " << file.name () << "_svnt.cpp" << std::endl
      << "  }" << std::endl
      << "}" << std::endl;
  }
}
