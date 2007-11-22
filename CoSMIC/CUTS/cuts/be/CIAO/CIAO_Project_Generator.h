// -*- C++ -*-

//=============================================================================
/**
 * @file      CIAO_Project_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_CIAO_PROJECT_GENERATOR_H_
#define _CUTS_BE_CIAO_PROJECT_GENERATOR_H_

#include "UDM_CIAO_Export.h"

#include "cuts/be/BE_Project_Generator.h"
#include "cuts/be/String_Set.h"

#include <iosfwd>
#include <string>

//=============================================================================
/**
 * @class CUTS_CIAO_Project_Generator
 *
 * Project file generator for CIAO projects.
 */
//=============================================================================

class CUTS_CIAO_Project_Generator :
  public CUTS_BE_Project_Generator
{
public:
  /// Default constructor.
  CUTS_CIAO_Project_Generator (void);

  /// Destructor.
  virtual ~CUTS_CIAO_Project_Generator (void);

  // Write the stub project file.
  virtual bool write_stub_project (const CUTS_BE_IDL_Node & node);

  // Write the executor project file.
  virtual bool write_exec_project (const CUTS_BE_Impl_Node & node);

private:
  void generate_exec_project (std::ofstream & out,
                              const CUTS_BE_Impl_Node & node,
                              bool executor_type);

  void generate_svnt_project (std::ofstream & out,
                              const CUTS_BE_Impl_Node & node);

  void generate_skel_project (std::ofstream & out,
                              const CUTS_BE_Impl_Node & node);

  /**
   * Generates a listing of stubs.
   *
   * @param[in]     project     Target project stream.
   * @param[in]     node        Starting node.
   */
  void generate_stub_listing (std::ofstream & project,
                              const CUTS_BE_IDL_Node * node);

  void generate_mpc_i (std::ofstream & project,
                       const CUTS_BE_Impl_Node & node);

  void generate_mpc_values (std::ofstream & project,
                            const std::string & heading,
                            const CUTS_String_Set & listing);

  typedef std::set <const CUTS_BE_IDL_Node *> IDL_Node_Set;

  IDL_Node_Set visited_nodes_;
};

#endif  // !defined _CUTS_BE_CIAO_PROJECT_GENERATOR_H_
