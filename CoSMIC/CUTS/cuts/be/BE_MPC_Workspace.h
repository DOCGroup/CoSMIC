// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_MPC_Workspace.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_MPC_WORKSPACE_H_
#define _CUTS_BE_MPC_WORKSPACE_H_

#include "BE_Workspace_Strategy.h"
#include <fstream>

//=============================================================================
/**
 * @class CUTS_BE_MPC_Workspace
 *
 * Workspace generator for the Makefile Project Creator (MPC)
 * utility.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_MPC_Workspace :
  public CUTS_BE_Workspace_Strategy
{
public:
  /// Default constructor.
  CUTS_BE_MPC_Workspace (void);

  /// Destructor.
  virtual ~CUTS_BE_MPC_Workspace (void);

  /**
   * Open the workspace file for writing. Information about the
   * location of the workspace file, or its name, can be derived
   * from the CUTS_BE_Options singleton.
   *
   * @retval        true        Successfully opened the file.
   * @retval        false       Failed to open file.
   */
  virtual bool open_workspace_file (void);

  /// Write the prologue for the workspace.
  virtual void write_prologue (void);

  /**
   * Include \a filename in the listing of project files.
   *
   * @param[in]     filename    Name of the project file. The
   *                            \a filename does not contains an
   *                            extension.
   */
  virtual void write_project_file (const std::string & filename);

  /// Close the workspace file.
  virtual void close_workspace_file (void);

  /// Write the prologue for the workspace.
  virtual void write_epilogue (void);

private:
  /// Name of the workspace.
  std::string workspace_name_;

  /// Output file stream for the workspace.
  std::ofstream outfile_;
};

#if defined (__CUTS_INLINE__)
#include "BE_MPC_Workspace.inl"
#endif

#endif  // !defined _CUTS_BE_WORKSPACE_H_
