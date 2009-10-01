// $Id$

#include "BE_ComponentImplementationGenerator.h"

namespace PICML_BE
{
//
// BE_ComponentImplementationGenerator
//
ComponentImplementationGenerator::
ComponentImplementationGenerator (PICML::ComponentImplementations & impl_folder,
                                  PICML::ImplementationArtifacts & artifact_folder)
: impl_folder_ (impl_folder),
  artifact_generator_ (artifact_folder)
{

}

//
// ~BE_ComponentImplementationGenerator
//
ComponentImplementationGenerator::~ComponentImplementationGenerator (void)
{

}

//
// Visit_Component
//
void ComponentImplementationGenerator::
Visit_Component (const PICML::Component & component)
{
  std::string name = std::string (component.name ()) + "Impl";

  // Create a new container for the component implementation.
  PICML::ComponentImplementationContainer container =
    PICML::ComponentImplementationContainer::Create (this->impl_folder_);
  container.name () = name;

  // Create the monolithic implementation for the component.
  this->impl_ = PICML::MonolithicImplementation::Create (container);
  this->impl_.name () = name;

  // Create the reference to the target component.
  PICML::ComponentRef ref = PICML::ComponentRef::Create (container);
  ref.name () = name;

  // Associate the monolithic implementation with the reference.
  PICML::Implements implements = PICML::Implements::Create (container);
  implements.srcImplements_end () = this->impl_;
  implements.dstImplements_end () = ref;

  // Generate the artifacts for the component.
  PICML::Component (component).Accept (this->artifact_generator_);

  // Insert the servant artifact for this component.
  PICML::ComponentServantArtifact svnt_artifact =
    PICML::ComponentServantArtifact::Create (container);

  svnt_artifact.ref () = this->artifact_generator_.svnt_artifact ();
  svnt_artifact.name () = this->artifact_generator_.svnt_artifact ().name ();

  PICML::MonolithprimaryArtifact pa = PICML::MonolithprimaryArtifact::Create (container);
  pa.srcMonolithprimaryArtifact_end () = this->impl_;
  pa.dstMonolithprimaryArtifact_end () = svnt_artifact;

  // Insert the implementation artifact for this component.
  PICML::ComponentImplementationArtifact impl_artifact =
    PICML::ComponentImplementationArtifact::Create (container);

  impl_artifact.ref () = this->artifact_generator_.impl_artifact ();
  impl_artifact.name () = this->artifact_generator_.impl_artifact ().name ();

  pa = PICML::MonolithprimaryArtifact::Create (container);
  pa.srcMonolithprimaryArtifact_end () = this->impl_;
  pa.dstMonolithprimaryArtifact_end () = impl_artifact;
}

}
