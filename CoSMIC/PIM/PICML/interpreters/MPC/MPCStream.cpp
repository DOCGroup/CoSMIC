#include "stdafx.h"
#include "MPCStream.h"
#include "ctype.h"
#include "UdmBase.h"

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

MPCStream::MPCStream (std::ostream& strm, std::string path)
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
    {
		--this->indent_level_;
    }
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
        {
			this->strm_ << "  ";
        }
    }
}

void
MPCStream::create_workspace (const PICML::Workspaces &workspace)
{
	// Write out the header for the workspace
	this->write_mwc_header ();
	this->nl ();
	this->incr_indent ();
	this->indent ();
	
	// Step 2: Get the individual projects in the workspace
	// and write them in order
	std::set<PICML::Project> proj_names = workspace.members ();
	for (std::set<PICML::Project>::iterator iter = proj_names.begin ();
	iter != proj_names.end ();
	iter ++)
	{
		this->nl ();
		this->indent ();
		
		std::string temp;
		(* iter).GetStrValue ("name", temp);
		
		//Write this name in the file
		this->strm_ << temp;
	}
	
	// close workspace
    this->write_mwc_footer ();
}

bool
MPCStream::dependent_project (PICML::ImplementationArtifact &artifact, 
							  std::string &dependent_proj)
{
	// Obtain a list of all dependent artifacts
	const std::set<PICML::ArtifactDependsOn> depends = 
		artifact.dstArtifactDependsOn();
	
	bool ret_val = false; // Flag
	
	// Check if these dependant artifacts are in some Stub_Project
	// if so include them in the after list
	for (std::set<PICML::ArtifactDependsOn>::iterator iter = depends.begin ();
	iter != depends.end ();
	iter ++)
	{
		PICML::ImplementationArtifactReference impl_ref = 
			iter->dstArtifactDependsOn_end();
		try 
		{
			PICML::StubProject proj = impl_ref.StubProject_parent ();
			ret_val = true;
			// Add this to the dependent project
			std::string name;
			proj.GetStrValue ("name", name);
			if (name.size () != 0)
				dependent_proj.append (name);
			else
			{
				PICML::ImplementationArtifact art = impl_ref.ref ();
				art.GetStrValue ("name", name);
				dependent_proj.append (name);
			}
			
			// Add a project separation
			dependent_proj.append (" ");
			
		} catch(udm_exception &)
		{
			// Indicates that this artifact is not present in the
			// folder
			// continue;
		}
	}
	
	return ret_val;
}

void
MPCStream::create_project_defn (std::string& proj_name, std::string root_proj)
{
	// Write out the stub header to the file
	this->strm_ << "project (";
	this->strm_ << proj_name;
	this->strm_ << "): ";
	this->strm_ << root_proj;
	this->strm_ << " {";
	this->nl ();
	
}

void MPCStream::create_after_defn (std::string& dep_proj_name)
{
	// Write the after definitions
    this->incr_indent ();
    this->indent ();
    this->strm_ << "after += ";
	this->strm_ << dep_proj_name;
	this->nl ();
		  
}

void
MPCStream::create_shared_defn (std::string& shared_name)
{
	// Write out the shared lib name 
	this->indent ();
	this->strm_ << "sharedname =";
	this->strm_ << shared_name;
}

void
MPCStream::create_export_defn (std::string& shared_name)
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
MPCStream::create_idl_file_defn (std::vector<std::string>& idl_files)
{
	// Write the IDL files and the Source_files
	this->nl ();
	this->indent ();
	this->strm_ << "IDL_Files {";
	this->nl ();
	this->incr_indent ();
	for (size_t i =0; i < idl_files.size (); i ++)
	{
		this->indent ();
		this->strm_ << idl_files[i];
		this->nl ();
	}
	
	// Close the IDL_Files definition
	this->decr_indent ();
	this->indent ();
	this->strm_ << "}";
}

void
MPCStream::create_dynamic_flags_defn (std::string& shared_name)
{
	//Write out the dynamic flags
	this->nl ();
	this->indent ();
	this->strm_ << "dynamicflags = ";
	this->upcase (shared_name.c_str ());
	this->strm_ << "_BUILD_DLL";
	
}

void
MPCStream::create_source_file_defn (std::vector<std::string>& idl_c_files)
{
	// Write out the Source_Files
	this->nl ();
	this->indent ();
	this->strm_ << "Source_Files {";
	this->nl ();
	this->incr_indent ();
	for (size_t counter =0; counter < idl_c_files.size (); counter ++)
	{
		this->indent ();
		this->strm_ << idl_c_files[counter];
		this->nl ();
	}
	
	// Close the Source_Files definition
	this->decr_indent ();
	this->indent ();
	this->strm_ << "}";
	this->nl ();
	
}

std::string 
MPCStream::skel_export_macro (PICML::Project project)
{
	std::set<PICML::ServantProject> skel = 
		project.ServantProject_kind_children ();
	
	std::string component_name;
	for (std::set<PICML::ServantProject>::iterator iter = skel.begin ();
		 iter != skel.end ();
		 iter ++)
		 {
			 // Obtain the library name -- Name of the artifact 
			PICML::ImplementationArtifactReference art_ref = 
				iter->ImplementationArtifactReference_child();
			PICML::ImplementationArtifact artifact = art_ref.ref ();
	
			artifact.GetStrValue ("name", component_name);
		 }
	return component_name;
}

void
MPCStream::create_export_macro (std::string& shared_name)
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
	command.append (this->output_path_);
	command.append ("\\");
	command.append (shared_name);
	command.append ("_export.h");
	command.append (" 2>&1");
	system (command.c_str ());
}

void
MPCStream::create_stub_definition (const PICML::StubProject &stub)
{
	// Obtain the library name -- Name of the artifact 
	PICML::ImplementationArtifactReference art_ref = 
		stub.ImplementationArtifactReference_child();
	PICML::ImplementationArtifact artifact = art_ref.ref ();
	
	std::string proj_name;
	artifact.GetStrValue ("name", proj_name);
	
	this->stub_project_ = proj_name;
	
	// Write out project header
	this->create_project_defn (proj_name, "ciao_dnc_client");
	
	// Obtain what libraries this depends on -- Name of dependent
	// libraries
	std::string dep_proj_name;
	if (this->dependent_project (artifact, dep_proj_name))
		// Write the after definitions
		this->create_after_defn (dep_proj_name);
	else
		this->incr_indent ();
	
	// Obtain the Library shared name for the project
	std::string shared_name;
	artifact.GetStrValue ("name", shared_name);
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
	std::string &skel_component_name = 
		this->skel_export_macro (stub.Project_parent ());

	this->strm_ << "-Wb,skel_export_macro=";
	this->upcase (skel_component_name.c_str ());
	this->strm_ << "_Export ";
	this->strm_ << "-Wb,skel_export_include=";
	this->strm_ << skel_component_name;
	this->strm_ << "_export.h";
	
	
	//Write out the dynamic flags
	this->create_dynamic_flags_defn (shared_name);
	
	// Write out the IDL files
	std::vector<std::string> idl_files;
	std::vector<std::string> idl_c_files;
	
	std::set<PICML::FileRef> idl_file_ref = stub.FileRef_children ();
	for (std::set<PICML::FileRef>::iterator iter = idl_file_ref.begin ();
	iter != idl_file_ref.end ();
	iter ++)
	{
		PICML::File idl_file = iter->ref ();
		std::string base;
		iter->GetStrValue ("name", base);
		std::string temp = base;
		idl_files.push_back (base.append (".idl"));
		
		// Append the generated file as well
		idl_c_files.push_back (temp.append ("C.cpp"));
	}
	
	// Write the IDL files and the Source_files
	this->create_idl_file_defn (idl_files);
	
	// Write out the Source_Files
	this->create_source_file_defn (idl_c_files);
	
	//Close the project
	this->create_close_proj_defn ();
	
}

void
MPCStream::create_lib_path_defn (std::string& lib_path)
{
	this->nl ();
	this->indent ();
	this->strm_ << "libpaths += ";
	this->strm_ << lib_path;
}

void 
MPCStream::create_cidl_defn (PICML::ImplementationArtifact& artifact)
{
	// Step 1: From the implementation artifact get all the references
	// Obtain the reference that is contained in the Implementations
	// foler
	std::set<PICML::ImplementationArtifactReference> impl_refs = 
		artifact.referedbyImplementationArtifactReference ();
	std::string msg = "Number of refs = " + impl_refs.size ();
	

	bool entered_loop = 0;
	for (std::set<PICML::ImplementationArtifactReference>::iterator iter = 
		impl_refs.begin ();
		iter != impl_refs.end ();
		iter ++)
	{
		try {
			PICML::ComponentImplementationContainer parent = 
				iter->ComponentImplementationContainer_parent();
			// @@ There should only be one Container that should hold
			// a reference to this
			entered_loop = 1;
			
			// Step 2: Obtain the Component name that is present within this
			// Implements folder
			PICML::ComponentImplementation child = parent.ComponentImplementation_child ();
			std::set<PICML::Implements> impls = child.dstImplements();
			
			for (std::set<PICML::Implements>::iterator impl_iter = impls.begin ();
				impl_iter != impls.end ();
				impl_iter ++)
			{
				PICML::ComponentRef type = impl_iter->dstImplements_end();
				
				// Get the name of the ComponentType
				PICML::Component comp = type.ref ();
				
				// Step 3: The name of the cidl will be based on the component idl
				// file name
				std::string name;
				comp.GetStrValue ("name", name);
				std::string message = "Cidl_file_name" + name;
			    this->cidl_file_.push_back (name);
			}
		}catch (udm_exception& )
		{
			
		}
		
	}

	// Step 4: Write out the cidl_files
	this->nl ();
	this->indent ();
	this->strm_ << "CIDL_Files {";
	this->nl ();
	this->incr_indent ();
	for (std::vector<std::string>::iterator cidl_iter = this->cidl_file_.begin ();
		 cidl_iter != this->cidl_file_.end ();
		 cidl_iter ++)
		{
			this->indent ();
			this->strm_ << (* cidl_iter);
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
MPCStream::create_skeleton_definition (const PICML::ServantProject &skel)
{
	// Obtain the library name -- Name of the artifact 
	PICML::ImplementationArtifactReference art_ref = 
		skel.ImplementationArtifactReference_child();
	PICML::ImplementationArtifact artifact = art_ref.ref ();
	
	std::string proj_name;
	artifact.GetStrValue ("name", proj_name);
	
	this->servant_project_ = proj_name;
	
	this->create_project_defn (proj_name, "ciao_dnc_servant");
	
	// Obtain what libraries this depends on -- Name of dependent
	// libraries
	std::string dep_proj_name = this->stub_project_;
	this->dependent_project (artifact, dep_proj_name);
	this->create_after_defn (dep_proj_name);
	
	// Obtain the Library shared name for the project
	std::string shared_name;
	artifact.GetStrValue ("name", shared_name);
	this->create_shared_defn (shared_name);
	
	// Write out name for the idlflag
	this->create_export_defn (shared_name);

	// Generate the export_file for windows based
	// platform
	this->create_export_macro (shared_name);
	
	// Add dependent library paths
	std::string path_name;
	artifact.GetStrValue ("libpaths", path_name);
	if (path_name.size () != 0)
		this->create_lib_path_defn (path_name);
	
	// Write out the dynamic flags
	this->create_dynamic_flags_defn (shared_name);
	
	// Write out CIDL file definitions
	this->create_cidl_defn (artifact);

	// Write out the IDL files generated by the cidl compiler
	std::vector<std::string> idl_file_names;
	std::vector<std::string> source_file_names;

	for (std::vector<std::string>::iterator iter = this->cidl_file_.begin ();
	     iter != this->cidl_file_.end ();
		 iter ++)
		 {
			 idl_file_names.push_back ((*iter) + "E.idl");
			 source_file_names.push_back ((* iter) + "EC.cpp");
			 source_file_names.push_back ((* iter) + "S.cpp");
			 source_file_names.push_back ((* iter) + "_svnt.cpp");
		 }

	// Write out the IDL file definitions
	this->create_idl_file_defn (idl_file_names);

	// Write out the Source file definitions
	this->create_source_file_defn (source_file_names);

	// Close Project files
	this->create_close_proj_defn ();
}

void
MPCStream::create_executor_definition (const PICML::ExecutorProject& exec)
{
	// Obtain the library name -- Name of the artifact 
	PICML::ImplementationArtifactReference art_ref = 
		exec.ImplementationArtifactReference_child();
	PICML::ImplementationArtifact artifact = art_ref.ref ();
	
	std::string proj_name;
	artifact.GetStrValue ("name", proj_name);
	
	this->create_project_defn (proj_name, "ciao_dnc_component");
	
	// Write out the after += definition
	this->create_after_defn (this->servant_project_);
	
	// Write out the shared name for the project
	std::string shared_name;
	artifact.GetStrValue ("name", shared_name);
	this->create_shared_defn (shared_name);
	
	// Write out idl_flags +=
	this->create_export_defn (shared_name);

	// Generate the export_file for windows based
	// platform
	this->create_export_macro (shared_name);
	
	// Write out the dynamic flags
	this->create_dynamic_flags_defn (shared_name);
	
	// Add dependent library paths
	std::string path_name;
	artifact.GetStrValue ("libpaths", path_name);
	if (path_name.size () != 0)
		this->create_lib_path_defn (path_name);
	
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
MPCStream::create_project (const PICML::Project &project)
{
	// For each project generate the stub, skel and exec part
	
	// Step 1: Generating the stub part --> Obtain dependencies
	std::set<PICML::StubProject> stub = project.StubProject_kind_children ();
	
	// There should only be one project -- Constraint checked via constraints
	assert (stub.size () == 1);
	std::set<PICML::StubProject>::iterator stub_iter = stub.begin ();
	this->create_stub_definition (* stub_iter);
	
	// Step 2: Generating the skeleton part --> Depends on stub project
	std::set<PICML::ServantProject> skel = project.ServantProject_kind_children ();
	
	// There should only be one project -- Constraint checked via constraints
	assert (skel.size () == 1);
	std::set<PICML::ServantProject>::iterator skel_iter = skel.begin ();
	this->create_skeleton_definition (* skel_iter);	
	
	// Step 3: Generating the executor part --> Depends on this skeleton and
	// External libraries if any
	std::set<PICML::ExecutorProject> exec = project.ExecutorProject_kind_children ();
	
	// There should only be one project -- Constraint checked via constraints
	assert (exec.size () == 1);
	std::set<PICML::ExecutorProject>::iterator exec_iter = exec.begin ();
	this->create_executor_definition (* exec_iter);	
	
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
MPCStream::operator<< (const std::string &s)
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
MPCStream::operator<< (const unsigned long &ul)
{
	this->strm_ << ul;
	return *this;
}

MPCStream &
MPCStream::operator<< (const double &d)
{
	this->strm_ << d;
	return *this;
}

MPCStream &
MPCStream::operator<< (const char &c)
{
	this->strm_ << c;
	return *this;
}

MPCStream &
MPCStream::operator<< (const NL&)
{
	(void) this->nl ();
	return *this;
}

MPCStream &
MPCStream::operator<< (const INDENT& i)
{
	this->incr_indent (0);
	
	if (i.do_now_)
    {
		(void) this->nl ();
    }
	
	return *this;
}

MPCStream &
MPCStream::operator<< (const UNINDENT& i)
{
	this->decr_indent (0);
	
	if (i.do_now_)
    {
		this->nl ();
    }
	
	return *this;
}

void
MPCStream::upcase (const char *str)
{
	int i = 0;
	char c;
	
	while ((c = str[i++]) != '\0')
    {
		this->strm_ << static_cast<char> (toupper (c));
    }
}

