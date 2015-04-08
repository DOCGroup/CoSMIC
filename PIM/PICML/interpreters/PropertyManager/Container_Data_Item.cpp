#include "StdAfx.h"
#include "Container_Data_Item.h"

//
// Container_Data_Item
//
Container_Data_Item::
Container_Data_Item (const GAME::Mga::Model_in item)
: item_ (item)
{

}


//
// get_display_info
//
void Container_Data_Item::
get_display_info (std::string & name, std::string & value) const
{
  name = this->item_->name ();

  if (!value.empty ())
    value.clear ();
}

//
// get_item
//
GAME::Mga::FCO Container_Data_Item::get_item (void)
{
  return this->item_.get ();
}

//
// is_complex
//
bool Container_Data_Item::is_complex (void) const
{
  return true;
}
