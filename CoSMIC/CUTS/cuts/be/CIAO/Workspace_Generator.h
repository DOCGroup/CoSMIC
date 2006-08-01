// -*- C++ -*-

//=============================================================================
/**
 * @file        Workspace_Generator.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _CUTS_WORKSPACE_GENERATOR_H_
#define _CUTS_WORKSPACE_GENERATOR_H_

#include "PICML/PICML.h"
#include "UDM_CIAO_Export.h"
#include "String_Set.h"
#include <iosfwd>

// Forward decl.
class CUTS_Dependency_Graph;

// Forward decl.
class CUTS_Dependency_Node;

//=============================================================================
/**
 * @class CUTS_Workspace_Generator
 *
 * Makefile, Project and Workspace Creator (MPC) file generator.
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CUTS_Workspace_Generator :
  public PICML::Visitor
{
public:
  /**
   * Constructor.
   *
   * @param[in]       outdir        Output directory.
   * @param[in]       graph         Dependency graph for the project.
   */
  CUTS_Workspace_Generator (const std::string & outdir,
                            CUTS_Dependency_Graph & impls,
                            CUTS_Dependency_Graph & stubs);

  /// Destructor.
  virtual ~CUTS_Workspace_Generator (void);

protected:
  /// Visit the RootFolder of a PICML model.
  void Visit_RootFolder (const PICML::RootFolder &);

private:
  /**
   * Generate the projects for a component implemenation.
   *
   * @param[in]     workspace         Parent workspace output stream.
   * @param[in]     node              Implementation node.
   */
  void generate_component_project (std::ostream & workspace,
                                   CUTS_Dependency_Node * node);

  /**
   * Generate the servant project.
   *
   * @param[in]     outfile         Target output file stream.
   * @param[in]     node            Source node.
   */
  void generate_svnt_project (std::ofstream & outfile,
                              CUTS_Dependency_Node * node);

  /**
   * Generate the executor project.
   *
   * @param[in]     outfile         Target output file stream.
   * @param[in]     node            Source node.
   */
  void generate_exec_project (std::ofstream & outfile,
                              CUTS_Dependency_Node * node);

  /**
   * Generate a server project for the node. The project is
   * generated in the location specified in the constructor.
   *
   * @param[in]     workspace     Target workspace stream.
   * @param[in]     node          Source node.
   */
  void generate_stub_project (std::ofstream & workspace,
                              CUTS_Dependency_Node * node);

  /**
   * Generates a listing of stubs.
   *
   * @param[in]     project     Target project stream.
   * @param[in]     node        Starting node.
   */
  void generate_stub_listing (std::ofstream & project,
                              CUTS_Dependency_Node * node);

  void generate_mpc_i (std::ofstream & project,
                       CUTS_Dependency_Node * node);

  void generate_mpc_values (std::ofstream & project,
                            const std::string & heading,
                            const CUTS_String_Set & listing);

  /// Output directory for the workspace.
  const std::string outdir_;

  /// The implemenation dependency graph.
  CUTS_Dependency_Graph & impls_;

  /// The stub dependency graph.
  CUTS_Dependency_Graph & stubs_;
};

#endif  // !defined _CUTS_WORKSPACE_GENERATOR_H_
