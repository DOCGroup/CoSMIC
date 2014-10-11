#include "StdAfx.h"

#include "BE_ComponentImplementationGenerator.h"

#include "game/mga/Connection.h"
#include "game/mga/Model.h"
#include "game/mga/MetaModel.h"
#include "game/mga/modelgen.h"
#include "game/mga/utils/Point.h"

#include "PICML/InterfaceDefinition/File.h"
#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentType/ComponentRef.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementationContainer.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/Implements.h"
#include "PICML/ImplementationCommon/MonolithprimaryArtifact.h"
#include "PICML/ImplementationCommon/ComponentServantArtifact.h"
#include "PICML/ImplementationCommon/ComponentImplementationArtifact.h"

#include <stack>

namespace PICML_BE
{
//
// BE_ComponentImplementationGenerator
//
ComponentImplementationGenerator::
ComponentImplementationGenerator (PICML::ComponentImplementations_in impl_folder,
                                  PICML::ImplementationArtifacts_in artifact_folder)
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
visit_Component (PICML::Component_in component)
{
  std::string name = component->name ();
  std::string impl_name = this->fq_type (component, "_") + "Impl";

  // Create a new container for the component implementation.
  PICML::ComponentImplementationContainer container;

  if (GAME::create_if_not <GAME::Mga_t> (this->impl_folder_, container,
      GAME::contains <GAME::Mga_t> ([&](PICML::ComponentImplementationContainer_in container) { 
        return container->name () == impl_name; })))
  {
    container->name (impl_name);
  }

  // Create the monolithic implementation for the component.
  if (GAME::create_if_not <GAME::Mga_t> (container, this->impl_,
      GAME::contains <GAME::Mga_t> ([&](PICML::MonolithicImplementation_in curr) { return curr->name () == impl_name; })))
  {
    this->impl_->name (impl_name);
    GAME::Mga::set_position ("Packaging", GAME::Mga::Point (250, 250), this->impl_);
  }

  // Create the reference to the target component.
  PICML::ComponentRef ref = PICML::ComponentRef_Impl::_create (container);
  ref->name (name);
  GAME::Mga::set_position ("Packaging", GAME::Mga::Point (187, 75), ref);

  // Associate the monolithic implementation with the reference.
  GAME::Mga::Connection implements =
    GAME::Mga::Connection_Impl::_create (container, 
                                               PICML::Implements_Impl::metaname,
                                               this->impl_,
                                               ref);

  // Generate the artifacts for the component.
  component->accept (&this->artifact_generator_);

  // Insert the servant artifact for this component.
  PICML::ComponentServantArtifact svnt_artifact =
    PICML::ComponentServantArtifact_Impl::_create (container);

  svnt_artifact->refers_to (this->artifact_generator_.svnt_artifact ());
  svnt_artifact->name (this->artifact_generator_.svnt_artifact ()->name ());
  svnt_artifact->EntryPoint ("create_" + this->fq_type (component, "_") + "_Servant");
  GAME::Mga::set_position ("Packaging", GAME::Mga::Point (560, 347), svnt_artifact);

  // Associate the monolithic implementation with the reference.
  GAME::Mga::Connection pa =
    GAME::Mga::Connection_Impl::_create (container, 
                                         PICML::MonolithprimaryArtifact_Impl::metaname,
                                         this->impl_,
                                         svnt_artifact);

  // Insert the implementation artifact for this component.
  PICML::ComponentImplementationArtifact impl_artifact =
    PICML::ComponentImplementationArtifact_Impl::_create (container);

  impl_artifact->refers_to (this->artifact_generator_.impl_artifact ());
  impl_artifact->name (this->artifact_generator_.impl_artifact ()->name ());
  impl_artifact->EntryPoint ("create_" + this->fq_type (component, "_") + "_Impl");
  GAME::Mga::set_position ("Packaging", GAME::Mga::Point (506, 151), svnt_artifact);

  pa =
    GAME::Mga::Connection_Impl::_create (container, 
                                         PICML::MonolithprimaryArtifact_Impl::metaname,
                                         this->impl_,
                                         impl_artifact);
}

//
// scope
//
std::string ComponentImplementationGenerator::
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
