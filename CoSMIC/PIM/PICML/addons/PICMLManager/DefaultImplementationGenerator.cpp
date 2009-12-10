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
DefaultImplementationGenerator (const GME::Folder & root,
                                const NewComponentConfig & config)
: artifact_gen_ (root, config)
{
  if (GAME::create_if_not (root, "ComponentImplementations", this->impls_,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      "ComponentImplementations",
                      boost::bind (&GME::Folder::name, _1)))))
  {
    this->impls_.name ("ComponentImplementations");
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
bool DefaultImplementationGenerator::generate (const GME::Model & component)
{
  // First, generate the artifacts for the component.
  this->artifact_gen_.generate (component);

  // Generate the monolithic implementation.
  std::string name = component.name ();
  std::string fq_type = PICML::GAME::fq_type (component, "_");
  std::string impl_name = fq_type + "Impl";

  // Create a new container for the component implementation.
  GME::Model container;

  if (GAME::create_if_not (this->impls_, "ComponentImplementationContainer", container,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      impl_name,
                      boost::bind (&GME::Model::name, _1)))))
  {
    container.name (impl_name);
  }

  // Create the monolithic implementation for the component.
  GME::Atom impl;

  if (GAME::create_if_not (container, "MonolithicImplementation", impl,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                     impl_name,
                     boost::bind (&GME::Atom::name, _1)))))
  {
    impl.name (impl_name);
    GME::position ("Packaging", Utils::Point (250, 250), impl);
  }

  // Create the reference to the target component.
  GME::Reference ref = GME::Reference::_create ("ComponentRef", container);
  ref.name (name);
  ref.refers_to (component);
  GME::position ("Packaging", Utils::Point (187, 75), ref);

  // Associate the monolithic implementation with the reference.
  GME::Connection implements =
    GME::Connection::_create ("Implements", container, impl, ref);

  // Insert the servant artifact for this component.
  GME::Reference svnt_artifact =
    GME::Reference::_create ("ComponentServantArtifact", container);

  svnt_artifact.refers_to (this->artifact_gen_.svnt_artifact ());
  svnt_artifact.name (this->artifact_gen_.svnt_artifact ().name ());

  std::string entrypoint ("create_" + fq_type + "_Servant");
  svnt_artifact.attribute ("EntryPoint").string_value (entrypoint);
  GME::position ("Packaging", Utils::Point (506,347), svnt_artifact);

  GME::Connection pa =
    GME::Connection::_create ("MonolithprimaryArtifact", container, impl, svnt_artifact);

  // Insert the implementation artifact for this component.
  GME::Reference impl_artifact =
    GME::Reference::_create ("ComponentImplementationArtifact", container);

  impl_artifact.refers_to (this->artifact_gen_.exec_artifact ());
  impl_artifact.name (this->artifact_gen_.exec_artifact ().name ());

  entrypoint = "create_" + fq_type + "_Impl";
  impl_artifact.attribute ("EntryPoint").string_value (entrypoint);
  GME::position ("Packaging", Utils::Point (506,151), impl_artifact);

  pa = GME::Connection::_create ("MonolithprimaryArtifact", container, impl, impl_artifact);

  return true;
}
