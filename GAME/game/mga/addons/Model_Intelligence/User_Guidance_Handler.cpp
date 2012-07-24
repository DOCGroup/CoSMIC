// $Id:  $

#include "StdAfx.h"
#include "User_Guidance_Handler.h"
#include "Association_Handler.h"

#include "game/mga/Model.h"
#include "game/mga/MetaConstraint.h"
#include "game/mga/MetaConnection.h"
#include "game/mga/Atom.h"
#include "game/mga/Filter.h"
#include "game/mga/MetaBase.h"
#include "game/mga/MetaModel.h"
#include "game/mga/MetaFolder.h"
#include "game/mga/FCO.h"
#include "game/mga/Reference.h"
#include "game/mga/MetaFCO.h"
#include "game/mga/MetaRole.h"
#include "game/mga/dialogs/Selection_List_Dialog_T.h"

#include "Model_Intelligence_Context.h"
#include "Boolean_Expr.h"
#include "OCL_Expr_Parser.h"
#include "Expr_Command.h"

//
// Default Constructor
//
User_Guidance_Handler::User_Guidance_Handler (void)
: GAME::Mga::Object_Event_Handler (eventmask)
{
}

//
// Destructor
//
User_Guidance_Handler::~User_Guidance_Handler (void)
{
}

//
// handle_notification_ready
//
int User_Guidance_Handler::handle_object_select (GAME::Mga::Object_in obj)
{
  if (this->is_importing_)
    return 0;

  GAME::Mga::RootFolder root_folder =  this->project_.root_folder ();

  /*GAME::Mga::Atom atm = GAME::Mga::Atom::_narrow (obj);
  GAME::Mga::RootFolder root_folder = atm->project ().root_folder ();*/

  // Contains all the models that can be added by the rootfolder
  std::vector <GAME::Mga::Meta::FCO> rootfcos;
  root_folder->meta ()->children (rootfcos);

  std::vector <GAME::Mga::Meta::Model> rootmodels;

  std::vector <GAME::Mga::Meta::FCO>::iterator
    rit = rootfcos.begin (), rit_end = rootfcos.end ();

  for (; rit != rit_end; ++ rit)
  {
    if ((*rit)->type () == OBJTYPE_MODEL)
      rootmodels.push_back ((*rit));
  }

  // Contains all the models contained by the rootfolder in model
  std::vector <GAME::Mga::Model> models;
  root_folder->children<GAME::Mga::Model> (models);

  // Initial list of options to the user
  std::vector <std::string> first;
  std::string first_select;

  first.push_back ("Add a model contained by rootfolder");

  first.push_back ("Actions relevant to existing models");

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <std::string> dlg (0, ::AfxGetMainWnd (), 2);
  dlg.title ("Please select an operation");
  dlg.directions ("User Guidance");
  dlg.string_insert (first);

  
  if (IDOK != dlg.DoModal ())
      return 0;

  first_select = dlg.string_selection ();

  if (first_select.size () > 0)
  {
    if (first_select == "Add a model contained by rootfolder")
      rootmodel_add (root_folder, rootmodels);
    else if (first_select == "Actions relevant to existing models")
      aspect_add (root_folder, models);
  } 

  return 0;

}

//
// rootmodel_add
//
int User_Guidance_Handler::rootmodel_add (GAME::Mga::RootFolder & root_folder,
                                          std::vector <GAME::Mga::Meta::Model> & rootmodels)
{
  GAME::Mga::Meta::Model metamod;

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <GAME::Mga::Meta::Model> dlg (0, ::AfxGetMainWnd (), 1);
  dlg.title ("Please select the parent model");
  dlg.directions ("Aspect Selection");
  dlg.meta_insert (rootmodels);

  if (IDOK != dlg.DoModal ())
      return 0;

  metamod = dlg.meta_selection ();

  if (!metamod.is_nil ())
  {
    GAME::Mga::Model new_model = GAME::Mga::Model_Impl::_create (root_folder, metamod);
     new_model->name (metamod->display_name ());
  }

  return 0;
}

//
// aspect_add
//
int User_Guidance_Handler::aspect_add (GAME::Mga::RootFolder & root_folder,
                                       std::vector <GAME::Mga::Model> & models)
{
  GAME::Mga::Model mod;

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <GAME::Mga::Model> dlg (0, ::AfxGetMainWnd (), 0);
  dlg.title ("Please select the parent model");
  dlg.directions ("Parent model Selection");
  dlg.insert (models);

  if (IDOK != dlg.DoModal ())
      return 0;

  mod = dlg.selection ();

  if (!mod.is_nil ())
  {
    option_list (mod);
  }
    
  return 0;
}

//
// option list
//
int User_Guidance_Handler::option_list (GAME::Mga::Model & mod)
{
  // Stores all the metafco's of type ATOM and MODEL
  std::vector <GAME::Mga::Meta::Role> fcos;

  // Stores all the metafco's of type REFERENCE
  std::vector <GAME::Mga::Meta::Role> ref;

  // Stores all the metafco's of type CONNECTION
  std::vector <GAME::Mga::Meta::Role> conn;

  GAME::Mga::Meta::Role select;

  // Collect the roles associated with the model
  // and put the metafcos in respective elements list
  std::vector <GAME::Mga::Meta::Role> allroles;

  mod->meta ()->roles (allroles);

  std::vector <GAME::Mga::Meta::Role>::iterator
    it = allroles.begin (), it_end = allroles.end ();

  for (; it != it_end; ++it)
  {
    if ((*it)->kind ()->type () == OBJTYPE_ATOM)
      fcos.push_back ((*it));
    else if ((*it)->kind ()->type () == OBJTYPE_MODEL)
      fcos.push_back ((*it));
    else if ((*it)->kind ()->type () == OBJTYPE_REFERENCE)
      ref.push_back ((*it));
    else if ((*it)->kind ()->type () == OBJTYPE_CONNECTION)
      conn.push_back ((*it));
  }

  // Initial list of operations
  std::vector <std::string> initial;
  std::string str_select;
  initial.push_back ("Add an Atom or Model");
  initial.push_back ("Delete an Atom or Model");
  initial.push_back ("Add a reference");
  initial.push_back ("Delete a reference");
  initial.push_back ("Create a Connection");

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <std::string> dlg (0, ::AfxGetMainWnd (), 2);
  dlg.title ("Please select an operation");
  dlg.directions ("User Guidance");
  dlg.string_insert (initial);

  
  if (IDOK != dlg.DoModal ())
      return 0;

  str_select = dlg.string_selection ();

  if (str_select.size () > 0)
  {
    if (str_select == "Add an Atom or Model")
      element_add (mod, fcos);
    else if (str_select == "Add a reference")
      reference_add (mod, ref);
    else if (str_select == "Create a Connection")
      connection_add (mod, conn);
    else if (str_select == "Delete an Atom or Model")
      element_delete (mod);
    else if (str_select == "Delete a reference")
      reference_delete (mod);
  } 

  return 0;
}

//
// element add
//
int User_Guidance_Handler::element_add (GAME::Mga::Model & parent_model,
                                        std::vector <GAME::Mga::Meta::Role> & fcos)
{

  GAME::Mga::Meta::Role select;
  
  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <GAME::Mga::Meta::Role> dlg (0, ::AfxGetMainWnd (), 1);
  dlg.title ("Please select the target Atom/Model for creation");
  dlg.directions ("Element Creator");
  dlg.meta_insert (fcos);

  if (IDOK != dlg.DoModal ())
      return 0;

  select = dlg.meta_selection ();

  if (!select.is_nil ())
  {
    if (select->kind()->type () == OBJTYPE_ATOM)
    {
      GAME::Mga::Atom new_atom = GAME::Mga::Atom_Impl::_create (parent_model, select);
      new_atom->name (select->display_name ());
    }
    else if (select->kind()->type () == OBJTYPE_MODEL)
    {
      GAME::Mga::Model new_model = GAME::Mga::Model_Impl::_create (parent_model, select);
      new_model->name (select->display_name ());
    }
  }

  return 0;
}

//
// element delete
//
int User_Guidance_Handler::element_delete (GAME::Mga::Model & parent_model)
{
  std::vector <GAME::Mga::FCO> elements;
  GAME::Mga::FCO select;
  parent_model->children (elements);

  std::vector <GAME::Mga::FCO> qual_fcos;

  std::vector <GAME::Mga::FCO>::iterator
    it = elements.begin (), it_end = elements.end ();

  for (; it != it_end; ++it)
  {
    if ((*it)->meta ()->type () == OBJTYPE_MODEL || (*it)->meta ()->type () == OBJTYPE_ATOM)
      qual_fcos.push_back ((*it));
  }

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <GAME::Mga::FCO> dlg (0, ::AfxGetMainWnd (), 0);
  dlg.title ("Please select the Model/Atom for deletion");
  dlg.directions ("Target evaluator");
  dlg.insert (qual_fcos);

  if (IDOK != dlg.DoModal ())
      return 0;

  select = dlg.selection ();

  if (!select.is_nil ())
  {
    select->destroy ();
  }


  return 0;
}

//
// reference delete
//
int User_Guidance_Handler::reference_delete (GAME::Mga::Model & parent_model)
{
  std::vector <GAME::Mga::FCO> elements;
  GAME::Mga::FCO select;
  parent_model->children (elements);

  std::vector <GAME::Mga::FCO> qual_fcos;

  std::vector <GAME::Mga::FCO>::iterator
    it = elements.begin (), it_end = elements.end ();

  for (; it != it_end; ++it)
  {
    if ((*it)->meta ()->type () == OBJTYPE_REFERENCE)
      qual_fcos.push_back ((*it));
  }

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <GAME::Mga::FCO> dlg (0, ::AfxGetMainWnd (), 0);
  dlg.title ("Please select the Model/Atom for deletion");
  dlg.directions ("Target evaluator");
  dlg.insert (qual_fcos);

  if (IDOK != dlg.DoModal ())
      return 0;

  select = dlg.selection ();

  if (!select.is_nil ())
  {
    select->destroy ();
  }


  return 0;
}

//
// reference add
//
int User_Guidance_Handler::reference_add (GAME::Mga::Model & parent_model,
                                          std::vector <GAME::Mga::Meta::Role> & ref)
{
  GAME::Mga::Meta::Role select;

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <GAME::Mga::Meta::Role> dlg (0, ::AfxGetMainWnd (), 1);
  dlg.title ("Please select the target Reference for creation");
  dlg.directions ("Reference Creator");
  dlg.meta_insert (ref);

  if (IDOK != dlg.DoModal ())
      return 0;

  select = dlg.meta_selection ();

  if (!select.is_nil ())
  {
    if (select->kind()->type () == OBJTYPE_REFERENCE)
    {
      GAME::Mga::Reference new_ref = GAME::Mga::Reference_Impl::_create (parent_model, select);
      new_ref->name (select->display_name ());
    }
  }

  return 0;
}

//
// connection add
//
int User_Guidance_Handler::connection_add (GAME::Mga::Model & parent_model,
                                           std::vector <GAME::Mga::Meta::Role> & conn)
{
  GAME::Mga::Meta::Role select;

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <GAME::Mga::Meta::Role> dlg (0, ::AfxGetMainWnd (), 1);
  dlg.title ("Please select the target Connection for creation");
  dlg.directions ("Connection Creator");
  dlg.meta_insert (conn);

  if (IDOK != dlg.DoModal ())
      return 0;

  select = dlg.meta_selection ();

  if (!select.is_nil ())
  {
    if (select->kind()->type () == OBJTYPE_CONNECTION)
      select_source (parent_model, select);    
  }

  return 0;
}

//
// select source
//
int User_Guidance_Handler::select_source (GAME::Mga::Model & parent_model,
                                          GAME::Mga::Meta::Role & conn)
{
  // narrowing the connection
  GAME::Mga::Meta::Connection metacon = GAME::Mga::Meta::Connection::_narrow (conn->kind ());

  GAME::Mga::FCO select;
  std::vector <GAME::Mga::FCO> fcos;

  // Collect all the possible source FCO's
  GAME::Mga::Meta::FCO metafco;

  // Get the connection points of the connection
  std::vector <GAME::Mga::Meta::ConnectionPoint> conpts;
  metacon->connectors (conpts);

  std::vector <GAME::Mga::Meta::ConnectionPoint>::iterator
    cit = conpts.begin (), cit_end = conpts.end ();

  for (; cit != cit_end; ++ cit)
    metafco = (*cit)->get_src ();

  GAME::Mga::Filter filter (parent_model->project ());

  filter.kind (metafco->name ());
  filter.apply (parent_model, fcos);

  AFX_MANAGE_STATE (::AfxGetStaticModuleState ());

  // Create the dialog and pass in the data
  using GAME::Dialogs::Selection_List_Dialog_T;
  Selection_List_Dialog_T <GAME::Mga::FCO> dlg (0, ::AfxGetMainWnd (), 0);
  dlg.title ("Please select the source for the connection");
  dlg.directions ("Source Evaluator");
  dlg.insert (fcos);

  if (IDOK != dlg.DoModal ())
      return 0;

  select = dlg.selection ();

  if (!select.is_nil ())
  {
    Association_Handler ah;
    ah.handle_object_select (select);
  }

  return 0;

}