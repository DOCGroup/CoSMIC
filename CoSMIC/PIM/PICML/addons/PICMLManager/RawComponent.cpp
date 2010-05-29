// $Id$

#include "StdAfx.h"
#include "Common.h"
#include "ComHelp.h"
#include "GMECOM.h"
#include "Dialogs.h"
#include "ComponentConfig.h"
#include "RawComponent.h"
#include "DefaultImplementationGenerator.h"
#include "NewComponentConfig.h"
#include "Utils/Utils.h"
#include "game/utils/Point.h"
#include "boost/bind.hpp"
#include <algorithm>
#include <sstream>

// Type definition
typedef std::vector <GAME::Reference> Reference_Set;

//
// RawComponent
//
RawComponent::RawComponent (void)
: importing_ (0)
{

}

//
// ~RawComponent
//
RawComponent::~RawComponent (void)
{

}

//
// Initaialize
//
STDMETHODIMP RawComponent::Initialize (struct IMgaProject * project)
{
  this->project_ = project;

  this->handlers_.bind ("ExternalDelegate",
                        &RawComponent::handle_ExternalDelegate);

  this->handlers_.bind ("PublishConnector",
                        &RawComponent::handle_PublishConnector);

  this->handlers_.bind ("AttributeValue",
                        &RawComponent::handle_AttributeValue);

  this->handlers_.bind ("AttributeMember",
                        &RawComponent::handle_AttributeMember);

  this->handlers_.bind ("CollocationGroup",
                        &RawComponent::handle_CollocationGroup);

  this->handlers_.bind ("Component",
                        &RawComponent::handle_Component);

  this->handlers_.bind ("ComponentAssembly",
                        &RawComponent::handle_ComponentAssembly);

  this->handlers_.bind ("ComponentPackage",
                        &RawComponent::handle_ComponentPackage);

  this->handlers_.bind ("ComponentRef",
                        &RawComponent::handle_ComponentRef);

  this->handlers_.bind ("Domain",
                        &RawComponent::handle_Domain);

  this->handlers_.bind ("PackageConfiguration",
                        &RawComponent::handle_PackageConfiguration);

  this->handlers_.bind ("MonolithicImplementation",
                        &RawComponent::handle_MonolithicImplementation);

  this->handlers_.bind ("ImplementationArtifact",
                        &RawComponent::handle_ImplementationArtifact);

  this->handlers_.bind ("ComponentImplementation",
                        &RawComponent::handle_ComponentImplementation);

  this->handlers_.bind ("ComponentFactoryInstance",
                        &RawComponent::handle_ComponentFactoryInstance);

  this->handlers_.bind ("DeploymentPlan",
                        &RawComponent::handle_DeploymentPlan);

  this->handlers_.bind ("NodeReference",
                        &RawComponent::handle_NodeReference);

  return S_OK;
}

//
// Invoke [obsolete]
//
STDMETHODIMP RawComponent::Invoke (IMgaProject* gme,
                                   IMgaFCOs *models,
                                   long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// InvokeEx
//
STDMETHODIMP RawComponent::InvokeEx (IMgaProject *project,
                                     IMgaFCO *currentobj,
                                     IMgaFCOs *selectedobjs,
                                     long param)
{
  return E_MGA_NOT_SUPPORTED;
}


//
// ObjectsInvokeEx [not implemented]
//
STDMETHODIMP RawComponent::ObjectsInvokeEx (IMgaProject *project,
                                            IMgaObject *currentobj,
                                            IMgaObjects *selectedobjs,
                                            long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// get_ComponentParameter
//
STDMETHODIMP RawComponent::get_ComponentParameter(BSTR name, VARIANT *pVal)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// put_ComponentParameter
//
STDMETHODIMP RawComponent::put_ComponentParameter (BSTR name, VARIANT newVal)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// GlobalEvent
//
STDMETHODIMP RawComponent::GlobalEvent (globalevent_enum event)
{
  /*
   * Right now I am simplifying the UUIDManager and it no longer
   * processes GlobalEvent messages. Instead the UUID manager
   * only creates UUIDs and manages existing ones when and
   * ObjectEvent is sent.
   */

  try
  {
    switch (event)
    {
    case APPEVENT_XML_IMPORT_BEGIN:
      this->importing_ = 1;
      break;

    case GLOBALEVENT_OPEN_PROJECT:
      // this->verify_all_uuids ();
      break;

    case APPEVENT_XML_IMPORT_END:
      this->importing_ = 0;
      // this->verify_all_uuids ();
      break;

    case GLOBALEVENT_NOTIFICATION_READY:
      //this->handle_pending ();
      break;

    default:
      /* do nothing */;
    }
  }
  catch (...)
  {
    AfxMessageBox ("Caught an unknown exception");
  }

  return S_OK;
}

//
// ObjectEvent
//
STDMETHODIMP RawComponent::
ObjectEvent (IMgaObject * obj, unsigned long eventmask, VARIANT v)
{
  //if (this->pending_.GetCount ())
  //  this->handle_pending ();

  //if (this->importing_)
  //  return S_OK;

  try
  {
    GAME::Object object (obj);

    if (object.is_lib_object ())
      return 0;

    // Get the meta information for the object.
    std::string type = object.meta ().name ();

    // Locate the handler for this object type.
    _member_function handler;

    if (this->handlers_.find (type, handler) != -1)
      (this->*handler) (eventmask, object);
  }
  catch (GAME::Exception &)
  {
    /* what should we really do right here??? */
  }
  catch (...)
  {
    /* what should we really do right here??? */
  }

  return S_OK;
}

//
// create_uuid
//
void RawComponent::
create_uuid (const GAME::FCO & fco)
{
  GAME::Attribute uuid_attr;

  if (this->get_uuid_i (fco, uuid_attr))
  {
    long status = uuid_attr.status ();

    // This will force the generation of an UUID for any element
    // that requires an UUID, including instances and subtypes.
    try
    {
      uuid_attr.string_value (Utils::CreateUuid ());
    }
    catch (...)
    {
      this->pending_.push_back (fco);
    }
  }
}

//
// verify_uuid
//
void RawComponent::verify_uuid (const GAME::FCO & fco)
{
  GAME::Attribute uuid_attr;

  if (this->get_uuid_i (fco, uuid_attr))
  {
    if (Utils::ValidUuid (uuid_attr.string_value ()))
      return;

    try
    {
      uuid_attr.string_value (Utils::CreateUuid ());
    }
    catch (GAME::Exception &)
    {
      this->pending_.push_back (fco);
    }
    catch (...)
    {

    }
  }
}

//
// get_uuid_i
//
bool RawComponent::
get_uuid_i (const GAME::FCO & fco, GAME::Attribute & attr)
{
  typedef std::vector <GAME::Attribute> Attribute_Set;
  Attribute_Set attrs;

  // Get all the attributes of this FCO. It would be nice to query
  // the FCO for the attribute of interest, however, that capability
  // seems to be broken in the current MGA library.
  if (fco.attributes (attrs))
  {
    // We need to iterate over all the attribute until we find the
    // attribute with the name of UUID. That will be the attribute
    // we return to the caller.
    for (Attribute_Set::iterator iter = attrs.begin ();
         iter != attrs.end ();
         iter ++)
    {
      if (iter->meta ().name () == "UUID")
      {
        attr = *iter;
        return true;
      }
    }
  }

  return false;
}

//
// verify_all_uuids
//
void RawComponent::verify_all_uuids (void)
{
  // Get all the component (component assembly) objects.
  CComPtr <IMgaFilter> filter;
  this->project_.impl ()->CreateFilter (&filter);

  long status;
  this->project_.impl ()->get_ProjectStatus (&status);

  filter->put_Kind (L"Component ComponentAssembly");
  filter->put_Level (L"0-");
  filter->put_ObjType (L"OBJTYPE_MODEL");

  CComPtr <IMgaFCOs> fcos;
  VERIFY_HRESULT (this->project_.impl ()->AllFCOs (filter, &fcos));

  long count;
  fcos->get_Count (&count);

  for (long i = 1; i <= count; i ++)
  {
    CComPtr <IMgaFCO> fco;
    fcos->get_Item (i, &fco);

    VARIANT_BOOL lib_object;
    fco->get_IsLibObject (&lib_object);

    if (lib_object == VARIANT_FALSE)
      this->verify_uuid (fco.p);
  }
}

//
// handle_pending
//
void RawComponent::handle_pending (void)
{
  long status;
  this->project_.impl ()->get_ProjectStatus (&status);

  while (!this->pending_.empty ())
  {
    this->verify_uuid (this->pending_.back ());
    this->pending_.pop_back ();
  }
}

//
// set_property_datatype
//
void RawComponent::
set_property_datatype (GAME::Model & prop, const GAME::FCO & type)
{
  // We need to make sure there isn't a data type already
  // present in the target prop.
  Reference_Set datatypes;
  GAME::Reference datatype;

  if (0 == prop.children ("DataType", datatypes))
  {
    datatype = GAME::Reference::_create (prop, "DataType");
  }
  else
  {
    datatype = datatypes.front ();
  }

  // Set the name of the data type and its reference.
  if (datatype.name () != type.name ())
    datatype.name (type.name ());

  // Get the current data type.
  GAME::FCO curr_type = datatype.refers_to ();

  if (curr_type.is_nil () || (curr_type != type))
    datatype.refers_to (type);
}

//
// verify_property_datatype
//
void RawComponent::
verify_property_datatype_entry (GAME::ConnectionPoints::value_type & attr,
                                const GAME::FCO & attr_type)
{
  verify_property_datatype (attr.item (), attr_type);
}

//
// verify_property_datatype
//
void RawComponent::
verify_property_datatype (GAME::ConnectionPoint & attr,
                          const GAME::FCO & attr_type)
{
  // Get the own of this connection. If this is an AttributeValue
  // connection, then we should continue walking the connection
  // until we get to the prop.
  GAME::Connection attr_value = GAME::Connection::_narrow (attr.owner ());

  if (attr_value.meta ().name () == "AttributeValue")
  {
    // We need to find the 'dst' connection point in this collection.
    // It will point to the target prop model.
    GAME::ConnectionPoints connpoints;
    attr_value.connection_points (connpoints);

    // Get the prop element from the connection. It will be
    // the 'dst' connection point.
    GAME::Model prop = GAME::Model::_narrow (connpoints["dst"].target ());

    // Set the data type for the prop.
    set_property_datatype (prop, attr_type);
  }
}

//
// handle_ExternalDelegate
//
void RawComponent::
handle_ExternalDelegate (unsigned long eventmask, GAME::Object & obj)
{
  // Extract the connection for the FCO.
  GAME::Connection ext_conn = GAME::Connection::_narrow (obj);
  GAME::ConnectionPoints points;

  if (ext_conn.connection_points (points))
  {
    // Get the connection points.
    GAME::ConnectionPoint ext_src = points["src"];
    GAME::ConnectionPoint ext_dst = points["dst"];

    // Get the destination port type (i.e., the target delegation port).
    GAME::Reference dst_port = GAME::Reference::_narrow (ext_dst.target ());
    GAME::Atom src_port = GAME::Atom::_narrow (ext_src.target ());

    // Update the name of the external reference.
    if (src_port.name () != dst_port.name ())
      src_port.name (dst_port.name ());
  }
}

//
// handle_PublishConnector
//
void RawComponent::
handle_PublishConnector (unsigned long eventmask, GAME::Object & obj)
{
  // We need to set the name of the newly create connector.
  if ((eventmask & OBJEVENT_CREATED))
    obj.name (obj.id ());
}

//
// handle_AttributeValue
//
void RawComponent::
handle_AttributeMember (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_RELATION))
  {
    // The reference for the attribute changes. This is either
    // because the reference was cleared, or another data type
    // was referenced. Either way, we need to update all the
    // properties in component assemblies for this attribute.

    GAME::Reference member = GAME::Reference::_narrow (obj);
    GAME::FCO attr_type = member.refers_to ();

    if (attr_type)
    {
      // Get the AttributeValue connection.
      GAME::Model attr = member.parent_model ();

      // Get all connection points that connect to this attribute.
      GAME::ConnectionPoints connpoints;
      attr.in_connection_points (connpoints);

      std::for_each (connpoints.begin (),
                     connpoints.end (),
                     boost::bind (&RawComponent::verify_property_datatype_entry,
                                  _1,
                                  attr_type));
    }
  }
}

//
// handle_AttributeValue
//
void RawComponent::
handle_AttributeValue (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_CREATED))
  {
    // Extract the connection from the object and get
    // the connection points in model.
    GAME::Connection attr_value = GAME::Connection::_narrow (obj);
    GAME::ConnectionPoints connpoints;

    if (attr_value.connection_points (connpoints) >= 2)
    {
      // Get the attribute at the 'src' of the connection.
      GAME::Model attr =
        GAME::Model::_narrow (connpoints["src"].target ());

      GAME::FCO attr_type;
      Reference_Set attr_members;

      if (1 == attr.children ("AttributeMember", attr_members))
      {
        // Let's get the data type of the attribute. Since there
        // is only 1 attribute member, we can just get the front
        // element in the container.
        attr_type = attr_members.front ().refers_to ();
      }

      // We have the destination connection point. This should
      // be a prop in an assembly.
      GAME::Model prop =
        GAME::Model::_narrow (connpoints["dst"].target ());

      // Set the name of the Property. We want to ensure the name
      // to the prop matches the name of the attribute.
      if (prop.name () != attr.name ())
        prop.name (attr.name ());

      if (attr_type)
        this->set_property_datatype (prop, attr_type);
    }
  }
}

//
// handle_Component
//
void RawComponent::
handle_Component (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));

  // If this is a newly created component, we need to generate
  // the default implementation elements for this component.
  if (!this->importing_ && (eventmask & OBJEVENT_CREATED))
  {
    // The parent determines if we should move forward. We should
    // only generate default artifacts for components that appear
    // in the file.
    GAME::Object parent = obj.parent ();
    std::string type = parent.meta ().name ();

    if ((type == "File" || type == "Package"))
    {
      // If the name is "Component", then this means that the
      // object was manaully added to the model and the default
      // name was assigned to the object.
      NewComponentConfig config;
      config.component_name_ = obj.name ().c_str ();

      if (obj.name () == "Component")
      {
        // Allow the end-user to rename the component. This will
        // also set the suffixes for the artifacts.
        NewComponentDialog new_component (config, ::AfxGetMainWnd ());

        if (new_component.DoModal () == IDCANCEL)
          return;

        // Set the name of the component.
        obj.name (config.component_name_.c_str ());
      }

      // Generate the component's default implementation.
      GAME::Folder root_folder = obj.project ().root_folder ();
      DefaultImplementationGenerator impl_gen (root_folder, config);

      GAME::Model component = GAME::Model::_narrow (obj);
      impl_gen.generate (component);
    }
  }
}

//
// handle_ComponentAssembly
//
void RawComponent::
handle_ComponentAssembly (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_ComponentPackage
//
void RawComponent::
handle_ComponentPackage (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_ComponentFactoryInstance
//
void RawComponent::
handle_ComponentFactoryInstance (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_Domain
//
void RawComponent::
handle_Domain (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_MonolithicImplementation
//
void RawComponent::
handle_MonolithicImplementation (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_PackageConfiguration
//
void RawComponent::
handle_PackageConfiguration (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_ComponentImplementation
//
void RawComponent::
handle_ComponentImplementation (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_DeploymentPlan
//
void RawComponent::
handle_DeploymentPlan (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_ImplementationArtifact
//
void RawComponent::
handle_ImplementationArtifact (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
}

//
// handle_UUID
//
void RawComponent::
handle_UUID (unsigned long eventmask, GAME::FCO & fco)
{
  // We are managing an object that has a UUID.
  if ((eventmask & OBJEVENT_CREATED) != 0)
  {
    this->create_uuid (fco);
  }
  else if ((eventmask & OBJEVENT_ATTR) != 0)
  {
    this->verify_uuid (fco);
  }
}

//
// handle_NodeReference
//
void RawComponent::
handle_NodeReference (unsigned long eventmask, GAME::Object & obj)
{
  if (this->importing_)
    return;

  if ((eventmask & OBJEVENT_CREATED) != 0)
  {
    static const char * _REGPATH_ = "PartRegs/NodeMapping/Position";

    // Get the parent model for the node reference.
    GAME::Reference node = GAME::Reference::_narrow (obj);
    GAME::Model parent = GAME::Model::_narrow (node.parent ());

    // Create a 'default' collocation group for the node reference
    GAME::Set group = GAME::Set::_create (parent, "CollocationGroup");
    group.name ("DefaultGroup");

    // Create an InstanceMapping connection between the node reference
    // and the collocation group.
    GAME::Connection mapping =
      GAME::Connection::_create (parent, "InstanceMapping", group, node);

    // Align the collocation group with its corresponding node.
    GAME::utils::Point pt;
    GAME::utils::position ("NodeMapping", node, pt);
    pt.shift (4, 128);

    GAME::utils::position ("NodeMapping", pt, group);
  }
}

//
// handle_CollocationGroup
//
void RawComponent::
handle_CollocationGroup (unsigned long eventmask, GAME::Object & obj)
{
  if (this->cg_member_)
  {
    // Get all sets that contain previously inserted collocation group member.
    typedef std::vector <GAME::Set> Sets;
    Sets sets;

    size_t count = this->cg_member_.in_sets (sets);

    if (count > 1)
    {
      // Get the updated collocation group.
      GAME::Set group = GAME::Set::_narrow (obj);

      Sets::iterator
        iter = sets.begin (), iter_end = sets.end ();

      // Make sure the last object added to this group does not appear
      // in any collocation group.
      for ( ; iter != iter_end; ++ iter)
      {
        if (!iter->is_equal_to (group))
          iter->remove (this->cg_member_);
      }
    }

    // Release our reference to this element.
    this->cg_member_.release ();
  }
}

//
// handle_ComponentRef
//
void RawComponent::
handle_ComponentRef (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_SETINCLUDED) != 0)
  {
    this->cg_member_ = GAME::FCO::_narrow (obj);
  }
}
