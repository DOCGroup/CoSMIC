// $Id$

#include "StdAfx.h"

#include "ConnectionPoint_Method.h"
#include "Connection.h"
#include "Object_Value.h"

//
// Default Constructor
//
ConnectionPoint_Method::ConnectionPoint_Method (std::string & role)
: role_ (role)
{
}

//
// Destructor
//
ConnectionPoint_Method::~ConnectionPoint_Method (void)
{
}

//
// evaluate
//
Value * ConnectionPoint_Method::evaluate (Ocl_Context & res, 
                                          GAME::Mga::Object caller)
{
  GAME::Mga::Connection conn = GAME::Mga::Connection::_narrow (caller);

  GAME::Mga::ConnectionPoint point;

  // Collecting the connection points of the connection
  GAME::Mga::ConnectionPoints conpts;

  conn->connection_points (conpts);

  GAME::Mga::ConnectionPoints::iterator 
      cit = conpts.begin (), cit_end = conpts.end ();

  // Filtering out the valid connection point
  for (; cit != cit_end; ++cit)
  {
    if (cit->item ()->role () == this->role_)
      point = cit->item ();
  }

  return new Object_Value (point);  
}

//
// evaluate
//
Value * ConnectionPoint_Method::evaluate (Ocl_Context & res, 
                                          Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();

		GAME::Mga::Connection conn = GAME::Mga::Connection::_narrow (obj);

    GAME::Mga::ConnectionPoint point;

    // Collecting the connection points of the connection
    GAME::Mga::ConnectionPoints conpts;

    conn->connection_points (conpts);

    GAME::Mga::ConnectionPoints::iterator 
        cit = conpts.begin (), cit_end = conpts.end ();

    // Filtering out the valid connection point
    for (; cit != cit_end; ++cit)
    {
      if (cit->item ()->role () == this->role_)
        point = cit->item ();
    }    

		return new Object_Value (point);
	}
	else
	{
		GAME::Mga::ConnectionPoint point;
		return new Object_Value (point);
	}
}

//
// is_filter
//
bool ConnectionPoint_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool ConnectionPoint_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool ConnectionPoint_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool ConnectionPoint_Method::is_reference (void)
{
  return false;
}