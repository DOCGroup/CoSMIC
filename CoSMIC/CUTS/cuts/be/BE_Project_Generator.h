// -*- C++ -*-

//=============================================================================
/**
 * @file      BE_Project_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_PROJECT_GENERATOR_H_
#define _CUTS_BE_PROJECT_GENERATOR_H_

#include "BE_File_Generator_Manager.h"

// Forward decl.
class CUTS_BE_File_Generator;

// Forward decl.
class CUTS_BE_Preprocess_Data;

// Forward decl.
struct CUTS_BE_IDL_Node;

//=============================================================================
/**
 * @class CUTS_BE_Project_Generator
 *
 * Base class for project file generators. This class provides two
 * methods for generating projects. The first method is using the
 * visitor pattern for PICML. The second method is by explicity
 * invoking the write_project () method. The former method allows
 * control to be passed to the CUTS_BE_File_Generator_Manager for the
 * project generator to generate the necessary source files. The
 * latter method will only generate the project file, and none of
 * the source files.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_Project_Generator :
  public PICML::Visitor
{
public:
  /// Destructor.
  virtual ~CUTS_BE_Project_Generator (void);

  /**
   * Signal to begin writing the project.
   *
   * @param[in]       container       Starting container.
   * @param[in]       ppd             Preprocess data for the container.
   */
  virtual void write_project (
    const PICML::ComponentImplementationContainer & container,
    const CUTS_BE_Preprocess_Data & ppd) = 0;

  /**
   * Write the project for a specific IDL node.
   *
   * @param[in]       node            Pointer to the source node.
   * @retval          true            Succeed to write file.
   * @retval          false           Failure to write file.
   */
  virtual bool write_project (CUTS_BE_IDL_Node * node) = 0;

protected:
  /// Default constructor.
  CUTS_BE_Project_Generator (void);

  /// Collection of file generators.
  CUTS_BE_File_Generator_Manager manager_;

private:
  /// Visit a ComponentImplementationContainer object.
  void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer &);

  /// Visit a MonolithicImplemenation object
  void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation &);

  /// Visit a Implements object.
  void Visit_Implements (
    const PICML::Implements &);

  /// Visit a Component object.
  void Visit_Component (
    const PICML::Component &);

  // prevent the following operations
  CUTS_BE_Project_Generator (const CUTS_BE_Project_Generator &);
  const CUTS_BE_Project_Generator & operator = (const CUTS_BE_Project_Generator &);
};

#if defined (__CUTS_INLINE__)
#include "BE_Project_Generator.inl"
#endif

#endif  // !defined _CUTS_BE_PROJECT_GENERATOR_H_
