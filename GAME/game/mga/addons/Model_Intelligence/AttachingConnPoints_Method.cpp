// $Id$

#include "StdAfx.h"

#include "AttachingConnPoints_Method.h"
#include "Collection_Value_T.h"
#include "Int_Value.h"
#include "Object_Value.h"
#include "game/mga/Connection.h"
#include "game/mga/FCO.h"

//
// Default Constructor
//
AttachingConnPoints_Method::AttachingConnPoints_Method (void)
{
  flag = 1;
}

//
// Kind/Role Constructor
//
AttachingConnPoints_Method::AttachingConnPoints_Method (std::string & temp)
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
AttachingConnPoints_Method::AttachingConnPoints_Method (std::string & role, 
                                                        std::string & kind)
: role_ (role),
  kind_ (kind)
{
  flag = 4;
}

//
// Destructor
//
AttachingConnPoints_Method::~AttachingConnPoints_Method (void)
{
}

//
// evaluate
//
Value * AttachingConnPoints_Method::evaluate (Ocl_Context & res, 
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

  std::vector <GAME::Mga::ConnectionPoint> conpts;

  std::vector <GAME::Mga::Connection>::iterator 
    cit = conns.begin(), cit_end = conns.end();

  // Get all the connection points based on the information provided
  // i.e. filtering based on role value
  for (; cit != cit_end; ++cit)
  {
    if (flag == 1 || flag == 2)
    {
      conpts.push_back ((*cit)->connection_point ("src"));
      conpts.push_back ((*cit)->connection_point ("dst"));
    }
    else if (flag == 3 || flag == 4)
    {
      conpts.push_back ((*cit)->connection_point (this->role_));
    }  
  }

  return new Collection_Value_T <GAME::Mga::ConnectionPoint> (conpts);
  
}

//
// evaluate
//
Value * AttachingConnPoints_Method::evaluate (Ocl_Context & res, 
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

    std::vector <GAME::Mga::ConnectionPoint> conpts;

    std::vector <GAME::Mga::Connection>::iterator
      cit = conns.begin(), cit_end = conns.end();

    // Get all the connection points based on the information provided
    // i.e. filtering based on role value
    for (; cit != cit_end; ++cit)
    {
      if (flag == 1 || flag == 2)
      {
        conpts.push_back ((*cit)->connection_point ("src"));
        conpts.push_back ((*cit)->connection_point ("dst"));
      }
      else if (flag == 3 || flag == 4)
      {
        conpts.push_back ((*cit)->connection_point (this->role_));
      }  
    }

    return new Collection_Value_T <GAME::Mga::ConnectionPoint> (conpts);    
  }
  else
	{
		std::vector <GAME::Mga::ConnectionPoint> conpts;
		return new Collection_Value_T <GAME::Mga::ConnectionPoint> (conpts);
	}  
}

//
// is_filter
//
bool AttachingConnPoints_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool AttachingConnPoints_Method::is_association (void)
{
  return true;
}

//
// is_containment
//
bool AttachingConnPoints_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool AttachingConnPoints_Method::is_reference (void)
{
  return false;
}