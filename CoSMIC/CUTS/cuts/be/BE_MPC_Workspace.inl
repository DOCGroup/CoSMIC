// -*- C++ -*-
// $Id$

//
// CUTS_BE_MPC_Workspace
//
CUTS_INLINE
CUTS_BE_MPC_Workspace::CUTS_BE_MPC_Workspace (void)
{

}

//
// ~CUTS_BE_MPC_Workspace
//
CUTS_INLINE
CUTS_BE_MPC_Workspace::~CUTS_BE_MPC_Workspace (void)
{

}

//
// write_project_file
//
CUTS_INLINE
void CUTS_BE_MPC_Workspace::
write_project_file (const std::string & project)
{
  this->outfile_ << "  " << project << ".mpc" << std::endl;
}


//
// write_epilogue
//
CUTS_INLINE
void CUTS_BE_MPC_Workspace::write_epilogue (void)
{
  // Close the output file and return its status.
  this->outfile_ << "}" << std::endl;
}

//
// close_workspace_file
//
CUTS_INLINE
void CUTS_BE_MPC_Workspace::close_workspace_file (void)
{
  this->outfile_.close ();
}
