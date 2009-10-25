// $Id$

#include "StdAfx.h"
#include "DefaultArtifactGenerator.h"
#include "game/Attribute.h"
#include "game/Model.h"
#include "game/MetaBase.h"
#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "boost/bind.hpp"
#include <functional>
#include <stack>

//
// DefaultArtifactGenerator
//
DefaultArtifactGenerator::DefaultArtifactGenerator (const GME::Folder & root)
{
  if (GAME::create_if_not (root, "ImplementationArtifacts", this->artifacts_,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      "ImplementationArtifacts",
                      boost::bind (&GME::Folder::name, _1)))))
  {
    this->artifacts_.name ("ImplementationArtifacts");
  }
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
bool DefaultArtifactGenerator::generate (const GME::Model & component)
{
  std::string name = this->fq_type (component, "_");
  std::string impl_name = name + "_exec";
  std::string svnt_name = name + "_svnt";

  // Create a new container for the component's artifacts.
  std::string container_name = name + "Artifacts";
  GME::Model container;

  if (GAME::create_if_not (this->artifacts_, "ArtifactContainer", container,
      GAME::contains (boost::bind (std::equal_to <std::string> (),
                      name,
                      boost::bind (&GME::Model::name, _1)))))
  {
    container.name (name);
  }

  // Create the servant artifact for the component.
  this->svnt_artifact_ = GME::Atom::_create ("ImplementationArtifact", container);
  this->svnt_artifact_.name (svnt_name);
  this->svnt_artifact_.attribute ("location").string_value (svnt_name);
  GME::position ("Packaging", Utils::Point (150, 150), this->svnt_artifact_);

  // Create the implementation artifact for the component.
  this->impl_artifact_ = GME::Atom::_create ("ImplementationArtifact", container);
  this->impl_artifact_.name (impl_name);
  this->impl_artifact_.attribute ("location").string_value (impl_name);
  GME::position ("Packaging", Utils::Point (450, 150), this->impl_artifact_);

  return true;
}

//
// scope
//
std::string DefaultArtifactGenerator::
fq_type (const GME::Model & component, const std::string & separator)
{
  std::string scope;
  std::stack <GME::Object> temp_stack;

  // Continue walking up the tree until we reach a File object.
  GME::Object parent = component.parent ();

  while (parent.meta ().name () != "File")
  {
    temp_stack.push (parent);
    parent = parent.parent ();
  }

  // Empty the remainder of the stack.
  while (!temp_stack.empty ())
  {
    parent = temp_stack.top ();
    temp_stack.pop ();

    scope += parent.name () + separator;
  }

  return scope + component.name ();
}

//
// svnt_artifact
//
const GME::Atom & DefaultArtifactGenerator::svnt_artifact (void) const
{
  return this->svnt_artifact_;
}

//
// exec_artifact
//
const GME::Atom & DefaultArtifactGenerator::exec_artifact (void) const
{
  return this->impl_artifact_;
}
