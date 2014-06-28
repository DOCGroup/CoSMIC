// -*- C++ -*-

//============================================================================
/**
 * @file    RootFolder.h
 *
 * $Id$
 *
 * @author  Alhad Mokashi <amokashi at iupui dot edu>
 *          James H. Hill <hillj at cs dot iupui dot edu>
 */
//============================================================================

#ifndef _PICML_ROOTFOLDER_H_
#define _PICML_ROOTFOLDER_H_

#include "game/mga/RootFolder.h"

#include "PICML_fwd.h"
#include "PICML_export.h"

namespace PICML
{
  // Forward decl. and type definitions
  class RootFolder_Impl;
  typedef RootFolder_Impl * RootFolder_in;
  typedef ::GAME::Mga::Smart_Ptr < RootFolder_Impl > RootFolder;

  /**
   * @class RootFolder_Impl
   *
   * Implementation of the root folder model element.
   */
  class PICML_Export RootFolder_Impl : public virtual ::GAME::Mga::RootFolder_Impl
  {
    public:
    /// Tag type of this extension class.
    typedef ::GAME::Mga::folder_tag_t type_tag;

    /// Type definition of this class's interface.
    typedef IMgaFolder interface_type;

    /// Metaname for this extension class.
    static const std::string metaname;

    /// Default constructor.
    RootFolder_Impl (void);

    /**
     * Initializing constructor.
     *
     * @param[in]       folder        The source folder interface.
     */
    RootFolder_Impl (IMgaFolder * folder);

    /// Destructor.
    virtual ~RootFolder_Impl (void);

    /// Accept a visitor for this model element.
    virtual void accept (::GAME::Mga::Visitor * v);

    size_t get_PredefinedTypes (std::vector <PredefinedTypes> & items) const;
    ::GAME::Mga::Collection_T <PredefinedTypes> get_PredefinedTypes (void) const;

    size_t get_InterfaceDefinitions (std::vector <InterfaceDefinitions> & items) const;
    ::GAME::Mga::Collection_T <InterfaceDefinitions> get_InterfaceDefinitions (void) const;

    size_t get_DeploymentPlans (std::vector <DeploymentPlans> & items) const;
    ::GAME::Mga::Collection_T <DeploymentPlans> get_DeploymentPlans (void) const;

    size_t get_ImplementationArtifacts (std::vector <ImplementationArtifacts> & items) const;
    ::GAME::Mga::Collection_T <ImplementationArtifacts> get_ImplementationArtifacts (void) const;

    size_t get_ComponentFactoryImplementations (std::vector <ComponentFactoryImplementations> & items) const;
    ::GAME::Mga::Collection_T <ComponentFactoryImplementations> get_ComponentFactoryImplementations (void) const;

    size_t get_ComponentImplementations (std::vector <ComponentImplementations> & items) const;
    ::GAME::Mga::Collection_T <ComponentImplementations> get_ComponentImplementations (void) const;

    size_t get_Targets (std::vector <Targets> & items) const;
    ::GAME::Mga::Collection_T <Targets> get_Targets (void) const;

    size_t get_ConnectorImplementations (std::vector <ConnectorImplementations> & items) const;
    ::GAME::Mga::Collection_T <ConnectorImplementations> get_ConnectorImplementations (void) const;

    size_t get_WorkerLibraries (std::vector <WorkerLibraries> & items) const;
    ::GAME::Mga::Collection_T <WorkerLibraries> get_WorkerLibraries (void) const;

    size_t get_ComponentTypes (std::vector <ComponentTypes> & items) const;
    ::GAME::Mga::Collection_T <ComponentTypes> get_ComponentTypes (void) const;

    size_t get_PathDiagrams (std::vector <PathDiagrams> & items) const;
    ::GAME::Mga::Collection_T <PathDiagrams> get_PathDiagrams (void) const;

    size_t get_ComponentAnalyses (std::vector <ComponentAnalyses> & items) const;
    ::GAME::Mga::Collection_T <ComponentAnalyses> get_ComponentAnalyses (void) const;

    size_t get_PackageConfigurations (std::vector <PackageConfigurations> & items) const;
    ::GAME::Mga::Collection_T <PackageConfigurations> get_PackageConfigurations (void) const;

    size_t get_TopLevelPackages (std::vector <TopLevelPackages> & items) const;
    ::GAME::Mga::Collection_T <TopLevelPackages> get_TopLevelPackages (void) const;

    size_t get_ComponentPackages (std::vector <ComponentPackages> & items) const;
    ::GAME::Mga::Collection_T <ComponentPackages> get_ComponentPackages (void) const;

    size_t get_ComponentBuild (std::vector <ComponentBuild> & items) const;
    ::GAME::Mga::Collection_T <ComponentBuild> get_ComponentBuild (void) const;
  };
}

#endif
