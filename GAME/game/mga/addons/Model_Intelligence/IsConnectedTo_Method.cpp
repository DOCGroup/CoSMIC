// $Id$

#include "StdAfx.h"

#include "IsConnectedTo_Method.h"
#include "Boolean_Value.h"
#include "Int_Value.h"
#include "Object_Value.h"
#include "game/mga/Connection.h"
#include "game/mga/FCO.h"

//
// Default Constructor
//
IsConnectedTo_Method::IsConnectedTo_Method (std::string & fco)
: fco_ (fco)
{
  flag = 1;
}

//
// Kind/Role Constructor
//
IsConnectedTo_Method::IsConnectedTo_Method (std::string & fco, 
                                            std::string & temp)
: fco_ (fco),
  temp_ (temp)
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
// FCO, Role and Kind Constructor
//
IsConnectedTo_Method::IsConnectedTo_Method (std::string & fco, 
                                            std::string & role, 
                                            std::string & kind)
: fco_ (fco),
  role_ (role),
  kind_ (kind)
{
  flag = 4;
}


//
// Destructor
//
IsConnectedTo_Method::~IsConnectedTo_Method (void)
{
}

//
// evaluate
//
Value * IsConnectedTo_Method::evaluate (Ocl_Context & res, 
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

  // The boolean keeping a check if the fco is connected or not
  bool isconnected = false;

  std::vector <GAME::Mga::Connection>::iterator 
    cit = conns.begin (), cit_end = conns.end ();

  // Checking if the fco is connected or not
  for (; cit != cit_end; ++cit)
  {
    if (flag == 1 || flag == 2)
    {
      if ((*cit)->src ()->name () == fco->name ())
      {
        if ((*cit)->dst ()->name () == this->fco_)
          isconnected = true;
      }
      else if ((*cit)->dst ()->name () == fco->name ())
      {
        if ((*cit)->src ()->name () == this->fco_)
          isconnected = true;
      }
    }
    else if (flag == 3 || flag == 4)
    {
      if (this->role_ == "src")
      {
        if ((*cit)->src ()->name () == this->fco_)
          isconnected = true;
      }
      else if (this->role_ == "dst")
      {
        if ((*cit)->dst ()->name () == this->fco_)
          isconnected = true;
      }
    }  
  }

  return new Boolean_Value (isconnected);
  
}

//
// evaluate
//
Value * IsConnectedTo_Method::evaluate (Ocl_Context & res, 
                                        Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

  // The boolean keeping a check if the fco is connected or not
  bool isconnected = false;

	if (iv != 0)
	{
    GAME::Mga::Object obj = iv->value ();
    GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (caller);

    // Get all the connections associated to this fco based on the 
    // kind of the connection
    std::vector <GAME::Mga::Connection> conns;

    // Filtering out the connections based on "kind" value
    if (flag == 1 || flag == 3)
      fco->in_connections (conns);
    else if (flag == 2 || flag == 4)
      fco->in_connections (this->kind_, conns);

    std::vector<GAME::Mga::Connection>::iterator
      cit = conns.begin(), cit_end = conns.end();

    // Get all the connection points based on the information provided
    // i.e. filtering based on role value
    for (; cit != cit_end; ++cit)
    {
      if (flag == 1 || flag == 2)
      {
        if ((*cit)->src ()->name () == fco->name ())
        {
          if ((*cit)->dst ()->name () == this->fco_)
            isconnected = true;
        }
        else if ((*cit)->dst ()->name () == fco->name ())
        {
          if ((*cit)->src ()->name () == this->fco_)
            isconnected = true;
        }
      }
      else if (flag == 3 || flag == 4)
      {
        if (this->role_ == "src")
        {
          if ((*cit)->src ()->name () == this->fco_)
            isconnected = true;
        }
        else if (this->role_ == "dst")
        {
          if ((*cit)->dst ()->name () == this->fco_)
            isconnected = true;
        }
      }  
    }  
  }

  return new Boolean_Value (isconnected);
  
}

//
// is_filter
//
bool IsConnectedTo_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool IsConnectedTo_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool IsConnectedTo_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool IsConnectedTo_Method::is_reference (void)
{
  return false;
}