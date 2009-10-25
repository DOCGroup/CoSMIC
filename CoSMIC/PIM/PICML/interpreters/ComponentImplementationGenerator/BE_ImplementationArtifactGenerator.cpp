// $Id$

#include "BE_ImplementationArtifactGenerator.h"
#include "Utils/UDM/modelgen.h"
#include "boost/bind.hpp"
#include "Uml.h"
#include <stack>

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
  std::string name = this->fq_type (component, "_");
  std::string impl_name = name + "_exec";
  std::string svnt_name = name + "_svnt";

  // Create a new container for the component's artifacts.
  PICML::ArtifactContainer container;
  std::string container_name = name + "Artifacts";

  if (Udm::create_if_not (this->artifact_folder_, container,
      Udm::contains (boost::bind (std::equal_to <std::string> (),
                     name,
                     boost::bind (&PICML::ArtifactContainer::name, _1)))))
  {
    container.name () = name;
  }

  // Create the monolithic implementation for the component.
  this->svnt_artifact_ = PICML::ImplementationArtifact::Create (container);
  this->svnt_artifact_.name () = svnt_name;
  this->svnt_artifact_.location () = svnt_name;
  this->svnt_artifact_.position () = "(150,150)";

  this->impl_artifact_ = PICML::ImplementationArtifact::Create (container);
  this->impl_artifact_.name () = impl_name;
  this->impl_artifact_.location () = impl_name;
  this->impl_artifact_.position () = "(450,150)";
}

//
// scope
//
std::string ImplementationArtifactGenerator::
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
