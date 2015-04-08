#include "StdAfx.h"
#include "New_Collection_Item.h"
#include "Collection_Container_Data_Item.h"
#include "Collection_Item.h"

//
// New_Collection_Item
//
New_Collection_Item::
New_Collection_Item (Collection_Container_Data_Item * parent,
                     GAME::Mga::FCO_in type,
                     int indent)
: parent_ (parent),
  type_ (type),
  indent_ (indent)
{

}

//
// get_display_info
//
void New_Collection_Item::
get_display_info (std::string & name, std::string & value) const
{
  if (!name.empty ())
    name.clear ();

  value = "Click here to insert new item...";
}

  //
  // value_click_begin
  //
void New_Collection_Item::
value_click_begin (CWnd * parent, int item, const CRect & rect)
{
  // The user wants to insert a new item into a sequence. We
  // need to find the parent of this item. This will be the
  // item that's one indentation less than the current one.
  std::auto_ptr <Collection_Item> ci (this->parent_->new_item ());

  // Insert the new items into the control.
  LVITEM lvitem;
  ZeroMemory (&lvitem, sizeof (LVITEM));

  lvitem.mask     = LVIF_IMAGE | LVIF_INDENT | LVIF_PARAM;
  lvitem.iItem    = item;
  lvitem.iIndent  = this->indent_;
  lvitem.iImage   = ci->is_complex () ? 1 : 0;
  lvitem.lParam   = reinterpret_cast <LPARAM> (ci.get ());

  CListCtrl * list_control = dynamic_cast <CListCtrl *> (parent);

  if (list_control->InsertItem (&lvitem) != -1)
    ci.release ();
  else
    ::AfxMessageBox ("Failed to insert new item");
}
