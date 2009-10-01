// $Id$

#include "BE_ImplementationArtifactGenerator.h"

namespace PICML_BE
{
//
// ImplementationArtifactGenerator
//
ImplementationArtifactGenerator::
ImplementationArtifactGenerator (PICML::ImplementationArtifacts & artifact_folder)
: artifact_folder_ (artifact_folder)
{

}

//
// ~ImplementationArtifactGenerator
//
ImplementationArtifactGenerator::~ImplementationArtifactGenerator (void)
{

}

//
// Visit_Component
//
void ImplementationArtifactGenerator::
Visit_Component (const PICML::Component & component)
{
  std::string name = std::string (component.name ());
  std::string impl_name = name + "_impl";
  std::string svnt_name = name + "_svnt";

  // Create a new container for the component's artifacts.
  PICML::ArtifactContainer container =
    PICML::ArtifactContainer::Create (this->artifact_folder_);

  container.name () = name + "Artifacts";

  // Create the monolithic implementation for the component.
  this->svnt_artifact_ = PICML::ImplementationArtifact::Create (container);
  this->svnt_artifact_.name () = svnt_name;
  this->svnt_artifact_.location () = svnt_name;

  this->impl_artifact_ = PICML::ImplementationArtifact::Create (container);
  this->impl_artifact_.name () = impl_name;
  this->impl_artifact_.location () = impl_name;
}

}
