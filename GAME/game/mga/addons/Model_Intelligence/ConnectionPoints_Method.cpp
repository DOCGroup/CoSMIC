// $Id$

#include "StdAfx.h"

#include "ConnectionPoints_Method.h"
#include "Connection.h"
#include "Collection_Value_T.h"
#include "Object_Value.h"

//
// Default Constructor
//
ConnectionPoints_Method::ConnectionPoints_Method (void)
{
  flag = 1;
}


//
// Constructor
//
ConnectionPoints_Method::ConnectionPoints_Method (std::string & role)
: role_ (role)
{
  flag = 2;
}

//
// Destructor
//
ConnectionPoints_Method::~ConnectionPoints_Method (void)
{
}

//
// evaluate
//
Value * ConnectionPoints_Method::evaluate (Ocl_Context & res, 
                                           GAME::Mga::Object caller)
{
  GAME::Mga::Connection conn = GAME::Mga::Connection::_narrow (caller);

  std::vector <GAME::Mga::ConnectionPoint> temp;

  // Collecting the connection points of the connection
  GAME::Mga::ConnectionPoints conpts;

  conn->connection_points (conpts);

  GAME::Mga::ConnectionPoints::iterator 
      cit = conpts.begin (), cit_end = conpts.end ();

  // Filtering out the connection points based on their role (if present)
  for (; cit != cit_end; ++cit)
  {
    if (flag == 1)
      temp.push_back (cit->item ());
    else if (flag == 2)
    {
      if (cit->item ()->role () == this->role_)
        temp.push_back (cit->item ());
    }
  }

  return new Collection_Value_T <GAME::Mga::ConnectionPoint> (temp);  
}

//
// evaluate
//
Value * ConnectionPoints_Method::evaluate (Ocl_Context &res, Value *caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();

		GAME::Mga::Connection conn = GAME::Mga::Connection::_narrow (obj);

    std::vector <GAME::Mga::ConnectionPoint> temp;

    // Collecting the connection points of the connection
    GAME::Mga::ConnectionPoints conpts;

    conn->connection_points (conpts);

    GAME::Mga::ConnectionPoints::iterator 
        cit = conpts.begin (), cit_end = conpts.end ();

    // Filtering out the connection points based on their role (if present)
    for (; cit != cit_end; ++cit)
    {
      if (flag == 1)
        temp.push_back (cit->item ());
      else if (flag == 2)
      {
        if (cit->item ()->role () == this->role_)
          temp.push_back (cit->item ());
      }
    }    

		return new Collection_Value_T <GAME::Mga::ConnectionPoint> (temp);
	}
	else
	{
		std::vector <GAME::Mga::ConnectionPoint> temp;
		return new Collection_Value_T <GAME::Mga::ConnectionPoint> (temp);
	}
}

//
// is_filter
//
bool ConnectionPoints_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool ConnectionPoints_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool ConnectionPoints_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool ConnectionPoints_Method::is_reference (void)
{
  return false;
}