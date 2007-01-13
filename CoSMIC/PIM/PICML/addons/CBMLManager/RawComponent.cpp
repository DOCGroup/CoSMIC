// $Id$

#include "StdAfx.h"
#include "ComHelp.h"
#include "GMECOM.h"
#include "ComponentConfig.h"
#include "RawComponent.h"

#include <sstream>

#define OFFSET_Y  7
#define OFFSET_X  50

#define PREF_AUTOROUTER           L"autorouterPref"
#define PREF_AUTOROUTER_ALL       L"NEWSnews"


//
// operator >>=
//
bool operator >>= (std::wstring & str, point_t & pt)
{
  std::wistringstream istr (str);
  istr >> pt.x_;
  istr.ignore (1);
  istr >> pt.y_;

  return istr.good ();
}

//
// operator <<=
//
bool operator <<= (std::wstring & str, const point_t & pt)
{
  std::wostringstream ostr;
  ostr << pt.x_ << "," << pt.y_;
  str = ostr.str ().c_str ();

  return ostr.good ();
}

//
// action_types_
//
RawComponent::wstring_set RawComponent::actions_types_;

//
// RawComponent
//
RawComponent::RawComponent (void)
{
  // Initialize the collection of action types we are interested
  // in when creating action -> state transitions.
  if (RawComponent::actions_types_.empty ())
  {
    RawComponent::actions_types_.insert (L"Action");
    RawComponent::actions_types_.insert (L"CompositeAction");
    RawComponent::actions_types_.insert (L"OutputAction");
  }
}

//
// ~RawComponent
//
RawComponent::~RawComponent (void)
{

}

//
// Initialize
//
STDMETHODIMP RawComponent::Initialize (struct IMgaProject *)
{
  this->importing_ = false;
  return S_OK;
}

//
// Invoke
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
// ObjectsInvokeEx
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
STDMETHODIMP RawComponent::get_ComponentParameter (BSTR name,
                                                   VARIANT *pVal)
{
  return S_OK;
}

//
// put_ComponentParameter
//
STDMETHODIMP RawComponent::put_ComponentParameter(BSTR name,
                                                  VARIANT newVal)
{
  return S_OK;
}

#if defined (GME_ADDON)

//
// GlobalEvent
//
STDMETHODIMP RawComponent::GlobalEvent(globalevent_enum event)
{
  if (event == APPEVENT_XML_IMPORT_BEGIN)
    this->importing_ = true;
  else if (event == APPEVENT_XML_IMPORT_END)
    this->importing_ = false;

  return S_OK;
}

//
// ObjectEvent
//
STDMETHODIMP RawComponent::ObjectEvent(IMgaObject * obj,
                                       unsigned long eventmask,
                                       VARIANT v)
{
  if (this->importing_)
    return S_OK;

  // This is a cool case of optimizing for the mostly frequently
  // taken path. We know for a fact that the elements will be
  // created more than anything else in the model. We, therefore,
  // explicitly check for OBJEVENT_CREATED to show that we are
  // favoring this event more than anything. We then assume that
  // all other events have the same probability of being triggered.

  if ((eventmask & OBJEVENT_CREATED))
    this->handle_objevent_created (obj);

  if ((eventmask & OBJEVENT_SELECT))
    this->handle_objevent_select (obj);

  //if ((eventmask & OBJEVENT_CLOSEMODEL))
  //  AfxMessageBox ("OBJEVENT_CLOSEMODEL");

  if ((eventmask & OBJEVENT_DESTROYED))
    this->handle_objevent_destroyed (obj);

  return S_OK;
}

#endif

//
// save_active_state
//
HRESULT RawComponent::save_active_state (void)
{
  // Get the parent of the <active_state_>
  CComPtr <IMgaObject> parent;
  this->active_state_->GetParent (&parent);

  CComPtr <IMgaFCO> fco;
  parent->QueryInterface (&fco);

  // Get the relative id for the <active_state_>
  long relid;
  fco->get_RelID (&relid);

  // Place the relative id for the <active_state_> in its parent
  // models registry.
  std::wostringstream ostr;
  ostr << relid;

  CComBSTR value (ostr.str ().c_str ());
  return fco->put_RegistryValue (L"CBML/ActiveState", value);
}

//
// save_active_state
//
HRESULT RawComponent::load_active_state (IMgaObject * model)
{
  // Get the parent of the <active_state_>
  CComPtr <IMgaFCO> fco;
  CComPtr <IMgaObject> parent (model);
  parent->QueryInterface (&fco);

  // Get the relative id from the registry.
  CComBSTR value;
  fco->get_RegistryValue (L"CBML/ActiveState", &value);

  long relid = _wtol (value.m_str);

  CComPtr <IMgaObject> relobj;
  parent->get_ChildObjectByRelID (relid, &relobj);

  if (relobj)
    relobj->QueryInterface (&this->active_state_);

  return S_OK;
}

//
// handle_objevent_destroyed
//
void RawComponent::handle_objevent_destroyed (IMgaObject * obj)
{
  CComPtr <IMgaFCO> fco;
  obj->QueryInterface (&fco);

  if (this->active_state_ == fco)
    this->active_state_.Release ();
}

//
// handle_objevent_select
//
void RawComponent::handle_objevent_select (IMgaObject * obj)
{
  // Let's determine if this object is an action that
  // we need to manage.
  CComPtr <IMgaObject> object (obj);

  CComPtr <IMgaMetaBase> metabase;
  obj->get_MetaBase (&metabase);

  CComBSTR metaname;
  metabase->get_Name (&metaname);

  if (metaname == L"State")
  {
    this->active_state_.Release ();
    object->QueryInterface (&this->active_state_);
  }
}

//
// handle_objevent_created
//
void RawComponent::handle_objevent_created (IMgaObject * obj)
{
  CComPtr <IMgaObject> object (obj);

  // We need to get the parent of the newly created object and determine
  // its type. We only need to continue if the parent's type is a
  // component.

  objtype_enum objtype;
  CComPtr <IMgaObject> parent;
  object->GetParent (&parent, &objtype);

  CComPtr <IMgaMetaBase> metabase;
  parent->get_MetaBase (&metabase);

  CComBSTR metaname;
  metabase->get_Name (&metaname);

  if (metaname == L"Component")
  {
    metaname.Empty ();
    metabase.Release ();

    CComPtr <IMgaFCO> parent_fco;
    parent->QueryInterface (&parent_fco);

    // There is no need to run the rest of this auto handle method
    // if we are interacting with an instance of a component. There
    // is no way possible we can add to it.
    VARIANT_BOOL is_instance;
    parent_fco->get_IsInstance (&is_instance);

    if (is_instance == VARIANT_TRUE)
      return;

    // Determine if this object is an action we need to manage.
    object->get_MetaBase (&metabase);
    metabase->get_Name (&metaname);

    // We check the map before comparing the name because it's the
    // more likeable. User's will create more Action -> State
    // transition than InputAction -> State transitions.
    if (RawComponent::actions_types_.find (metaname.m_str) !=
        RawComponent::actions_types_.end ())
    {
      CComPtr <IMgaFCO> base_type;
      parent_fco->get_DerivedFrom (&base_type);

      // First, go ahead and connect the state to the action.
      this->create_state_and_connect (object, L"Effect");

    }
    else if (metaname == L"InputAction")
    {
      if (this->active_state_)
        this->active_state_.Release ();

      this->create_state_and_connect (object, L"InputEffect");
    }
  }
}

//
// create_model
//
HRESULT RawComponent::create_model (const std::wstring & type,
                                    IMgaModel * parent,
                                    IMgaFCO ** state)
{
  // Get the role "State" from the parent model.
  CComPtr <IMgaMetaRole> role;
  this->get_role (parent, type, &role);

  // Create the child object using the provide role.
  return parent->CreateChildObject (role, state);
}

//
// create_connection
//
HRESULT RawComponent::create_connection (const std::wstring & type,
                                         IMgaModel * model,
                                         IMgaFCO * src,
                                         IMgaFCO * dst,
                                         IMgaFCO ** conn)
{
  // Get the role for the connection.
  CComPtr <IMgaModel> parent (model);
  CComPtr <IMgaFCO> src_ptr (src);
  CComPtr <IMgaFCO> dst_ptr (dst);

  CComPtr <IMgaMetaRole> role;
  this->get_role (model, type, &role);

  // Create the connection using the provided role.
  return parent->CreateSimpleConn (role, src_ptr, dst_ptr, 0, 0, conn);
}

//
// get_role
//
HRESULT RawComponent::get_role (IMgaModel * parent,
                                const std::wstring & rolename,
                                IMgaMetaRole ** role)
{
  MgaMetaRole_Map::iterator iter = this->role_map_.find (rolename);

  if (iter == this->role_map_.end ())
  {
    // Get the interface the meta information for the model.
    CComPtr <IMgaMetaBase> metabase;
    parent->get_MetaBase (&metabase);

    CComPtr <IMgaMetaModel> metamodel;
    metabase->QueryInterface (&metamodel);

    // Get all the roles/types of elements that can be contained
    // by this parent object.
    CComPtr <IMgaMetaRoles> roles;
    metamodel->get_Roles (&roles);

    // Get the number of roles in this model.
    long count;
    roles->get_Count (&count);

    // Iterate over all roles looking for the one of interest.
    CComPtr <IMgaMetaRole> current_role;

    for (long i = 1; i <= count; i ++)
    {
      // Get the next child element/role.
      roles->get_Item (i, &current_role);

      CComBSTR name;
      current_role->get_Name (&name);

      if (name == rolename.c_str ())
      {
        // Insert the role into <role_map_> for quick access in
        // the near future.
        this->role_map_.insert (
          MgaMetaRole_Map::value_type (rolename, current_role));

        // Return the <current_role> to the client.
        *role = current_role;
        break;
      }
      current_role.Release ();
    }
  }
  else
    *role = iter->second;

  (*role)->AddRef ();
  return S_OK;
}

//
// get_position
//
HRESULT RawComponent::get_position (IMgaFCO * fco, point_t & pt)
{
  CComBSTR value;
  HRESULT hr = fco->get_RegistryValue (L"PartRegs/Behavior/Position", &value);
  std::wstring (value.m_str) >>= pt;

  return S_OK;
}

//
// get_position
//
HRESULT RawComponent::set_position (IMgaFCO * fco, const point_t & pt)
{
  std::wstring str;
  str <<= pt;

  CComBSTR bstr (str.c_str ());
  return fco->put_RegistryValue (L"PartRegs/Behavior/Position", bstr);
}

//
// create_state_and_connect
//
HRESULT RawComponent::
create_state_and_connect (IMgaObject * src,
                          const std::wstring & conntype)
{
  // Get the parent of the current action element.
  CComPtr <IMgaObject> parent;
  CComPtr <IMgaObject> object (src);
  object->GetParent (&parent);

  // Get the model interface from the parent.
  CComPtr <IMgaModel> parent_model;
  parent->QueryInterface (&parent_model);

  if (this->active_state_)
  {
    // Get the parent of the active state and determine if this
    // state is in the same model as the current action.
    CComPtr <IMgaObject> temp;
    this->active_state_->GetParent (&temp);

    VARIANT_BOOL is_equal;
    parent->get_IsEqual (temp, &is_equal);

    if (is_equal == VARIANT_FALSE)
      this->active_state_.Release ();
  }


  // Get the FCO interface from the object. We also need to
  // change the auto router preferences for the action.
  CComPtr <IMgaFCO> action;
  object->QueryInterface (&action);
  action->put_RegistryValue (PREF_AUTOROUTER, PREF_AUTOROUTER_ALL);

  point_t position;

  if (this->active_state_)
  {
    // Create a connection between the <active_state_> and the <action>.
    CComPtr <IMgaFCO> transition;

    this->create_connection (L"Transition",
                             parent_model,
                             this->active_state_,
                             action,
                             &transition);
  }

  // Create the new state element for the action.
  CComPtr <IMgaFCO> state;
  this->create_model (L"State", parent_model, &state);

  if (state)
  {
    state->put_RegistryValue (PREF_AUTOROUTER, PREF_AUTOROUTER_ALL);

    if (this->active_state_ != 0)
    {
      // Align newly created action with previous state.
      this->get_position (this->active_state_, position);
      position.shift (OFFSET_X, OFFSET_Y);
      this->set_position (action, position);
    }

    this->active_state_ = state;

    // Create the effect connection from the action to the state.
    CComPtr <IMgaFCO> effect;

    this->create_connection (conntype.c_str (),
                             parent_model,
                             action,
                             this->active_state_,
                             &effect);

    // Align the <state> to the right of the <action>.
    this->get_position (action, position);
    position.shift (OFFSET_X, -OFFSET_Y);
    this->set_position (this->active_state_, position);
  }

  return S_OK;
}
