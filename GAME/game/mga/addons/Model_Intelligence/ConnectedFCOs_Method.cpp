// $Id$

#include "StdAfx.h"

#include "ConnectedFCOs_Method.h"
#include "Collection_Value_T.h"
#include "Int_Value.h"
#include "Object_Value.h"
#include "game/mga/Connection.h"
#include "game/mga/FCO.h"

//
// Default Constructor
//
ConnectedFCOs_Method::ConnectedFCOs_Method (void)
{
  flag = 1;
}

//
// Role/Kind Constructor
//
ConnectedFCOs_Method::ConnectedFCOs_Method (std::string & temp)
: temp_ (temp)
{
  if (this->temp_ == "src" || this->temp_ == "dst")
  {
    this->role_ = this->temp_;
    flag = 3;
  }
  else
  {
    this->kind_ = this->temp_;
    flag = 2;
  }
}

//
// Role and Kind Constructor
//
ConnectedFCOs_Method::ConnectedFCOs_Method (std::string & role, 
                                            std::string & kind)
: role_ (role),
  kind_ (kind)
{
  flag = 4;
}

//
// Destructor
//
ConnectedFCOs_Method::~ConnectedFCOs_Method (void)
{
}

//
// evaluate
//
Value * ConnectedFCOs_Method::evaluate (Ocl_Context & res, 
                                        GAME::Mga::Object caller)
{
  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (caller);
  
  // Get all the connections associated to this fco based on the 
  // kind of the connection
  std::vector <GAME::Mga::Connection> conns;

  // Filtering out the connections based on "kind" value
  if (flag == 1 || flag == 3)
    fco->in_connections (conns);
  else if (flag == 2 || flag == 4)
    fco->in_connections (this->kind_, conns);

  std::vector <GAME::Mga::FCO> fcos;

  std::vector <GAME::Mga::Connection>::iterator 
    cit = conns.begin (), cit_end = conns.end ();

  // Get all the connected fcos on the other end of this fco
  // based on the "role" values
  for (; cit != cit_end; ++cit)
  {
    if (flag == 1 || flag == 2)
    {
      if ((*cit)->src ()->name () == fco->name ())
        fcos.push_back ((*cit)->dst ());
      else if ((*cit)->dst ()->name () == fco->name ())
        fcos.push_back ((*cit)->src ());
    }
    else if (flag == 3 || flag == 4)
    {
      if (this->role_ == "src")
        fcos.push_back ((*cit)->src ());
      else if (this->role_ == "dst")
        fcos.push_back ((*cit)->dst ());
    }
  }

  return new Collection_Value_T <GAME::Mga::FCO> (fcos);
  
}

//
// evaluate
//
Value * ConnectedFCOs_Method::evaluate (Ocl_Context & res, 
                                        Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
    GAME::Mga::Object obj = iv->value ();
    GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);

    std::vector <GAME::Mga::Connection> conns;

    // Filtering out the connections based on "kind" value
    if (flag == 1 || flag == 3)
      fco->in_connections (conns);
    else if (flag == 2 || flag == 4)
      fco->in_connections (this->kind_, conns);
    
    std::vector <GAME::Mga::FCO> fcos;
    std::vector <GAME::Mga::Connection>::iterator 
      cit = conns.begin (), cit_end = conns.end ();

    // Get all the connected fcos on the other end of this fco
    // based on the "role" values
    for (; cit != cit_end; ++cit)
    {
      if (flag == 1 || flag == 2)
      {
        if ((*cit)->src ()->name () == fco->name ())
          fcos.push_back ((*cit)->dst ());
        else if ((*cit)->dst ()->name () == fco->name ())
          fcos.push_back ((*cit)->src ());
      }
      else if (flag == 3 || flag == 4)
      {
        if (this->role_ == "src")
          fcos.push_back ((*cit)->src ());
        else if (this->role_ == "dst")
          fcos.push_back ((*cit)->dst ());
      }
    }
    return new Collection_Value_T <GAME::Mga::FCO> (fcos);
  }
  else
	{
		std::vector <GAME::Mga::FCO> fcos;
		return new Collection_Value_T <GAME::Mga::FCO> (fcos);
	}  
}

//
// is_filter
//
bool ConnectedFCOs_Method::is_filter (void)
{
  return true;
}

//
// is_association
//
bool ConnectedFCOs_Method::is_association (void)
{
  return true;
}

//
// is_containment
//
bool ConnectedFCOs_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool ConnectedFCOs_Method::is_reference (void)
{
  return false;
}