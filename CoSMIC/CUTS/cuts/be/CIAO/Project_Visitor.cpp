// $Id$

#include "cuts/be/CIAO/Project_Visitor.h"
#include "cuts/be/CIAO/File_Visitor.h"
#include "cuts/be/CIAO/MWC_Visitor.h"
#include "cuts/pir/Project.h"
#include "cuts/pir/File.h"

#include <algorithm>

namespace CUTS_CIAO
{
  //===========================================================================
  /*
   * class Project_Visitor
   */
  //===========================================================================

  //
  // Project_Visitor
  //
  Project_Visitor::Project_Visitor (const char * outdir)
    : outdir_ (outdir)
  {

  }

  //
  // ~Project_Visitor
  //
  Project_Visitor::~Project_Visitor (void)
  {

  }

  //
  // visit_project
  //
  void Project_Visitor::visit_project (const CUTS_PIR::Project & project)
  {
    // Instantiate a <File_Visitor> for parsing the files.
    File_Visitor file_visitor (this->outdir_.c_str ());

    std::for_each (
      project.files ().begin (),
      project.files ().end (),
      std::bind2nd (
        std::mem_fun <void, CUTS_PIR::File, CUTS_PIR::Visitor *> (
          &CUTS_PIR::File::accept),
        &file_visitor));

    // Write the necessary MWC files.
    MWC_Visitor mwc_visitor (this->outdir_.c_str ());
    project.accept (&mwc_visitor);
  }
}
