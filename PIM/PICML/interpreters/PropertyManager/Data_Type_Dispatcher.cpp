#include "stdafx.h"
#include "Data_Type_Dispatcher.h"

//
// PICML_Data_Type_Dispatcher
//
PICML_Data_Type_Dispatcher::PICML_Data_Type_Dispatcher (void)
{ 
  this->insert <PICML::Boolean> ();

  this->insert <PICML::Byte> ();
  this->insert <PICML::Char> ();
  this->insert <PICML::WideChar> ();

  this->insert <PICML::String> ();
  this->insert <PICML::WideString> ();

  this->insert <PICML::ShortInteger> ();
  this->insert <PICML::LongInteger> ();
  this->insert <PICML::LongLongInteger> ();

  this->insert <PICML::UnsignedShortInteger> ();
  this->insert <PICML::UnsignedLongInteger> ();
  this->insert <PICML::UnsignedLongLongInteger> ();

  this->insert <PICML::FloatNumber> ();
  this->insert <PICML::DoubleNumber> ();
  this->insert <PICML::LongDoubleNumber> ();

  this->insert <PICML::Enum> ();

  this->insert <PICML::Aggregate> ();
  this->insert <PICML::Collection> ();
}
