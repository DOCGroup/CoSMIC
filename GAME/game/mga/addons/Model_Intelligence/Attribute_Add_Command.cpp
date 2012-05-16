// $Id:  $

#include "StdAfx.h"
#include "Attribute_Add_Command.h"
#include "MetaAttribute.h"
#include "MetaFCO.h"


//
// Constructor
//
Attribute_Add_Command::Attribute_Add_Command (GAME::Mga::FCO fco,
                                              std::string name,
                                              double count,
                                              int flag)
: fco_ (fco),
  atrname_ (name),
  count_ (count),
  flag_ (flag)
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
  // This gets called if the attribute is an int/float/double
  if (this->flag_ == 1)
  {
    GAME::Mga::Meta::FCO metafco = this->fco_->meta ();

	  std::string name = metafco->name ();
    GAME::Mga::Meta::Attribute meta_atr = metafco->attribute (this->atrname_, false);
	  
	  GAME::Mga::Attribute work_atr = this->fco_->attribute (meta_atr);

    if (meta_atr->type () == ATTVAL_INTEGER)
      work_atr->int_value (this->count_);
    else if (meta_atr->type () == ATTVAL_DOUBLE)
      work_atr->double_value (this->count_);
  }
  return true;
}