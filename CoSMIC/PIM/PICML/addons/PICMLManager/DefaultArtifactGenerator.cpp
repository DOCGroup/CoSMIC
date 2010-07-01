// $Id$

#include "StdAfx.h"
#include "DefaultArtifactGenerator.h"
#include "NewComponentConfig.h"
#include "game/Attribute.h"
#include "game/Model.h"
#include "game/MetaBase.h"
#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "PIM/PICML/utils/game/Utility.h"
#include "boost/bind.hpp"
#include <functional>
#include <stack>

//
// operator +
//
std::string operator + (const std::string & str, const ACE_CString & acestr)
{
  std::string temp (str);
  temp.append (acestr.c_str (), acestr.length ());

  return temp;
}

//
// DefaultArtifactGenerator
//
DefaultArtifactGenerator::
DefaultArtifactGenerator (GAME::Folder & folder)
: artifacts_ (folder)
{

}

//
// ~DefaultArtifactGenerator
//
DefaultArtifactGenerator::~DefaultArtifactGenerator (void)
{

}

//
// generate
//
bool DefaultArtifactGenerator::
generate (const NewComponentConfig & config, const GAME::Model & component)
{
  std::string name = PICML::GAME::fq_type (component, "_");
  std::string impl_name = name + config.exec_artifact_suffix_;
  std::string svnt_name = name + config.svnt_artifact_suffix_;

  // Create a new container for the component's artifacts.
  std::string container_name = name + "Artifacts";
  GAME::Model container;

  if (GAME::create_if_not (this->artifacts_, "ArtifactContainer", container,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      container_name,
                      boost::bind (&GAME::Model::name, _1)))))
  {
    container.name (container_name);
  }

  // Create the servant artifact for the component.
  if (GAME::create_if_not (container, "ImplementationArtifact", this->svnt_artifact_,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      svnt_name,
                      boost::bind (&GAME::Atom::name, _1)))))
  {
    this->svnt_artifact_.name (svnt_name);
  }

  this->svnt_artifact_.attribute ("location").string_value (svnt_name);
  GAME::utils::position ("Packaging", GAME::utils::Point (150, 150), this->svnt_artifact_);

  // Create the implementation artifact for the component.
  if (GAME::create_if_not (container, "ImplementationArtifact", this->impl_artifact_,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      impl_name,
                      boost::bind (&GAME::Atom::name, _1)))))
  {
    this->impl_artifact_.name (impl_name);
  }

  this->impl_artifact_.attribute ("location").string_value (impl_name);
  GAME::utils::position ("Packaging", GAME::utils::Point (450, 150), this->impl_artifact_);

  return true;
}

//
// svnt_artifact
//
const GAME::Atom & DefaultArtifactGenerator::svnt_artifact (void) const
{
  return this->svnt_artifact_;
}

//
// exec_artifact
//
const GAME::Atom & DefaultArtifactGenerator::exec_artifact (void) const
{
  return this->impl_artifact_;
}
