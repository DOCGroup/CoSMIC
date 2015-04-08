#include "stdafx.h"
#include "RootFolder.h"
#include "Visitor.h"

#include "PICML/PredefinedTypes/PredefinedTypes.h"
#include "PICML/InterfaceDefinition/InterfaceDefinitions.h"
#include "PICML/DeploymentPlan/DeploymentPlans.h"
#include "PICML/ImplementationArtifact/ImplementationArtifacts.h"
#include "PICML/ComponentFactoryImplementation/ComponentFactoryImplementations.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementations.h"
#include "PICML/Domain/Targets.h"
#include "PICML/ConnectorParadigmSheets/ConnectorImplementation/ConnectorImplementations.h"
#include "PICML/WorkloadParadigmSheets/WML/WorkerLibraries.h"
#include "PICML/ComponentParadigmSheets/ComponentInterface/ComponentTypes.h"
#include "PICML/PathDiagram/PathDiagrams.h"
#include "PICML/ComponentBenchmark/ComponentAnalyses.h"
#include "PICML/PackageConfiguration/PackageConfigurations.h"
#include "PICML/TopLevelPackageDescription/TopLevelPackages.h"
#include "PICML/ComponentPackage/ComponentPackages.h"
#include "PICML/ComponentBuild/ComponentBuild.h"

namespace PICML
{
  const std::string RootFolder_Impl::metaname ("RootFolder");

  RootFolder_Impl::RootFolder_Impl (void)
  {
  }

  RootFolder_Impl::RootFolder_Impl (IMgaFolder * folder)
  : ::GAME::Mga::Folder_Impl (folder),
    ::GAME::Mga::RootFolder_Impl (folder)
  {
  }

  RootFolder_Impl::~RootFolder_Impl (void)
  {
  }

  void RootFolder_Impl::accept (::GAME::Mga::Visitor * v)
  {
    Visitor * this_visitor = dynamic_cast <Visitor *> (v);

    if (0 != this_visitor)
      this_visitor->visit_RootFolder (this);
    else
      v->visit_Folder (this);
  }

  size_t RootFolder_Impl::get_PredefinedTypes (std::vector <PredefinedTypes> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <PredefinedTypes> RootFolder_Impl::get_PredefinedTypes (void) const
  {
    return this->folders <PredefinedTypes> ();
  }

  size_t RootFolder_Impl::get_InterfaceDefinitions (std::vector <InterfaceDefinitions> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <InterfaceDefinitions> RootFolder_Impl::get_InterfaceDefinitions (void) const
  {
    return this->folders <InterfaceDefinitions> ();
  }

  size_t RootFolder_Impl::get_DeploymentPlans (std::vector <DeploymentPlans> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <DeploymentPlans> RootFolder_Impl::get_DeploymentPlans (void) const
  {
    return this->folders <DeploymentPlans> ();
  }

  size_t RootFolder_Impl::get_ImplementationArtifacts (std::vector <ImplementationArtifacts> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <ImplementationArtifacts> RootFolder_Impl::get_ImplementationArtifacts (void) const
  {
    return this->folders <ImplementationArtifacts> ();
  }

  size_t RootFolder_Impl::get_ComponentFactoryImplementations (std::vector <ComponentFactoryImplementations> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <ComponentFactoryImplementations> RootFolder_Impl::get_ComponentFactoryImplementations (void) const
  {
    return this->folders <ComponentFactoryImplementations> ();
  }

  size_t RootFolder_Impl::get_ComponentImplementations (std::vector <ComponentImplementations> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <ComponentImplementations> RootFolder_Impl::get_ComponentImplementations (void) const
  {
    return this->folders <ComponentImplementations> ();
  }

  size_t RootFolder_Impl::get_Targets (std::vector <Targets> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <Targets> RootFolder_Impl::get_Targets (void) const
  {
    return this->folders <Targets> ();
  }

  size_t RootFolder_Impl::get_ConnectorImplementations (std::vector <ConnectorImplementations> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <ConnectorImplementations> RootFolder_Impl::get_ConnectorImplementations (void) const
  {
    return this->folders <ConnectorImplementations> ();
  }

  size_t RootFolder_Impl::get_WorkerLibraries (std::vector <WorkerLibraries> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <WorkerLibraries> RootFolder_Impl::get_WorkerLibraries (void) const
  {
    return this->folders <WorkerLibraries> ();
  }

  size_t RootFolder_Impl::get_ComponentTypes (std::vector <ComponentTypes> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <ComponentTypes> RootFolder_Impl::get_ComponentTypes (void) const
  {
    return this->folders <ComponentTypes> ();
  }

  size_t RootFolder_Impl::get_PathDiagrams (std::vector <PathDiagrams> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <PathDiagrams> RootFolder_Impl::get_PathDiagrams (void) const
  {
    return this->folders <PathDiagrams> ();
  }

  size_t RootFolder_Impl::get_ComponentAnalyses (std::vector <ComponentAnalyses> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <ComponentAnalyses> RootFolder_Impl::get_ComponentAnalyses (void) const
  {
    return this->folders <ComponentAnalyses> ();
  }

  size_t RootFolder_Impl::get_PackageConfigurations (std::vector <PackageConfigurations> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <PackageConfigurations> RootFolder_Impl::get_PackageConfigurations (void) const
  {
    return this->folders <PackageConfigurations> ();
  }

  size_t RootFolder_Impl::get_TopLevelPackages (std::vector <TopLevelPackages> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <TopLevelPackages> RootFolder_Impl::get_TopLevelPackages (void) const
  {
    return this->folders <TopLevelPackages> ();
  }

  size_t RootFolder_Impl::get_ComponentPackages (std::vector <ComponentPackages> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <ComponentPackages> RootFolder_Impl::get_ComponentPackages (void) const
  {
    return this->folders <ComponentPackages> ();
  }

  size_t RootFolder_Impl::get_ComponentBuild (std::vector <ComponentBuild> & items) const
  {
    return this->folders (items);
  }

  ::GAME::Mga::Collection_T <ComponentBuild> RootFolder_Impl::get_ComponentBuild (void) const
  {
    return this->folders <ComponentBuild> ();
  }
}


