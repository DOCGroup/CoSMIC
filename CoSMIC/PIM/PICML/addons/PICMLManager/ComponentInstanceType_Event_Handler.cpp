// -*- C++ -*-
// $Id: ComponentInstanceType_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "ComponentInstanceType_Event_Handler.h"

#include "game/modelgen.h"
#include "game/utils/Point.h"

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
: GAME::Event_Handler_Impl (mask)
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
handle_object_relation (GAME::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  using GAME::Reference;
  using GAME::Model;
  using GAME::Atom;
  using GAME::Connection;
  using GAME::FCO;

  Model inst = Model::_narrow (obj->parent ());

  // The the component's implementation.
  Reference ref = GAME::Reference::_narrow (obj);
  FCO fco = ref->refers_to ();

  if (fco.is_nil ())
  {
    GAME::Model model = GAME::Model::_narrow (obj->parent ());

    // Delete the ports in the model.
    std::vector <GAME::FCO> children;
    GAME::Meta::Aspect aspect = model->meta ()->aspect ("ComponentInterface");

    model->children (aspect, children);
    std::for_each (children.begin (),
                   children.end (),
                   boost::bind (&GAME::FCO::impl_type::destroy,
                                boost::bind (&GAME::FCO::get, _1)));
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
  generate_instance_t (GAME::Model_in parent, const std::string & type)
    : parent_ (parent),
      type_ (type)
  {

  }

  void operator () (const GAME::FCO_in target) const
  {
    using GAME::Mga_t;

    using GAME::Reference;
    using GAME::FCO;

    Reference ref;

    if (GAME::create_if_not <Mga_t> (this->parent_, this->type_, ref,
        GAME::contains <Mga_t> (boost::bind (std::equal_to <FCO> (),
                                target,
                                boost::bind (&GAME::Reference::impl_type::refers_to,
                                             boost::bind (&GAME::Reference::get, _1))))))
    {
      ref->refers_to (target);
      ref->name (target->name ());
    }
  }

private:
  GAME::Model parent_;

  const std::string & type_;
};

//
// generate_port_instances
//
void ComponentInstanceType_Event_Handler::
generate_port_instances (GAME::Model inst,  const GAME::Model & component)
{
  using GAME::Reference;
  using GAME::Model;

  std::vector <GAME::FCO> ports;

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
