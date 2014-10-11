// $Id$

#include "StdAfx.h"
#include "ComponentImplementationGenerator_Component.h"
#include "ComponentImplementationGenerator_Component_Impl.h"
#include "game/mga/utils/Project_Settings.h"

#include "game/mga/Atom.h"
#include "game/mga/Model.h"
#include "game/mga/Transaction.h"
#include "game/mga/Utils.h"
#include "game/mga/component/Interpreter_T.h"
#include "game/mga/modelgen.h"

#include "PICML/ComponentParadigmSheets/ComponentType/Component.h"
#include "PICML/ComponentParadigmSheets/ComponentImplementation/ComponentImplementations.h"
#include "PICML/ImplementationArtifact/ImplementationArtifacts.h"

#include "BE_ComponentImplementationGenerator.h"

#include <iostream>

#define DEFAULT_COMPONENT_IMPLENTATIONS_NAME    "ComponentImplementations"
#define DEFAULT_IMPLENTATION_ARTIFACTS_NAME     "ImplementationArtifacts"

GAME_DECLARE_INTERPRETER (ComponentImplementationGenerator_Component, ComponentImplementationGenerator_Component_Impl);

//
//ComponentImplementationGenerator_Component_Impl
//
ComponentImplementationGenerator_Component_Impl::ComponentImplementationGenerator_Component_Impl (void)
: GAME::Mga::Interpreter_Impl_Base ("PICML ComponentImplementationGenerator Generator",
                                    "PICML",
                                    "PICML.Interpreter.ComponentImplementationGenerator")
{

}

//
//~ComponentImplementationGenerator_Component_Impl
//
ComponentImplementationGenerator_Component_Impl::~ComponentImplementationGenerator_Component_Impl (void)
{

}

//
//invoke ex
//
int ComponentImplementationGenerator_Component_Impl::
invoke_ex (GAME::Mga::Project project,
           GAME::Mga::FCO_in focus,
           std::vector <GAME::Mga::FCO> & selected,
           long flags)
{
  // Allow the user to select which components we should generate. Otherwise,
  // we can just assume that the components of interest are already selected.
  if (selected.empty ())
    return 0;

  // Convert selected objects into Components, and remove those objects
  // that are not components.
  GAME::Mga::Transaction t (project);

  std::vector <PICML::Component> components;

  for (GAME::Mga::FCO fco : selected)
  {
    try
    {
      components.push_back (PICML::Component::_narrow (fco));
    }
    catch (const GAME::Mga::Invalid_Cast &) 
    { 
    }
  }

  // Make sure the target implementation and artifact folder exists.
  PICML::RootFolder root_folder = PICML::RootFolder::_narrow (project.root_folder ());

  PICML::ComponentImplementations impl_folder;
  if (GAME::create_if_not <GAME::Mga_t> (root_folder, impl_folder,
      GAME::contains <GAME::Mga_t> ([&](PICML::ComponentImplementations curr) {
        return curr->name () == DEFAULT_COMPONENT_IMPLENTATIONS_NAME; })))
  {
    impl_folder->name (DEFAULT_COMPONENT_IMPLENTATIONS_NAME);
  }

  PICML::ImplementationArtifacts artifact_folder;
  if (GAME::create_if_not <GAME::Mga_t> (root_folder, artifact_folder,
      GAME::contains <GAME::Mga_t> ([&](PICML::ImplementationArtifacts curr) {
        return curr->name () == DEFAULT_IMPLENTATION_ARTIFACTS_NAME; })))
  {
    artifact_folder->name (DEFAULT_IMPLENTATION_ARTIFACTS_NAME);
  }

  // Generate default implementations for selected components.
  PICML_BE::ComponentImplementationGenerator generator (impl_folder, artifact_folder);

  for (const PICML::Component & component : components)
    component->accept (&generator);

  t.commit ();

  return 0;
}

