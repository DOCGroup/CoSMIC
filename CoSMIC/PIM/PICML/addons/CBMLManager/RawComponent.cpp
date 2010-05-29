// $Id$

#include "StdAfx.h"
#include "ComHelp.h"
#include "GMECOM.h"
#include "ComponentConfig.h"
#include "RawComponent.h"
#include "String_Selection_Dialog.h"
#include "Output_Event_Builder.h"
#include "game/Atom.h"
#include "game/Model.h"
#include "game/Object.h"
#include "game/Connection.h"
#include "game/MetaBase.h"
#include "game/MetaFCO.h"
#include "game/Reference.h"
#include "game/utils/Point.h"
#include "boost/bind.hpp"
#include <algorithm>
#include <sstream>

#define OFFSET_Y  7
#define OFFSET_X  50

#define PREF_AUTOROUTER           "autorouterPref"
#define PREF_AUTOROUTER_ALL       "NEWSnews"

struct insert_item
{
public:
  insert_item (String_Selection_Dialog::items_type & items)
    : items_ (items)
  {

  }

  void operator () (const GAME::Reference & ref) const
  {
    this->items_.insert (std::make_pair (ref.name (), ref));
  }

private:
  String_Selection_Dialog::items_type & items_;
};

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

  this->state_transition_map_.bind ("State", "Transition");
  this->state_transition_map_.bind ("ForState", "LoopTransition");
  this->state_transition_map_.bind ("WhileState", "LoopTransition");
  this->state_transition_map_.bind ("DoWhileState", "LoopTransition");
  this->state_transition_map_.bind ("BranchState", "BranchTransition");
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
      GAME::Object object (obj);

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
  catch (const GAME::Failed_Result & ex)
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
  GAME::FCO parent = GAME::FCO::_narrow (this->active_state_.parent ());

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
void RawComponent::load_active_state (GAME::Object & model)
{
  // Get the parent of the active state.
  GAME::FCO parent = GAME::FCO::_narrow (model);

  // Get the relative id from the registry.
  std::string value = parent.registry_value ("CBML/ActiveState");

  // Convert the relative id to its integer format.
  long relid;
  std::istringstream istr (value);
  istr >> relid;

  // Locate the child with the relative id. We need to then save the
  // object as the active state.
  GAME::Object relobj = parent.child_by_relative_id (relid);

  if (relobj)
    this->active_state_ = GAME::FCO::_narrow (relobj);
}

//
// handle_objevent_destroyed
//
void RawComponent::handle_objevent_destroyed (GAME::Object & obj)
{
  GAME::FCO fco = GAME::FCO::_narrow (obj);

  std::string metaname = obj.meta ().name ();

  if (metaname == "State")
  {
    if (this->active_state_ && this->active_state_ == fco)
      this->active_state_ = 0;
  }
}

//
// handle_objevent_select
//
void RawComponent::handle_objevent_select (GAME::Object & obj)
{
  if (obj.meta ().name () == "State")
  {
    // Set the active state of the behavior.
    this->active_state_ = GAME::FCO::_narrow (obj);

    // We no longer need to last action.
    this->last_action_ = 0;
  }
}

//
// handle_objevent_created
//
void RawComponent::handle_objevent_created (GAME::Object & obj)
{
  // We need to get the parent of the newly created object and determine
  // its type. We only need to continue if the parent's type is a
  // component.

  GAME::Object parent = obj.parent ();
  std::string metaname = parent.meta ().name ();

  if (metaname == "Component")
  {
    // Narrow the parent to its FCO type.
    GAME::FCO parent_fco = GAME::FCO::_narrow (parent);

    if (!parent_fco.is_instance ())
    {
      // Get the type of the newly created object.
      metaname = obj.meta ().name ();

      // We check the map before comparing the name because it's the
      // more likeable. User's will create more Action -> State
      // transition than InputAction -> State transitions.
      if (metaname == "Action" ||
          metaname == "OutputAction")
      {
        GAME::FCO base_type = parent_fco.derived_from ();

        // First, go ahead and connect the state to the action.
        this->create_state_and_connect (obj, "Effect");

        if (this->last_action_)
          this->last_action_ = 0;

        // Save the action as the last action.
        this->last_action_ = GAME::FCO::_narrow (obj);
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
        this->last_action_ = GAME::FCO::_narrow (obj);
      }
      else if (this->state_transition_map_.find (metaname.c_str ()) == 0)
      {
        this->active_state_ = GAME::FCO::_narrow (obj);
      }
      else if (metaname == "WorkerType")
      {
        GAME::Reference ref = GAME::Reference::_narrow (obj);
        this->cache_worker_type (ref);
      }
    }
  }
}

//
// create_state_and_connect
//
void RawComponent::
create_state_and_connect (GAME::Object & src, const std::string & conntype)
{
  if (this->last_action_)
  {
    // Delete the <active_state_> if the <last_action_> is a subtype
    // of the newly created action.
    GAME::FCO basetype = this->last_action_.derived_from ();

    if (basetype && (basetype == src))
      this->active_state_.destroy ();
  }

  // Get the model interface from the parent.
  GAME::Model parent = GAME::Model::_narrow (src.parent ());

  if (this->active_state_)
  {
    // Get the parent of the active state and determine if this
    // state is in the same model as the current action.
    GAME::Object temp = this->active_state_.parent ();

    if (!parent == temp)
      this->active_state_ = 0;
  }

  // Get the FCO interface from the object. We also need to change
  // the auto router preferences for the action.
  GAME::FCO action = GAME::FCO::_narrow (src);
  action.registry_value (PREF_AUTOROUTER, PREF_AUTOROUTER_ALL);

  // Resolve worker that owns the newly created action.
  std::string metaname = action.meta ().name ();

  if (action.is_instance () && metaname == "Action")
    this->resolve_worker_action (action);
  else if (metaname == "OutputAction")
    this->resolve_output_action (action);

  GAME::utils::Point position;

  if (this->active_state_)
  {
    // Align newly created action with previous state.
    GAME::utils::position ("Behavior", this->active_state_, position);
    position.shift (OFFSET_X, OFFSET_Y);

    GAME::utils::position ("Behavior", position, action);

    // Create a connection between the <active_state_> and the <action>.
    std::string transition_type;
    int retval =
      this->state_transition_map_.find (this->active_state_.meta ().name ().c_str (),
                                        transition_type);

    if (retval == 0)
    {
      GAME::Connection transition =
        GAME::Connection::_create (parent,
                                  transition_type,
                                  this->active_state_,
                                  action);
    }
  }

  // Create the new State element for the action.
  GAME::Atom state = GAME::Atom::_create (parent, "State");
  state.registry_value (PREF_AUTOROUTER, PREF_AUTOROUTER_ALL);

  // Create the effect connection from the action to the state.
  GAME::Connection effect =
    GAME::Connection::_create (parent,
                              conntype,
                              action,
                              state);

  // Get the position of the action, if not already set.
  if (!this->active_state_)
    GAME::utils::position ("Behavior", action, position);

  // Align the <state> to the right of the <action>.
  position.shift (OFFSET_X, -OFFSET_Y);
  GAME::utils::position ("Behavior", position, state);
}

//
// handle_objevent_modelopen
//
void RawComponent::
handle_objevent_modelopen (GAME::Object & obj)
{
  // Get the metaname of the object
  std::string metaname = obj.meta ().name ();

  if (metaname == "Component")
  {
    // Extract the FCO object from the object.
    GAME::Model model = GAME::Model::_narrow (obj);

    // Clear the model worker cache.
    if (!this->workers_.empty ())
      this->workers_.clear ();

    if (!this->worker_types_.empty ())
      this->worker_types_.clear ();

    if (!model.is_instance ())
    {
      typedef std::vector <GAME::Reference> reference_set_type;
      reference_set_type refs;

      // Cache information about the workers in this component.
      model.children ("WorkerType", refs);
      std::for_each (refs.begin (),
                     refs.end (),
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
handle_objevent_modelclose (GAME::Object & obj)
{
  if (obj.meta ().name () == "Component")
  {
    // Clear the worker infomration.
    if (!this->workers_.empty ())
      this->workers_.clear ();

    if (!this->worker_types_.empty ())
      this->worker_types_.clear ();
  }
}

//
// cache_worker_type
//
void RawComponent::cache_worker_type (const GAME::Reference & worker)
{
  // Get the reference for this worker.
  GAME::FCO ref = worker.refers_to ();

  if (ref)
  {
    // Cache this worker type for the component.
    GAME::Model model = GAME::Model::_narrow (ref);
    this->worker_types_.insert (model);

    // Also, save the worker instance information.
    this->workers_[model].insert (worker.name ());
  }
}

//
// resolve_output_action
//
void RawComponent::resolve_output_action (GAME::FCO & action)
{
  GAME::Reference output;
  std::vector <GAME::Reference> refs;
  GAME::Model model = action.parent_model ();

  if (model.children ("OutEventPort", refs))
  {
    if (refs.size () == 1)
    {
      output = *refs.begin ();
    }
    else
    {
      // Get the names of the output event ports.
      String_Selection_Dialog::items_type items;

      std::for_each (refs.begin (),
                     refs.end (),
                     insert_item (items));

      // Need to display a dialog for selecting a name.
      String_Selection_Dialog dialog (items, ::AfxGetMainWnd ());

      // Set the title of the dialog box.
      dialog.title ("Select target OutEventPort");

      // Display the dialog for the end-user.
      if (dialog.DoModal () == IDOK)
        output = GAME::Reference::_narrow (dialog.selection ()->second);
    }
  }

  if (output)
  {
    // Set the name of the output action.
    action.name (output.name ());

    // Create the elements for the output event.
    GAME::Model event = GAME::Model::_narrow (output.refers_to ());

    GAME::Model output_action = GAME::Model::_narrow (action);
    CBML_Output_Event_Builder builder (output_action);
  }
}

//
// resolve_worker_action
//
void RawComponent::resolve_worker_action (GAME::FCO & action)
{
  // Locate the archetype for this action instance.
  GAME::FCO basetype = action.archetype ();

  while (basetype.is_instance ())
    basetype = basetype.archetype ();

  // Get the parent of this instance. It should be a Worker.
  GAME::Model worker = GAME::Model::_narrow (basetype.parent ());

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
      //// Need to display a dialog for selecting a name.
      //String_Selection_Dialog dialog (iter->second, ::AfxGetMainWnd ());

      //// Set the title of the dialog box.
      //std::ostringstream ostr;
      //ostr << "Select target " << worker.name () << " worker";

      //dialog.title (ostr.str ().c_str ());

      //// Display the dialog for the end-user.
      //if (dialog.DoModal () == IDOK)
      //  name = dialog.selection ();
    }

    if (!name.empty ())
      action.name (name);
  }
}
