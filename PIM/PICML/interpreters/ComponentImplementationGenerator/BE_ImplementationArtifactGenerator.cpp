#include "StdAfx.h"
#include "BE_ImplementationArtifactGenerator.h"

#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/InterfaceDefinition/File.h"
#include "PICML/ImplementationArtifact/ArtifactContainer.h"
#include "PICML/NamedTypes/NamedType.h"

#include "game/mga/Model.h"
#include "game/mga/MetaModel.h"

#include "game/mga/modelgen.h"
#include "game/mga/utils/Point.h"

#include <stack>

namespace PICML_BE
{

void ImplementationArtifactGenerator::visit_Component (PICML::Component_in component)
{
  std::string name = this->fq_type (component, "_");
  std::string impl_name = name + "_exec";
  std::string svnt_name = name + "_svnt";

  // Create a new container for the component's artifacts.
  PICML::ArtifactContainer container;
  std::string container_name = name + "Artifacts";

  if (GAME::create_if_not <GAME::Mga_t> (this->artifact_folder_, container,
      GAME::contains <GAME::Mga_t> ([&](PICML::ArtifactContainer_in curr) { return curr->name () == name; })))
  {
    container->name (name);
  }

  // Create the monolithic implementation for the component.
  this->svnt_artifact_ = PICML::ImplementationArtifact_Impl::_create (container);
  this->svnt_artifact_->name (svnt_name);
  this->svnt_artifact_->location (svnt_name);
  GAME::Mga::set_position ("Packaging", GAME::Mga::Point (150, 150), this->svnt_artifact_);

  this->impl_artifact_ = PICML::ImplementationArtifact_Impl::_create (container);
  this->impl_artifact_->name (impl_name);
  this->impl_artifact_->location (impl_name);
  GAME::Mga::set_position ("Packaging", GAME::Mga::Point (450, 150), this->impl_artifact_);
}

//
// scope
//
std::string ImplementationArtifactGenerator::
fq_type (PICML::NamedType_in type, const std::string & separator)
{
  std::string scope;
  std::stack <GAME::Mga::Model> temp_stack;

  // Continue walking up the tree until we reach a File object
  GAME::Mga::Model parent = type->parent ();

  while (PICML::File_Impl::metaname != parent->meta ()->name ())
  {
    temp_stack.push (parent);
    parent = parent->parent_model ();
  }

  // Empty the remainder of the stack.
  while (!temp_stack.empty ())
  {
    parent = temp_stack.top ();
    temp_stack.pop ();

    scope += std::string (parent->name ()) + separator;
  }

  return scope + type->name ();
}

}
