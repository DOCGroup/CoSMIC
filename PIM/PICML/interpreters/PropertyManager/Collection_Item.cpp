#include "StdAfx.h"

#include "Collection_Item.h"
#include "Collection_Container_Data_Item.h"

#include "resource.h"

#include <sstream>
#include "game/mga/utils/Point.h"

//
// Collection_Item
//
Collection_Item::
Collection_Item (Collection_Container_Data_Item * parent,
                 Data_Value_Item_Base * item,
                 size_t index)
: parent_ (parent),
  real_item_ (item),
  index_ (index)
{

}

//
// ~Collection_Item
//
Collection_Item::~Collection_Item (void)
{
  if (0 != this->real_item_)
    delete this->real_item_;
}

//
// get_display_info
//
void Collection_Item::
get_display_info (std::string & name, std::string & value) const
{
  if (0 != this->real_item_)
    this->real_item_->get_display_info (name, value);

  std::ostringstream ostr;
  ostr << '[' << this->index_ << ']';
  name = ostr.str ();
}

//
// get_item
//
GAME::Mga::FCO Collection_Item::get_item (void)
{
  return this->real_item_->get_item ();
}

//
// value_click_begin
//
void Collection_Item::
value_click_begin (CWnd * parent, int item, const CRect & rect)
{
  if (0 != this->real_item_)
    this->real_item_->value_click_begin (parent, item, rect);
}

//
// value_click_end
//
void Collection_Item::value_click_end (void)
{
  if (0 != this->real_item_)
    this->real_item_->value_click_end ();
}

//
// get_context_menu
//
int Collection_Item::get_context_menu (void) const
{
  return IDR_LISTCTRL_CTX;
}

//
// init_menu_popup
//
void Collection_Item::init_menu_popup (CMenu * popup) const
{
  // Enable/disable the "Move up" command.
  UINT flags = MF_BYCOMMAND | (this->index_ != 0 ? MF_ENABLED : MF_GRAYED);
  popup->EnableMenuItem (ID_IDR_MOVEUP, flags);

  // Enable/disable the "Move down" command.
  const size_t size = this->parent_->get_size ();
  flags = MF_BYCOMMAND | (this->index_ < size - 1 ? MF_ENABLED : MF_GRAYED);
  popup->EnableMenuItem (ID_IDR_MOVEDOWN, flags);
}

//
// swap
//
void Collection_Item::swap (Collection_Item * lhs, Collection_Item * rhs)
{
  // Swap the actual item values.
  std::swap (lhs->real_item_, rhs->real_item_);

  // Swap the position of the items.
  GAME::Mga::Point pt_lhs, pt_rhs;
  GAME::Mga::position ("DataValueAspect", lhs->real_item_->get_item (), pt_lhs);
  GAME::Mga::position ("DataValueAspect", rhs->real_item_->get_item (), pt_rhs);

  GAME::Mga::position ("DataValueAspect", pt_lhs, rhs->real_item_->get_item ());
  GAME::Mga::position ("DataValueAspect", pt_rhs, lhs->real_item_->get_item ());
}

//
// get_index
//
size_t Collection_Item::get_index (void) const
{
  return this->index_;
}

//
// set_index
//
void Collection_Item::set_index (size_t i)
{
  this->index_ = i;
}

//
// is_complex
//
bool Collection_Item::is_complex (void) const
{
  return this->real_item_->is_complex ();
}

//
// parent
//
Collection_Container_Data_Item * Collection_Item::parent (void)
{
  return this->parent_;
}
