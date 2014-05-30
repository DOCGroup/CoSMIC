// $Id$

#include "BE_ComponentImplementationGenerator.h"
#include "Utils/UDM/modelgen.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <stack>

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
  std::string name = component.name ();
  std::string impl_name = this->fq_type (component, "_") + "Impl";

  // Create a new container for the component implementation.
  PICML::ComponentImplementationContainer container;

  if (CoSMIC::Udm::create_if_not (this->impl_folder_, container,
      CoSMIC::Udm::contains (boost::bind (std::equal_to <std::string> (),
                     impl_name,
                     boost::bind (&PICML::ComponentImplementationContainer::name, _1)))))
  {
    container.name () = impl_name;
  }

  // Create the monolithic implementation for the component.
  if (CoSMIC::Udm::create_if_not (container, this->impl_,
      CoSMIC::Udm::contains (boost::bind (std::equal_to <std::string> (),
                     impl_name,
                     boost::bind (&PICML::MonolithicImplementation::name, _1)))))
  {
    this->impl_.name () = impl_name;
    this->impl_.position () = "(250,250)";
  }

  // Create the reference to the target component.
  PICML::ComponentRef ref = PICML::ComponentRef::Create (container);
  ref.name () = name;
  ref.position () = "(187,75)";

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
  svnt_artifact.EntryPoint () = "create_" + this->fq_type (component, "_") + "_Servant";
  svnt_artifact.position () = "(506,347)";

  PICML::MonolithprimaryArtifact pa = PICML::MonolithprimaryArtifact::Create (container);
  pa.srcMonolithprimaryArtifact_end () = this->impl_;
  pa.dstMonolithprimaryArtifact_end () = svnt_artifact;

  // Insert the implementation artifact for this component.
  PICML::ComponentImplementationArtifact impl_artifact =
    PICML::ComponentImplementationArtifact::Create (container);

  impl_artifact.ref () = this->artifact_generator_.impl_artifact ();
  impl_artifact.name () = this->artifact_generator_.impl_artifact ().name ();
  impl_artifact.EntryPoint () = "create_" + this->fq_type (component, "_") + "_Impl";
  impl_artifact.position () = "(506,151)";

  pa = PICML::MonolithprimaryArtifact::Create (container);
  pa.srcMonolithprimaryArtifact_end () = this->impl_;
  pa.dstMonolithprimaryArtifact_end () = impl_artifact;
}

//
// scope
//
std::string ComponentImplementationGenerator::
fq_type (const PICML::NamedType & type, const std::string & separator)
{
  std::string scope;
  std::stack <PICML::MgaObject> temp_stack;

  // Continue walking up the tree until we reach a File object.
  PICML::MgaObject parent = PICML::MgaObject::Cast (type.parent ());

  while (PICML::File::meta != parent.type () )
  {
    temp_stack.push (parent);
    parent = PICML::MgaObject::Cast (parent.parent ());
  }

  // Empty the remainder of the stack.
  while (!temp_stack.empty ())
  {
    parent = temp_stack.top ();
    temp_stack.pop ();

    scope += std::string (parent.name ()) + separator;
  }

  return scope + std::string (type.name ());
}

}
