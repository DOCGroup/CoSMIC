#include "StdAfx.h"

#include "MPCStream.h"
#include <ctype.h>
#include <algorithm>
#include <cassert>

NL::NL (void)
{
}

INDENT::INDENT (int do_now)
:  do_now_ (do_now)
{
}

UNINDENT::UNINDENT (int do_now)
:  do_now_ (do_now)
{
}

const NL nl;
const INDENT idt;
const INDENT idt_nl (1);
const UNINDENT uidt;
const UNINDENT uidt_nl (1);

MPCStream::MPCStream (std::ostream & strm, std::string path)
: strm_ (strm),
  output_path_ (path),
  indent_level_ (0)
{
}

MPCStream::~MPCStream (void)
{
}

void
MPCStream::incr_indent (unsigned short flag)
{
  ++indent_level_;
}

// Indentation
void
MPCStream::decr_indent (unsigned short flag)
{
  if (this->indent_level_ > 0)
    --this->indent_level_;
}

void
MPCStream::reset (void)
{
  this->indent_level_ = 0;
}

// Indented print.
void
MPCStream::indent (void)
{
  // Based on the current indentation level, leave appropriate number of blank
  // spaces in the output.
  if (this->indent_level_ > 0)
  {
    for (int i = 0; i < this->indent_level_; ++i)
      this->strm_ << "  ";
  }
}

void
MPCStream::create_workspace (const PICML::Workspaces_in workspace)
{
  // Write out the header for the workspace
  this->write_mwc_header ();
  this->nl ();
  this->incr_indent ();
  this->indent ();

  // Step 2: Get the individual projects in the workspace
  // and write them in order
  for (auto project : workspace->members_Project ())
  {
    this->nl ();
    this->indent ();

    //Write this name in the file
    this->strm_ << project->name ();
  }

  // close workspace
  this->write_mwc_footer ();
}

bool
MPCStream::dependent_project (PICML::ImplementationArtifact_in artifact,
                              std::string & dependent_proj)
{
  bool ret_val = false; // Flag

  // Check if these dependant artifacts are in some Stub_Project
  // if so include them in the after list
  for (PICML::ArtifactDependsOn dependency : artifact->src_of_ArtifactDependsOn ())
  {
    PICML::ImplementationArtifactReference impl_ref =
      dependency->dst_ImplementationArtifactReference ();

    try
    {
      PICML::StubProject proj = impl_ref->parent_StubProject ();
      ret_val = true;
      // Add this to the dependent project
      std::string name = proj->name ();

      if (name.size () != 0)
        dependent_proj.append (name);
      else
      {
        PICML::ImplementationArtifact art = impl_ref->refers_to ();
        name = art->name ();
        dependent_proj.append (name);
      }

      // Add a project separation
      dependent_proj.append (" ");
    }
    catch (GAME::Mga::Exception &)
    {
      // Indicates that this artifact is not present in the
      // folder
      // continue;
    }
  }

  return ret_val;
}

void
MPCStream::create_project_defn (std::string & proj_name, std::string root_proj)
{
  // Write out the stub header to the file
  this->strm_ << "project (";
  this->strm_ << proj_name;
  this->strm_ << "): ";
  this->strm_ << root_proj;
  this->strm_ << " {";
  this->nl ();

}

void MPCStream::create_after_defn (std::string & dep_proj_name)
{
  // Write the after definitions
  this->incr_indent ();
  this->indent ();
  this->strm_ << "after += ";
  this->strm_ << dep_proj_name;
  this->nl ();

}

void
MPCStream::create_shared_defn (std::string & shared_name)
{
  // Write out the shared lib name
  this->indent ();
  this->strm_ << "sharedname =";
  this->strm_ << shared_name;
}

void
MPCStream::create_export_defn (std::string & shared_name)
{
  this->nl ();
  this->indent ();
  this->strm_ << "idlflags += ";
  this->strm_ << "-Wb,export_macro=";
  this->upcase (shared_name.c_str ());
  this->strm_ << "_Export ";
  this->strm_ << "-Wb,export_include=";
  this->strm_ << shared_name;
  this->strm_ << "_export.h ";

}

void
MPCStream::create_close_proj_defn ()
{
  // Project files
  this->nl ();
  this->decr_indent ();
  this->strm_ << "}";
  this->nl ();
}

void
MPCStream::create_idl_file_defn (std::vector <std::string> & idl_files)
{
  // Write the IDL files and the Source_files
  this->nl ();
  this->indent ();
  this->strm_ << "IDL_Files {";
  this->nl ();
  this->incr_indent ();
  for (std::string & idl_file : idl_files)
  {
    this->indent ();
    this->strm_ << idl_file;
    this->nl ();
  }

  // Close the IDL_Files definition
  this->decr_indent ();
  this->indent ();
  this->strm_ << "}";
}

void
MPCStream::create_dynamic_flags_defn (std::string & shared_name)
{
  //Write out the dynamic flags
  this->nl ();
  this->indent ();
  this->strm_ << "dynamicflags = ";
  this->upcase (shared_name.c_str ());
  this->strm_ << "_BUILD_DLL";

}

void
MPCStream::create_source_file_defn (std::vector <std::string> & idl_c_files)
{
  // Write out the Source_Files
  this->nl ();
  this->indent ();
  this->strm_ << "Source_Files {";
  this->nl ();
  this->incr_indent ();
  for (std::string & idl_c_file : idl_c_files)
  {
    this->indent ();
    this->strm_ << idl_c_file;
    this->nl ();
  }

  // Close the Source_Files definition
  this->decr_indent ();
  this->indent ();
  this->strm_ << "}";
  this->nl ();

}

std::string
MPCStream::skel_export_macro (PICML::Project_in project)
{
  std::string component_name;
  for (auto skel : project->get_ServantProjects ())
  {
    // Obtain the library name -- Name of the artifact
    component_name = skel->get_ImplementationArtifactReference ()->refers_to ()->name ();
  }

  return component_name;
}

void
MPCStream::create_export_macro (std::string & shared_name)
{
  // Generate the stub export file name as well
  std::string command = "generate_export_file.pl -s ";

  // Convert the export to upper case
  const char* str = shared_name.c_str ();
  int i = 0;
  char c;

  while ((c = str[i++]) != '\0')
  {
    command += toupper (c);
  }

  // Redirect to required file
  command.append (" > ");

  // The output path should be within quotes otherwise it is going to crib if
  // the output directory has spaces in it somewhere
  command.append ("\"");
  command.append (this->output_path_);
  command.append ("\"");

  command.append ("\\");
  command.append (shared_name);
  command.append ("_export.h");
  command.append (" 2>&1");
  system (command.c_str ());
}

void
MPCStream::create_stub_definition (const PICML::StubProject_in stub)
{
  // Obtain the library name -- Name of the artifact
  std::string proj_name;
  PICML::ImplementationArtifact artifact = stub->get_ImplementationArtifactReference ()->refers_to ();
  proj_name = artifact->name ();

  this->stub_project_ = proj_name;

  // Write out project header
  this->create_project_defn (proj_name, "ciao_client_dnc");

  // Obtain what libraries this depends on -- Name of dependent
  // libraries
  std::string dep_proj_name;
  if (this->dependent_project (artifact, dep_proj_name))
    // Write the after definitions
    this->create_after_defn (dep_proj_name);
  else
    this->incr_indent ();

  // Obtain the Library shared name for the project
  std::string shared_name = artifact->name ();
  this->create_shared_defn(shared_name);

  // Write out IDL-Flags Definition
  this->nl ();
  this->indent ();
  this->strm_ << "idlflags += ";
  this->strm_ << "-Wb,stub_export_macro=";
  this->upcase (shared_name.c_str ());
  this->strm_ << "_Export ";
  this->strm_ << "-Wb,stub_export_include=";
  this->strm_ << shared_name;
  this->strm_ << "_export.h ";

  // Generate the export_file for windows based
  // platform
  this->create_export_macro (shared_name);

  // Obtain the Skeleton Export Macros
  std::string & skel_component_name =
    this->skel_export_macro (stub->parent_Project ());

  this->strm_ << "-Wb,skel_export_macro=";
  this->upcase (skel_component_name.c_str ());
  this->strm_ << "_Export ";
  this->strm_ << "-Wb,skel_export_include=";
  this->strm_ << skel_component_name;
  this->strm_ << "_export.h";


  //Write out the dynamic flags
  this->create_dynamic_flags_defn (shared_name);

  // Write out the IDL files
  std::vector<std::string> idl_c_files;
  std::vector<std::string> idl_files;

  PICML::FileRef idl_file_ref = stub->get_FileRef ();
  PICML::File idl_file = idl_file_ref->refers_to ();
  std::string base = idl_file->name ();
  std::string temp = base;

  this->idl_files_.push_back (base);
  idl_files.push_back (base.append (".idl"));

  // Append the generated file as well
  idl_c_files.push_back (temp.append ("C.cpp"));

  // Write the IDL files and the Source_files
  this->create_idl_file_defn (idl_files);

  // Write out the Source_Files
  this->create_source_file_defn (idl_c_files);

  //Close the project
  this->create_close_proj_defn ();
}

void
MPCStream::create_lib_path_defn (std::string & lib_path)
{
  this->nl ();
  this->indent ();
  this->strm_ << "libpaths += ";
  this->strm_ << lib_path;
}


void
MPCStream::create_dependant_libs_defn (std::vector <std::string> & lib_list)
{
  // @@ The problem here could be when using static libraries, where the ordering
  // of the libraries are needed to build the artifact. In fact the ordering needs
  // to be preserved. Here our approach sorts the libraries, so this ordering may
  // be lost. In fact, there may not be a way to get the ordering from the modeling
  // tool that depicts the libraries. As there is no notion of ordering there.

  this->nl ();
  this->indent ();
  this->strm_ << "libs += ";

  /// Print out unique elements in the array
  // 1: Step 1: Sort the elements in the array
  std::sort (lib_list.begin (), lib_list.end ());

  // 2: Remove all the unique elements from the array
  lib_list.erase (std::unique (lib_list.begin (), lib_list.end ()), lib_list.end ());

  // 3: Copy this to the output file
  std::copy (lib_list.begin (), lib_list.end (),
    std::ostream_iterator <std::string> (this->strm_, " "));
}

void
MPCStream::create_cidl_defn (PICML::ImplementationArtifact_in artifact)
{
  // Step 1: From the implementation artifact get all the references
  // Obtain the reference that is contained in the Implementations
  // foler

  auto impl_refs = artifact->referenced_by ();

  bool entered_loop = 0;
  for (auto artifact_ref : impl_refs)
  {

    try
    {
      PICML::ComponentImplementationContainer parent = artifact_ref->parent ();

      // @@ There should only be one Container that should hold
      // a reference to this
      entered_loop = 1;

      // Step 2: Obtain the Component name that is present within this
      // Implements folder
      auto children = parent->get_MonolithprimaryArtifacts ();

      if (children.count ())
      {
        PICML::ComponentImplementation ci = *children.begin ();

        std::vector <PICML::Implements> impls;
        ci->src_of_Implements (impls);

        PICML::ComponentRef type = impls[0]->dst_ComponentRef ();

        // Get the name of the ComponentType
        PICML::Component comp = type->refers_to ();

        // Step 3: The name of the cidl will be based on the component idl
        // file name
        std::string name = comp->name ();

        std::string message = "Cidl_file_name" + name;
        this->cidl_file_.push_back (name);
      }
    }
    catch (GAME::Mga::Exception & )
    {

    }

  }

  // Step 4: Write out the cidl_files
  this->nl ();
  this->indent ();
  this->strm_ << "CIDL_Files {";
  this->nl ();
  this->incr_indent ();
  for (std::string & cidl_entry : this->cidl_file_)
  {
    this->indent ();
    this->strm_ << (cidl_entry);
    //@@ Need to check for command line arguments to the cidl file
    // if any
    this->strm_ << ".cidl";
    this->nl ();
  }

  // Close the Cidl file
  this->decr_indent ();
  this->indent ();
  this->strm_<< "}";
  this->nl ();
}

void
MPCStream::create_skeleton_definition (const PICML::ServantProject_in skel, bool exec_not_present)
{
  // Obtain the library name -- Name of the artifact
  PICML::ImplementationArtifact artifact = skel->get_ImplementationArtifactReference ()->refers_to ();

  std::string proj_name = artifact->name ();

  this->servant_project_ = proj_name;

  /// Check if File ref is present
  PICML::FileRef file_ref = skel->get_FileRef ();

  this->create_project_defn (proj_name, "ciao_servant_dnc");

  // Obtain what libraries this depends on -- Name of dependent
  // libraries
  std::string dep_proj_name = this->stub_project_;
  this->dependent_project (artifact, dep_proj_name);
  this->create_after_defn (dep_proj_name);

  // Obtain the Library shared name for the project
  std::string shared_name = artifact->name ();

  // Write out name for the idlflag
  this->create_export_defn (shared_name);

  // Generate the export_file for windows based
  // platform
  this->create_export_macro (shared_name);

  // Identify the dependent libraries and
  // generate the lib+= definition

  std::vector <PICML::ArtifactDependsOn> dep_list;
  artifact->src_of_ArtifactDependsOn (dep_list);

  /// Obtain the dependecy names from the list
  std::vector<std::string> &lib_list =
    this->generate_dependant_libs (dep_list);

  /// Add the dependency path to the list
  // @@ Hard coded: Need to be configured via
  // configuration files
  if (dep_list.size ())
  {
    std::string path_name = "$ACE_ROOT/lib";
    this->create_lib_path_defn (path_name);
  }

  /// Add the lib += definition to the list
  this->create_dependant_libs_defn (lib_list);

  // Write out the dynamic flags
  this->create_dynamic_flags_defn (shared_name);

  std::vector<std::string> source_file_names;

  // check if the executor project is also present; if
  // so then create the cidl files
  if (exec_not_present)
  {
    // Write out the source file definitions
    for (std::string idl_file : this->idl_files_)
      source_file_names.push_back (idl_file + "S.cpp");
  }
  else
  {
    // Write out CIDL file definitions
    this->create_cidl_defn (artifact);

    // Write out the IDL files generated by the cidl compiler
    std::vector <std::string> idl_file_names;

    for (std::string cidl_file : this->cidl_file_)
    {
      idl_file_names.push_back (cidl_file + "E.idl");
      source_file_names.push_back (cidl_file + "EC.cpp");
      source_file_names.push_back (cidl_file + "S.cpp");
      source_file_names.push_back (cidl_file + "_svnt.cpp");
    }

    // Write out the IDL file definitions
    this->create_idl_file_defn (idl_file_names);
  }

  // Write out the Source file definitions
  this->create_source_file_defn (source_file_names);

  // Close Project files
  this->create_close_proj_defn ();
}

std::vector<std::string>
MPCStream::generate_dependant_libs (std::vector <PICML::ArtifactDependsOn> art_deps)
{
  std::vector <std::string> return_list;

  // Stopping Criteria for the function
  if (! art_deps.size ())
    return return_list;

  for (PICML::ArtifactDependsOn dep : art_deps)
  {
    // Get the implementation artifact
    PICML::ImplementationArtifact artifact = dep->dst_ImplementationArtifactReference ()->refers_to ();

    // Get the name of the Artifact -- Add to dependency list
    std::string name = artifact->name ();
    return_list.push_back (name);

    /// Generate the dependencies of this artifact
    std::vector <PICML::ArtifactDependsOn> artifact_dependencies;
    artifact->src_of_ArtifactDependsOn (artifact_dependencies);

    // Get the destination reference
    std::vector <std::string> & depends_names =
      this->generate_dependant_libs (artifact_dependencies);

    for (std::string & name : depends_names)
      return_list.push_back (name);
  }

  // Return dependancy list
  return return_list;
}

void
MPCStream::create_executor_definition (const PICML::ExecutorProject_in exec)
{
  // Obtain the library name -- Name of the artifact
  PICML::ImplementationArtifact artifact = exec->get_ImplementationArtifactReference ()->refers_to ();

  std::string proj_name = artifact->name ();

  this->create_project_defn (proj_name, "ciao_component_dnc");

  // Write out the after += definition
  this->create_after_defn (this->servant_project_);

  // Write out the shared name for the project
  std::string shared_name = artifact->name ();
  this->create_shared_defn (shared_name);

  // Write out idl_flags +=
  this->create_export_defn (shared_name);

  // Generate the export_file for windows based
  // platform
  this->create_export_macro (shared_name);

  // Write out the dynamic flags
  this->create_dynamic_flags_defn (shared_name);

  // Identify the dependent libraries and
  // generate the lib+= definition
  std::vector <PICML::ArtifactDependsOn> dep_list;
  artifact->src_of_ArtifactDependsOn (dep_list);

  /// Obtain the dependecy names from the list
  std::vector<std::string> &lib_list =
    this->generate_dependant_libs (dep_list);

  /// Add the dependency path to the list
  // @@ Hard coded: Need to be configured via
  // configuration files
  if (dep_list.size ())
  {
    std::string path_name = "$ACE_ROOT/lib";
    this->create_lib_path_defn (path_name);
  }

  /// Add the lib += definition to the list
  this->create_dependant_libs_defn (lib_list);

  // Write out the IDL files
  std::vector<std::string> idl_files;
  std::vector<std::string> source_files;

  // Add the exec implementation file name as well
  // @@ Would depend on how cidl compiler is going to generate the dummy
  // implementation
  source_files.push_back (proj_name + ".cpp");

  // Write out the IDL and source files
  this->create_idl_file_defn (idl_files);
  this->create_source_file_defn (source_files);

  // Close Project files
  this->create_close_proj_defn ();
}

void
MPCStream::create_project (const PICML::Project_in project)
{
  // For each project generate the stub, skel and exec part

  // Step 1: Generating the stub part --> Obtain dependencies
  auto stub = project->get_StubProjects ();

  // There should only be one project -- Constraint checked via constraints
  assert (stub.count () == 1);
  this->create_stub_definition (*stub.begin ());

  // Step 2: Generating the skeleton part --> Depends on stub project
  auto skel = project->get_ServantProjects ();

  // There should be atmost one project -- Constraint checked via constraints
  assert (skel.count () <= 1);

  // If there is an executor project modeled, then CIDL files should be generated
  // for the servant. Otherwise it should be a plain vanilla servant.
  auto exec = project->get_ExecutorProjects ();

  // There should be atmost one project -- Constraint checked via constraints
  assert (exec.count () <= 1);
  if (skel.count ())
    this->create_skeleton_definition (*skel.begin (), (exec.count () == 0));

  // Step 3: Generating the executor part --> Depends on this skeleton and
  // External libraries if any
  if (exec.count ())
    this->create_executor_definition (*exec.begin ());

}

void
MPCStream::write_mwc_footer ()
{
  this->nl ();
  this->decr_indent ();
  this->strm_ << "}";
    this->nl ();
}

void
MPCStream::write_mwc_header ()
{
  this->strm_ << "workspace { ";
}

void
MPCStream::nl (void)
{
  this->strm_ << std::endl;
}

MPCStream &
MPCStream::operator<< (const std::string & s)
{
  this->strm_ << s.c_str ();
  return *this;
}

MPCStream &
MPCStream::operator<< (const char *str)
{
  this->strm_ << str;
  return *this;
}

MPCStream &
MPCStream::operator<< (const long &l)
{
  this->strm_ << l;
  return *this;
}

MPCStream &
MPCStream::operator<< (const unsigned long & ul)
{
  this->strm_ << ul;
  return *this;
}

MPCStream &
MPCStream::operator<< (const double & d)
{
  this->strm_ << d;
  return *this;
}

MPCStream &
MPCStream::operator<< (const char & c)
{
  this->strm_ << c;
  return *this;
}

MPCStream &
MPCStream::operator<< (const NL & )
{
  (void) this->nl ();
  return *this;
}

MPCStream &
MPCStream::operator<< (const INDENT & i)
{
  this->incr_indent (0);

  if (i.do_now_)
    (void) this->nl ();

  return *this;
}

MPCStream &
MPCStream::operator<< (const UNINDENT & i)
{
  this->decr_indent (0);

  if (i.do_now_)
    this->nl ();

  return *this;
}

void
MPCStream::upcase (const char * str)
{
  int i = 0;
  char c;

  while ((c = str[i++]) != '\0')
    this->strm_ << static_cast<char> (toupper (c));

}
