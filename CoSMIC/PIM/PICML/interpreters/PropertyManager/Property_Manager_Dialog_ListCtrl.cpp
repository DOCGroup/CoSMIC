// $Id$

#include "stdafx.h"
#include "resource.h"
#include "Property_Manager_Dialog_ListCtrl.h"

#include "Data_Value_Controls.h"
#include "Collection_Item.h"
#include "Collection_Container_Data_Item.h"
#include "New_Collection_Item.h"
#include "Data_Value_Item.h"

#include "game/utils/Point.h"
#include "boost/bind.hpp"

#include <memory>
#include <algorithm>
#include <set>

/**
 * @struct top_to_bottom_t
 *
 * Functor for sorting elements in a property from top to bottom.
 */
struct top_to_bottom_t
{
  template <typename T>
  bool operator () (const T & lhs, const T & rhs) const
  {
    GAME::utils::Point pt_lhs, pt_rhs;

    GAME::utils::position ("DataValueAspect", lhs, pt_lhs);
    GAME::utils::position ("DataValueAspect", rhs, pt_rhs);

    return pt_lhs.y_value () < pt_rhs.y_value ();
  }
};

//
// get_complex_type
//
static bool
get_complex_type (const GAME::Model & container, GAME::FCO & complex)
{
  std::vector <GAME::Reference> complex_types;
  if (0 == container.children ("ComplexTypeReference", complex_types))
    return false;

  // Get the complex type.
  complex = complex_types.front ().refers_to ();
  return !complex.is_nil ();
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListView_Expand

class PICML_Property_Manager_ListView_Expand
{
public:
  PICML_Property_Manager_ListView_Expand (CListCtrl & parent, int index, int indent)
    : parent_ (parent),
      collection_ (0),
      index_counter_ (0)
  {
    ZeroMemory (&this->item_, sizeof (LVITEM));
    this->item_.iItem   = index;
    this->item_.iIndent = indent;
  }

  virtual ~PICML_Property_Manager_ListView_Expand (void)
  {

  }

  virtual void Visit_Property (const GAME::Model & prop)
  {
    this->visit_property_datavalue_container (prop);
  }

  virtual void Visit_DataValueContainer (const GAME::Model & c)
  {
    this->visit_property_datavalue_container (c);
  }

private:
  //
  // visit_property_datavalue_container
  //
  void visit_property_datavalue_container (const GAME::Model & model)
  {
    // We are going to make the assumption the elements contained
    // in the property are correct. This means that simple types
    // contain only a single DataValueBase element and complex types
    // contain [1..n] DataValueBase elements.
    GAME::FCO complex_type;
    ::get_complex_type (model, complex_type);

    if (!complex_type.is_nil () && complex_type.meta () == "Collection")
      this->collection_ = new Collection_Container_Data_Item (model);

    std::vector <GAME::FCO> data_values, data_value_containers;
    model.children ("DataValue", data_values);
    model.children ("DataValueContainer", data_value_containers);

    std::set <GAME::FCO, top_to_bottom_t> sorted_values;

    std::for_each (data_values.begin (),
                   data_values.end (),
                   boost::bind (&std::set <GAME::FCO, top_to_bottom_t>::insert,
                                boost::ref (sorted_values),
                                _1));

    std::for_each (data_value_containers.begin (),
                   data_value_containers.end (),
                   boost::bind (&std::set <GAME::FCO, top_to_bottom_t>::insert,
                                boost::ref (sorted_values),
                                _1));

    std::for_each (sorted_values.begin (),
                   sorted_values.end (),
                   boost::bind (&PICML_Property_Manager_ListView_Expand::Visit_DataValueBase,
                                this,
                                _1));

    // We need to add a "blank" element to the end of the list
    // if this is a collection (i.e., a sequence). This will allow
    // the user to add new elements to the sequence.
    if (0 != this->collection_)
    {
      GAME::Reference collection = GAME::Reference::_narrow (complex_type);
      this->insert_collection_footer (collection.refers_to ());
    }
  }

  //
  // insert_collection_footer
  //
  void insert_collection_footer (const GAME::FCO & type)
  {
    // Insert the blank item into the listing. This will be used
    // to determine when the sequence is clicked.
    New_Collection_Item * item =
      new New_Collection_Item (this->collection_,
                               type,
                               this->item_.iIndent);

    this->item_.mask     = LVIF_INDENT | LVIF_IMAGE | LVIF_PARAM;
    this->item_.iImage   = 0;
    this->item_.iSubItem = 0;
    this->item_.lParam   = reinterpret_cast <LPARAM> (item);

    this->parent_.InsertItem (&this->item_);
  }

  //
  // Visit_DataValueBase
  //
  void Visit_DataValueBase (const GAME::FCO & value)
  {
    std::string metaname (value.meta ().name ());
    const bool expand = (metaname == "DataValueContainer");

    Data_Value_Item_Base * item = 0;

    if (this->collection_ == 0)
    {
      if (metaname == "DataValue")
      {
        item = new Data_Value_Item (value);
      }
      else
      {
        // Get the container's complex type. This will determine if
        // we are to create a standard container, or a collection
        // container for this item.
        GAME::Model container = GAME::Model::_narrow (value);

        GAME::FCO complex;
        if (!::get_complex_type (container, complex))
          return;

        metaname = complex.meta ().name ();

        if (metaname == "Collection")
          item = new Collection_Container_Data_Item (container);
        else
          item = new Container_Data_Item (container);
      }
    }
    else
      item = this->collection_->new_item (value);


    // Initialize the item's properties.
    this->item_.mask     = LVIF_PARAM | LVIF_INDENT | LVIF_IMAGE;
    this->item_.lParam   = reinterpret_cast <LPARAM> (item);
    this->item_.iImage   = expand ? 1 : 0;
    this->item_.iSubItem = 0;

    if (this->parent_.InsertItem (&this->item_) == -1)
      return;

    // Move to the next item in the list.
    ++ this->item_.iItem;
  }

  /// Parent control of the item.
  CListCtrl & parent_;

  /// Item structure for the visitor.
  LVITEM item_;

  Collection_Container_Data_Item * collection_;

  size_t index_counter_;
};

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListCtrl

BEGIN_MESSAGE_MAP (PICML_Property_Manager_ListCtrl, CListCtrl)
  ON_WM_CONTEXTMENU ()
  ON_WM_INITMENUPOPUP ()
  ON_WM_HSCROLL ()
  ON_WM_LBUTTONDOWN ()
  ON_WM_VSCROLL ()

  ON_COMMAND (ID_IDR_DELETEITEM, OnCommand_DeleteItem)
  ON_COMMAND (ID_IDR_MOVEUP, OnCommand_MoveUp)
  ON_COMMAND (ID_IDR_MOVEDOWN, OnCommand_MoveDown)
END_MESSAGE_MAP ()

//
// PICML_Property_Manager_ListCtrl
//
PICML_Property_Manager_ListCtrl::PICML_Property_Manager_ListCtrl (void)
: active_item_ (0)
{

}

//
// ~PICML_Property_Manager_ListCtrl
//
PICML_Property_Manager_ListCtrl::~PICML_Property_Manager_ListCtrl (void)
{
}

//
// InitControl
//
BOOL PICML_Property_Manager_ListCtrl::InitControl (void)
{
#define MEMBER_COLUMN_WIDTH 75

  CRect rc;
  this->GetClientRect (rc);

  // Setup the columns for the list view report style.
  if (this->InsertColumn (0, "Name", LVCFMT_LEFT, MEMBER_COLUMN_WIDTH) < 0)
    return FALSE;

  if (this->InsertColumn (1, "Value", LVCFMT_LEFT, rc.Width () - MEMBER_COLUMN_WIDTH) < 0)
    return FALSE;

  // Create the image list for the items.
  CImageList * image_list = new CImageList ();
  std::auto_ptr <CImageList> auto_clean (image_list);

  image_list->Create (::GetSystemMetrics (SM_CXSMICON),
                      ::GetSystemMetrics (SM_CXSMICON),
                      ILC_COLOR32 | ILC_MASK,
                      0,
                      3);

  image_list->SetBkColor (CLR_NONE);

  // Insert the images into the image list.
  int icons [3] = {IDI_BLANK, IDI_EXPAND, IDI_COLLAPSE};

  for (size_t i = 0; i < 3; i ++)
    image_list->Add (::AfxGetApp ()->LoadIcon (icons[i]));

  // Install the image list. Since we are only showing in report
  // view, we only need to worry about the small images.
  this->SetImageList (image_list, LVSIL_SMALL);
  auto_clean.release ();

  return TRUE;
}

//
// SetProperty
//
void PICML_Property_Manager_ListCtrl::SetProperty (const GAME::Model & prop)
{
  // Initialize the control based on the property.
  PICML_Property_Manager_ListView_Expand expander (*this, 0, 0);
  expander.Visit_Property (prop);

  this->prop_ = prop;
}

//
// DrawItem
//
void PICML_Property_Manager_ListCtrl::DrawItem (LPDRAWITEMSTRUCT item)
{
  int image = 0;
  std::string name, value;

  // Get the display information for the item.
  Data_Item * data_item = reinterpret_cast <Data_Item *> (item->itemData);
  data_item->get_display_info (name, value);

  // Get the image index for the item.
  LVITEM lvitem;
  ZeroMemory (&lvitem, sizeof (LVITEM));

  lvitem.mask     = LVIF_IMAGE;
  lvitem.iItem    = item->itemID;
  lvitem.iSubItem = 0;

  if (this->GetItem (&lvitem) != 0)
    image = lvitem.iImage;

  // Get the dimension of each item in the column. This will
  // be the image, name, and value dimensions.
  CRect rect_image, rect_name, rect_value;
  this->GetItemRect (item->itemID, rect_image, LVIR_ICON);
  this->GetItemRect (item->itemID, rect_name, LVIR_LABEL);

  this->GetSubItemRect (item->itemID, 1, LVIR_BOUNDS, rect_value);
  rect_value.left += 4;

  // Attach to the provided device context.
  CDC device;
  device.Attach (item->hDC);

  device.FillSolidRect (&item->rcItem, RGB (255, 255, 255));

  // Select the pen for outlining the items.
  CPen grey_pen (PS_SOLID, 1, RGB (230, 230, 230));
  CPen * old_pen = device.SelectObject (&grey_pen);

  // Draw a line at the bottom of the rectangle.
  int vert_y = item->rcItem.bottom - 1;
  device.MoveTo (item->rcItem.left, vert_y);
  device.LineTo (item->rcItem.right, vert_y);

  // Draw a line between the name and value.
  int horiz_x = rect_name.right - 1;

  device.MoveTo (horiz_x, item->rcItem.top);
  device.LineTo (horiz_x, vert_y);

  // Restore the original pen.
  device.SelectObject (old_pen);

  // Make sure we don't draw on our horizontal line.
  -- rect_image.bottom;

  // Draw the image for the list view item.
  this->GetImageList (LVSIL_SMALL)->DrawEx (&device,
                                            image,
                                            rect_image.TopLeft (),
                                            rect_image.Size (),
                                            CLR_DEFAULT,
                                            CLR_DEFAULT,
                                            ILD_NORMAL);

  static const UINT format =
    DT_LEFT | DT_END_ELLIPSIS | DT_VCENTER | DT_SINGLELINE;

  // TODO Convert graphics code to Gdiplus.

  // Draw the name of the value to the device.
  if (!name.empty ())
    device.DrawText (name.c_str (),
                     name.length (),
                     rect_name,
                     format);

    // Draw the actual value to the device.
  if (!value.empty ())
    device.DrawText (value.c_str (),
                     value.length (),
                     rect_value,
                     format);

  // Release device context since it was temporary ownership.
  device.Detach ();
}


//
// OnLButtonDblClk
//
void PICML_Property_Manager_ListCtrl::
OnContextMenu (CWnd * parent, CPoint point)
{
  // We need to cleanup the current edit control if we are receiving
  // this message because the user has clicked somewhere else on
  // the listview control (i.e., outside the edit control).
  this->end_label_edit ();

  // Convert the screen coordinates to client coordinates.
  CPoint pt (point);
  this->ScreenToClient (&pt);

  // Prepare the hit test structure using the client coordinates.
  LVHITTESTINFO info;
  info.pt.x = pt.x;
  info.pt.y = pt.y;

   //Determine what item in the list was selected. Also, we only
   //care about the 'value' column being clicked.
  if (this->SubItemHitTest (&info) == -1 || info.iSubItem != 1)
    return;

  LVITEM lvitem;
  lvitem.mask     = LVIF_INDENT | LVIF_PARAM;
  lvitem.iItem    = info.iItem;
  lvitem.iSubItem = 0;

  // Get the information about the selected item.
  this->GetItem (&lvitem);

  this->active_item_ = reinterpret_cast <Data_Item *> (lvitem.lParam);
  int menu_resource = this->active_item_->get_context_menu ();

  if (-1 != menu_resource)
  {
    // Load the main menu from the resources.
    CMenu menu;
    menu.LoadMenu (menu_resource);

    // Get the first submenu, which is our context menu.
    CMenu * popup = menu.GetSubMenu (0);

    if (popup != 0)
      popup->TrackPopupMenu (TPM_LEFTALIGN | TPM_LEFTBUTTON,
                             point.x,
                             point.y,
                             this);
  }
  else
    this->active_item_ = 0;
}

//
// OnLButtonDown
//
void PICML_Property_Manager_ListCtrl::OnLButtonDown (UINT flags, CPoint point)
{
  // Pass control to the base class first.
  CListCtrl::OnLButtonDown (flags, point);

  // We need to cleanup the current edit control if we are receiving
  // this message because the user has clicked somewhere else on
  // the listview control (i.e., outside the edit control).
  this->end_label_edit ();

  // Setup a hit test for the point.
  LVHITTESTINFO info;
  info.pt.x = point.x;
  info.pt.y = point.y;

  // Determine what item in the list was selected.
  if (this->SubItemHitTest (&info) == -1)
    return;

  switch (info.iSubItem)
  {
  case 0:
    this->handle_name_click (info);
    break;

  case 1:
    this->handle_value_click (info);
    break;
  }
}

//
// OnVScroll
//
void PICML_Property_Manager_ListCtrl::
OnVScroll(UINT code, UINT pos, CScrollBar* scrollbar)
{
  CListCtrl::OnVScroll (code, pos, scrollbar);
  this->end_label_edit ();
}

//
// OnHScroll
//
void PICML_Property_Manager_ListCtrl::
OnHScroll(UINT code, UINT pos, CScrollBar* scrollbar)
{
  CListCtrl::OnHScroll (code, pos, scrollbar);
  this->end_label_edit ();
}

//
// handle_name_click
//
void PICML_Property_Manager_ListCtrl::
handle_name_click (const LVHITTESTINFO & testinfo)
{
  // We are only interest in clicks on the icon.
  if ((testinfo.flags & LVHT_ONITEMICON) == 0)
    return;

  // Get the appropriate information needed to toggle the
  // child items for this item, if applicable.
  LVITEM lvitem;
  lvitem.mask     = LVIF_IMAGE | LVIF_PARAM | LVIF_INDENT;
  lvitem.iItem    = testinfo.iItem;
  lvitem.iSubItem = 0;

  if (this->GetItem (&lvitem) == 0)
    return;

  if (lvitem.iImage == 1)
  {
    // Get the data value from the parameter.
    Data_Value_Item_Base * dvib = reinterpret_cast <Data_Value_Item_Base *> (lvitem.lParam);
    GAME::FCO fco = dvib->get_item ();

    // Insert the child items into the control.
    GAME::Model container = GAME::Model::_narrow (fco);
    PICML_Property_Manager_ListView_Expand builder (*this, lvitem.iItem + 1, lvitem.iIndent + 1);
    builder.Visit_DataValueContainer (container);

    // Set to collapse image since we have expanded list.
    lvitem.iImage = 2;
    this->SetItem (&lvitem);
  }
  else if (lvitem.iImage == 2)
  {
    this->collapse_item (lvitem.iItem);
  }
}

//
// handle_value_click
//
void PICML_Property_Manager_ListCtrl::
handle_value_click (const LVHITTESTINFO & testinfo)
{
  // Get the data for the item.
  LVITEM lvitem;
  lvitem.mask     = LVIF_PARAM | LVIF_INDENT;
  lvitem.iItem    = testinfo.iItem;
  lvitem.iSubItem = 0;

  if (this->GetItem (&lvitem) == 0)
    return;

  // Get the dimensions of the subitem.
  CRect subitem_rect;
  this->GetSubItemRect (testinfo.iItem,
                        testinfo.iSubItem,
                        LVIR_BOUNDS,
                        subitem_rect);

  // Shrink the height of the control so we do not draw it
  // over the horizontal borders.
  -- subitem_rect.bottom;

  // Pass control to the data item.
  this->active_item_ = reinterpret_cast <Data_Item *> (lvitem.lParam);
  this->active_item_->value_click_begin (this, testinfo.iItem, subitem_rect);
}

//
// end_label_edit
//
void PICML_Property_Manager_ListCtrl::end_label_edit (void)
{
  if (0 == this->active_item_)
    return;

  // Destroy the window, but not the actual class since there
  // is chance we will be using the class later one.
  this->active_item_->value_click_end ();
  this->active_item_ = 0;

  // Invalidate this control.
  this->InvalidateRect (0);
}

//
// OnInitMenuPopup
//
void PICML_Property_Manager_ListCtrl::
OnInitMenuPopup (CMenu * popup, UINT index, BOOL sysmenu)
{
  if (0 == this->active_item_)
    return;

  // Reset the active item.
  this->active_item_->init_menu_popup (popup);
}

//
// OnCommand_MoveUp
//
void PICML_Property_Manager_ListCtrl::OnCommand_MoveUp (void)
{
  if (0 == this->active_item_)
    return;

  // Locate the item in the list control that has the
  // specified parameter.
  LVFINDINFO find_info;
  find_info.flags  = LVFI_PARAM;
  find_info.lParam = reinterpret_cast <LPARAM> (this->active_item_);

  int index = this->FindItem (&find_info);

  if (index != -1)
    this->swap_item_data (index, index - 1);

  this->active_item_ = 0;
}

//
// OnCommand_MoveDown
//
void PICML_Property_Manager_ListCtrl::OnCommand_MoveDown (void)
{
  if (0 == this->active_item_)
    return;

  // Locate the item in the list control that has the
  // specified parameter.
  LVFINDINFO find_info;
  find_info.flags  = LVFI_PARAM;
  find_info.lParam = reinterpret_cast <LPARAM> (this->active_item_);

  int index = this->FindItem (&find_info);

  if (index != -1)
    this->swap_item_data (index, index + 1);

  this->active_item_ = 0;
}

//
// OnCommand_DeleteItem
//
void PICML_Property_Manager_ListCtrl::OnCommand_DeleteItem (void)
{
  if (0 == this->active_item_)
    return;

  // Locate the item in the list control that has the
  // specified parameter.
  LVFINDINFO find_info;
  find_info.flags  = LVFI_PARAM;
  find_info.lParam = reinterpret_cast <LPARAM> (this->active_item_);

  int index = this->FindItem (&find_info);

  if (index == -1)
    return;

  // We know this is a collection item, so let's get it.
  Collection_Item * ci = dynamic_cast <Collection_Item *> (this->active_item_);
  Collection_Container_Data_Item * container = ci->parent ();

  if (container->delete_item (ci))
    this->DeleteItem (index);
}

//
// collapse_item
//
void PICML_Property_Manager_ListCtrl::collapse_item (int item)
{
  // Update the image of the item.
  this->lvitem_.mask     = LVIF_IMAGE;
  this->lvitem_.iItem    = item;
  this->lvitem_.iSubItem = 0;
  this->lvitem_.iImage   = 1;
  this->SetItem (&this->lvitem_);

  // Get the current indentation value of the item.
  this->lvitem_.mask = LVIF_INDENT | LVIF_PARAM;

  if (this->GetItem (&this->lvitem_) == 0)
    return;

  // Save the parent item's indentation value.
  int indent = this->lvitem_.iIndent;

  // Move the next item. From this point forward, we do not
  // have to change this value.
  ++ this->lvitem_.iItem;

  // Delete all the items with a greater indentation value. This
  // will make sure we remove all items within this scope.
  while (this->GetItem (&this->lvitem_) != 0 && this->lvitem_.iIndent > indent)
  {
    // Delete the item's data.
    Data_Item * di = reinterpret_cast <Data_Item *> (this->lvitem_.lParam);

    if (0 != di)
      delete di;

    // Delete the actual item.
    this->DeleteItem (this->lvitem_.iItem);
  }
}

//
// swap_data_value
//
void PICML_Property_Manager_ListCtrl::swap_item_data (int i, int j)
{
  // Get the collection items.
  Collection_Item
    * ci_lower = reinterpret_cast <Collection_Item *> (this->GetItemData (i)),
    * ci_upper = reinterpret_cast <Collection_Item *> (this->GetItemData (j));

  // Swap the collection items.
  Collection_Item::swap (ci_lower, ci_upper);

  this->Update (i);
  this->Update (j);
}
