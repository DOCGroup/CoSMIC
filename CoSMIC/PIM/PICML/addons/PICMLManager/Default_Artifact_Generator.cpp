// $Id$

#include "StdAfx.h"
#include "Default_Artifact_Generator.h"
#include "Implementation_Configuration.h"

#include "game/mga/Attribute.h"
#include "game/mga/Folder.h"
#include "game/mga/Model.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Project.h"
#include "game/mga/modelgen.h"
#include "game/mga/utils/Point.h"
#include "PIM/PICML/utils/game/Utility.h"

#include "boost/bind.hpp"
#include <functional>
#include <stack>

namespace PICML
{
namespace MI
{

//
// Default_Artifact_Generator
//
Default_Artifact_Generator::
Default_Artifact_Generator (::GAME::Mga::Project project,
                            const std::string & folder_name)
{
  using ::GAME::Mga_t;

  GAME::Mga::Folder root_folder = project.root_folder ();

  if (GAME::create_if_not <Mga_t> (root_folder, "ImplementationArtifacts", this->artifact_folder_,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                              folder_name,
                              boost::bind (&GAME::Mga::Folder::impl_type::name,
                                           boost::bind (&GAME::Mga::Folder::get, _1))))))
  {
    this->artifact_folder_->name (folder_name);
  }
}

//
// ~Default_Artifact_Generator
//
Default_Artifact_Generator::~Default_Artifact_Generator (void)
{

}

//
// generate
//
bool Default_Artifact_Generator::
generate (const Implementation_Configuration & config,
          const ::GAME::Mga::Model_in type)
{
  using ::GAME::Mga_t;

  std::string name = PICML::fq_type (type, "_");
  std::string impl_name = name + config.exec_artifact_suffix_;
  std::string svnt_name = name + config.svnt_artifact_suffix_;
  const std::string location_basename = this->get_location_basename (type);
  const std::string impl_location = location_basename + config.exec_artifact_suffix_;
  const std::string svnt_location = location_basename + config.svnt_artifact_suffix_;

  // Create a new container for the component's artifacts.
  std::string container_name = name + "Artifacts";
  ::GAME::Mga::Model container;

  if (::GAME::create_if_not <Mga_t> (this->artifact_folder_, "ArtifactContainer", container,
      ::GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                container_name,
                                boost::bind (&::GAME::Mga::Model::impl_type::name,
                                             boost::bind (&::GAME::Mga::Model::get, _1))))))
  {
    container->name (container_name);
  }

  // Create the servant artifact for the component.
  if (::GAME::create_if_not <Mga_t> (container, "ImplementationArtifact", this->svnt_artifact_,
      ::GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                svnt_name,
                                boost::bind (&::GAME::Mga::Atom::impl_type::name,
                                             boost::bind (&::GAME::Mga::Atom::get, _1))))))
  {
    this->svnt_artifact_->name (svnt_name);
  }

  this->svnt_artifact_->attribute ("location")->string_value (svnt_location);

  GAME::Mga::set_position ("Packaging",
                           GAME::Mga::Point (150, 150),
                           this->svnt_artifact_);

  // Create the implementation artifact for the component.
  if (GAME::create_if_not <Mga_t> (container, "ImplementationArtifact", this->impl_artifact_,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                              impl_name,
                              boost::bind (&GAME::Mga::Atom::impl_type::name,
                                           boost::bind (&GAME::Mga::Atom::get, _1))))))
  {
    this->impl_artifact_->name (impl_name);
  }

  this->impl_artifact_->attribute ("location")->string_value (impl_location);

  GAME::Mga::set_position ("Packaging",
                           GAME::Mga::Point (450, 150),
                           this->impl_artifact_);

  return true;
}

//
// svnt_artifact
//
::GAME::Mga::Atom Default_Artifact_Generator::svnt_artifact (void)
{
  return this->svnt_artifact_;
}

//
// exec_artifact
//
::GAME::Mga::Atom Default_Artifact_Generator::exec_artifact (void)
{
  return this->impl_artifact_;
}

//
// get_location_basename
//
std::string Default_Artifact_Generator::
get_location_basename (const GAME::Mga::Model_in type)
{
  if (type->meta ()->name () == "ConnectorObject")
  {
    std::string name = type->name ();

    if (name.find ("AMI4CCM_") == 0)
    {
#define PREFIX_LENGTH     8
#define SUFFIX_LENGTH     10

      // Calculate the length of the interface name that is used to
      // create the connector's name.
      GAME::Mga::Model parent = type->parent_model ();
      name = parent->name ();

      const size_t length = name.length () - (PREFIX_LENGTH + SUFFIX_LENGTH);

      return
        PICML::scope (parent, "_") +
        name.substr (PREFIX_LENGTH, length);
    }
    else
    {
      GAME::Mga::Model package_inst = PICML::get_template_package_inst (type);

      if (!package_inst.is_nil ())
        return PICML::fq_type (package_inst, "_");
      else
        return PICML::fq_type (type, "_");
    }
  }
  else
    return PICML::fq_type (type,  "_");
}

}
}
