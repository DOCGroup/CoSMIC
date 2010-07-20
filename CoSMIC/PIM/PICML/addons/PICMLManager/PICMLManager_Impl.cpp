// $Id$

#include "StdAfx.h"
#include "PICMLManager_Impl.h"

#include "game/GAME.h"
#include "game/utils/modelgen.h"
#include "game/dialogs/Selection_List_Dialog.h"

#include "Dialogs.h"

#include "DefaultImplementationGenerator.h"
#include "DefaultArtifactGenerator.h"
#include "NewComponentConfig.h"

#include "Utils/Utils.h"
#include "game/utils/Point.h"
#include "boost/bind.hpp"

#include <algorithm>
#include <sstream>
#include <functional>

// Type definition
typedef std::vector <GAME::Reference> Reference_Set;

static const long EVENTMASK =
   OBJEVENT_CREATED | OBJEVENT_ATTR |
   OBJEVENT_RELATION |  OBJEVENT_SELECT |
   OBJEVENT_SETINCLUDED | OBJEVENT_SETEXCLUDED |
   OBJEVENT_DESTROYED | OBJEVENT_LOSTCHILD;

//
// PICMLManager_Impl
//
PICMLManager_Impl::PICMLManager_Impl (void)
: GAME::Event_Handler_Impl (EVENTMASK),
  importing_ (0),
  impl_folder_ ("ComponentImplementations"),
  artifact_folder_ ("ImplementationArtifacts")
{

}

//
// ~PICMLManager_Impl
//
PICMLManager_Impl::~PICMLManager_Impl (void)
{

}

//
// Initaialize
//
int PICMLManager_Impl::initialize (GAME::Project & project)
{
  this->project_ = project;

  this->handlers_.bind ("ExternalDelegate", &PICMLManager_Impl::handle_ExternalDelegate);
  this->handlers_.bind ("PublishConnector", &PICMLManager_Impl::handle_PublishConnector);
  this->handlers_.bind ("AttributeValue", &PICMLManager_Impl::handle_AttributeValue);
  this->handlers_.bind ("AttributeMember", &PICMLManager_Impl::handle_AttributeMember);
  this->handlers_.bind ("CollocationGroup", &PICMLManager_Impl::handle_CollocationGroup);

  this->handlers_.bind ("Component", &PICMLManager_Impl::handle_Component);
  this->handlers_.bind ("ConnectorObject", &PICMLManager_Impl::handle_ConnectorObject);

  this->handlers_.bind ("ComponentAssembly", &PICMLManager_Impl::handle_ComponentAssembly);
  this->handlers_.bind ("ComponentPackage", &PICMLManager_Impl::handle_ComponentPackage);
  this->handlers_.bind ("ComponentRef", &PICMLManager_Impl::handle_ComponentRef);
  this->handlers_.bind ("Domain", &PICMLManager_Impl::handle_Domain);
  this->handlers_.bind ("PackageConfiguration", &PICMLManager_Impl::handle_PackageConfiguration);
  this->handlers_.bind ("ComponentInstanceType", &PICMLManager_Impl::handle_ComponentInstanceType);

  this->handlers_.bind ("ExtendedPortInstance", &PICMLManager_Impl::handle_ExtendedPortInstance);
  this->handlers_.bind ("MirrorPortInstance", &PICMLManager_Impl::handle_MirrorPortInstance);

  this->handlers_.bind ("MonolithicImplementation", &PICMLManager_Impl::handle_MonolithicImplementation);
  this->handlers_.bind ("ComponentImplementation", &PICMLManager_Impl::handle_ComponentImplementation);
  this->handlers_.bind ("ConnectorImplementation", &PICMLManager_Impl::handle_ConnectorImplementation);

  this->handlers_.bind ("ComponentFactoryInstance", &PICMLManager_Impl::handle_ComponentFactoryInstance);
  this->handlers_.bind ("DeploymentPlan", &PICMLManager_Impl::handle_DeploymentPlan);
  this->handlers_.bind ("NodeReference", &PICMLManager_Impl::handle_NodeReference);
  this->handlers_.bind ("ComponentInstanceType", &PICMLManager_Impl::handle_ComponentInstanceType);

  this->handlers_.bind ("ImplementationArtifact", &PICMLManager_Impl::handle_ImplementationArtifact);

  this->handlers_.bind ("ComplexTypeReference", &PICMLManager_Impl::handle_ComplexTypeReference);

  this->handlers_.bind ("ComponentInstance", &PICMLManager_Impl::handle_ComponentInstance);
  this->handlers_.bind ("ConnectorInstance", &PICMLManager_Impl::handle_ConnectorInstance);

  this->handlers_.bind ("Consume", &PICMLManager_Impl::handle_Consume);
  this->handlers_.bind ("Publish", &PICMLManager_Impl::handle_Publish);

  this->handlers_.bind ("DataType", &PICMLManager_Impl::handle_DataType);
  this->handlers_.bind ("Property", &PICMLManager_Impl::handle_Property);

  return 0;
}


//
// handle_global_event
//
int PICMLManager_Impl::handle_global_event (long global_event)
{
  /*
   * Right now I am simplifying the UUIDManager and it no longer
   * processes GlobalEvent messages. Instead the UUID manager
   * only creates UUIDs and manages existing ones when and
   * ObjectEvent is sent.
   */
  try
  {
    switch (global_event)
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
// handle_object_event
//
int PICMLManager_Impl::
handle_object_event (GAME::Object & obj, unsigned long eventmask)
{
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  try
  {
    GAME::Object object (obj);

    if (object.is_lib_object ())
      return 0;

    // Get the meta information for the object.
    std::string type = object.meta ().name ();
    _member_function handler;

    if (this->handlers_.find (type, handler) != -1)
      return (this->*handler) (eventmask, object);
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
// set_artifact_folder
//
void PICMLManager_Impl::set_artifact_folder (const std::string & name)
{
  this->artifact_folder_ = name;
}

//
// set_implementation_folder
//
void PICMLManager_Impl::set_implementation_folder (const std::string & name)
{
  this->impl_folder_ = name;
}

//
// reset_configuration
//
void PICMLManager_Impl::reset_configuration (void)
{
  this->artifact_folder_ = "ImplementationArtifacts";
  this->impl_folder_ = "ComponentImplementations";
}

//
// create_uuid
//
void PICMLManager_Impl::
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
void PICMLManager_Impl::verify_uuid (const GAME::FCO & fco)
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
bool PICMLManager_Impl::
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
void PICMLManager_Impl::verify_all_uuids (void)
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
void PICMLManager_Impl::handle_pending (void)
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
// set_property_type
//
void PICMLManager_Impl::
set_property_type (GAME::Model & prop, const GAME::FCO & type)
{
  GAME::Meta::FCO metafco = type.meta ();
  GAME::FCO real_type = type;

  // We need to remove all the mask of this alias. Only then can
  // we really set the property's type.
  while (metafco == "Alias")
  {
    GAME::Reference alias = GAME::Reference::_narrow (real_type);
    real_type = alias.refers_to ();
    metafco = real_type.meta ();
  }

  if (metafco == "Aggregate" || metafco == "Collection")
  {
    GAME::Reference complex;
    std::vector <GAME::Reference> complex_refs;

    // We are working with a predefined type, or an Enum.
    if (0 == prop.children ("ComplexTypeReference", complex_refs))
      complex = GAME::Reference::_create (prop, "ComplexTypeReference");
    else
      complex = complex_refs.front ();

    // Set the reference for the type. This will force the
    // add-on to make sure each member is set correct.
    complex.refers_to (type);
  }
  else
  {
    GAME::Reference datavalue;
    std::vector <GAME::Reference> datavalues;

    // We are working with a predefined type, or an Enum.
    if (0 == prop.children ("DataValue", datavalues))
      datavalue = GAME::Reference::_create (prop, "DataValue");
    else
      datavalue = datavalues.front ();

    // Set the name of the data type and its reference.
    if (datavalue.name () != prop.name ())
      datavalue.name (prop.name ());

    // Get the current data type.
    GAME::FCO current = datavalue.refers_to ();

    if (current.is_nil () || (current != type))
      datavalue.refers_to (type);
  }
}

//
// verify_property_datatype
//
void PICMLManager_Impl::
verify_property_datatype_entry (GAME::ConnectionPoints::value_type & attr,
                                const GAME::FCO & attr_type)
{
  verify_property_datatype (attr.item (), attr_type);
}

//
// verify_property_datatype
//
void PICMLManager_Impl::
verify_property_datatype (GAME::ConnectionPoint & attr, const GAME::FCO & attr_type)
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
    set_property_type (prop, attr_type);
  }

}

//
// handle_ExternalDelegate
//
int PICMLManager_Impl::
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

  return 0;
}

//
// handle_PublishConnector
//
int PICMLManager_Impl::
handle_PublishConnector (unsigned long eventmask, GAME::Object & obj)
{
  // We need to set the name of the newly create connector.
  if ((eventmask & OBJEVENT_CREATED))
    obj.name (obj.id ());

  return 0;
}

//
// handle_MirrorPortInstance
//
int PICMLManager_Impl::
handle_MirrorPortInstance (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_DESTROYED))
    return S_FALSE;


  return 0;
}

//
// handle_ExtendedPortInstance
//
int PICMLManager_Impl::
handle_ExtendedPortInstance (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_DESTROYED))
    return S_FALSE;

  return 0;
}

//
// handle_AttributeValue
//
int PICMLManager_Impl::
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
                     boost::bind (&PICMLManager_Impl::verify_property_datatype_entry,
                                  this,
                                  _1,
                                  attr_type));
    }
  }

  return 0;
}

//
// handle_AttributeValue
//
int PICMLManager_Impl::
handle_AttributeValue (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_CREATED) == 0)
    return 0;

  // Extract the connection from the object and get its endpoints.
  GAME::Connection attr_value = GAME::Connection::_narrow (obj);
  GAME::Reference attr_inst = GAME::Reference::_narrow (attr_value[std::string ("src")].target ());
  GAME::Model prop = GAME::Model::_narrow (attr_value[std::string ("dst")].target ());

  // Get the target attribute.
  GAME::Model attr = GAME::Model::_narrow (attr_inst.refers_to ());

  if (attr.is_nil ())
    return 0;

  // Set the name of the Property. We want to ensure the name to
  // the prop matches the name of the attribute.
  if (prop.name () != attr.name ())
    prop.name (attr.name ());

  GAME::FCO member_type;
  Reference_Set attr_members;

  // Let's get the data type of the attribute. Since there is only
  // 1 attribute member, we can just get the front element in the
  // container.
  if (1 == attr.children ("AttributeMember", attr_members))
    member_type = attr_members.front ().refers_to ();

  if (!member_type.is_nil ())
    this->set_property_type (prop, member_type);

  return 0;
}

//
// handle_Component
//
int PICMLManager_Impl::
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
          return 0;

        // Set the name of the component.
        obj.name (config.component_name_.c_str ());
      }

      // Make sure the target folder's exist.
      GAME::Folder root_folder = obj.project ().root_folder ();
      GAME::Folder artifact_folder, impl_folder;

      if (GAME::create_if_not (root_folder, "ImplementationArtifacts", artifact_folder,
          GAME::contains (boost::bind (std::equal_to <std::string> (),
                          this->artifact_folder_,
                          boost::bind (&GAME::Model::name, _1)))))
      {
        artifact_folder.name (this->artifact_folder_);
      }

      if (GAME::create_if_not (root_folder, "ComponentImplementations", impl_folder,
          GAME::contains (boost::bind (std::equal_to <std::string> (),
                          this->impl_folder_,
                          boost::bind (&GAME::Model::name, _1)))))
      {
        impl_folder.name (this->impl_folder_);
      }

      // Generate the component's artifacts.
      GAME::Model component = GAME::Model::_narrow (obj);
      DefaultArtifactGenerator artifact_gen (artifact_folder);

      if (artifact_gen.generate (config, component))
      {
        // Generate the component's implementation.
        DefaultImplementationGenerator impl_gen (artifact_gen, impl_folder);
        impl_gen.generate (component);
      }
    }
  }

  return 0;
}

//
// handle_ComponentAssembly
//
int PICMLManager_Impl::
handle_ComponentAssembly (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_ComponentPackage
//
int PICMLManager_Impl::
handle_ComponentPackage (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_ComponentFactoryInstance
//
int PICMLManager_Impl::
handle_ComponentFactoryInstance (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_Domain
//
int PICMLManager_Impl::
handle_Domain (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_MonolithicImplementation
//
int PICMLManager_Impl::
handle_MonolithicImplementation (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_PackageConfiguration
//
int PICMLManager_Impl::
handle_PackageConfiguration (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_ComponentImplementation
//
int PICMLManager_Impl::
handle_ComponentImplementation (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_ConnectorImplementation
//
int PICMLManager_Impl::
handle_ConnectorImplementation (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_ConnectorObject
//
int PICMLManager_Impl::
handle_ConnectorObject (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_ComponentInstance
//
int PICMLManager_Impl::
handle_ComponentInstance (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));

  if (this->importing_)
    return 0;

  if ((eventmask && OBJEVENT_LOSTCHILD))
  {
    static const std::string meta_ComponentInstanceType ("ComponentInstanceType");
    GAME::Model model = GAME::Model::_narrow (obj);

    std::vector <GAME::Reference> types;

    if (model.children (meta_ComponentInstanceType, types) == 0 ||
        types.front ().is_nil ())
    {
      // Delete all the children in the inferface.
      std::vector <GAME::FCO> children;
      GAME::Meta::Aspect aspect = model.meta ().aspect ("ComponentInterface");

      model.children (aspect, children);
      std::for_each (children.begin (),
                     children.end (),
                     boost::bind (&GAME::FCO::destroy, _1));
      return 0;
    }
    else
      return -1;
  }

  return 0;
}

//
// handle_ConnectorInstance
//
int PICMLManager_Impl::
handle_ConnectorInstance (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_DeploymentPlan
//
int PICMLManager_Impl::
handle_DeploymentPlan (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_ImplementationArtifact
//
int PICMLManager_Impl::
handle_ImplementationArtifact (unsigned long eventmask, GAME::Object & obj)
{
  this->handle_UUID (eventmask, GAME::FCO::_narrow (obj));
  return 0;
}

//
// handle_UUID
//
void PICMLManager_Impl::
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
int PICMLManager_Impl::
handle_NodeReference (unsigned long eventmask, GAME::Object & obj)
{
  if (this->importing_)
    return 0;

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

  return 0;
}

//
// handle_CollocationGroup
//
int PICMLManager_Impl::
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

  return 0;
}

//
// handle_ComponentRef
//
int PICMLManager_Impl::
handle_ComponentRef (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_SETINCLUDED) != 0)
    this->cg_member_ = GAME::FCO::_narrow (obj);

  return 0;
}

//
// handle_ComponentInstanceType
//
int PICMLManager_Impl::
handle_ComponentInstanceType (unsigned long eventmask, GAME::Object & obj)
{
  if (this->importing_)
    return 0;

  using GAME::Reference;
  using GAME::Model;
  using GAME::Atom;
  using GAME::Connection;
  using GAME::FCO;

  if ((eventmask & OBJEVENT_RELATION) != 0)
  {
    Model inst = Model::_narrow (obj.parent ());

    // The the component's implementation.
    Reference ref = GAME::Reference::_narrow (obj);
    FCO fco = ref.refers_to ();

    if (fco.is_nil ())
    {
      GAME::Model model = GAME::Model::_narrow (obj.parent ());

      // Delete the ports in the model.
      std::vector <GAME::FCO> children;
      GAME::Meta::Aspect aspect = model.meta ().aspect ("ComponentInterface");

      model.children (aspect, children);
      std::for_each (children.begin (),
                     children.end (),
                     boost::bind (&GAME::FCO::destroy, _1));
    }
    else
    {
      // Walk this until we locate the component interface.
      Atom impl = Atom::_narrow (ref.refers_to ());
      std::vector <Connection> implements;
      impl.in_connections ("Implements", implements);

      if (implements.empty ())
        return 0;

      Connection implement = implements[0];
      ref = Reference::_narrow (implement[std::string ("dst")].target ());
      Model component = Model::_narrow (ref.refers_to ());

      this->generate_port_instances (inst, component);
    }
  }

  return 0;
}

struct generate_instance_t
{
  generate_instance_t (GAME::Model & parent, const std::string & type)
    : parent_ (parent),
      type_ (type)
  {

  }

  void operator () (const GAME::FCO & target) const
  {
    using GAME::Reference;
    using GAME::FCO;

    Reference ref;

    if (GAME::create_if_not (this->parent_, this->type_, ref,
        GAME::contains (boost::bind (std::equal_to <FCO> (),
                        target,
                        boost::bind (&Reference::refers_to, _1)))))
    {
      ref.refers_to (target);
      ref.name (target.name ());
    }
  }

private:
  GAME::Model & parent_;

  const std::string & type_;
};

//
// gather_component_ports
//
void PICMLManager_Impl::
generate_port_instances (GAME::Model inst,  const GAME::Model & component)
{
  using GAME::Reference;
  using GAME::Model;

  std::vector <GAME::FCO> ports;

  if (component.children ("InEventPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "InEventPortInstance"));

  if (component.children ("OutEventPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "OutEventPortInstance"));

  if (component.children ("ProvidedRequestPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "ProvidedRequestPortInstance"));

  if (component.children ("RequiredRequestPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "RequiredRequestPortInstance"));

  if (component.children ("Attribute", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "AttributeInstance"));

  if (component.children ("ReadonlyAttribute", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "AttributeInstance"));

  if (component.children ("ExtendedPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "ExtendedPortInstance"));

  if (component.children ("MirrorPort", ports))
    std::for_each (ports.begin (),
                   ports.end (),
                   generate_instance_t (inst, "MirrorPortInstance"));

  // Finally, generate the ports of the base type in this
  // component instance.
  std::vector <Reference> inherits;

  if (component.children ("ComponentInherits", inherits))
  {
    Model basetype = Model::_narrow (inherits.begin ()->refers_to ());
    this->generate_port_instances (inst, basetype);
  }
}

//
// handle_Publish
//
int PICMLManager_Impl::
handle_Publish (unsigned long eventmask, GAME::Object & obj)
{
  using GAME::Connection;
  using GAME::Model;
  using GAME::Reference;

  if ((eventmask & OBJEVENT_CREATED))
  {
    using GAME::Connection;
    using GAME::Model;

    // This is a publish connection.
    Connection publish = Connection::_narrow (obj);

    // First, let's get the source PortType that wants to connect to
    // the target connector.
    GAME::FCO port =  publish[std::string ("src")].target ();
    Model connector_inst = Model::_narrow (publish[std::string ("dst")].target ());

    return this->handle_connector_porttype_connection (connector_inst, port, publish);
  }

  return 0;
}

//
// handle_Consume
//
int PICMLManager_Impl::
handle_Consume (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_CREATED))
  {
    using GAME::Connection;
    using GAME::Model;

    // This is a publish connection.
    Connection publish = Connection::_narrow (obj);

    // First, let's get the source PortType that wants to connect to
    // the target connector.
    GAME::FCO port =  publish[std::string ("dst")].target ();
    Model connector_inst = Model::_narrow (publish[std::string ("src")].target ());

    return this->handle_connector_porttype_connection (connector_inst, port, publish);
  }

  return 0;
}

//
// handle_DataType
//
int PICMLManager_Impl::
handle_DataType (unsigned long eventmask, GAME::Object & obj)
{
  AfxMessageBox ("The use of DataType has been deprecated.\nPlease use DataValue in the DataValueAspect of the \"Part Browser\" instead.");

  if (this->importing_)
  {
    AfxMessageBox ("Please use the latest migration script to remove the deprecated functionality");
  }

  return -1;
}

//
// handle_Property
//
int PICMLManager_Impl::
handle_Property (unsigned long eventmask, GAME::Object & obj)
{
  if (eventmask == OBJEVENT_ATTR)
  {
    AfxMessageBox ("Setting the Property value has been deprecated.\nInstead please use DataValue in the DataValueAspect of the \"Part Browser\" within the Property.");
    return -1;
  }
}

//
// handle_connector_porttype_connection
//
int PICMLManager_Impl::
handle_connector_porttype_connection (const GAME::Model & connector_inst,
                                      const GAME::FCO & port,
                                      GAME::Connection & connection)
{
  using GAME::Reference;
  using GAME::Model;

  Reference extended_port_inst = Reference::_narrow (port);
  Reference extended_port = GAME::Reference::_narrow (extended_port_inst.refers_to ());
  GAME::FCO port_type = extended_port.refers_to ();
  const bool is_extended_port = extended_port.meta () == "ExtendedPort" ? true : false;

  // Now that we have the port type, we need to locate either the
  // extended port, or mirror port, on the connector.
  Model connector;
  if (!this->get_connector_type (connector_inst, connector))
    return 0;

  std::string metaname = is_extended_port ? "MirrorPort" : "ExtendedPort";

  // Select all the port types of the specified metaname.
  std::vector <Reference> extended_ports;
  connector.children (metaname, extended_ports);

  // Of these port types, narrow the selection down to those
  // that have the same port types as the source.
  std::vector <Reference>::iterator
    iter = extended_ports.begin (),
    iter_end = extended_ports.end ();

  std::vector <Reference> valid_set;

  for (; iter != iter_end; ++ iter)
  {
    if (iter->refers_to () == port_type)
      valid_set.push_back (*iter);
  }

  Reference valid_port;

  if (valid_set.size () == 1)
  {
    // Since there is only one element in the set, we can
    // just use that as the selection.
    valid_port = valid_set.front ();
  }
  else
  {
    using GAME::Dialogs::Selection_List_Dialog;

    // Since there is more than one element in the set, we
    // need to ask the user to select the correct one.
    Selection_List_Dialog <Reference> dlg (valid_set);

    dlg.title ("Please select the connector's port name");

    if (dlg.DoModal () != IDOK)
      return 0;

    valid_port = dlg.selection ();
  }

  // We can now set the name of the connection since we have the
  // valid target port on the connector.
  connection.name (valid_port.name ());
  return 0;
}

//
// get_connector_type
//
bool PICMLManager_Impl::
get_connector_type (const GAME::Model & inst, GAME::Model & connector)
{
  using GAME::Reference;
  using GAME::Connection;
  using GAME::Model;

  std::vector <Reference> types;
  if (inst.children ("ConnectorImplementationType", types) == 0)
    return false;

  GAME::FCO impl = types.front ().refers_to ();

  std::vector <Connection> conns;
  if (impl.in_connections ("ConnectorImplements", conns) == 0)
    return false;

  Connection implements = conns.front ();
  Reference conn_ref = Reference::_narrow (implements[std::string ("dst")].target ());

  connector = Model::_narrow (conn_ref.refers_to ());
  return true;
}

//
// handle_ComplexTypeReference
//
int PICMLManager_Impl::
handle_ComplexTypeReference (unsigned long eventmask, GAME::Object & obj)
{
  if ((eventmask & OBJEVENT_RELATION) == 0)
    return 0;

  // Get the complex types actual type.
  GAME::Model container = GAME::Model::_narrow (obj.parent ());
  GAME::Reference complex = GAME::Reference::_narrow (obj);
  GAME::FCO type = complex.refers_to ();

  // We need to remove all the mask of this alias. Only then can
  // we really set the property's type.
  GAME::FCO real_type = type;
  GAME::Meta::FCO metafco = real_type.meta ();

  while (metafco == "Alias")
  {
    GAME::Reference alias = GAME::Reference::_narrow (real_type);
    real_type = alias.refers_to ();
    metafco = real_type.meta ();
  }

  if (metafco == "Aggregate")
  {
    GAME::Model aggregate = GAME::Model::_narrow (real_type);

    // Get all the members of the aggregate.
    std::vector <GAME::FCO> members;
    aggregate.children (members);

    std::for_each (members.begin (),
                   members.end (),
                   boost::bind (&PICMLManager_Impl::create_DataValue,
                                this,
                                container,
                                _1));
  }
  else if (metafco == "Collection")
  {

  }

  return 0;
}

//
// create_DataValue
//
void PICMLManager_Impl::
create_DataValue (GAME::Model & container, const GAME::FCO & fco)
{
  GAME::Reference member = GAME::Reference::_narrow (fco);
  GAME::FCO type = member.refers_to ();

  if (type.is_nil ())
    return;

  GAME::FCO real_type = type;
  GAME::Meta::FCO metafco = type.meta ();
  const std::string name (fco.name ());

  // We need to remove all the mask of this alias. Only then can
  // we really set the property's type.
  while (metafco == "Alias")
  {
    GAME::Reference alias = GAME::Reference::_narrow (real_type);
    real_type = alias.refers_to ();

    if (real_type.is_nil ())
      return;

    metafco = real_type.meta ();
  }

  if (metafco == "Aggregate" || metafco == "Collection")
  {
    // Make sure the container contains the element that has the
    // same name as <fco> input parameter.
    GAME::Model child_container;

    if (GAME::create_if_not (container, "DataValueContainer", child_container,
        GAME::contains (boost::bind (std::equal_to <std::string> (),
                        name,
                        boost::bind (&GAME::Model::name, _1)))))
    {
      child_container.name (name);
    }

    // Set the child container's type. This will cause the add-on to
    // generate the container's elements.
    GAME::Reference complex_type;
    std::vector <GAME::Reference> complex_types;

    if (0 == child_container.children ("ComplexTypeReference", complex_types))
      complex_type = GAME::Reference::_create (child_container, "ComplexTypeReference");
    else
      complex_type = complex_types.front ();

    complex_type.refers_to (type);
    complex_type.name (type.name ());

    // Finally, set the position of the data value. We can do this by
    // just copying the current position of the type.
    GAME::utils::Point pt;
    GAME::utils::position ("InterfaceDefinition", fco, pt);
    GAME::utils::position ("DataValueAspect", pt, child_container);
  }
  else
  {
    // Make sure the container contains the element that has the
    // same name as <fco> input parameter.
    GAME::Reference data_value;

    if (GAME::create_if_not (container, "DataValue", data_value,
        GAME::contains (boost::bind (std::equal_to <std::string> (),
                        name,
                        boost::bind (&GAME::Reference::name, _1)))))
    {
      data_value.name (name);
    }

    // Set the data values type.
    data_value.refers_to (type);

    // Finally, set the position of the data value. We can do this by
    // just copying the current position of the type.
    GAME::utils::Point pt;
    GAME::utils::position ("InterfaceDefinition", fco, pt);
    GAME::utils::position ("DataValueAspect", pt, data_value);
  }
}
