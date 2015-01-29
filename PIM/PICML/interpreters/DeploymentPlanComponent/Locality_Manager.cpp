#include "StdAfx.h"
#include "Locality_Manager.h"
#include "game/xml/Fragment.h"

using GAME::Xml::Fragment;
using GAME::Xml::String;

namespace PICML
{
namespace Deployment
{

const std::string Locality_Manager::DEFAULT_ARTIFACT_ID ("_2DBE7BA9-5DB7-48e2-A260-D141CB66DEB1");
const std::string Locality_Manager::DEFAULT_ARTIFACT_NAME ("DAnCE_LocalityManager_Artifact");

const std::string Locality_Manager::DEFAULT_IMPLEMENTATION_ID ("_1C073253-AACD-4130-B0A8-6AED69931E25_");
const std::string Locality_Manager::DEFAULT_IMPLEMENTATION_NAME ("DAnCE_LocalityManager_Impl");

//
// generate_artifacts
//
void Locality_Manager::generate_default_artifacts (GAME::Xml::Fragment parent)
{
  // Set the id for the artifact.
  Fragment artifact = parent.create_element ("artifact");
  artifact.set_attribute ("xmi:id", DEFAULT_ARTIFACT_ID);

  // Add the remaining tags to the artifact.
  artifact.create_simple_content ("name", DEFAULT_ARTIFACT_NAME);
  artifact.create_simple_content ("source", "");
  artifact.create_simple_content ("node", "");
  artifact.create_simple_content ("location", "dance_locality_manager");
}

//
// generate_artifacts
//
void Locality_Manager::generate_default_implementation (GAME::Xml::Fragment parent)
{
  Fragment impl = parent.create_element ("implementation");
  impl.set_attribute ("xmi:id", DEFAULT_IMPLEMENTATION_ID);

  // Add the remaining tags to the implementation.
  impl.create_simple_content ("name", DEFAULT_IMPLEMENTATION_NAME);
  impl.create_simple_content ("source", "");

  Fragment artifact = impl.create_element ("artifact");
  artifact.set_attribute ("xmi:idref", DEFAULT_ARTIFACT_ID);

  Fragment execParameter = impl.create_element ("execParameter");
  execParameter.create_simple_content ("name", "edu.vanderbilt.dre.DAnCE.ImplementationType");
  Fragment value = execParameter.create_element ("value");
  Fragment type = value.create_element ("type");
  type.create_simple_content ("kind", "tk_string");
  Fragment inner_value = value.create_element ("value");
  inner_value.create_simple_content ("string", "edu.vanderbilt.dre.DAnCE.LocalityManager");
}

//
// generate_default_instance_configs
//
void Locality_Manager::
generate_default_instance_configs (GAME::Xml::Fragment parent, PICML::CollocationGroup_in group)
{
  Fragment configProperty = parent.create_element ("configProperty");
  configProperty.create_simple_content ("name", "edu.vanderbilt.dre.DAnCE.LocalityManager.ProcessName");

  Fragment value = configProperty.create_element ("value");
  Fragment type = value.create_element ("type");
  type.create_simple_content ("kind", "tk_string");
  
  Fragment inner_value = value.create_element ("value");
  inner_value.create_simple_content ("string", group->name ());
}

}
}
