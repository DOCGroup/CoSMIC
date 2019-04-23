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

#include "PIM/PICML/ext/PICML/PICML.h"
#include "PIM/PICML/ext/PICML/Visitor.h"

#include "PIM/PICML/utils/game/Utility.h"

#include "boost/bind.hpp"
#include <functional>
#include <stack>

namespace PICML
{
namespace MI
{

class Get_Location_Basename : public Visitor
{
public:
  virtual void visit_Component (Component_in comp)
  {
    this->basename_ = PICML::fq_type (comp,  "_");
  }

  virtual void visit_ConnectorObject (ConnectorObject_in co)
  {
    std::string name = co->name ();
    static const std::string SEPARATOR ("_");

    if (name.find ("AMI4CCM_") == 0)
    {
#define PREFIX_LENGTH     8
#define SUFFIX_LENGTH     10

      // Calculate the length of the interface name that is used to
      // create the connector's name.
      GAME::Mga::Model parent = co->parent_model ();
      name = parent->name ();
      const size_t length = name.length () - (PREFIX_LENGTH + SUFFIX_LENGTH);

      try
      {
        NamedType named_type = NamedType::_narrow (parent);
        this->basename_ = PICML::scope (named_type, SEPARATOR);
      }
      catch (const GAME::Mga::Invalid_Cast & )
      {
        Package package = Package::_narrow (parent);
        this->basename_ = PICML::scope (package, SEPARATOR);
      }

      this->basename_ += name.substr (PREFIX_LENGTH, length);
    }
    else
    {
      TemplatePackageInstance package_inst = PICML::get_template_package_inst (co);

      if (!package_inst.is_nil ())
        this->basename_ = PICML::fq_type (package_inst.get (), SEPARATOR);
      else
        this->basename_ = PICML::fq_type (co, SEPARATOR);
    }
  }

  const std::string & basename () const
  {
    return this->basename_;
  }

private:
  std::string basename_;
};

//
// Default_Artifact_Generator
//
Default_Artifact_Generator::
Default_Artifact_Generator (::GAME::Mga::Project project, const std::string & folder_name)
{
  using ::GAME::Mga_t;

  PICML::RootFolder root_folder = PICML::RootFolder::_narrow (project.root_folder ());
  auto predicate = GAME::contains <Mga_t> ([&] (ImplementationArtifacts_in folder) {
    return folder->name () == folder_name;
  });

  if (GAME::create_if_not <Mga_t> (root_folder, this->artifact_folder_, predicate))
    this->artifact_folder_->name (folder_name);
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
generate (const Implementation_Configuration & config, Component_in type)
{
  using ::GAME::Mga_t;

  std::string name = PICML::fq_type (type, "_");
  std::string impl_name = name + config.exec_artifact_suffix_;
  std::string svnt_name = name + config.svnt_artifact_suffix_;

  Get_Location_Basename get_location_basename;
  type->accept (&get_location_basename);

  const std::string location_basename = get_location_basename.basename ();
  const std::string svnt_location_basename = 
    config.svnt_artifact_location_based_on_filename_ ?
    this->get_file (type)->name () : location_basename;

  const std::string impl_location = location_basename + config.exec_artifact_suffix_;
  const std::string svnt_location = svnt_location_basename + config.svnt_artifact_suffix_;

  // Create a new container for the component's artifacts.
  const std::string container_name = name + "Artifacts";
  ArtifactContainer container;

  if (::GAME::create_if_not <Mga_t> (this->artifact_folder_, container,
      ::GAME::contains <Mga_t> ([&] (ArtifactContainer_in item) { return item->name () == container_name; })))
  {
    container->name (container_name);
  }

  // Create the servant artifact for the component.
  if (::GAME::create_if_not <Mga_t> (container, this->svnt_artifact_,
      ::GAME::contains <Mga_t> ([&] (ImplementationArtifact_in artifact) { return artifact->name () == svnt_name; })))
  {
    this->svnt_artifact_->name (svnt_name);
  }

  this->svnt_artifact_->attribute ("location")->string_value (svnt_location);
  GAME::Mga::set_position ("Packaging", GAME::Mga::Point (150, 150), this->svnt_artifact_);

  // Create the implementation artifact for the component.
  if (::GAME::create_if_not <Mga_t> (container, this->impl_artifact_,
      ::GAME::contains <Mga_t> ([&] (ImplementationArtifact_in artifact) { return artifact->name () == impl_name; })))
  {
    this->impl_artifact_->name (impl_name);
  }

  this->impl_artifact_->attribute ("location")->string_value (impl_location);
  GAME::Mga::set_position ("Packaging", GAME::Mga::Point (450, 150), this->impl_artifact_);

  return true;
}

//
// svnt_artifact
//
ImplementationArtifact Default_Artifact_Generator::svnt_artifact (void)
{
  return this->svnt_artifact_;
}

//
// exec_artifact
//
ImplementationArtifact Default_Artifact_Generator::exec_artifact (void)
{
  return this->impl_artifact_;
}

//
// get_file
//
GAME::Mga::Model
Default_Artifact_Generator::get_file (const GAME::Mga::Model_in type)
{
  const std::string meta_File ("File");
  GAME::Mga::Model parent = GAME::Mga::Model::_narrow (type->parent ());

  while (parent->meta ()->name () != meta_File)
    parent = GAME::Mga::Model::_narrow (parent->parent ());

  return parent;
}

}
}
