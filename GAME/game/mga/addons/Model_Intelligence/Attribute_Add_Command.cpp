// $Id$

#include "StdAfx.h"
#include "Attribute_Add_Command.h"
#include "MetaAttribute.h"
#include "MetaFCO.h"
#include "Long_Value.h"
#include "Int_Value.h"
#include "Object_Value.h"
#include "String_Value.h"
#include "Boolean_Value.h"
#include "Double_Value.h"

//
// Constructor
//
Attribute_Add_Command::Attribute_Add_Command (GAME::Mga::FCO fco,
                                              std::string name,
                                              Value * val)
: fco_ (fco),
  atrname_ (name),
  val_ (val)
{
}

//
// Destructor
//
Attribute_Add_Command::~Attribute_Add_Command (void)
{
}

//
// execute
//
bool Attribute_Add_Command::execute (void)
{
  GAME::Mga::Meta::FCO metafco = this->fco_->meta ();

  GAME::Mga::Meta::Attribute meta_atr = metafco->attribute (this->atrname_, false);

  GAME::Mga::Attribute work_atr = this->fco_->attribute (meta_atr);

  // Filling the value of the attribute according to the type
  if (meta_atr->type () == ATTVAL_INTEGER)
  {
    Int_Value * iv = dynamic_cast <Int_Value *> (this->val_);

    if (iv != 0)
      work_atr->int_value (iv->value ());
  }
  else if (meta_atr->type () == ATTVAL_DOUBLE)
  {
    Double_Value * iv = dynamic_cast <Double_Value *> (this->val_);

    if (iv != 0)
      work_atr->double_value (iv->value ());
  }
  else if (meta_atr->type () == ATTVAL_STRING)
  {
    String_Value * iv = dynamic_cast <String_Value *> (this->val_);

    if (iv != 0)
      work_atr->string_value (iv->value ());
  }
  else if (meta_atr->type () == ATTVAL_BOOLEAN)
  {
    Boolean_Value * iv = dynamic_cast <Boolean_Value *> (this->val_);

    if (iv != 0)
      work_atr->bool_value (iv->value ());
  }

  return true;
}