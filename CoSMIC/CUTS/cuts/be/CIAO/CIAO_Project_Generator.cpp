// $Id$

#include "CIAO_Project_Generator.h"

#include "cuts/be/Export_File_Generator.h"
#include "cuts/be/BE_Options.h"
#include "cuts/be/BE_IDL_Node.h"
#include "cuts/be/BE_Impl_Node.h"

#include "boost/bind.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>

#define EXEC_SUFFIX       "_exec"
#define SVNT_SUFFIX       "_svnt"
#define STUB_SUFFIX       "_stub"

#define CLIENT_SUFFIX     "C"
#define SERVER_SUFFIX     "S"

//
// CUTS_CIAO_Project_Generator
//
CUTS_CIAO_Project_Generator::
CUTS_CIAO_Project_Generator (void)
{

}

//
// ~CUTS_CIAO_Project_Generator
//
CUTS_CIAO_Project_Generator::
~CUTS_CIAO_Project_Generator (void)
{

}

//
// generate_exec
//
bool CUTS_CIAO_Project_Generator::
write_exec_project (const CUTS_BE_Impl_Node & node)
{
  // Construct the filename of the MPC file.
  std::ostringstream ostr;
  ostr
    << CUTS_BE_OPTIONS ()->output_directory_ << "/"
    << node.name_
    << CUTS_BE_OPTIONS ()->exec_suffix_ << ".mpc";

  // Open the MPC file for writing.
  std::ofstream outfile;
  outfile.open (ostr.str ().c_str ());

  if (!outfile.is_open ())
    return false;

  outfile
    << "// This project file was generated by" << std::endl
    << "// $Id$"
    << std::endl
    << std::endl;

  // Let's reset the <visited_nodes_> object, if necessary.
  if (!this->visited_nodes_.empty ())
    this->visited_nodes_.clear ();

  // Generate the executor and servant projects.
  this->generate_impl_project (outfile, node, true);
  this->generate_svnt_project (outfile, node);

  // Close the output file and return its status.
  outfile.close ();
  return outfile.good ();
}

//
// generate_stub
//
bool CUTS_CIAO_Project_Generator::
write_stub_project (const CUTS_BE_IDL_Node & node)
{
  // Construct the name of the MPC file.
  std::ostringstream pathname;
  pathname
    << CUTS_BE_OPTIONS ()->output_directory_
    << "/" << node.name_ << STUB_SUFFIX << ".mpc";

  // Open the MPC file for writing.
  std::ofstream outfile;
  outfile.open (pathname.str ().c_str ());

  if (!outfile.is_open ())
    return false;

  // Write the preamble for the project file. We need to add a more
  // detailed one in the near future.
  outfile
    << "// This project file was generated by" << std::endl
    << "// $Id$"
    << std::endl
    << std::endl;

  // Generate the export file for the project.
  std::string stub_name = node.basename_ + STUB_SUFFIX;
  CUTS_Export_File_Generator export_file (stub_name);
  export_file.generate ();

  // Generate the project.
  outfile
    << "project (" << stub_name << ") : cuts_coworker_stub {" << std::endl
    << "  sharedname   = " << stub_name << std::endl
    << std::endl
    << "  dynamicflags = " << export_file.build_flag () << std::endl
    << std::endl
    << "  idlflags += -Wb,export_macro=" << export_file.export_macro ()
    << " \\" << std::endl
    << "              -Wb,export_include=" << export_file.export_file ()
    << std::endl;

  if (!node.references_.empty ())
  {
    this->visited_nodes_.clear ();

    // Generate the dependencies for this project. This will be
    // all the client projects of the references for this node.
    outfile
      << std::endl
      << "  after +=";

    std::for_each (node.references_.begin (),
                   node.references_.end (),
                   boost::bind (&CUTS_CIAO_Project_Generator::
                                generate_stub_listing,
                                this,
                                boost::ref (outfile),
                                _1));

    // Generate the import libraries for this project. This will be
    // all client project of the references for this node. The will
    // also be the same as those specified in the "after" tag.

    this->visited_nodes_.clear ();

    outfile
      << std::endl
      << std::endl
      << "  libs  +=";

    std::for_each (node.references_.begin (),
                   node.references_.end (),
                   boost::bind (&CUTS_CIAO_Project_Generator::
                                generate_stub_listing,
                                this,
                                boost::ref (outfile),
                                _1));

    outfile
      << std::endl;
  }

  outfile
    << std::endl
    // Generate the IDL files for this project.
    << "  IDL_Files {" << std::endl
    << "    " << node.basename_ << ".idl" << std::endl
    << "  }" << std::endl
    << std::endl

    // Generate the source files for this project.
    << "  Source_Files {" << std::endl
    << "    " << node.basename_ << SERVER_SUFFIX << ".cpp" << std::endl
    << "    " << node.basename_ << CLIENT_SUFFIX << ".cpp" << std::endl
    << "  }" << std::endl
    << std::endl
    // Generate the header files for this project.
    << "  Header_Files {" << std::endl
    << std::endl
    << "  }" << std::endl
    << "}" << std::endl
    << std::endl;

  // Close the project and add it to the workspace.
  outfile.close ();
  return outfile.good ();
}

//
// write_exec_project
//
void CUTS_CIAO_Project_Generator::
generate_impl_project (std::ofstream & outfile,
                       const CUTS_BE_Impl_Node & node,
                       bool executor_type)
{
  // Generate the export_file file for the project.
  std::string impl_project = node.name_ + CUTS_BE_OPTIONS ()->exec_suffix_;
  std::string impl_export (impl_project.size (), '\0');

  std::replace_copy (impl_project.begin (),
                     impl_project.end (),
                     impl_export.begin (),
                     '/', '_');

  CUTS_Export_File_Generator efg (impl_export, impl_project);
  efg.generate ();

  // Convert the name to a valid project name.
  std::replace (impl_project.begin (), impl_project.end (), '/', '_');

  // Construct the name of the servant project.
  std::string svnt_project = node.name_ + SVNT_SUFFIX;
  std::replace (svnt_project.begin (), svnt_project.end (), '/', '_');

  // Generate the executor project.
  outfile
    << "project (" << impl_project << ") : cuts_coworker_exec {" << std::endl
    << "  sharedname   = " << impl_project << std::endl
    << std::endl
    << "  dynamicflags = " << efg.build_flag () << std::endl
    << std::endl
    << "  after  += " << svnt_project << std::endl
    << std::endl
    << "  libs   += \\ " << std::endl
    << "    " << svnt_project;

  // Generate the stub import libraries for this node.
  std::for_each (node.references_.begin (),
                 node.references_.end (),
                 boost::bind (&CUTS_CIAO_Project_Generator::
                              generate_stub_listing,
                              this,
                              boost::ref (outfile),
                              _1));

  // Generate the remaining MPC stuff for this project.
  outfile
    << std::endl
    << std::endl;

  if (executor_type)
    this->generate_mpc_i (outfile, node);

  outfile
    // Generate the source files.
    << "  Source_Files {" << std::endl
    << "    " << node.basename_ <<  CUTS_BE_OPTIONS ()->exec_suffix_
    << ".cpp" << std::endl
    << "  }" << std::endl
    << std::endl

    // Generate the header files.
    << "  Header_Files {" << std::endl
    << std::endl
    << "  }" << std::endl
    << std::endl
    << "  Inline_Files {" << std::endl
    << std::endl
    << "  }" << std::endl
    << std::endl
    << "  IDL_Files {" << std::endl
    << std::endl
    << "  }" << std::endl
    << "}" << std::endl
    << std::endl;
}

//
// write_svnt_project
//
void CUTS_CIAO_Project_Generator::
generate_svnt_project (std::ofstream & outfile,
                       const CUTS_BE_Impl_Node & node)
{
  // Generator the export file.
  std::string svnt_project = node.name_ + SVNT_SUFFIX;
  std::string svnt_export = node.basename_ + SVNT_SUFFIX;

  CUTS_Export_File_Generator efg (svnt_export, svnt_project);
  efg.generate ();

  // Convert the <svnt_project> to a valid name.
  std::replace (svnt_project.begin (), svnt_project.end (), '/', '_');

  std::string efg_basename = efg.export_file ();
  size_t index = efg_basename.find_last_of ('/');

  if (index != std::string::npos)
    efg_basename.erase (0, index + 1);

  outfile
    << "project (" << svnt_project << ") : cuts_coworker_svnt {" << std::endl
    << "  sharedname   = " << svnt_project << std::endl
    << std::endl
    << "  dynamicflags = " << efg.build_flag () << std::endl
    << std::endl

    // Generate the IDL flag definitions.
    << "  idlflags += -Wb,export_macro=" << efg.export_macro ()
    << " \\" << std::endl
    << "              -Wb,export_include=" << efg_basename
    << std::endl
    << std::endl;

  // Generate the STUB dependencies for this node.
  if (!node.references_.empty ())
  {
    this->visited_nodes_.clear ();

    outfile
      << "  after +=";

    std::for_each (node.references_.begin (),
                   node.references_.end (),
                   boost::bind (&CUTS_CIAO_Project_Generator::
                                generate_stub_listing,
                                this,
                                boost::ref (outfile),
                                _1));

    outfile
      << std::endl
      << std::endl;

    // Clear the visited nodes so we can iterate over them once
    // more. This time we are generating the libs declaration.
    this->visited_nodes_.clear ();

    outfile
      << "  libs +=";

    std::for_each (node.references_.begin (),
                   node.references_.end (),
                   boost::bind (&CUTS_CIAO_Project_Generator::
                                generate_stub_listing,
                                this,
                                boost::ref (outfile),
                                _1));

    outfile
      << std::endl
      << std::endl;
  }

  outfile
    // Generate the CIDL files
    << "  CIDL_Files {" << std::endl
    << "    " << node.basename_ << ".cidl" << std::endl
    << "  }" << std::endl
    << std::endl

    // Generate the IDL files
    << "  IDL_Files {" << std::endl
    << "    " << node.basename_ << "E.idl" << std::endl
    << "  }" << std::endl
    << std::endl

    // Generate the source files
    << "  Source_Files {" << std::endl
    << "    " << node.basename_ << "EC.cpp" << std::endl
    << "    " << node.basename_ << SVNT_SUFFIX << ".cpp" << std::endl
    << "  }" << std::endl
    << std::endl

    // Generate the header files
    << "  Header_Files {" << std::endl
    << std::endl
    << "  }" << std::endl
    << "}" << std::endl
    << std::endl;
}

//
// generate_stub_listing
//
void CUTS_CIAO_Project_Generator::
generate_stub_listing (std::ofstream & outfile,
                       const CUTS_BE_IDL_Node * node)
{
  IDL_Node_Set::const_iterator iter = this->visited_nodes_.find (node);

  if (iter == this->visited_nodes_.end ())
  {
    this->visited_nodes_.insert (node);

    outfile
      << " \\" << std::endl
      << "    " << node->basename_ << STUB_SUFFIX;

    std::for_each (node->references_.begin (),
                   node->references_.end (),
                   boost::bind (&CUTS_CIAO_Project_Generator::
                                generate_stub_listing,
                                this,
                                boost::ref (outfile),
                                _1));
  }
}

//
// genereate_mpc_i
//
void CUTS_CIAO_Project_Generator::
generate_mpc_i (std::ofstream & outfile,
                const CUTS_BE_Impl_Node & node)
{
  this->generate_mpc_values (outfile, "includes", node.include_paths_);
  this->generate_mpc_values (outfile, "libpaths", node.lib_paths_);
  this->generate_mpc_values (outfile, "libs", node.lib_);
}

//
// generate_mpc_values
//
void CUTS_CIAO_Project_Generator::
generate_mpc_values (std::ofstream & outfile,
                     const std::string & heading,
                     const CUTS_String_Set & listing)
{
  if (listing.empty ())
    return;

  outfile
    << "  " << heading << " +=";

  for (CUTS_String_Set::const_iterator iter = listing.begin ();
       iter != listing.end ();
       iter ++)
  {
    outfile
      << " \\" << std::endl
      << "    " << iter->c_str ();
  }

  outfile
    << std::endl
    << std::endl;
}
