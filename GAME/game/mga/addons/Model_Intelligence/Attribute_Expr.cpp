// $Id:  $

#include "StdAfx.h"

#include "Attribute_Expr.h"
#include "MetaFCO.h"
#include "MetaBase.h"
#include "MetaAttribute.h"
#include "Long_Value.h"
#include "Int_Value.h"
#include "Object_Value.h"
#include "String_Value.h"
#include "Boolean_Value.h"
#include "Double_Value.h"

//
// Constructor
//
Attribute_Expr::Attribute_Expr (std::string &var, std::string &attr)
: var_(var),
  attribute_(attr)
{
}

//
// Destructor
//
Attribute_Expr::~Attribute_Expr (void)
{
}

//
// evaluate
//
Value * Attribute_Expr::evaluate (Ocl_Context &res)
{
	res.model_constraint = false;

  // The object value associated with the local variable is taken from map
  // and is used for attribute value calculation
  Object_Value * iv = dynamic_cast <Object_Value *> (res.locals [this->var_]);

  GAME::Mga::FCO fco = GAME::Mga::FCO::_narrow (iv->value ());

  GAME::Mga::Meta::FCO metafco = fco->meta ();

	std::string name = metafco->name ();
	GAME::Mga::Meta::Attribute meta_atr = metafco->attribute (this->attribute_, false);
	std::string atrname = meta_atr->name ();

	GAME::Mga::Attribute work_atr = fco->attribute (meta_atr);

	if (meta_atr->type () == ATTVAL_INTEGER)
	{
		long val = work_atr->int_value ();
		return new Int_Value (val);
	}
	else if (meta_atr->type () == ATTVAL_STRING)
	{
		std::string val = work_atr->string_value ();
		return new String_Value (val);
	}
	else if (meta_atr->type () == ATTVAL_BOOLEAN)
	{
		bool val = work_atr->bool_value ();
		return new Boolean_Value (val);
	}
	else if (meta_atr->type () == ATTVAL_DOUBLE)
	{
		double val = work_atr->double_value ();
		return new Double_Value (val);
	}
	else
	{
		std::cerr <<"Invalid return type of Attribute";
	}
}

//
// filter_evaluate
//
Value * Attribute_Expr::filter_evaluate (Ocl_Context &res)
{
	res.model_constraint = false;

  // The current fco is used for attribute value computation
	GAME::Mga::Meta::FCO metafco = res.cur_fco->meta ();

	std::string name = metafco->name ();
	GAME::Mga::Meta::Attribute meta_atr = metafco->attribute (this->attribute_, false);
	std::string atrname = meta_atr->name ();

	GAME::Mga::Attribute work_atr = res.cur_fco->attribute (meta_atr);

	if (meta_atr->type () == ATTVAL_INTEGER)
	{
		long val = work_atr->int_value ();
		return new Int_Value (val);
	}
	else if (meta_atr->type () == ATTVAL_STRING)
	{
		std::string val = work_atr->string_value ();
		return new String_Value (val);
	}
	else if (meta_atr->type () == ATTVAL_BOOLEAN)
	{
		bool val = work_atr->bool_value ();
		return new Boolean_Value (val);
	}
	else if (meta_atr->type () == ATTVAL_DOUBLE)
	{
		double val = work_atr->double_value ();
		return new Double_Value (val);
	}
	else
	{
		std::cerr <<"Invalid return type of Attribute";
	}
}

//
// is_mutable
//
bool Attribute_Expr::is_mutable (void)
{
	return true;
}

//
// is_filter
//
bool Attribute_Expr::is_filter (void)
{
  return true;
}