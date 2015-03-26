#include "StdAfx.h"

#include "MPC_Visitor.h"
#include <fstream>

namespace PICML
{
  MPC_Visitor::MPC_Visitor (const std::string & outputPath)
    : outputPath_ (outputPath)
  {

  }

  MPC_Visitor::~MPC_Visitor ()
  {

  }

  void MPC_Visitor::Visit_StubProject (const PICML::StubProject_in stub_proj)
  {

  }

  void MPC_Visitor::Visit_ServantProject (const PICML::ServantProject_in skeleton_proj)
  {

  }

  void MPC_Visitor::Visit_ExecutorProject (const PICML::ExecutorProject_in exec_proj)
  {

  }

  // Visit Component Assembly
  void MPC_Visitor::Visit_MPC (const PICML::MPC_in proj_folder)
  {
	  // Start for interpretation
	  // Step 1: Create Workspace for the projects
    for (PICML::Workspaces workspace : proj_folder->get_Workspacess ())
    {
		  // Step 1: Get the name of the workspace to be generated
      std::string wspace_name = workspace->name ();

		  // Step 2: Write out the header for the workspace
		  // Outputpath refers to a directory
		  // The target file is : <dir> + "\" + fileName + ".cidl"
		  std::string file_name = this->outputPath_ + "\\" + wspace_name + ".mwc";
		  std::ofstream file_stream (file_name.c_str ());

		  MPCStream mpc_stream (file_stream, this->outputPath_);
		  mpc_stream.create_workspace (workspace);
	  }

	  /// Create the individual MPC files for each artifact
	  for (PICML::Project project : proj_folder->get_Projects ())
	  {
		 // Step 1: Get the name of the project file
		  std::string proj_name = project->name ();

		  // Step 2: Write the stub skeleton and executor IDL projects
		  std::string file_name = this->outputPath_ + "\\" + proj_name + ".mpc";
		  std::ofstream file_stream (file_name.c_str ());

		  MPCStream mpc_stream (file_stream, this->outputPath_);
		  mpc_stream.create_project (project);
	  }
  }

}
