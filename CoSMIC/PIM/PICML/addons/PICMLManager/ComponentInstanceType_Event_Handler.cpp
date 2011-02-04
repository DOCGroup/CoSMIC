// -*- C++ -*-
// $Id: ComponentInstanceType_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "ComponentInstanceType_Event_Handler.h"

#include "game/mga/modelgen.h"
#include "game/mga/utils/Point.h"
#include "game/mga/Atom.h"
#include "game/mga/Connection.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaModel.h"

#include "Utils/Utils.h"

#include <functional>

namespace PICML
{
namespace MI
{

static const unsigned long mask = OBJEVENT_RELATION;

//
// ComponentInstanceType_Event_Handler
//
ComponentInstanceType_Event_Handler::ComponentInstanceType_Event_Handler (void)
: GAME::Mga::Event_Handler_Impl (mask)
{

}

//
// ~ComponentInstanceType_Event_Handler
//
ComponentInstanceType_Event_Handler::~ComponentInstanceType_Event_Handler (void)
{

}

//
// handle_object_relation
//
int ComponentInstanceType_Event_Handler::
handle_object_relation (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  using GAME::Mga::Reference;
  using GAME::Mga::Model;
  using GAME::Mga::Atom;
  using GAME::Mga::Connection;
  using GAME::Mga::FCO;

  Model inst = Model::_narrow (obj->parent ());

  // The the component's implementation.
  Reference ref = GAME::Mga::Reference::_narrow (obj);
  FCO fco = ref->refers_to ();

  if (fco.is_nil ())
  {
    GAME::Mga::Model model = GAME::Mga::Model::_narrow (obj->parent ());

    // Delete the ports in the model.
    std::vector <GAME::Mga::FCO> children;
    GAME::Mga::Meta::Aspect aspect = model->meta ()->aspect ("ComponentInterface");

    model->children (aspect, children);
    std::for_each (children.begin (),
                   children.end (),
                   boost::bind (&GAME::Mga::FCO::impl_type::destroy,
                                boost::bind (&GAME::Mga::FCO::get, _1)));
  }
  else
  {
    // Walk this until we locate the component interface.
    Atom impl = Atom::_narrow (ref->refers_to ());
    std::vector <Connection> implements;
    impl->in_connections ("Implements", implements);

    if (implements.empty ())
      return 0;

    ref = Reference::_narrow (implements.front ()->dst ());
    Model component = Model::_narrow (ref->refers_to ());

    this->generate_port_instances (inst, component);
  }

  return 0;
}

struct generate_instance_t
{
  generate_instance_t (GAME::Mga::Model_in parent, const std::string & type)
    : parent_ (parent),
      type_ (type)
  {

  }

  void operator () (const GAME::Mga::FCO_in target) const
  {
    using GAME::Mga_t;

    using GAME::Mga::Reference;
    using GAME::Mga::FCO;

    Reference ref;

    if (GAME::create_if_not <Mga_t> (this->parent_, this->type_, ref,
        GAME::contains <Mga_t> (boost::bind (std::equal_to <FCO> (),
                                target,
                                boost::bind (&GAME::Mga::Reference::impl_type::refers_to,
                                             boost::bind (&GAME::Mga::Reference::get, _1))))))
    {
      ref->refers_to (target);
      ref->name (target->name ());
    }
  }

private:
  GAME::Mga::Model parent_;

  const std::string & type_;
};

//
// generate_port_instances
//
void ComponentInstanceType_Event_Handler::
generate_port_instances (GAME::Mga::Model inst,  const GAME::Mga::Model & component)
{
  using GAME::Mga::Reference;
  using GAME::Mga::Model;

  std::vector <GAME::Mga::FCO> ports;

  if (component->children ("InEventPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "InEventPortInstance"));

  if (component->children ("OutEventPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "OutEventPortInstance"));

  if (component->children ("ProvidedRequestPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "ProvidedRequestPortInstance"));

  if (component->children ("RequiredRequestPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "RequiredRequestPortInstance"));

  if (component->children ("Attribute", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "AttributeInstance"));

  if (component->children ("ReadonlyAttribute", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "AttributeInstance"));

  if (component->children ("ExtendedPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "ExtendedPortInstance"));

  if (component->children ("MirrorPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "MirrorPortInstance"));

  // Finally, generate the ports of the base type in this
  // component instance.
  std::vector <Reference> inherits;

  if (component->children ("ComponentInherits", inherits))
  {
    Model basetype = Model::_narrow (inherits.front ()->refers_to ());
    this->generate_port_instances (inst, basetype);
  }
}

}
}
