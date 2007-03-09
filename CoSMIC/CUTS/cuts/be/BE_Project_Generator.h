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

#include "BE_export.h"

// Forward decl.
struct CUTS_BE_IDL_Node;

// Forward decl.
struct CUTS_BE_Impl_Node;

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

class CUTS_BE_Export CUTS_BE_Project_Generator
{
public:
  /// Default constructor.
  CUTS_BE_Project_Generator (void);

  /// Destructor.
  virtual ~CUTS_BE_Project_Generator (void);

  /**
   * Generate the project file for a stub project.
   *
   * @param[in]         node        The target node/project.
   * @retval            true        Successfully generated file.
   * @retval            false       Failed to generate file.
   */
  virtual bool write_stub_project (const CUTS_BE_IDL_Node & node);

  /**
   * Generate the project file for a executor project.
   *
   * @param[in]         node        The target node/project.
   * @retval            true        Successfully generated file.
   * @retval            false       Failed to generate file.
   */
  virtual bool write_exec_project (const CUTS_BE_Impl_Node & node);

private:
  // prevent the following operations
  CUTS_BE_Project_Generator (const CUTS_BE_Project_Generator &);
  const CUTS_BE_Project_Generator & operator = (const CUTS_BE_Project_Generator &);
};

#if defined (__CUTS_INLINE__)
#include "BE_Project_Generator.inl"
#endif

#endif  // !defined _CUTS_BE_PROJECT_GENERATOR_H_
