#include "StdAfx.h"

#include "Default_Implementation_Generator.h"

#include "game/mga/modelgen.h"
#include "game/mga/utils/Point.h"
#include "game/mga/Attribute.h"
#include "game/mga/Model.h"
#include "game/mga/Project.h"
#include "game/mga/Reference.h"
#include "game/mga/Connection.h"
#include "game/mga/MetaBase.h"
#include "PIM/PICML/utils/game/Utility.h"
#include "boost/bind.hpp"
#include <functional>
#include <stack>

namespace PICML
{
namespace MI
{

//
// Default_Implementation_Generator
//
Default_Implementation_Generator::
Default_Implementation_Generator (GAME::Mga::Project project, const meta_info_t & info)
: info_ (info),
  artifact_gen_ (project, info.artifact_folder_)
{
  using ::GAME::Mga_t;

  PICML::RootFolder root_folder = PICML::RootFolder::_narrow (project.root_folder ());
  auto predicate = GAME::contains <Mga_t> ([&](PICML::ComponentImplementations folder) {
    return folder->name () == info.impl_folder_name_;
  });

  if (GAME::create_if_not <Mga_t> (root_folder, info.impl_folder_, this->impl_folder_, predicate))
    this->impl_folder_->name (info.impl_folder_name_);
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
generate (const Implementation_Configuration & config, Component_in type)
{
  using ::GAME::Mga_t;

  using ::GAME::Mga::Atom;
  using ::GAME::Mga::Connection;
  using ::GAME::Mga::FCO;
  using ::GAME::Mga::Model;
  using ::GAME::Mga::Reference;

  // First, generate the artifacts for this type.
  this->artifact_gen_.generate (config, type);

  // Generate the monolithic implementation.
  std::string name = type->name ();
  std::string fq_type = PICML::fq_type (type, "_");
  std::string impl_name = fq_type + "Impl";

  // Create a new container for the component implementation.
  Model container;

  if (GAME::create_if_not <Mga_t> (this->impl_folder_, this->info_.container_type_, container,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                impl_name,
                                boost::bind (&::GAME::Mga::Model::impl_type::name,
                                             boost::bind (&::GAME::Mga::Model::get, _1))))))
  {
    container->name (impl_name);
  }

  // Create the monolithic implementation for the component.
  Atom impl;

  if (GAME::create_if_not <Mga_t> (container, this->info_.impl_type_, impl,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <std::string> (),
                                impl_name,
                                boost::bind (&::GAME::Mga::Atom::impl_type::name,
                                             boost::bind (&::GAME::Mga::Atom::get, _1))))))
  {
    impl->name (impl_name);
  }

  // Set the location of the implementation.
 GAME::Mga::set_position ("Packaging",
                          GAME::Mga::Point (250, 250),
                          impl);

  // Create the reference to the target component.
  Reference ref;

  if (GAME::create_if_not <Mga_t> (container, this->info_.type_ref_, ref,
      GAME::contains <Mga_t> (boost::bind (std::equal_to <FCO> (),
                                type,
                                boost::bind (&::GAME::Mga::Reference::impl_type::refers_to,
                                             boost::bind (&::GAME::Mga::Reference::get, _1))))))
  {
    ref->refers_to (type);
  }

  // Set the name and location of the reference.
  ref->name (name);

  GAME::Mga::set_position ("Packaging",
                           GAME::Mga::Point (187, 75),
                           ref);

  Connection implements;

  if (!GAME::find <Mga_t> (container, this->info_.implements_type_, implements,
        boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <FCO> (),
                       impl,
                       boost::bind (&::GAME::Mga::Connection::impl_type::src,
                                    boost::bind (&::GAME::Mga::Connection::get, _1))),
          boost::bind (std::equal_to <FCO> (),
                       ref,
                       boost::bind (&::GAME::Mga::Connection::impl_type::dst,
                                    boost::bind (&::GAME::Mga::Connection::get, _1))))))
  {
    implements =
      GAME::Mga::Connection_Impl::_create (container,
                                           this->info_.implements_type_,
                                           impl,
                                           ref);

    implements->name (this->info_.implements_type_);
  }

  // Insert the servant artifact for this component.
  Reference svnt_artifact;

  if (GAME::create_if_not <Mga_t> (container, "ComponentServantArtifact", svnt_artifact,
      GAME::contains <::GAME::Mga_t> (boost::bind (std::equal_to <FCO> (),
                                      this->artifact_gen_.svnt_artifact (),
                                      boost::bind (&GAME::Mga::Reference::impl_type::refers_to,
                                                   boost::bind (&GAME::Mga::Reference::get, _1))))))
  {
    svnt_artifact->refers_to (this->artifact_gen_.svnt_artifact ());
  }

  svnt_artifact->name (this->artifact_gen_.svnt_artifact ()->name ());

  std::string entrypoint ("create_" + fq_type + "_Servant");
  svnt_artifact->attribute ("EntryPoint")->string_value (entrypoint);

  GAME::Mga::set_position ("Packaging",
                           GAME::Mga::Point (506,347),
                           svnt_artifact);

  Connection pa;
  static const std::string meta_MonolithprimaryArtifact ("MonolithprimaryArtifact");

  if (!GAME::find <Mga_t> (container, meta_MonolithprimaryArtifact, pa,
        boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <FCO> (),
                       impl,
                       boost::bind (&GAME::Mga::Connection::impl_type::src,
                                    boost::bind (&GAME::Mga::Connection::get, _1))),
          boost::bind (std::equal_to <FCO> (),
                       svnt_artifact,
                       boost::bind (&GAME::Mga::Connection::impl_type::dst,
                                    boost::bind (&GAME::Mga::Connection::get, _1))))))
  {
    pa =
      GAME::Mga::Connection_Impl::_create (container,
                                           meta_MonolithprimaryArtifact,
                                           impl,
                                           svnt_artifact);

    pa->name (meta_MonolithprimaryArtifact);
  }

  // Insert the implementation artifact for this component.
  Reference impl_artifact;

  if (GAME::create_if_not <Mga_t> (container, "ComponentImplementationArtifact", impl_artifact,
      GAME::contains <::GAME::Mga_t> (boost::bind (std::equal_to <FCO> (),
                                      this->artifact_gen_.exec_artifact (),
                                      boost::bind (&GAME::Mga::Reference::impl_type::refers_to,
                                                   boost::bind (&GAME::Mga::Reference::get, _1))))))
  {
    impl_artifact->refers_to (this->artifact_gen_.exec_artifact ());
  }

  impl_artifact->name (this->artifact_gen_.exec_artifact ()->name ());

  entrypoint = "create_" + fq_type + "_Impl";
  impl_artifact->attribute ("EntryPoint")->string_value (entrypoint);

  GAME::Mga::set_position ("Packaging",
                           GAME::Mga::Point (506,151),
                           impl_artifact);

  if (!GAME::find <Mga_t> (container, meta_MonolithprimaryArtifact, pa,
        boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <FCO> (),
                       impl,
                       boost::bind (&GAME::Mga::Connection::impl_type::src,
                                    boost::bind (&::GAME::Mga::Connection::get, _1))),
          boost::bind (std::equal_to <FCO> (),
                       impl_artifact,
                       boost::bind (&GAME::Mga::Connection::impl_type::dst,
                                    boost::bind (&::GAME::Mga::Connection::get, _1))))))
  {
    pa =
      GAME::Mga::Connection_Impl::_create (container,
                                           meta_MonolithprimaryArtifact,
                                           impl,
                                           impl_artifact);

    pa->name (meta_MonolithprimaryArtifact);
  }

  return true;
}

}
}
