// $Id$

#include "StdAfx.h"

#include "UsedByConnPoints_Method.h"
#include "Connection.h"
#include "Collection_Value_T.h"
#include "Object_Value.h"

//
// Default Constructor
//
UsedByConnPoints_Method::UsedByConnPoints_Method (void)
{
  flag = 1;
}


//
// Constructor
//
UsedByConnPoints_Method::UsedByConnPoints_Method (std::string & kind)
: kind_ (kind)
{
  flag = 2;
}

//
// Destructor
//
UsedByConnPoints_Method::~UsedByConnPoints_Method (void)
{
}

//
// evaluate
//
Value * UsedByConnPoints_Method::evaluate (Ocl_Context & res, 
                                           GAME::Mga::Object caller)
{
  GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (caller);

  std::vector <GAME::Mga::ConnectionPoint> pts;

  // Collecting the connection points of the connection
  GAME::Mga::ConnectionPoints conpts;

  ref->in_connection_points (conpts);

  GAME::Mga::ConnectionPoints::iterator 
      cit = conpts.begin (), cit_end = conpts.end ();

  // Filtering the connection points based on the kind of connection
  for (; cit != cit_end; ++cit)
  {
    if (flag == 1)
      pts.push_back(cit->item ());
    else if (flag == 2)
    {
      if (cit->item()->owner ()->name () == this->kind_)
        pts.push_back(cit->item ());
    }
  }

  return new Collection_Value_T <GAME::Mga::ConnectionPoint> (pts);  
}

//
// evaluate
//
Value * UsedByConnPoints_Method::evaluate (Ocl_Context & res, 
                                           Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
		GAME::Mga::Object obj = iv->value ();

    GAME::Mga::Reference ref = GAME::Mga::Reference::_narrow (obj);

    std::vector <GAME::Mga::ConnectionPoint> pts;

    // Collecting the connection points of the connection
    GAME::Mga::ConnectionPoints conpts;

    ref->in_connection_points (conpts);

    GAME::Mga::ConnectionPoints::iterator 
        cit = conpts.begin (), cit_end = conpts.end ();

    // Filtering the connection points based on the kind of connection
    for (; cit != cit_end; ++cit)
    {
      if (flag == 1)
        pts.push_back(cit->item ());
      else if (flag == 2)
      {
        if (cit->item()->owner ()->name () == this->kind_)
          pts.push_back(cit->item ());
      }
    }    

		return new Collection_Value_T <GAME::Mga::ConnectionPoint> (pts);
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
bool UsedByConnPoints_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool UsedByConnPoints_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool UsedByConnPoints_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool UsedByConnPoints_Method::is_reference (void)
{
  return false;
}