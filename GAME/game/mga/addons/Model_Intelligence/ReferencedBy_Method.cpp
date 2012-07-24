// $Id$

#include "StdAfx.h"

#include "ReferencedBy_Method.h"
#include "game/mga/Filter.h"
#include "MetaModel.h"
#include "MetaRole.h"
#include "MetaFCO.h"
#include "FCO.h"
#include "Collection_Value_T.h"
#include "Object_Value.h"

//
// Constructor
//
ReferencedBy_Method::ReferencedBy_Method (void)
{
}

//
// Kind constructor
//
ReferencedBy_Method::ReferencedBy_Method (std::string & kind)
: kind_ (kind)
{
  flag = 1;
}

//
// Destructor
//
ReferencedBy_Method::~ReferencedBy_Method (void)
{
}

//
// evaluate
//
Value * ReferencedBy_Method::evaluate (Ocl_Context & res, 
                                       GAME::Mga::Object caller)
{
  GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

  std::vector <GAME::Mga::Reference> temps;

  // Collected the references
  obj->referenced_by (temps);

  // Prune the reference set by KIND
  if (flag == 1)
  {
    std::vector <GAME::Mga::Reference> refs;

    std::vector <GAME::Mga::Reference>::iterator
      it = temps.begin (), it_end = temps.end ();

    for (; it != it_end; ++ it)
    {
      if ((*it)->meta ()->name () == this->kind_)
        refs.push_back ((*it));
    }

    return new Collection_Value_T <GAME::Mga::Reference> (refs);
  }

  return new Collection_Value_T <GAME::Mga::Reference> (temps);
	
}

//
// evaluate
//
Value * ReferencedBy_Method::evaluate (Ocl_Context & res, 
                                       Value * caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);
  std::vector <GAME::Mga::Reference> temps;

	if (iv != 0)
	{
		GAME::Mga::Object val = iv->value ();

    GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (val);

    // Collected the references
    obj->referenced_by (temps);

    // Prune the reference set by KIND
    if (flag == 1)
    {
      std::vector <GAME::Mga::Reference> refs;

      std::vector <GAME::Mga::Reference>::iterator
        it = temps.begin (), it_end = temps.end ();

      for (; it != it_end; ++ it)
      {
        if ((*it)->meta ()->name () == this->kind_)
          refs.push_back ((*it));
      }

      return new Collection_Value_T <GAME::Mga::Reference> (refs);
    }         
  }
  
	return new Collection_Value_T <GAME::Mga::Reference> (temps);
}

//
// is_filter
//
bool ReferencedBy_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool ReferencedBy_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool ReferencedBy_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool ReferencedBy_Method::is_reference (void)
{
  return false;
}