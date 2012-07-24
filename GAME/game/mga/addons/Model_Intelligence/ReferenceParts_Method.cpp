// $Id:  $

#include "StdAfx.h"

#include "ReferenceParts_Method.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Reference.h"
#include "Collection_Value_T.h"
#include "Object_Value.h"

//
// Constructor
//
ReferenceParts_Method::ReferenceParts_Method (std::string &role)
: role_ (role)
{
}

//
// Destructor
//
ReferenceParts_Method::~ReferenceParts_Method (void)
{
}

//
// evaluate
//
Value * ReferenceParts_Method::evaluate (Ocl_Context & res, 
                                         GAME::Mga::Object caller)
{
	GAME::Mga::Model mod = GAME::Mga::Model::_narrow (caller);

  std::vector <GAME::Mga::Reference> parts;
  std::vector <std::string> rolenames;
  bool flag = false;

  // Verifying if role_ is a valid containment role
  std::vector <GAME::Mga::Meta::Role> all;
  mod->meta ()->roles (all);
  std::vector <GAME::Mga::Meta::Role>::iterator
    it = all.begin (), ite = all.end ();

  for (; it != ite; ++it)
    rolenames.push_back ((*it)->name ());

  std::vector <std::string>::iterator
    st = rolenames.begin (), ste = rolenames.end ();

  for (; st != ste; ++st)
  {
    if ((*st) == this->role_)
      flag = true;
  }

  // Continue if the role is valid
  if (flag)
  {
    GAME::Mga::Meta::Role target_metarole = mod->meta ()->role (this->role_);

    // Setting the target metarole in the model intelligence context
    // only if it doesn't already exist in the list
    std::vector <GAME::Mga::Meta::Role>::iterator
      roleit = res.target_metaroles.begin (), roleit_end = res.target_metaroles.end ();

    bool exists = false;

    for (; roleit != roleit_end; ++ roleit)
    {
      if ((*roleit)->name () == target_metarole->name ())
        exists = true;
    }

    if (!exists)
      res.target_metaroles.push_back (target_metarole);
  
    GAME::Mga::Meta::FCO temp = target_metarole->kind ();

    // Collecting children only if the type of element is Reference
    if (temp->type () == OBJTYPE_REFERENCE)
      mod->children (temp->name (), parts);
  }

  return new Collection_Value_T <GAME::Mga::Reference> (parts);


}

//
// evaluate
//
Value * ReferenceParts_Method::evaluate (Ocl_Context & res, 
                                         Value * caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
    // Collecting value of the object
		GAME::Mga::Object obj = iv->value ();

		GAME::Mga::Model mod = GAME::Mga::Model::_narrow (obj);

    std::vector <GAME::Mga::Reference> parts;
    std::vector <std::string> rolenames;
    bool flag = false;

    // Verifying if role_ is a valid containment role
    std::vector <GAME::Mga::Meta::Role> all;
    mod->meta ()->roles (all);
    std::vector <GAME::Mga::Meta::Role>::iterator
      it = all.begin (), ite = all.end ();

    for (; it != ite; ++it)
      rolenames.push_back ((*it)->name ());

    std::vector <std::string>::iterator
      st = rolenames.begin (), ste = rolenames.end ();

    for (; st != ste; ++st)
    {
      if ((*st) == this->role_)
        flag = true;
    }

    // Continuing if the role is valid
    if (flag)
    {
      GAME::Mga::Meta::Role target_metarole = mod->meta ()->role (this->role_);

      // Setting the target metarole in the model intelligence context
      // only if it doesn't already exist in the list
      std::vector <GAME::Mga::Meta::Role>::iterator
        roleit = res.target_metaroles.begin (), roleit_end = res.target_metaroles.end ();

      bool exists = false;

      for (; roleit != roleit_end; ++ roleit)
      {
        if ((*roleit)->name () == target_metarole->name ())
          exists = true;
      }

      if (!exists)
        res.target_metaroles.push_back (target_metarole);
  	  
		  GAME::Mga::Meta::FCO temp = target_metarole->kind ();

      // Collecting children only if the type of element is Reference
      if (temp->type () == OBJTYPE_REFERENCE)
        mod->children (temp->name (), parts);
    }

    return new Collection_Value_T <GAME::Mga::Reference> (parts);
	}
	else
	{
    std::vector <GAME::Mga::Reference> parts;
    return new Collection_Value_T <GAME::Mga::Reference> (parts);
	}
}

//
// is_filter
//
bool ReferenceParts_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool ReferenceParts_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool ReferenceParts_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool ReferenceParts_Method::is_reference (void)
{
  return false;
}