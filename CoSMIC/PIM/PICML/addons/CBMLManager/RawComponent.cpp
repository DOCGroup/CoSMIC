// $Id$

#include "StdAfx.h"
#include "ComHelp.h"
#include "GMECOM.h"
#include "ComponentConfig.h"
#include "RawComponent.h"
#include "String_Selection_Dialog.h"
#include "GME/Connection.h"
#include "GME/MetaBase.h"
#include "GME/Model.h"
#include "GME/Object.h"
#include "boost/bind.hpp"
#include <algorithm>
#include <sstream>

#define OFFSET_Y  7
#define OFFSET_X  50

#define PREF_AUTOROUTER           "autorouterPref"
#define PREF_AUTOROUTER_ALL       "NEWSnews"

//
// operator >>=
//
template <typename T>
bool operator >>= (std::basic_string <T> & str, point_t & pt)
{
  std::basic_istringstream <T> istr (str);

  istr >> pt.x_;
  istr.ignore (1);
  istr >> pt.y_;

  return istr.good ();
}

//
// operator <<=
//
template <typename T>
bool operator <<= (std::basic_string <T> & str, const point_t & pt)
{
  std::basic_ostringstream <T> ostr;

  ostr << pt.x_ << "," << pt.y_;
  str = ostr.str ().c_str ();

  return ostr.good ();
}

//
// action_types_
//
RawComponent::string_set RawComponent::actions_types_;

//
// RawComponent
//
RawComponent::RawComponent (void)
{
  // Initialize the collection of action types we are interested
  // in when creating action -> state transitions.
  if (RawComponent::actions_types_.empty ())
  {
    RawComponent::actions_types_.insert ("Action");
    RawComponent::actions_types_.insert ("OutputAction");
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
STDMETHODIMP RawComponent::
Invoke (IMgaProject* gme, IMgaFCOs *models, long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// InvokeEx
//
STDMETHODIMP RawComponent::
InvokeEx (IMgaProject *project,
          IMgaFCO *currentobj,
          IMgaFCOs *selectedobjs,
          long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// ObjectsInvokeEx
//
STDMETHODIMP RawComponent::
ObjectsInvokeEx (IMgaProject *project,
                 IMgaObject *currentobj,
                 IMgaObjects *selectedobjs,
                 long param)
{
  return E_MGA_NOT_SUPPORTED;
}

//
// get_ComponentParameter
//
STDMETHODIMP RawComponent::
get_ComponentParameter (BSTR name, VARIANT *pVal)
{
  return S_OK;
}

//
// put_ComponentParameter
//
STDMETHODIMP RawComponent::
put_ComponentParameter(BSTR name, VARIANT newVal)
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
STDMETHODIMP RawComponent::
ObjectEvent(IMgaObject * obj, unsigned long eventmask, VARIANT v)
{
  try
  {
    if (!this->importing_)
    {
      GME::Object object (obj);

      // This is a cool case of optimizing for the mostly frequently
      // taken path. We know for a fact that the elements will be
      // created more than anything else in the model. We, therefore,
      // explicitly check for OBJEVENT_CREATED to show that we are
      // favoring this event more than anything. We then assume that
      // all other events have the same probability of being triggered.

      if ((eventmask & OBJEVENT_CREATED))
        this->handle_objevent_created (object);

      if ((eventmask & OBJEVENT_SELECT))
        this->handle_objevent_select (object);

      if ((eventmask & OBJEVENT_CLOSEMODEL))
        this->handle_objevent_modelclose (object);

      if ((eventmask & OBJEVENT_OPENMODEL))
        this->handle_objevent_modelopen (object);

      if ((eventmask & OBJEVENT_DESTROYED))
        this->handle_objevent_destroyed (object);
    }

    return S_OK;
  }
  catch (const GME::Failed_Result & ex)
  {
    HRESULT hr = ex.value ();
  }
  catch (...)
  {

  }

  return S_FALSE;
}

#endif

//
// save_active_state
//
void RawComponent::save_active_state (void)
{
  // Get the parent of the active state.
  GME::FCO parent = GME::FCO::_narrow (this->active_state_.parent ());

  // Get the relative id for the active state
  long relid = parent.relative_id ();

  // Place the relative id for the <active_state_> in its parent
  // models registry.
  std::ostringstream ostr;
  ostr << relid;

  parent.registry_value ("CBML/ActiveState", ostr.str ());
}

//
// load_active_state
//
void RawComponent::load_active_state (GME::Object & model)
{
  // Get the parent of the active state.
  GME::FCO parent = GME::FCO::_narrow (model);

  // Get the relative id from the registry.
  std::string value = parent.registry_value ("CBML/ActiveState");

  // Convert the relative id to its integer format.
  long relid;
  std::istringstream istr (value);
  istr >> relid;

  // Locate the child with the relative id. We need to then save the
  // object as the active state.
  GME::Object relobj = parent.child_by_relative_id (relid);

  if (relobj)
    this->active_state_ = GME::FCO::_narrow (relobj);
}

//
// handle_objevent_destroyed
//
void RawComponent::handle_objevent_destroyed (GME::Object & obj)
{
  GME::FCO fco = GME::FCO::_narrow (obj);

  if (this->active_state_ && this->active_state_ == fco)
    this->active_state_ = 0;
}

//
// handle_objevent_select
//
void RawComponent::handle_objevent_select (GME::Object & obj)
{
  if (obj.meta ().name () == "State")
  {
    // Set the active state of the behavior.
    this->active_state_ = GME::FCO::_narrow (obj);

    // We no longer need to last action.
    this->last_action_ = 0;
  }
}

//
// handle_objevent_created
//
void RawComponent::handle_objevent_created (GME::Object & obj)
{
  // We need to get the parent of the newly created object and determine
  // its type. We only need to continue if the parent's type is a
  // component.

  GME::Object parent = obj.parent ();
  std::string metaname = parent.meta ().name ();

  if (metaname == "Component")
  {
    // Narrow the parent to its FCO type.
    GME::FCO parent_fco = GME::FCO::_narrow (parent);

    if (!parent_fco.is_instance ())
    {
      // Get the type of the newly created object.
      metaname = obj.meta ().name ();

      // We check the map before comparing the name because it's the
      // more likeable. User's will create more Action -> State
      // transition than InputAction -> State transitions.
      if (RawComponent::actions_types_.find (metaname) !=
          RawComponent::actions_types_.end ())
      {
        GME::FCO base_type = parent_fco.derived_from ();

        // First, go ahead and connect the state to the action.
        this->create_state_and_connect (obj, "Effect");

        if (this->last_action_)
          this->last_action_ = 0;

        // Save the action as the last action.
        this->last_action_ = GME::FCO::_narrow (obj);
      }
      else if (metaname == "InputAction" ||
               metaname == "MultiInputAction")
      {
        if (this->active_state_)
          this->active_state_ = 0;

        this->create_state_and_connect (obj, "InputEffect");

        if (this->last_action_)
          this->last_action_ = 0;

        // Save the action as the last action.
        this->last_action_ = GME::FCO::_narrow (obj);
      }
      else if (metaname == "State")
      {
        this->active_state_ = GME::FCO::_narrow (obj);
      }
      else if (metaname == "WorkerType")
      {
        GME::Reference ref = GME::Reference::_narrow (obj);
        this->cache_worker_type (ref);
      }
    }
  }
}

//
// get_position
//
bool RawComponent::get_position (GME::FCO & fco, point_t & pt)
{
  std::string pos = fco.registry_value ("PartRegs/Behavior/Position");
  return pos >>= pt;
}

//
// set_position
//
bool RawComponent::set_position (GME::FCO & fco, const point_t & pt)
{
  std::string str;

  if (!(str <<= pt))
    return false;

  fco.registry_value ("PartRegs/Behavior/Position", str);
  return true;
}

//
// create_state_and_connect
//
void RawComponent::
create_state_and_connect (GME::Object & src, const std::string & conntype)
{
  if (this->last_action_)
  {
    // Delete the <active_state_> if the <last_action_> is a subtype
    // of the newly created action.
    GME::FCO basetype = this->last_action_.derived_from ();

    if (basetype && (basetype == src))
      this->active_state_.destroy ();
  }

  // Get the model interface from the parent.
  GME::Model parent = GME::Model::_narrow (src.parent ());

  if (this->active_state_)
  {
    // Get the parent of the active state and determine if this
    // state is in the same model as the current action.
    GME::Object temp = this->active_state_.parent ();

    if (!parent == temp)
      this->active_state_ = 0;
  }

  // Get the FCO interface from the object. We also need to change
  // the auto router preferences for the action.
  GME::FCO action = GME::FCO::_narrow (src);
  action.registry_value (PREF_AUTOROUTER, PREF_AUTOROUTER_ALL);

  // Resolve worker that own the newly created action.
  if (action.is_instance ())
    this->resolve_worker_action (action);

  point_t position;

  if (this->active_state_)
  {
    // Align newly created action with previous state.
    this->get_position (this->active_state_, position);

    position.shift (OFFSET_X, OFFSET_Y);
    this->set_position (action, position);

    // Create a connection between the <active_state_> and the <action>.
    GME::Connection transition =
      GME::Connection::_create ("Transition",
                                parent,
                                this->active_state_,
                                action);
  }

  // Create the new State element for the action.
  GME::Atom state = GME::Atom::_create ("State", parent);
  state.registry_value (PREF_AUTOROUTER, PREF_AUTOROUTER_ALL);

  // Create the effect connection from the action to the state.
  GME::Connection effect =
    GME::Connection::_create (conntype,
                              parent,
                              action,
                              state);

  // Align the <state> to the right of the <action>.
  this->get_position (action, position);
  position.shift (OFFSET_X, -OFFSET_Y);
  this->set_position (state, position);
}

//
// handle_objevent_modelopen
//
void RawComponent::
handle_objevent_modelopen (GME::Object & obj)
{
  // Get the metaname of the object
  std::string metaname = obj.meta ().name ();

  if (metaname == "Component")
  {
    // Extract the FCO object from the object.
    GME::Model model = GME::Model::_narrow (obj);

    if (!model.is_instance ())
    {
      // Gather all the workers in the component.
      typedef GME::Collection_T <GME::Reference> worker_set_type;
      worker_set_type workers;

      model.references ("WorkerType", workers);

      // Cache information about worker's in this component.
      std::for_each (workers.begin (),
                     workers.end (),
                     boost::bind (&RawComponent::cache_worker_type,
                                  this,
                                  _1));
    }
  }
}

//
// handle_objevent_modelopen
//
void RawComponent::
handle_objevent_modelclose (GME::Object & obj)
{
  // Clear the worker infomration.
  this->workers_.clear ();
  this->worker_types_.clear ();

  // Clear the output information.
  this->outputs_.clear ();
}

//
// cache_worker_type
//
void RawComponent::cache_worker_type (const GME::Reference & worker)
{
  // Get the reference for this worker.
  GME::FCO ref = worker.refers_to ();

  if (ref)
  {
    // Cache this worker type for the component.
    GME::Model model = GME::Model::_narrow (ref);
    this->worker_types_.insert (model);

    // Also, save the worker instance information.
    this->workers_[model].insert (worker.name ());
  }
}

//
// resolve_worker_action
//
void RawComponent::resolve_worker_action (GME::FCO & action)
{
  // Locate the archetype for this action instance.
  GME::FCO basetype = action.archetype ();

  while (basetype.is_instance ())
    basetype = basetype.archetype ();

  // Get the parent of this instance. It should be a Worker.
  GME::Model worker = GME::Model::_narrow (basetype.parent ());

  // Determine many workers this model contains that match this worker.
  worker_map_type::iterator iter = this->workers_.find (worker);

  if (iter != this->workers_.end ())
  {
    std::string name;

    if (iter->second.size () == 1)
    {
      name = *iter->second.begin ();
    }
    else
    {
      // Need to display a dialog for selecting a name.
      String_Selection_Dialog dialog (iter->second, ::AfxGetMainWnd ());

      // Set the title of the dialog box.
      std::ostringstream ostr;
      ostr << "Select target " << worker.name () << " worker";

      dialog.title (ostr.str ().c_str ());

      // Display the dialog for the end-user.
      if (dialog.DoModal () == IDOK)
        name = dialog.selection ();
    }

    if (!name.empty ())
      action.name (name);
  }
}
