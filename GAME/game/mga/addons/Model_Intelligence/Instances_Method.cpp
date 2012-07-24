// $Id$

#include "StdAfx.h"

#include "Instances_Method.h"
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
Instances_Method::Instances_Method (void)
{
}

//
// Destructor
//
Instances_Method::~Instances_Method (void)
{
}

//
// evaluate
//
Value * Instances_Method::evaluate (Ocl_Context & res, GAME::Mga::Object caller)
{
  GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (caller);

  std::vector <GAME::Mga::FCO> temp;
  std::vector <GAME::Mga::FCO> fcos;
  GAME::Mga::Filter filter (caller->project ());
  filter.kind (obj->meta ()->name ());
  filter.apply (obj->parent_model (), temp);

  // Excluding the caller from the set
  std::vector <GAME::Mga::FCO>::iterator
    it = temp.begin (), it_end = temp.end ();

  for (; it != it_end; ++it)
  {
    if ((*it)->is_instance ())
      fcos.push_back ((*it));
  }

  return new Collection_Value_T <GAME::Mga::FCO> (fcos);
	
}

//
// evaluate
//
Value * Instances_Method::evaluate(Ocl_Context &res, Value *caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);
  std::vector <GAME::Mga::FCO> fcos;

	if (iv != 0)
	{
		GAME::Mga::Object val = iv->value ();

    GAME::Mga::FCO obj = GAME::Mga::FCO::_narrow (val);

    std::vector <GAME::Mga::FCO> temp;
    GAME::Mga::Filter filter (obj->project ());
    filter.kind (obj->meta ()->name ());
    filter.apply (obj->parent_model (), temp);

    // Exclusing the caller from the set
    std::vector <GAME::Mga::FCO>::iterator
      it = temp.begin (), it_end = temp.end ();

    for (; it != it_end; ++it)
    {
      if ((*it)->is_instance ())
        fcos.push_back ((*it));
    }
  }
  
	return new Collection_Value_T<GAME::Mga::FCO> (fcos);
}

//
// is_filter
//
bool Instances_Method::is_filter (void)
{
  return false;
}

//
// is_association
//
bool Instances_Method::is_association (void)
{
  return false;
}

//
// is_containment
//
bool Instances_Method::is_containment (void)
{
  return false;
}

//
// is_reference
//
bool Instances_Method::is_reference (void)
{
  return false;
}