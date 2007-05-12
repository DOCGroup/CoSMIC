// -*- C++ -*-

//=============================================================================
/**
 * @file      CoWorkEr_Generator.h
 *
 * $Id$
 *
 * @author    James H. Hill
 */
//=============================================================================

#ifndef _CUTS_COWORKER_GENERATOR_H_
#define _CUTS_COWORKER_GENERATOR_H_

#include "BE_export.h"
#include "PICML/PICML.h"

//=============================================================================
/**
 * @class CUTS_CoWorkEr_Generator
 *
 * CoWorkEr generator for PICML.
 */
//=============================================================================

class CUTS_BE_Export CUTS_CoWorkEr_Generator : public PICML::Visitor
{
public:
  /// Default constructor.
  CUTS_CoWorkEr_Generator (void);

  /// Destructor.
  virtual ~CUTS_CoWorkEr_Generator (void);

  /// Visit a PICML::RootFolder element.
  void Visit_RootFolder (const PICML::RootFolder &);

  /// Visit a PICML::InterfaceDefinitions element.
  void Visit_InterfaceDefinitions (const PICML::InterfaceDefinitions &);

  /// Visit a PICML::File element.
  void Visit_File (const PICML::File & file);

  /// Visia a PICML::Package element.
  void Visit_Package (const PICML::Package & package);

  /// Visit a PICML::Component element.
  void Visit_Component (const PICML::Component &);

private:
  /// Type definition for a collection of artifacts.
  typedef std::vector <PICML::ImplementationArtifact> Artifact_Set;

  /// Shared implementation for visiting a RootFolder.
  void Visit_RootFolder_i (const PICML::RootFolder & root);

  /// Implmentation for visiting a InterfaceDefinitions element.
  void find_interface_definitions_i (const std::vector <PICML::File> & fileset,
                                     const PICML::File & srcfile);

  void find_package_i (const std::vector <PICML::Package> & pkgset,
                        const PICML::Package & srcpkg);

  void find_component_i (const std::vector <PICML::Component> & comset,
                         const PICML::Component & target_com);

  void find_artifact_i (PICML::ComponentImplementationContainer &,
                        const PICML::MonolithicImplementation &,
                        const std::vector <PICML::ImplementationArtifactReference> &,
                        const PICML::ImplementationArtifact &);

  /// Helper method for visiting File and Package elements.
  void visit_file_and_package (const Udm::Object & obj);

  /**
   * Helper method to generate the artifacts for the current
   * coworker_.
   *
   * @param[out]        artifacts       The artifacts for the component.
   */
  void generate_artifacts (Artifact_Set & artifacts);

  /**
   * Helper method to generate the monolithic implementation for
   * the current coworker.
   *
   * @param[in]         artifacts       The artifacts for the component.
   * @param[out]        monolithic      The monolithic implementation.
   */
  void generate_monolithic_implementation (
    const Artifact_Set & artifacts,
    PICML::MonolithicImplementation & monolithic);

  /**
   * Helper method to generator the package for a monolithic.
   *
   * @param[in]         monolithic      The target monolithic.
   */
  void generate_monolithic_package (
    const PICML::MonolithicImplementation & monolithic);

  /**
   * Helper method to get the scope of an object.
   *
   * @param[in]         object          The object in question.
   * @param[in]         seperator       Separator value.
   * @return            The fully scoped name.
   */
  std::string get_scope (const Udm::Object & object,
                         const std::string & separator);

  /// Folder that contains the interface defintion files.
  PICML::InterfaceDefinitions coworker_idefs_;

  /// Folder that contains all the implementation artifacts.
  PICML::ImplementationArtifacts coworker_artifacts_;

  /// Folder that contains all the implementation models.
  PICML::ComponentImplementations coworker_implementations_;

  /// Folder that contains all the coworker packages.
  PICML::ComponentPackages coworker_packages_;

  /// The parent of the CoWorkEr (e.g., File or Package).
  Udm::Object coworker_parent_;

  /// The current CoWorkEr.
  PICML::Component coworker_;

  /// The factory of the coworker_.
  PICML::ComponentFactory coworker_factory_;

  /// Number of CoWorkEr in a file.
  size_t coworker_count_;

  size_t artifact_position_x_;
  size_t artifact_position_y_;
  size_t artifact_position_delta_y_;
};

#endif  /* !defined _CUTS_COWORKER_GENERATOR_H_ */
