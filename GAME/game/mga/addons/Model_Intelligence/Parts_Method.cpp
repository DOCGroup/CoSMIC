// $Id$

#include "StdAfx.h"

#include "Parts_Method.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Collection_Value_T.h"
#include "Object_Value.h"

//
// Constructor
//
Parts_Method::Parts_Method (std::string & role)
: role_ (role)
{
}

//
// Destructor
//
Parts_Method::~Parts_Method (void)
{
}

//
// evaluate
//
Value * Parts_Method::evaluate (Ocl_Context & res, 
                                GAME::Mga::Object caller)
{
	GAME::Mga::Model mod = GAME::Mga::Model::_narrow (caller);

	std::vector <GAME::Mga::FCO> parts;
  std::vector <std::string> rolenames;
  bool flag = false;

  // Collecting all FCOS under the invoking object
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

    mod->children (temp->name(), parts);
  }

  return new Collection_Value_T<GAME::Mga::FCO> (parts);
}

//
// evaluate
//
Value * Parts_Method::evaluate(Ocl_Context &res, Value *caller)
{
	Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();

		GAME::Mga::Model mod = GAME::Mga::Model::_narrow (obj);

		std::vector<GAME::Mga::FCO> parts;
    std::vector <std::string> rolenames;
    bool flag = false;

    // Collecting all FCOs contained by the invoking FCO
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

		  mod->children (temp->name(), parts);
    }

		return new Collection_Value_T <GAME::Mga::FCO> (parts);
	}
	else
	{
		std::vector <GAME::Mga::FCO> parts;
		return new Collection_Value_T <GAME::Mga::FCO> (parts);
	}
}

//
// is_filter
//
bool Parts_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Parts_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Parts_Method::is_containment (void)
{
  return true;
}

//
// is_reference
//
bool Parts_Method::is_reference (void)
{
  return false;
}