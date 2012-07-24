// $Id$

#include "StdAfx.h"

#include "Subtypes_Method.h"
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
Subtypes_Method::Subtypes_Method (void)
{
}

//
// Destructor
//
Subtypes_Method::~Subtypes_Method (void)
{
}

//
// evaluate
//
Value * Subtypes_Method::evaluate (Ocl_Context & res, 
                                   GAME::Mga::Object caller)
{
  GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

  std::vector <GAME::Mga::FCO> temp;
  std::vector <GAME::Mga::FCO> fcos;

  // Collecting all FCOs contained by the parent model
  GAME::Mga::Filter filter (caller->project ());
  filter.kind (obj->meta ()->name ());
  filter.apply (obj->parent_model (), temp);

  // Excluding the caller from the set
  std::vector <GAME::Mga::FCO>::iterator
    it = temp.begin (), it_end = temp.end ();

  // Collecting all the subtypes
  for (; it != it_end; ++it)
  {
    if ((*it)->is_subtype ())
      fcos.push_back ((*it));
  }

  return new Collection_Value_T <GAME::Mga::FCO> (fcos);
	
}

//
// evaluate
//
Value * Subtypes_Method::evaluate (Ocl_Context & res, 
                                   Value *caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);
  std::vector <GAME::Mga::FCO> fcos;

	if (iv != 0)
	{
		GAME::Mga::Object val = iv->value ();

    GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (val);

    // Collecting all FCOs contained by the parent mode
    std::vector <GAME::Mga::FCO> temp;
    GAME::Mga::Filter filter (obj->project ());
    filter.kind (obj->meta ()->name ());
    filter.apply (obj->parent_model (), temp);

    std::vector <GAME::Mga::FCO>::iterator
      it = temp.begin (), it_end = temp.end ();

    // Collecting all the subtypes
    for (; it != it_end; ++it)
    {
      if ((*it)->is_subtype ())
        fcos.push_back ((*it));
    }
  }
  
	return new Collection_Value_T <GAME::Mga::FCO> (fcos);
}

//
// is_filter
//
bool Subtypes_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Subtypes_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Subtypes_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Subtypes_Method::is_reference (void)
{
  return false;
}