// $Id$

#include "StdAfx.h"
#include "Common.h"
#include "ComHelp.h"
#include "GMECOM.h"
#include "ComponentConfig.h"
#include "RawComponent.h"
#include "Utils/Utils.h"

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

    if (!object.is_lib_object ())
    {
      // Get the meta information for the object.
      GME::FCO fco = GME::FCO::_narrow (object);

      if (this->uuid_types_.find (fco.meta ().name ()) !=
          this->uuid_types_ .end ())
      {
        if ((eventmask & OBJEVENT_CREATED) != 0)
        {
          this->create_uuid (fco);
        }
        else if ((eventmask & OBJEVENT_ATTR) != 0)
        {
          this->verify_uuid (fco);
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
