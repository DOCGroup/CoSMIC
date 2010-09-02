// $Id$

#include "Implementation_Generator.h"
#include "Scope.h"

#include "game/xme/functional.h"
#include "game/xme/Connection.h"

#include "game/utils/modelgen.h"
#include "game/utils/Point.h"
#include "boost/bind.hpp"
#include <functional>
#include <stack>

namespace constant
{
namespace meta
{
  const GAME::Xml::String MonolithprimaryArtifact ("MonolithprimaryArtifact");
}

namespace aspect
{
  const GAME::Xml::String Packaging ("Packaging");
}

namespace attr
{
  const GAME::Xml::String EntryPoint ("EntryPoint");
}

}

//
// Implementation_Generator
//
Implementation_Generator::
Implementation_Generator (GAME::XME::Folder & root)
: artifact_gen_ (root)
{
  static const GAME::Xml::String meta_ComponentImplementations ("ComponentImplementations");

  if (GAME::create_if_not (root, meta_ComponentImplementations, this->impls_,
      GAME::contains (boost::bind (std::equal_to < GAME::Xml::String > (),
                      meta_ComponentImplementations,
                      boost::bind (&GAME::XME::Folder::name, _1)))))
  {
    this->impls_.name (meta_ComponentImplementations);
  }
}

//
// ~Implementation_Generator
//
Implementation_Generator::~Implementation_Generator (void)
{

}

//
// generate
//
bool Implementation_Generator::generate (const GAME::XME::Model & component)
{
  // First, generate the artifacts for the component.
  this->artifact_gen_.generate (component);

  // Generate the monolithic implementation.
  GAME::Xml::String name (component.name (), false);

  GAME::Xml::String fq_type;
  Scope::fq_name (component, "_", false, fq_type);

  static const GAME::Xml::String impl_suffix ("Impl");
  GAME::Xml::String impl_name (fq_type);
  impl_name.append (impl_suffix);

  // Create a new container for the component implementation.
  GAME::XME::Model container;

  static const GAME::Xml::String meta_ComponentImplementationContainer ("ComponentImplementationContainer");

  if (GAME::create_if_not (this->impls_, meta_ComponentImplementationContainer, container,
      GAME::contains (boost::bind (std::equal_to < GAME::Xml::String > (),
                      impl_name,
                      boost::bind (&GAME::XME::Model::name, _1)))))
  {
    container.name (impl_name);
  }

  // Create the monolithic implementation for the component.
  GAME::XME::Atom impl;
  static const GAME::Xml::String meta_MonolithicImplementation ("MonolithicImplementation");

  if (GAME::create_if_not (container, meta_MonolithicImplementation, impl,
      GAME::contains (boost::bind (std::equal_to < GAME::Xml::String > (),
                      impl_name,
                      boost::bind (&GAME::XME::Atom::name, _1)))))
  {
    impl.name (impl_name);
  }

  GAME::XME::set_position (impl,
                           constant::aspect::Packaging,
                           250, 
                           250);

  // Create the reference to the target component.
  GAME::XME::Reference component_ref;
  static const GAME::Xml::String meta_ComponentRef ("ComponentRef");

  GAME::create_if_not (container, meta_ComponentRef, component_ref,
    GAME::contains (boost::bind (std::equal_to < GAME::Xml::String > (),
                    meta_ComponentRef,
                    boost::bind (&GAME::XME::Atom::kind, _1))));

  component_ref.name (name);
  component_ref.refers_to (component);

  GAME::XME::set_position (component_ref,
                           constant::aspect::Packaging,
                           187, 
                           75);

  // Associate the monolithic implementation with the reference.
  using GAME::XME::Connection;

  static const GAME::Xml::String meta_Implements ("Implements");
  Connection connection;

  if (!GAME::find (container, meta_Implements, connection,
        boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <GAME::XME::FCO> (),
                       impl,
                       boost::bind (&Connection::src, _1)),
          boost::bind (std::equal_to <GAME::XME::FCO> (),
                       component_ref,
                       boost::bind (&Connection::dst, _1)))))
  {
    GAME::XME::Connection::_create (container,
                                   meta_Implements,
                                   impl,
                                   component_ref);
  }

  this->generate_servant (container, impl, fq_type);
  this->generate_impl (container, impl, fq_type);

  return true;
}

//
// generate_impl
//
void Implementation_Generator::
generate_impl (GAME::XME::Model & container,
               const GAME::XME::FCO & impl,
               const GAME::Xml::String & fq_type)
{
  static const GAME::Xml::String meta_ComponentImplementationArtifact ("ComponentImplementationArtifact");
  GAME::XME::Reference impl_artifact;

  if (GAME::create_if_not (container, meta_ComponentImplementationArtifact, impl_artifact,
      GAME::contains (boost::bind (std::equal_to <GAME::XME::FCO> (),
                      this->artifact_gen_.exec_artifact (),
                      boost::bind (&GAME::XME::Reference::refers_to, _1)))))
  {
    impl_artifact.refers_to (this->artifact_gen_.exec_artifact ());
  }

  impl_artifact.name (GAME::Xml::String (this->artifact_gen_.exec_artifact ().name (), false));

  // Set the entrypoint for the implementation artifact.
  static const GAME::Xml::String _Impl ("_Impl");

  GAME::Xml::String entrypoint = "create_";
  entrypoint.append (fq_type);
  entrypoint.append (_Impl);

  impl_artifact.attribute (constant::attr::EntryPoint, true).value (entrypoint);

  GAME::XME::set_position (impl_artifact,
                           constant::aspect::Packaging,
                           506,
                           151);

  using GAME::XME::Connection;
  Connection connection;

  if (!GAME::find (container, constant::meta::MonolithprimaryArtifact, connection,
        boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <GAME::XME::FCO> (),
                       impl,
                       boost::bind (&Connection::src, _1)),
          boost::bind (std::equal_to <GAME::XME::FCO> (),
                       impl_artifact,
                       boost::bind (&Connection::dst, _1)))))
  {
    GAME::XME::Connection::_create (container,
                                   constant::meta::MonolithprimaryArtifact,
                                   impl,
                                   impl_artifact);
  }
}

//
// generate_servant
//
void Implementation_Generator::
generate_servant (GAME::XME::Model & container,
                  const GAME::XME::FCO & impl,
                  const GAME::Xml::String & fq_type)
{
  // First, create the servant artifact for the implementation.
  static const GAME::Xml::String meta_ComponentServantArtifact ("ComponentServantArtifact");
  GAME::XME::Reference svnt_artifact;

  if (GAME::create_if_not (container, meta_ComponentServantArtifact, svnt_artifact,
      GAME::contains (boost::bind (std::equal_to <GAME::XME::FCO> (),
                      this->artifact_gen_.svnt_artifact (),
                      boost::bind (&GAME::XME::Reference::refers_to, _1)))))
  {
    svnt_artifact.refers_to (this->artifact_gen_.svnt_artifact ());
  }

  svnt_artifact.name (GAME::Xml::String (this->artifact_gen_.svnt_artifact ().name (), false));

  static const GAME::Xml::String _Servant ("_Servant");

  GAME::Xml::String entrypoint ("create_");
  entrypoint.append (fq_type);
  entrypoint.append (_Servant);

  svnt_artifact.attribute (constant::attr::EntryPoint, true).value (entrypoint);
  GAME::XME::set_position (svnt_artifact,
                           constant::aspect::Packaging,
                           506,
                           347);

  // Next, associate the artifact with the implementation.
  using GAME::XME::Connection;
  Connection connection;

  if (!GAME::find (container, constant::meta::MonolithprimaryArtifact, connection,
        boost::bind (std::logical_and <bool> (),
          boost::bind (std::equal_to <GAME::XME::FCO> (),
                       impl,
                       boost::bind (&Connection::src, _1)),
          boost::bind (std::equal_to <GAME::XME::FCO> (),
                       svnt_artifact,
                       boost::bind (&Connection::dst, _1)))))
  {
    GAME::XME::Connection::_create (container,
                                   constant::meta::MonolithprimaryArtifact,
                                   impl,
                                   svnt_artifact);
  }
}
