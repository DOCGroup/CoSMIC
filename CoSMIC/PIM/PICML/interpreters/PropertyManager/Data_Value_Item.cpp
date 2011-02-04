// $Id$

#include "StdAfx.h"
#include "Data_Value_Item.h"
#include "Data_Value_Controls.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "ace/Hash_Map_Manager.h"

#include "resource.h"

#include "game/mga/stlace.h"

///////////////////////////////////////////////////////////////////////////////
// class PICML_Data_Value_Control_Selector

#define SINGLETON_CONTROL(X) \
  ACE_Singleton <X, ACE_Null_Mutex>::instance ()

/**
 * @class PICML_Data_Value_Control_Selector
 *
 * Helper class for selecting the correct control for data value.
 */
class PICML_Data_Value_Control_Selector
{
public:
  PICML_Data_Value_Control_Selector (void)
  {
    this->controls_.bind ("Boolean",
                          SINGLETON_CONTROL (PICML_Boolean_Data_Value_Control));

    this->controls_.bind ("Char",
                          SINGLETON_CONTROL (PICML_Char_Data_Value_Control));

    this->controls_.bind ("WideChar",
                          SINGLETON_CONTROL (PICML_Char_Data_Value_Control));

    this->controls_.bind ("Enum",
                          SINGLETON_CONTROL (PICML_Enum_Data_Value_Control));

    this->controls_.bind ("ShortInteger",
                          SINGLETON_CONTROL (PICML_Short_Data_Value_Control));

    this->controls_.bind ("UnsignedShortInteger",
                          SINGLETON_CONTROL (PICML_UShort_Data_Value_Control));

    this->controls_.bind ("LongInteger",
                          SINGLETON_CONTROL (PICML_Long_Data_Value_Control));

    this->controls_.bind ("UnsignedLongInteger",
                          SINGLETON_CONTROL (PICML_ULong_Data_Value_Control));

    // TODO Update control for LongLongInteger
    this->controls_.bind ("LongLongInteger",
                          SINGLETON_CONTROL (PICML_String_Data_Value_Control));

    // TODO Update control for UnsignedLongLongInteger
    this->controls_.bind ("UnsignedLongLongInteger",
                          SINGLETON_CONTROL (PICML_String_Data_Value_Control));

    this->controls_.bind ("FloatNumber",
                          SINGLETON_CONTROL (PICML_String_Data_Value_Control));

    this->controls_.bind ("DoubleNumber",
                          SINGLETON_CONTROL (PICML_String_Data_Value_Control));

    this->controls_.bind ("String",
                          SINGLETON_CONTROL (PICML_String_Data_Value_Control));

    this->controls_.bind ("WideString",
                          SINGLETON_CONTROL (PICML_String_Data_Value_Control));
  }

  int select (const std::string & metaname, PICML_Data_Value_Control * & control)
  {
    return this->controls_.find (metaname, control);
  }

private:
  /// Mapping of the controls by their type.
  ACE_Hash_Map_Manager <std::string,
                        PICML_Data_Value_Control *,
                        ACE_Null_Mutex> controls_;
};

#define PICML_GLOBAL_CONTROL_SELECTOR \
  ACE_Singleton <PICML_Data_Value_Control_Selector, \
                 ACE_Null_Mutex>::instance ()

///////////////////////////////////////////////////////////////////////////////
// class Data_Value_Item

//
// Data_Value_Item
//
Data_Value_Item::Data_Value_Item (const GAME::Mga::FCO_in item)
: item_ (item),
  control_ (0)
{

}

//
// is_complex
//
bool Data_Value_Item::is_complex (void) const
{
  return false;
}

//
// get_item
//
GAME::Mga::FCO Data_Value_Item::get_item (void)
{
  return this->item_;
}

//
// get_display_info
//
void Data_Value_Item::
get_display_info (std::string & name, std::string & value) const
{
  name = this->item_->name ();
  value = this->item_->attribute ("Value")->string_value ();
}

//
// value_click_begin
//
void Data_Value_Item::
value_click_begin (CWnd * parent, int item, const CRect & rect)
{
  // Select the correct control based on the value's type.
  GAME::Mga::Reference data_value = GAME::Mga::Reference::_narrow (this->item_);
  GAME::Mga::FCO fco = data_value->refers_to ();

  const std::string metaname = fco->meta ()->name ();

  if (0 != PICML_GLOBAL_CONTROL_SELECTOR->select (metaname, this->control_))
    return;

  // Initialize and create the control.
  this->control_->InitControl (this->item_);
  this->control_->Create (0,
                          rect,
                          parent,
                          IDC_EDIT_CONTROL);
}

//
// value_click_end
//
void Data_Value_Item::value_click_end (void)
{
  if (0 == this->control_)
    return;

  // Destroy the control.
  this->control_->Destroy ();
  this->control_ = 0;
}
