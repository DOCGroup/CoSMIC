// $Id$

#include "StdAfx.h"
#include "Component_Observer_Event_Handler.h"

#include "game/mga/Object_Filter.h"

#include "boost/bind.hpp"
#include <algorithm>

namespace PICML
{
namespace MI
{

//
// Component_Observer_Event_Handler
//
Component_Observer_Event_Handler::Component_Observer_Event_Handler (void)
: GAME::Mga::Object_Event_Handler (OBJEVENT_CREATED | OBJEVENT_PRE_DESTROYED | OBJEVENT_PROPERTIES, false)
{

}

//
// handle_project_open
//
int Component_Observer_Event_Handler::handle_project_open (void)
{
  if (0 != GAME::Mga::Global_Event_Handler::handle_project_open ())
    return -1;

  this->load_instances ();
  return 0;
}

//
// handle_xml_import_end
//
int Component_Observer_Event_Handler::handle_xml_import_end (void)
{
  if (0 != GAME::Mga::Global_Event_Handler::handle_xml_import_end ())
    return -1;

  this->load_instances ();
  return 0;
}

//
// load_instances
//
void Component_Observer_Event_Handler::load_instances (void)
{
  // Locate all the ComponentInstance elements in this project.
  GAME::Mga::Filter filter (this->project_);
  filter.kind ("ComponentInstance");
  std::vector <ComponentInstance> objs;
  filter.apply(objs);
  for (auto obj : objs)
    insert_all (obj);
}

//
// insert_all
//
void Component_Observer_Event_Handler::insert_all (ComponentInstance_in inst)
{
  // Locate the component interface for this implementation. Once we have
  // located it, we are going to store it in the map so we can know what
  // instances to update when the component interface updates.
  ComponentInstanceType type = inst->get_ComponentInstanceType ();
  if (type.is_nil ())
    return;

  MonolithicImplementation impl = type->refers_to_MonolithicImplementation ();
  if (impl.is_nil ())
    return;

  if (!impl->has_src_of_Implements ())
    return;

  ComponentRef ref = impl->src_of_Implements ()->dst_ComponentRef ();
  Component comp = ref->refers_to_Component ();

  if (!comp.is_nil ())
    this->insert (comp, inst);
}

//
// handle_object_created
//
int Component_Observer_Event_Handler::
handle_object_created (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);
  Component comp = Component::_narrow (obj->parent ());

  // Create the correct port instance.
  GAME::Mga::Reference port_inst;

  Component_Map::iterator iter = this->map_.find (comp);

  if (iter != this->map_.end ())
    std::for_each (GAME::Mga::make_impl_iter (iter->second.begin ()),
                   GAME::Mga::make_impl_iter (iter->second.end ()),
                   boost::bind (&Component_Observer_Event_Handler::create_inst, this, fco, _1));

  return 0;
}

//
// handle_object_destroyed
//
int Component_Observer_Event_Handler::
handle_object_predestroyed (GAME::Mga::Object_in obj)
{
  // Delete all the port instances, which are the references that
  // refer to this model element.
  GAME::Mga::Reference port = GAME::Mga::Reference::_narrow (obj);
  GAME::Mga::Collection_T <GAME::Mga::Reference> ports = port->referenced_by ();
  for (auto & port : ports)
    port->destroy();

  return 0;
}

/**
 * @struct validate_name_t
 *
 * Functor that validates the name an object. If the name does not
 * match the supplied name, then item's name is updated.
 */
struct validate_name_t
{
  validate_name_t (const std::string & name)
    : name_ (name)
  {

  }

  void operator () (GAME::Mga::Object_in item) const
  {
    if (this->name_ != item->name ())
      item->name (this->name_);
  }

private:
  const std::string & name_;
};

//
// handle_object_properties
//
int Component_Observer_Event_Handler::
handle_object_properties (GAME::Mga::Object_in obj)
{
  // Delete all the port instances, which are the references that
  // refer to this model element.
  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);
  GAME::Mga::Collection_T <GAME::Mga::Reference> collections = fco->referenced_by ();

  for (auto & collection : collections)
    validate_name_t (collection->name ());

  return 0;
}

//
// update_instance
//
void Component_Observer_Event_Handler::
create_inst (GAME::Mga::FCO_in item, ComponentInstance_in inst)
{
  GAME::Mga::Reference port_inst;
  const std::string metaname = item->meta ()->name ();

  if (metaname == InEventPort_Impl::metaname)
    port_inst = InEventPortInstance_Impl::_create (inst);
  else if (metaname == OutEventPort_Impl::metaname)
    port_inst = OutEventPortInstance_Impl::_create (inst);
  else if (metaname == ProvidedRequestPort_Impl::metaname)
    port_inst = ProvidedRequestPortInstance_Impl::_create (inst);
  else if (metaname == RequiredRequestPort_Impl::metaname)
    port_inst = RequiredRequestPortInstance_Impl::_create (inst);
  else if (metaname == Attribute_Impl::metaname)
    port_inst = AttributeInstance_Impl::_create (inst);
  else if (metaname == ReadonlyAttribute_Impl::metaname)
    port_inst = AttributeInstance_Impl::_create (inst);
  else if (metaname == ExtendedPort_Impl::metaname)
    port_inst = ExtendedPortInstance_Impl::_create (inst);
  else if (metaname == MirrorPort_Impl::metaname)
    port_inst = MirrorPortInstance_Impl::_create (inst);
  else
    return;

  port_inst->name (item->name ());
  port_inst->refers_to (item);
}

} // namespace PICML
} // namespace MI
