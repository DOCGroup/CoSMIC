// $Id$

#include "StdAfx.h"

#include "ConnectedFCOs_Method.h"
#include "Collection_Value_T.h"
#include "Int_Value.h"
#include "Object_Value.h"
#include "game/mga/Connection.h"
#include "game/mga/FCO.h"

//
// Constructor
//
ConnectedFCOs_Method::ConnectedFCOs_Method (std::string &kind)
: kind_(kind)
{
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
Value * ConnectedFCOs_Method::evaluate (Ocl_Context &res, GAME::Mga::Object caller)
{
  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (caller);
  
  // Get all the connections associated to this fco based on the 
  // kind of the connection
  std::vector<GAME::Mga::Connection> conns;

  fco->in_connections (this->kind_, conns);

  std::vector<GAME::Mga::FCO> fcos;

  std::vector<GAME::Mga::Connection>::iterator 
    cit = conns.begin(), cit_end = conns.end();

  // Get all the connected fcos on the other end of this fco
  for (; cit != cit_end; ++cit)
  {
    if ((*cit)->src()->name () == fco->name ())
    {
      fcos.push_back((*cit)->dst ());
    }
    else if ((*cit)->dst()->name () == fco->name ())
    {
      fcos.push_back((*cit)->src ());
    }
  }

  return new Collection_Value_T<GAME::Mga::FCO> (fcos);
  
}

//
// evaluate
//
Value * ConnectedFCOs_Method::evaluate (Ocl_Context &res, Value *caller)
{
  Object_Value * iv = dynamic_cast <Object_Value *> (caller);

	if (iv != 0)
	{
    GAME::Mga::Object obj = iv->value ();
    GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (obj);

    std::vector<GAME::Mga::Connection> conns;
    fco->in_connections (this->kind_, conns);

    std::vector<GAME::Mga::FCO> fcos;
    std::vector<GAME::Mga::Connection>::iterator 
      cit = conns.begin(), cit_end = conns.end();

    for (; cit != cit_end; ++cit)
    {
      if ((*cit)->src()->name () == fco->name ())
        fcos.push_back((*cit)->dst ());
      else if ((*cit)->dst()->name () == fco->name ())
        fcos.push_back((*cit)->src ());
    }
    return new Collection_Value_T<GAME::Mga::FCO> (fcos);
  }
  else
	{
		std::vector<GAME::Mga::FCO> fcos;
		return new Collection_Value_T<GAME::Mga::FCO> (fcos);
	}  
}

//
// is_filter
//
bool ConnectedFCOs_Method::is_filter (void)
{
  return true;
}