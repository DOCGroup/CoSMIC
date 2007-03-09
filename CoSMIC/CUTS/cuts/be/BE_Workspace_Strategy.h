// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Workspace_Strategy.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_WORKSPACE_STRATEGY_H_
#define _CUTS_BE_WORKSPACE_STRATEGY_H_

#include "BE_export.h"
#include <string>

//=============================================================================
/**
 * @class CUTS_BE_Workspace_Strategy
 *
 * Strategy for generating workspaces in the backend.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Workspace_Strategy
{
public:
  /// Default constructor.
  CUTS_BE_Workspace_Strategy (void);

  /// Destructor.
  virtual ~CUTS_BE_Workspace_Strategy (void);

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

  /// Write the epilogue for the workspace.
  virtual void write_epilogue (void);

  /// Close the workspace file.
  virtual void close_workspace_file (void);

private:
  // prevent the following operations.
  CUTS_BE_Workspace_Strategy (const CUTS_BE_Workspace_Strategy &);

  const CUTS_BE_Workspace_Strategy &
    operator = (const CUTS_BE_Workspace_Strategy &);
};

#if defined (__CUTS_INLINE__)
#include "BE_Workspace_Strategy.inl"
#endif

#endif  // !defined _CUTS_BE_WORKSPACE_STRATEGY_H_
