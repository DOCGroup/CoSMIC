// $Id$

#include "Artifact_Generator.h"
#include "Scope.h"

#include "game/xme/functional.h"
#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "boost/bind.hpp"
#include <functional>
#include <stack>

//
// Artifact_Generator
//
Artifact_Generator::Artifact_Generator (GAME::XME::Folder & root)
{
  using GAME::XME::Folder;
  static const GAME::Xml::String meta_ImplementationArtifacts ("ImplementationArtifacts");

  if (GAME::create_if_not (root, meta_ImplementationArtifacts, this->artifacts_,
      GAME::contains (boost::bind (std::equal_to < GAME::Xml::String > (),
                      meta_ImplementationArtifacts,
                      boost::bind (&Folder::name, _1)))))
  {
    this->artifacts_.name ("ImplementationArtifacts");
  }
}

//
// ~Artifact_Generator
//
Artifact_Generator::~Artifact_Generator (void)
{

}

//
// generate
//
bool Artifact_Generator::generate (const GAME::XME::Model & component)
{
  // Get the fully qualified name for the component.
  GAME::Xml::String name;
  Scope::fq_name (component, "_", false, name);

  // Get the name of the component's artifacts.
  static const GAME::Xml::String impl_suffix ("_exec");
  GAME::Xml::String impl_name (name);
  impl_name.append (impl_suffix);

  static const GAME::Xml::String svnt_suffix ("_svnt");
  GAME::Xml::String svnt_name (name);
  svnt_name.append (svnt_suffix);

  // Create a new container for the component's artifacts.
  static const GAME::Xml::String container_suffix ("Artifacts");
  GAME::Xml::String container_name (name);
  container_name.append (container_suffix);

  // Locate the container for the artifacts.
  GAME::XME::Model container;
  static const GAME::Xml::String meta_ArtifactContainer ("ArtifactContainer");

  if (GAME::create_if_not (this->artifacts_, meta_ArtifactContainer, container,
      GAME::contains (boost::bind (std::equal_to < GAME::Xml::String > (),
                      container_name,
                      boost::bind (&GAME::XME::Model::name, _1)))))
  {
    container.name (container_name);
  }

  // Create the servant artifact for the component.
  static const GAME::Xml::String meta_ImplementationArtifact ("ImplementationArtifact");
  if (GAME::create_if_not (container, meta_ImplementationArtifact, this->svnt_artifact_,
      GAME::contains (boost::bind (std::equal_to < GAME::Xml::String > (),
                      svnt_name,
                      boost::bind (&GAME::XME::Atom::name, _1)))))
  {
    this->svnt_artifact_.name (svnt_name);
  }

  static const GAME::Xml::String attr_location ("location");
  static const GAME::Xml::String aspect_Packaging ("Packaging");

  // Set the position of the artifact.
  this->svnt_artifact_.attribute (attr_location, true).value (svnt_name);
  GAME::XME::set_position (this->svnt_artifact_,
                           aspect_Packaging,
                           150, 
                           150);

  // Create the implementation artifact for the component.
  if (GAME::create_if_not (container, meta_ImplementationArtifact, this->impl_artifact_,
      GAME::contains (boost::bind (std::equal_to < GAME::Xml::String > (),
                      impl_name,
                      boost::bind (&GAME::XME::Atom::name, _1)))))
  {
    this->impl_artifact_.name (impl_name);
  }

  // Set the position of the artifact.
  this->impl_artifact_.attribute (attr_location, true).value (impl_name);
  GAME::XME::set_position (this->impl_artifact_,
                           aspect_Packaging,
                           450, 
                           150);

  return true;
}
