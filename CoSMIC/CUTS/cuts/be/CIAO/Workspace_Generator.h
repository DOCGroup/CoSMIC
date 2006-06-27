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
#include <iosfwd>

// Forward decl.
class CUTS_Dependency_Graph;
class CUTS_Dependency_Node;

//=============================================================================
/**
 * @class CUTS_Workspace_Generator
 */
//=============================================================================

class CUTS_UDM_CIAO_Export CUTS_Workspace_Generator : public PICML::Visitor
{
public:
  CUTS_Workspace_Generator (const std::string & outdir,
                            const CUTS_Dependency_Graph & graph);

  /// Destructor.
  virtual ~CUTS_Workspace_Generator (void);

protected:
  /// Visit the RootFolder of a PICML model.
  void Visit_RootFolder (const PICML::RootFolder &);

private:
  /// Generete the workspace for the dependency graph.
  void generate_workspace (std::ofstream &,
                           const std::string &);

  /// Generate the projects based on the dependency graph.
  void generate_project (std::ofstream &,
                         const CUTS_Dependency_Node *);

  void generate_stub_project (std::ofstream &,
                              const CUTS_Dependency_Node *);

  void generate_svnt_project (std::ofstream &,
                              const CUTS_Dependency_Node *);

  void generate_exec_project (std::ofstream &,
                              const CUTS_Dependency_Node *);

  /// Output directory for the workspace.
  const std::string outdir_;

  /// The source dependency graph.
  const CUTS_Dependency_Graph & graph_;
};

#endif  // !defined _CUTS_WORKSPACE_GENERATOR_H_
