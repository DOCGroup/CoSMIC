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
#include <string>
#include <fstream>

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
                            const CUTS_Dependency_Graph & graph);

  /// Destructor.
  virtual ~CUTS_Workspace_Generator (void);

protected:
  /// Visit the RootFolder of a PICML model.
  void Visit_RootFolder (const PICML::RootFolder &);

  /// Visit the ComponentImplementation of a PICML model.
  void Visit_ComponentImplementations (
    const PICML::ComponentImplementations &);

  /// Visit the ComponentImplementationContainer of a PICML model.
  void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer &);

  /// Vist the MonolithicImplementation of a PICML model.
  void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation &);

  /// Visit the Implements connection of a PICML model.
  void Visit_Implements (const PICML::Implements & implements);

  /// Visit the ComponentRef of a PICML model.
  void Visit_ComponentRef (const PICML::ComponentRef & ref);

  void Visit_Component (const PICML::Component &);

private:
  /// Generates a project for the current component implemenation.
  void generate_component_project (void);

  /// Generate the servant project.
  void generate_svnt_project (void);

  /// Generate the executor project.
  void generate_exec_project (void);

  /**
   * Generate a server project for the node. The project is
   * generated in the location specified in the constructor.
   *
   * @param[in]     node      Target node.
   */
  void generate_stub_project (const CUTS_Dependency_Node * node);

  /// Output directory for the workspace.
  const std::string outdir_;

  /// The source dependency graph.
  const CUTS_Dependency_Graph & graph_;

  /// The dependency node for the component.
  CUTS_Dependency_Node * node_;

  /// Workspace output file stream.
  std::ofstream workspace_;

  /// Project output file stream.
  std::ofstream project_;

  /// Name of the current project.
  std::string project_name_;
};

#endif  // !defined _CUTS_WORKSPACE_GENERATOR_H_
