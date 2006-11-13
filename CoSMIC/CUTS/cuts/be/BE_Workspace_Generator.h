// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Workspace_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_WORKSPACE_GENERATOR_H_
#define _CUTS_BE_WORKSPACE_GENERATOR_H_

#include "BE_export.h"
#include "PICML/PICML.h"
#include <fstream>
#include <memory>

// Forward decl.
class CUTS_BE_Project_Generator;

// Forward decl.
struct CUTS_BE_IDL_Node;

//=============================================================================
/**
 * @class CUTS_BE_Workspace_Generator
 *
 * Visitor that will generate all workspace files in a project. This
 * includes all source and build files.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Workspace_Generator :
  public PICML::Visitor
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     project     Project generator.
   */
  CUTS_BE_Workspace_Generator (CUTS_BE_Project_Generator * project);

  /// Destructor.
  virtual ~CUTS_BE_Workspace_Generator (void);

protected:
  /// Visit a RootFolder object.
  void Visit_RootFolder (
    const PICML::RootFolder &);

  /// Visit a ComponentImplementations object.
  void Visit_ComponentImplementations (
    const PICML::ComponentImplementations &);

  /// Visit a ComponentImplementationContainer object.
  void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer &);

  void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation &);

  void Visit_Component (
    const PICML::Component &);

private:
  /// Method for writing a specific IDL project.
  void write_project (CUTS_BE_IDL_Node * node);

  /// Implementation of the write_project method.
  void write_project_i (CUTS_BE_IDL_Node * node);

  /// Target project generator.
  std::auto_ptr <CUTS_BE_Project_Generator> project_;

  /// Workspace output file stream.
  std::ofstream workspace_;

  /// Flag specifying if current component is a CoWorkEr.
  bool coworker_;

  // prevent the following operations
  CUTS_BE_Workspace_Generator (const CUTS_BE_Workspace_Generator &);
  const CUTS_BE_Workspace_Generator & operator = (const CUTS_BE_Workspace_Generator &);
};

#endif  // !defined _CUTS_BE_WORKSPACE_GENERATOR_H_
