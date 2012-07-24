// $Id$

#include "StdAfx.h"

#include "AttachingConnections_Method.h"
#include "Collection_Value_T.h"
#include "Int_Value.h"
#include "Object_Value.h"
#include "game/mga/Connection.h"
#include "game/mga/FCO.h"

//
// Default Constructor
//
AttachingConnections_Method::AttachingConnections_Method (void)
{
  flag = 1;
}

//
// Kind/Role Constructor
//
AttachingConnections_Method::AttachingConnections_Method (std::string & temp)
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
AttachingConnections_Method::AttachingConnections_Method (std::string & role, 
                                                          std::string & kind)
: role_ (role),
  kind_ (kind)
{
  flag = 4;
}

//
// Destructor
//
AttachingConnections_Method::~AttachingConnections_Method (void)
{
}

//
// evaluate
//
Value * AttachingConnections_Method::evaluate (Ocl_Context & res, 
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

  std::vector <GAME::Mga::Connection> qual_conn;

  std::vector <GAME::Mga::Connection>::iterator 
    cit = conns.begin (), cit_end = conns.end ();

  // Get all the connections based on the information provided
  // i.e. filtering based on role value (only those connections
  // are collected for which the calling fco has role "this->role_")
  for (; cit != cit_end; ++cit)
  {
    if (flag == 1 || flag == 2)
    {
      qual_conn.push_back ((*cit));
    }
    else if (flag == 3 || flag == 4)
    {
      if (this->role_ == "src")
        qual_conn.push_back ((*cit)->connection_point ("dst")->target ());
      else if (this->role_ == "dst")
        qual_conn.push_back ((*cit)->connection_point ("src")->target ());
    }  
  }

  return new Collection_Value_T <GAME::Mga::Connection> (qual_conn);
  
}

//
// evaluate
//
Value * AttachingConnections_Method::evaluate (Ocl_Context & res, 
                                               Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

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

    std::vector <GAME::Mga::Connection> qual_conn;

    std::vector <GAME::Mga::Connection>::iterator
      cit = conns.begin (), cit_end = conns.end ();

    // Get all the connection points based on the information provided
    // i.e. filtering based on role value
    for (; cit != cit_end; ++cit)
    {
      if (flag == 1 || flag == 2)
      {
        qual_conn.push_back ((*cit));
      }
      else if (flag == 3 || flag == 4)
      {
        if (this->role_ == "src")
          qual_conn.push_back ((*cit)->connection_point ("dst")->target ());
        else if (this->role_ == "dst")
          qual_conn.push_back ((*cit)->connection_point ("src")->target ());
      }  
    }

    return new Collection_Value_T <GAME::Mga::Connection> (qual_conn);    
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
bool AttachingConnections_Method::is_filter (void)
{
  return true;
}

//
// is_association
//
bool AttachingConnections_Method::is_association (void)
{
  return true;
}

//
// is_containment
//
bool AttachingConnections_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool AttachingConnections_Method::is_reference (void)
{
  return false;
}