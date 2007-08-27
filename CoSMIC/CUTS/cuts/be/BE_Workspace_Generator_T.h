// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Workspace_Generator_T.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_WORKSPACE_GENERATOR_H_
#define _CUTS_BE_WORKSPACE_GENERATOR_H_

#include <iosfwd>
#include <vector>
#include "String_Set.h"

// Forward decl.
class CUTS_BE_Preprocessor;

// Forward decl.
struct CUTS_BE_Impl_Node;

// Forward decl.
struct CUTS_BE_IDL_Node;

//=============================================================================
/**
 * @class CUTS_BE_Workspace_Generator_T
 *
 * Workspace generator for backends. This used the Makefile, Project, and
 * Workspace Creator format for generation. When generating the project
 * files, it pass control the trait. If the project file is successfully
 * generated, then it is included in the workspace.
 */
//=============================================================================

template <typename WORKSPACE_STRATEGY, typename PROJ_STRATEGY>
class CUTS_BE_Workspace_Generator_T
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     project     Project generator.
   */
  CUTS_BE_Workspace_Generator_T (void);

  /// Destructor.
  virtual ~CUTS_BE_Workspace_Generator_T (void);

  /**
   * Generate the workspace for a collection of preprocessed data. This
   * will generate the workspaces for all the stub and implementations
   * projects.
   *
   * @param[in]     processor       Data source.
   */
  bool generate (void);

protected:
  void generate_impl_project (const CUTS_BE_Impl_Node * node);

  void generate_stub_project (const CUTS_BE_IDL_Node * node);

private:
  /// The workspace generator strategy.
  WORKSPACE_STRATEGY workspace_generator_;

  /// Project generator for this workspace.
  PROJ_STRATEGY proj_generator_;

  /// Type definition for visited nodes.
  typedef std::set <const CUTS_BE_IDL_Node *> IDL_Node_Set;

  /// Collection of visited nodes.
  IDL_Node_Set visited_nodes_;

  /// Collection of stubs that need to be generated.
  IDL_Node_Set required_stubs_;

  /// Collection of project files.
  CUTS_String_Set project_files_;

  // prevent the following operations
  CUTS_BE_Workspace_Generator_T (
    const CUTS_BE_Workspace_Generator_T &);

  const CUTS_BE_Workspace_Generator_T &
    operator = (const CUTS_BE_Workspace_Generator_T &);
};

#include "BE_Workspace_Generator_T.cpp"

#endif  // !defined _CUTS_BE_WORKSPACE_GENERATOR_H_
