// -*- C++ -*-

//=============================================================================
/**
 * @class     BE_File_Generator_Manager.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_BE_FILE_GENERATOR_MANAGER_H_
#define _CUTS_BE_FILE_GENERATOR_MANAGER_H_

#include <stack>
#include "Preprocess_Data.h"
#include "BE_File_Generator_Set.h"

//=============================================================================
/**
 * @class CUTS_BE_File_Generator_Manager
 *
 * Manager class for generating files from PICML models.
 */
//=============================================================================

class CUTS_BE_Export CUTS_BE_File_Generator_Manager :
  public PICML::Visitor
{
public:
  /// Default constructor.
  CUTS_BE_File_Generator_Manager (void);

  /**
   * Initialize the file generator manager.
   *
   * @param[in]       outdir      Output directory.
   */
  void init (const std::string & outdir);

  /// Destructor.
  virtual ~CUTS_BE_File_Generator_Manager (void);

  /**
   * Insert a new generator into the manager. Once the generator
   * has been installed into the manager, it manages all its
   * memory.
   *
   * @param[in]     generator     Pointer to the new generator.
   */
  void insert (CUTS_BE_File_Generator * generator);

  /// Remove all the generators from the manager.
  void remove_all (void);

  /**
   * Get the preprocess data.
   *
   * @return    Reference to the preprocess data.
   */
  const CUTS_BE_Preprocess_Data & preprocess_data (void);

protected:
  virtual void Visit_ComponentImplementationContainer (
    const PICML::ComponentImplementationContainer & container);

  virtual void Visit_MonolithicImplementation (
    const PICML::MonolithicImplementation & mono);

  virtual void Visit_Component (
    const PICML::Component & component);

private:
  /// Clear all the component dependent information.
  void clear (void);

  /**
   * Get the factory for the component.
   */
  PICML::ComponentFactory
    get_component_factory (const PICML::Component & component);

  /// Output directory for the manager.
  std::string outdir_;

  /// Preprocess data for the components.
  CUTS_BE_Preprocess_Data ppd_;

  /// Collection of file generators.
  CUTS_BE_File_Generator_Set generators_;

  // prevent the following operations
  CUTS_BE_File_Generator_Manager (const CUTS_BE_File_Generator_Manager &);
  const CUTS_BE_File_Generator_Manager & operator = (const CUTS_BE_File_Generator_Manager &);
};

#if defined (__CUTS_INLINE__)
#include "BE_File_Generator_Manager.inl"
#endif

#endif  // !defined _CUTS_BE_FILE_GENERATOR_MANAGER_H_
