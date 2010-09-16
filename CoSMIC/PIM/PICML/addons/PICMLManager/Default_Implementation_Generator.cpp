// $Id$

#include "StdAfx.h"

#include "Default_Implementation_Generator.h"

#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "game/Attribute.h"
#include "game/Model.h"
#include "game/Project.h"
#include "game/Reference.h"
#include "game/Connection.h"
#include "game/MetaBase.h"
#include "PIM/PICML/utils/game/Utility.h"
#include "boost/bind.hpp"
#include <functional>
#include <stack>

namespace PICML
{
namespace MI
{

using ::GAME::Folder;

//
// Default_Implementation_Generator
//
Default_Implementation_Generator::
Default_Implementation_Generator (::GAME::Project project, const meta_info_t & info)
: info_ (info),
  artifact_gen_ (project, info.artifact_folder_)
{
  ::GAME::Folder root_folder = project.root_folder ();

  if (::GAME::create_if_not (root_folder, info.impl_folder_, this->impl_folder_,
      ::GAME::contains (boost::bind (std::equal_to <std::string> (),
                        info.impl_folder_name_,
                        boost::bind (&::GAME::Model::name, _1)))))
  {
    this->impl_folder_.name (info.impl_folder_name_);
  }
}

//
// ~Default_Implementation_Generator
//
Default_Implementation_Generator::~Default_Implementation_Generator (void)
{

}

//
// generate
//
bool Default_Implementation_Generator::
generate (const Implementation_Configuration & config, const ::GAME::Model & type)
{
  using ::GAME::Atom;
  using ::GAME::Model;

  // First, generate the artifacts for this type.
  this->artifact_gen_.generate (config, type);

  // Generate the monolithic implementation.
  std::string name = type.name ();
  std::string fq_type = PICML::GAME::fq_type (type, "_");
  std::string impl_name = fq_type + "Impl";

  // Create a new container for the component implementation.
  Model container;

  if (::GAME::create_if_not (this->impl_folder_, this->info_.container_type_, container,
      ::GAME::contains (boost::bind (std::equal_to <std::string> (),
                        impl_name,
                        boost::bind (&Model::name, _1)))))
  {
    container.name (impl_name);
  }

  // Create the monolithic implementation for the component.
  Atom impl;

  if (::GAME::create_if_not (container, this->info_.impl_type_, impl,
      ::GAME::contains (boost::bind (std::equal_to <std::string> (),
                        impl_name,
                        boost::bind (&Atom::name, _1)))))
  {
    impl.name (impl_name);
    ::GAME::utils::position ("Packaging",
                             ::GAME::utils::Point (250, 250),
                             impl);
  }

  // Create the reference to the target component.
  using ::GAME::Reference;
  Reference ref = Reference::_create (container, this->info_.type_ref_);
  ref.name (name);
  ref.refers_to (type);

  ::GAME::utils::position ("Packaging",
                           ::GAME::utils::Point (187, 75),
                           ref);

  // Associate the monolithic implementation with the reference.
  using ::GAME::Connection;
  Connection implements = Connection::_create (container,
                                               this->info_.implements_type_,
                                               impl,
                                               ref);

  // Insert the servant artifact for this component.
  Reference svnt_artifact = Reference::_create (container, "ComponentServantArtifact");
  svnt_artifact.refers_to (this->artifact_gen_.svnt_artifact ());
  svnt_artifact.name (this->artifact_gen_.svnt_artifact ().name ());

  std::string entrypoint ("create_" + fq_type + "_Servant");
  svnt_artifact.attribute ("EntryPoint").string_value (entrypoint);
  ::GAME::utils::position ("Packaging",
                           ::GAME::utils::Point (506,347),
                           svnt_artifact);

  Connection pa = Connection::_create (container,
                                       "MonolithprimaryArtifact",
                                       impl,
                                       svnt_artifact);

  // Insert the implementation artifact for this component.
  Reference impl_artifact = Reference::_create (container,
                                                "ComponentImplementationArtifact");

  impl_artifact.refers_to (this->artifact_gen_.exec_artifact ());
  impl_artifact.name (this->artifact_gen_.exec_artifact ().name ());

  entrypoint = "create_" + fq_type + "_Impl";
  impl_artifact.attribute ("EntryPoint").string_value (entrypoint);

  ::GAME::utils::position ("Packaging",
                           ::GAME::utils::Point (506,151),
                           impl_artifact);

  pa = Connection::_create (container,
                            "MonolithprimaryArtifact",
                            impl,
                            impl_artifact);

  return true;
}

}
}
