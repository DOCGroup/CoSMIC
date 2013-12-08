// -*- C++ -*-
// $Id: ComponentInstanceType_Event_Handler.cpp 2482 2010-09-08 04:26:38Z hillj $

#include "StdAfx.h"
#include "ComponentInstanceType_Event_Handler.h"

#include "game/mga/modelgen.h"
#include "game/mga/MetaModel.h"
#include "game/mga/Object_Filter.h"

#include <functional>
#include "boost/bind.hpp"

namespace PICML
{
namespace MI
{

//
// ComponentInstanceType_Event_Handler
//
ComponentInstanceType_Event_Handler::ComponentInstanceType_Event_Handler (void)
: GAME::Mga::Object_Event_Handler (OBJEVENT_RELATION | OBJEVENT_PRE_DESTROYED)
{

}

//
// ~ComponentInstanceType_Event_Handler
//
ComponentInstanceType_Event_Handler::~ComponentInstanceType_Event_Handler (void)
{

}

//
// handle_project_open
//
int ComponentInstanceType_Event_Handler::handle_project_open (void)
{
  if (0 != GAME::Mga::Global_Event_Handler::handle_project_open ())
    return -1;

  this->load_defined_types ();
  return 0;
}

//
// handle_xml_import_end
//
int ComponentInstanceType_Event_Handler::handle_xml_import_end (void)
{
  if (0 != GAME::Mga::Global_Event_Handler::handle_xml_import_end ())
    return -1;

  this->load_defined_types ();
  return 0;
}

//
// load_defined_types
//
void ComponentInstanceType_Event_Handler::load_defined_types (void)
{
  GAME::Mga::Filter filter (this->project_);
  filter.kind (ComponentInstanceType_Impl::metaname);
  GAME::Mga::Iterator <ComponentInstanceType> iter = filter.apply <ComponentInstanceType> ();

  std::for_each (GAME::Mga::make_impl_iter (iter),
                 GAME::Mga::make_impl_iter (iter.make_end ()),
                 boost::bind (&std::set <ComponentInstanceType>::insert, boost::ref (this->defined_), _1));
}

//
// handle_object_relation
//
int ComponentInstanceType_Event_Handler::handle_object_relation (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  ComponentInstanceType inst_type = ComponentInstanceType::_narrow (obj);

  if (this->defined_.find (inst_type) != this->defined_.end ())
  {
    // We do not allow you to redefine the component instance type. You
    // must delete the component instance, and then add a new one.
    ::AfxMessageBox ("Not allowed to redefine a component instance type.", MB_ICONERROR);
    return -1;
  }
  else
  {
    ComponentInstance inst = ComponentInstance::_narrow (inst_type->parent ());
    MonolithicImplementation impl = inst_type->get_MonolithicImplementation ();
    std::vector <Implements> implements;

    if (impl->src_Implements (implements))
    {
      ComponentRef cref = implements.front ()->dst_ComponentRef ();
      Component comp = cref->refers_to ();

      if (!comp.is_nil ())
        this->generate_port_instances (inst, comp);
    }

    // Store the instance type for later usage.
    this->defined_.insert (inst_type);
  }

  return 0;
}

//
// delete_all_ports
//
void ComponentInstanceType_Event_Handler::delete_all_ports (ComponentInstance_in inst)
{
  // Delete all the children in the inferface.
  std::vector <GAME::Mga::FCO> children;
  static const std::string aspect_ComponentInterface ("ComponentInterface");
  GAME::Mga::Meta::Aspect aspect = inst->meta ()->aspect (aspect_ComponentInterface);

  inst->children (aspect, children);
  std::for_each (GAME::Mga::make_impl_iter (children.begin ()),
                 GAME::Mga::make_impl_iter (children.end ()),
                 boost::bind (&GAME::Mga::FCO::impl_type::destroy, _1));
}

//
// handle_object_predestroyed
//
int ComponentInstanceType_Event_Handler::
handle_object_predestroyed (GAME::Mga::Object_in obj)
{
  ComponentInstanceType inst_type = ComponentInstanceType::_narrow (obj);
  this->defined_.erase (inst_type);

  return 0;
}

/**
 * @struct generate_instance_t
 */
struct generate_instance_t
{
  generate_instance_t (ComponentInstance_in parent, const std::string & type)
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
  ComponentInstance_in parent_;

  const std::string & type_;
};

//
// generate_port_instances
//
void ComponentInstanceType_Event_Handler::
generate_port_instances (ComponentInstance_in inst, Component_in component)
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

  if (component->children ("Supports", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "SupportsInstance"));

  // Finally, generate the ports of the base type in this
  // component instance.
  std::vector <Reference> inherits;

  if (component->children ("ComponentInherits", inherits))
  {
    Component basetype = Component::_narrow (inherits.front ()->refers_to ());
    this->generate_port_instances (inst, basetype);
  }
}

}
}
