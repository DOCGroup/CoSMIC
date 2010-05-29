// $Id$

#include "StdAfx.h"
#include "DefaultImplementationGenerator.h"
#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "game/Attribute.h"
#include "game/Model.h"
#include "game/Reference.h"
#include "game/Connection.h"
#include "game/MetaBase.h"
#include "PIM/PICML/utils/game/Utility.h"
#include "boost/bind.hpp"
#include <functional>
#include <stack>

//
// DefaultImplementationGenerator
//
DefaultImplementationGenerator::
DefaultImplementationGenerator (GAME::Folder & root, const NewComponentConfig & config)
: artifact_gen_ (root, config)
{
  static const std::string metaname ("ComponentImplementations");

  if (GAME::create_if_not (root, metaname, this->impls_,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      metaname,
                      boost::bind (&GAME::Folder::name, _1)))))
  {
    this->impls_.name (metaname);
  }
}

//
// ~DefaultImplementationGenerator
//
DefaultImplementationGenerator::~DefaultImplementationGenerator (void)
{

}

//
// generate
//
bool DefaultImplementationGenerator::generate (const GAME::Model & component)
{
  // First, generate the artifacts for the component.
  this->artifact_gen_.generate (component);

  // Generate the monolithic implementation.
  std::string name = component.name ();
  std::string fq_type = PICML::GAME::fq_type (component, "_");
  std::string impl_name = fq_type + "Impl";

  // Create a new container for the component implementation.
  GAME::Model container;

  if (GAME::create_if_not (this->impls_, "ComponentImplementationContainer", container,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      impl_name,
                      boost::bind (&GAME::Model::name, _1)))))
  {
    container.name (impl_name);
  }

  // Create the monolithic implementation for the component.
  GAME::Atom impl;

  if (GAME::create_if_not (container, "MonolithicImplementation", impl,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                     impl_name,
                     boost::bind (&GAME::Atom::name, _1)))))
  {
    impl.name (impl_name);
    GAME::utils::position ("Packaging", GAME::utils::Point (250, 250), impl);
  }

  // Create the reference to the target component.
  GAME::Reference ref = GAME::Reference::_create (container, "ComponentRef");
  ref.name (name);
  ref.refers_to (component);
  GAME::utils::position ("Packaging", GAME::utils::Point (187, 75), ref);

  // Associate the monolithic implementation with the reference.
  GAME::Connection implements =
    GAME::Connection::_create (container, "Implements", impl, ref);

  // Insert the servant artifact for this component.
  GAME::Reference svnt_artifact =
    GAME::Reference::_create (container, "ComponentServantArtifact");

  svnt_artifact.refers_to (this->artifact_gen_.svnt_artifact ());
  svnt_artifact.name (this->artifact_gen_.svnt_artifact ().name ());

  std::string entrypoint ("create_" + fq_type + "_Servant");
  svnt_artifact.attribute ("EntryPoint").string_value (entrypoint);
  GAME::utils::position ("Packaging", GAME::utils::Point (506,347), svnt_artifact);

  GAME::Connection pa =
    GAME::Connection::_create (container, "MonolithprimaryArtifact", impl, svnt_artifact);

  // Insert the implementation artifact for this component.
  GAME::Reference impl_artifact =
    GAME::Reference::_create (container, "ComponentImplementationArtifact");

  impl_artifact.refers_to (this->artifact_gen_.exec_artifact ());
  impl_artifact.name (this->artifact_gen_.exec_artifact ().name ());

  entrypoint = "create_" + fq_type + "_Impl";
  impl_artifact.attribute ("EntryPoint").string_value (entrypoint);
  GAME::utils::position ("Packaging", GAME::utils::Point (506,151), impl_artifact);

  pa = GAME::Connection::_create (container, "MonolithprimaryArtifact", impl, impl_artifact);

  return true;
}
