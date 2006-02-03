// $Id$

#include "StdAfx.h"
#include "Component_Listener.h"
#include "PICML/Utils.h"

class COM_Exception
{
public:
  COM_Exception (void) { }
  ~COM_Exception (void) { }
};

#define VERIFY_RESULT(x) \
  if (FAILED (x)) \
    throw COM_Exception ();

//
// Component_Listner
//
Component_Listener::Component_Listener (void)
{

}

//
// Component_Listner
//
Component_Listener::~Component_Listener (void)
{

}

//
// GlobalEvent
//
STDMETHODIMP Component_Listener::GlobalEvent (globalevent_enum event)
{
  return S_OK;
}

//
// ObjectEvent
//
STDMETHODIMP Component_Listener::ObjectEvent (IMgaObject * obj,
                                              unsigned long eventmask,
                                              VARIANT v)
{
  if (eventmask == OBJEVENT_DESTROYED)
  {
    POSITION pos = this->objects_.Find (obj);

    if (pos)
    {
      this->objects_.RemoveAt (pos);
    }

    this->territory_->CloseObj (obj);
  }
  else
  {
    // Get the <IMgaFCO> interface for the object.
    CComPtr <IMgaObject> mga_object (obj);
    CComPtr <IMgaFCO> fco_object;
    mga_object.QueryInterface (&fco_object);

    // Manage the UUID for the component.
    Component_Listener::manage_uuid (fco_object);
  }
  return S_OK;
}

//
// territory
//
IMgaTerritory * Component_Listener::territory (IMgaTerritory * territory)
{
  IMgaTerritory * old = this->territory_.Detach ();
  this->territory_.Attach (territory);

  try
  {
    if (this->territory_)
    {
      VERIFY_RESULT (
        this->territory_->put_RWEventMask (
        OBJEVENT_DESTROYED | OBJEVENT_ATTR | OBJEVENT_CREATED));
    }
  }
  catch (COM_Exception &)
  {

  }
  catch (...)
  {
    AfxMessageBox ("unhandled exception");
  }
  return old;
}

//
// listen_to_object
//
bool Component_Listener::listen_to_object (IMgaObject * object)
{
  try
  {
    CComPtr <IMgaObject> new_object;
    this->territory_->OpenObj (object, &new_object);
    this->objects_.InsertAfter (0, new_object);

    CComPtr <IMgaFCO> mga_fco;
    new_object->QueryInterface (&mga_fco);
    manage_uuid (mga_fco);
    return true;
  }
  catch (COM_Exception &)
  {
    return false;
  }
  catch (...)
  {
    return false;
  }
}

//
// manage_uuid
//
void Component_Listener::manage_uuid (IMgaFCO * fco)
{
  CComPtr <IMgaFCO> fco_object (fco);

  // Get the <IMgaAttributes> of the <fco_object>.
  CComPtr <IMgaAttributes> attrs;
  VERIFY_RESULT (fco_object->get_Attributes (&attrs));

  long count;
  VERIFY_RESULT (attrs->get_Count (&count));

  CComPtr <IMgaAttribute> uuid_attr;
  CComPtr <IMgaMetaAttribute> meta_attr;
  CComBSTR attr_name;

  for (long i = 1; i <= count; i ++)
  {
    long status;

    // Get the next <IMgaAttribute>.
    VERIFY_RESULT (attrs->get_Item (i, &uuid_attr));

    // Determine if this is the UUID <attribute>.
    VERIFY_RESULT (uuid_attr->get_Status (&status));
    VERIFY_RESULT (uuid_attr->get_Meta (&meta_attr));
    VERIFY_RESULT (meta_attr->get_Name (&attr_name));

    if (attr_name == L"UUID")
    {
      if (status == ATTSTATUS_INVALID)
      {
        ; // This should never happen.
      }
      else if (status == ATTSTATUS_METADEFAULT ||
               status == ATTSTATUS_UNDEFINED ||
               status > 0)
      {
        // This will force the generation of an <UUID> for
        // any new component/assembly inserted, as well as
        // instances and subtypes.
        VERIFY_RESULT (
          uuid_attr->put_StringValue (
          CComBSTR (PICML::CreateUuid ().c_str ())));
      }
      else
      {
        // This will validate <UUID> of existing components.
        // This is mainly useful during the "import" phase.
        CComBSTR uuid_bstr;
        VERIFY_RESULT (uuid_attr->get_StringValue (&uuid_bstr));

        if (
          !PICML::ValidUuid (
          std::string (CW2A (uuid_bstr).m_szBuffer)))
        {
          VERIFY_RESULT (
            uuid_attr->put_StringValue (
            CComBSTR (PICML::CreateUuid ().c_str ())));
        }
      }
      break;
    }

    // Apparently the implementation of CComPtr and CComBSTR
    // do not allow usage of "initialized" objects for holding
    // data. Therefore we have to "manually" release everything
    // which is really STUPID!!!!
    uuid_attr.Release ();
    meta_attr.Release ();
    attr_name.Empty ();
  }
}
