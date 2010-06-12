// $Id$

#include "Artifact_Generator.h"
#include "Scope.h"

#include "game/xme/functional.h"
#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "PIM/PICML/utils/game/Utility.h"
#include "boost/bind.hpp"
#include <functional>
#include <stack>

////
//// operator +
////
//::Utils::XStr operator + (const ::Utils::XStr & str, const ACE_CString & acestr)
//{
//  ::Utils::XStr temp (str);
//  temp.append (acestr.c_str (), acestr.length ());
//
//  return temp;
//}

//
// Artifact_Generator
//
Artifact_Generator::Artifact_Generator (GAME::XME::Folder & root)
{
  using GAME::XME::Folder;
  static const ::Utils::XStr meta_ImplementationArtifacts ("ImplementationArtifacts");

  if (GAME::create_if_not (root, meta_ImplementationArtifacts, this->artifacts_,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
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
  ::Utils::XStr name;
  Scope::fq_name (component, "_", false, name);

  // Get the name of the component's artifacts.
  static const ::Utils::XStr impl_suffix ("_exec");
  ::Utils::XStr impl_name (name);
  impl_name.append (impl_suffix);

  static const ::Utils::XStr svnt_suffix ("_svnt");
  ::Utils::XStr svnt_name (name);
  svnt_name.append (svnt_suffix);

  // Create a new container for the component's artifacts.
  static const ::Utils::XStr container_suffix ("Artifacts");
  ::Utils::XStr container_name (name);
  container_name.append (container_suffix);

  // Locate the container for the artifacts.
  GAME::XME::Model container;
  static const ::Utils::XStr meta_ArtifactContainer ("ArtifactContainer");

  if (GAME::create_if_not (this->artifacts_, meta_ArtifactContainer, container,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                      container_name,
                      boost::bind (&GAME::XME::Model::name, _1)))))
  {
    container.name (container_name);
  }

  // Create the servant artifact for the component.
  static const ::Utils::XStr meta_ImplementationArtifact ("ImplementationArtifact");
  if (GAME::create_if_not (container, meta_ImplementationArtifact, this->svnt_artifact_,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                      svnt_name,
                      boost::bind (&GAME::XME::Atom::name, _1)))))
  {
    this->svnt_artifact_.name (svnt_name);
  }

  static const ::Utils::XStr attr_location ("location");
  static const ::Utils::XStr aspect_Packaging ("Packaging");

  // Set the position of the artifact.
  this->svnt_artifact_.attribute (attr_location, true).value (svnt_name);
  GAME::XME::set_position (this->svnt_artifact_,
                          aspect_Packaging,
                          Utils::Point (150, 150));

  // Create the implementation artifact for the component.
  if (GAME::create_if_not (container, meta_ImplementationArtifact, this->impl_artifact_,
      GAME::contains (boost::bind (std::equal_to <::Utils::XStr> (),
                      impl_name,
                      boost::bind (&GAME::XME::Atom::name, _1)))))
  {
    this->impl_artifact_.name (impl_name);
  }

  // Set the position of the artifact.
  this->impl_artifact_.attribute (attr_location, true).value (impl_name);
  GAME::XME::set_position (this->impl_artifact_,
                          aspect_Packaging,
                          Utils::Point (450, 150));

  return true;
}