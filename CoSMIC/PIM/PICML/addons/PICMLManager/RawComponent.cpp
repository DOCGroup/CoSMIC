// $Id$

#include "StdAfx.h"
#include "Common.h"
#include "ComHelp.h"
#include "GMECOM.h"
#include "ComponentConfig.h"
#include "RawComponent.h"
#include "Utils/Utils.h"

// Type definition
typedef GME::Collection_T <GME::Reference> Reference_Set;

// Type definition
typedef GME::Collection_T <GME::ConnectionPoint> ConnectionPoint_Set;

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

  /// Create a collection of PICML types that contain a UUID
  /// attribute. This will allow the addon to manage it's UUID.
  this->uuid_types_.insert ("Component");
  this->uuid_types_.insert ("ComponentAssembly");
  this->uuid_types_.insert ("ComponentPackage");
  this->uuid_types_.insert ("ComponentImplementation");
  this->uuid_types_.insert ("DeploymentPlan");
  this->uuid_types_.insert ("Domain");
  this->uuid_types_.insert ("ImplementationArtifact");
  this->uuid_types_.insert ("MonolithicImplementation");
  this->uuid_types_.insert ("PackageConfiguration");

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

  //try
  //{
  //  switch (event)
  //  {
  //  case APPEVENT_XML_IMPORT_BEGIN:
  //    this->importing_ = 1;

  //  case GLOBALEVENT_OPEN_PROJECT:
  //    this->verify_all_uuids ();
  //    break;

  //  case APPEVENT_XML_IMPORT_END:
  //    this->importing_ = 0;
  //    this->verify_all_uuids ();
  //    break;

  //  case GLOBALEVENT_NOTIFICATION_READY:
  //    this->handle_pending ();
  //    break;

  //  default:
  //    /* do nothing */;
  //  }
  //}
  //catch (COM_Exception &)
  //{
  //  AfxMessageBox ("Caught a COM exception");
  //}
  //catch (...)
  //{
  //  AfxMessageBox ("Caught an unknown exception");
  //}

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
    GME::Object object (obj);

    if (object.is_lib_object ())
      return 0;

    // Get the meta information for the object.
    GME::FCO fco = GME::FCO::_narrow (object);
    std::string type = fco.meta ().name ();

    if ((eventmask & (OBJEVENT_CREATED | OBJEVENT_ATTR)))
    {
      if (this->uuid_types_.find (type) != this->uuid_types_ .end ())
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
      else if (type == "PublishConnector")
      {
        // We need to set the name of the newly create connector.
        if ((eventmask & OBJEVENT_CREATED))
          fco.name (fco.id ());
      }
      else if (type == "AttributeValue")
      {
        if ((eventmask & OBJEVENT_CREATED))
        {
          // Extract the connection from the object.
          GME::Connection attr_value = GME::Connection::_narrow (object);

          // Get the set of connection points from the connection.
          ConnectionPoint_Set conn_points;

          if (attr_value.connection_points (conn_points) >= 2)
          {
            GME::FCO attr_type;
            GME::Model property;
            ConnectionPoint_Set::iterator iter;

            for (iter = conn_points.items ().begin ();
                  iter != conn_points.items ().end ();
                  iter ++)
            {
              if (iter->role () == "src")
              {
                // We have the source connection point. This should be
                // an attribute in a component.
                GME::Model attr = GME::Model::_narrow (iter->target ());
                Reference_Set attr_members;

                if (attr.references ("AttributeMember", attr_members) == 1)
                {
                  // Let's get the data type of the attribute. Since there
                  // is only 1 attribute member, we can just get the front
                  // element in the container.
                  attr_type = attr_members.items ().front ().refers_to ();
                }
              }
              else if (iter->role () == "dst")
              {
                // We have the destination connection point. This should
                // be a property in an assembly.
                property = GME::Model::_narrow (iter->target ());
              }
            }

            if (attr_type)
              this->set_property_datatype (property, attr_type);
          }
        }
      }
    }
    else if ((eventmask & OBJEVENT_RELATION))
    {
      if (type == "AttributeMember")
      {
        // The reference for the attribute changes. This is either
        // because the reference was cleared, or another data type
        // was referenced. Either way, we need to update all the
        // properties in component assemblies for this attribute.

        GME::Reference member = GME::Reference::_narrow (fco);
        GME::FCO attr_type = member.refers_to ();

        if (attr_type)
        {
          GME::Model attr = member.parent_model ();

          ConnectionPoint_Set points;
          attr.in_connection_points (points);

          GME::Connection attr_value;

          for (ConnectionPoint_Set::iterator iter = points.items ().begin ();
               iter != points.items ().end ();
               iter ++)
          {
            // Get the own of this connection. If this is an AttributeValue
            // connection, then we should continue walking the connection
            // until we get to the property.
            attr_value = iter->owner ();

            if (attr_value.meta ().name () == "AttributeValue")
            {
              // We need to find the 'dst' connection point in this collection.
              // It will point to the target property model.
              ConnectionPoint_Set cps;
              attr_value.connection_points (cps);

              for (ConnectionPoint_Set::iterator it = cps.items ().begin ();
                  it != cps.items ().end ();
                  it ++)
              {
                if (it->role () == "dst")
                {
                  // Extract the property model and set its data type.
                  GME::Model property = GME::Model::_narrow (it->target ());
                  this->set_property_datatype (property, attr_type);
                }
              }
            }
          }
        }
      }
    }
  }
  catch (GME::Exception &)
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
create_uuid (const GME::FCO & fco)
{
  GME::Attribute uuid_attr;

  if (this->get_uuid_i (fco, uuid_attr))
  {
    long status = uuid_attr.status ();

    if (status == ATTSTATUS_METADEFAULT ||
        status == ATTSTATUS_UNDEFINED ||
        status > 0)
    {
      // This will force the generation of an <UUID> for any new
      // component/assembly inserted, as well as instances and
      // subtypes.
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
}

//
// verify_uuid
//
void RawComponent::verify_uuid (const GME::FCO & fco)
{
  GME::Attribute uuid_attr;

  if (this->get_uuid_i (fco, uuid_attr))
  {
    if (Utils::ValidUuid (uuid_attr.string_value ()))
      return;

    try
    {
      uuid_attr.string_value (Utils::CreateUuid ());
    }
    catch (GME::Exception &)
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
get_uuid_i (const GME::FCO & fco, GME::Attribute & attr)
{
  typedef GME::Collection_T <GME::Attribute> Attribute_Set;
  Attribute_Set attrs;

  // Get all the attributes of this FCO. It would be nice to query
  // the FCO for the attribute of interest, however, that capability
  // seems to be broken in the current MGA library.
  if (fco.attributes (attrs))
  {
    // We need to iterate over all the attribute until we find the
    // attribute with the name of UUID. That will be the attribute
    // we return to the caller.
    for (Attribute_Set::iterator iter = attrs.items ().begin ();
         iter != attrs.items ().end ();
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
  //// Get the <project> hosting the add-on.
  //CComPtr <IMgaProject> project;
  //VERIFY_RESULT (this->addon->get_Project (&project));

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
set_property_datatype (GME::Model & property, const GME::FCO & type)
{
  // We need to make sure there isn't a data type already
  // present in the target property.
  Reference_Set datatypes;
  GME::Reference datatype;

  if (property.references ("DataType", datatypes) == 0)
  {
    datatype = GME::Reference::_create ("DataType", property);
  }
  else
  {
    datatype = datatypes.items ().front ();
  }

  // Set the name of the data type and its reference.
  if (datatype.name () != type.name ())
    datatype.name (type.name ());

  if (datatype.refers_to () != type)
    datatype.refers_to (type);
}
