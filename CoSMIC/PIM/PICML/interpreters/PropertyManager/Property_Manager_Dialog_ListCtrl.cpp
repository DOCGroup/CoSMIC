// $Id$

#include "stdafx.h"
#include "resource.h"
#include "Property_Manager_Dialog_ListCtrl.h"
#include "Data_Value_Controls.h"

#include "game/stlace.h"
#include "game/utils/Point.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"
#include "ace/Hash_Map_Manager.h"

#include "boost/bind.hpp"

#include <memory>
#include <sstream>
#include <algorithm>
#include <set>

#define SINGLETON_CONTROL(X) \
  ACE_Singleton <X, ACE_Null_Mutex>::instance ()

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
static bool get_complex_type (const GAME::Model & container,
                              GAME::FCO & complex)
{
  std::vector <GAME::Reference> complex_types;
  if (0 == container.children ("ComplexTypeReference", complex_types))
    return false;

  // Get the complex type.
  complex = complex_types.front ().refers_to ();
  return !complex.is_nil ();
}

//
// is_complex_type
//
static bool is_complex_type (const GAME::FCO & fco)
{
  const std::string metaname (fco.meta ().name ());
  return metaname == "Collection" || metaname == "Aggregate";
}

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
  ACE_Hash_Map_Manager <std::string,
                        PICML_Data_Value_Control *,
                        ACE_Null_Mutex> controls_;
};

#define PICML_GLOBAL_CONTROL_SELECTOR \
  ACE_Singleton <PICML_Data_Value_Control_Selector, \
                 ACE_Null_Mutex>::instance ()

///////////////////////////////////////////////////////////////////////////////
// Data_Item

/**
 * @class Data_Item
 *
 * Base class for all items in the list view. Using this base
 * abstraction will make it a LOT easier to manage the different
 * element types.
 */
class Data_Item
{
public:
  /// Destructor.
  virtual ~Data_Item (void)
  {

  }

  /**
   * Get the GAME item contained in the item.
   */
  GAME::FCO get_item (void) const
  {
    return this->item_;
  }

  virtual void get_display_info (std::string & name, std::string & value) const = 0;

  virtual void value_click_begin (CWnd * parent, int item, const CRect & rect)
  {

  }

  virtual void value_click_end (void)
  {

  }

protected:
  /// Initailizing constructor.
  Data_Item (GAME::FCO item)
    : item_ (item) { }

  /// The FCO assigned to this item.
  GAME::FCO item_;
};

/**
 * @class Data_Value_Item
 *
 * Wrapper class for the DataValue element.
 */
class Data_Value_Item : public Data_Item
{
public:
  //
  // Data_Value_Item
  //
  Data_Value_Item (GAME::FCO item)
    : Data_Item (item) { }

  //
  // get_display_info
  //
  virtual void get_display_info (std::string & name, std::string & value) const
  {
    name = this->item_.name ();
    value = this->item_.attribute ("Value").string_value ();
  }

  //
  // value_click_begin
  //
  virtual void value_click_begin (CWnd * parent, int item, const CRect & rect)
  {
    // Select the correct control based on the value's type.
    GAME::Reference data_value = GAME::Reference::_narrow (this->item_);
    GAME::FCO fco = data_value.refers_to ();

    const std::string metaname (fco.meta ().name ());

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
  virtual void value_click_end (void)
  {
    if (0 == this->control_)
      return;

    // Destroy the control.
    this->control_->Destroy ();
    this->control_ = 0;

    // Invalidate the parent window's rectangle.
  }

private:
  /// The control for editing the value.
  PICML_Data_Value_Control * control_;
};

/**
 * @class Data_Value_Item
 *
 * Wrapper class for the DataValue element.
 */
class Container_Data_Item : public Data_Item
{
public:
  Container_Data_Item (GAME::FCO item)
    : Data_Item (item) { }

  virtual void get_display_info (std::string & name, std::string & value) const
  {
    name = this->item_.name ();
    value = "";
  }
};

/**
 * @class Collection_Item
 */
class Collection_Item : public Data_Item
{
public:
  Collection_Item (GAME::FCO value, Data_Item * item, size_t index)
    : Data_Item (value),
      real_item_ (item),
      index_ (index)
  {

  }

  //
  // get_display_info
  //
  virtual void get_display_info (std::string & name, std::string & value) const
  {
    this->real_item_->get_display_info (name, value);

    std::ostringstream ostr;
    ostr << '[' << this->index_ << ']';
    name = ostr.str ();
  }

  //
  // value_click_begin
  //
  virtual void value_click_begin (CWnd * parent, int item, const CRect & rect)
  {
    if (0 != this->real_item_.get ())
      this->real_item_->value_click_begin (parent, item, rect);
  }

  //
  // value_click_end
  //
  virtual void value_click_end (void)
  {
    if (0 != this->real_item_.get ())
      this->real_item_->value_click_end ();
  }

private:
  std::auto_ptr <Data_Item> real_item_;

  size_t index_;
};

/**
 * @class New_Collection_Item
 *
 * Wrapper class for the DataValue element.
 */
class New_Collection_Item : public Data_Item
{
public:
  New_Collection_Item (GAME::FCO value,
                       GAME::FCO type,
                       int indent,
                       size_t next_index,
                       const GAME::utils::Point & last_location)
    : Data_Item (value),
      type_ (type),
      indent_ (indent),
      next_index_ (next_index),
      last_location_ (last_location)
  {

  }

  //
  // get_display_info
  //
  virtual void get_display_info (std::string & name, std::string & value) const
  {
    if (!name.empty ())
      name.clear ();

    value = "Click here to insert new item...";
  }

  //
  // value_click_begin
  //
  virtual void value_click_begin (CWnd * parent, int item, const CRect & rect)
  {
    // The user wants to insert a new item into a sequence. We
    // need to find the parent of this item. This will be the
    // item that's one indentation less than the current one.
    GAME::FCO value_base;
    GAME::Model parent_container = GAME::Model::_narrow (this->item_);
    bool is_complex_type = ::is_complex_type (this->type_);

    if (is_complex_type)
    {
      using GAME::Model;
      using GAME::Reference;

      // We need to create a DataValueContainer element.
      Model container = Model::_create (parent_container, "DataValueContainer");
      Reference ctr = Reference::_create (container, "ComplexTypeReference");
      ctr.refers_to (this->type_);

      // Save the container.
      value_base = container;
    }
    else
    {
      // We are create space for a predefined type, or an enumeration.
      GAME::Reference data_value = GAME::Reference::_create (parent_container, "DataValue");
      data_value.refers_to (this->type_);

      value_base = data_value;
    }

    // Increase the y-value for the last location to represent the
    // new created item.
    this->last_location_.shift (0, 100);
    GAME::utils::position ("DataValueAspect", this->last_location_, value_base);

    // Add a new element to the collection to the DataValueContainer.
    std::auto_ptr <Data_Item> data_item;

    if (is_complex_type)
      data_item.reset (new Container_Data_Item (value_base));
    else
      data_item.reset (new Data_Value_Item (value_base));

    std::auto_ptr <Data_Item> ci (
      new Collection_Item (value_base,
                           data_item.release (),
                           this->next_index_ ++));

    LVITEM lvitem;
    ZeroMemory (&lvitem, sizeof (LVITEM));

    lvitem.mask     = LVIF_IMAGE | LVIF_INDENT | LVIF_PARAM;
    lvitem.iItem    = item;
    lvitem.iIndent  = this->indent_;
    lvitem.iImage   = is_complex_type ? 1 : 0;
    lvitem.lParam   = reinterpret_cast <LPARAM> (ci.get ());

    CListCtrl * list_control = dynamic_cast <CListCtrl *> (parent);

    if (list_control->InsertItem (&lvitem) == -1)
      ::AfxMessageBox ("Failed to insert new item");
    else
      ci.release ();
  }

private:
  GAME::FCO type_;

  int indent_;

  size_t next_index_;

  GAME::utils::Point last_location_;
};

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListView_Expand

class PICML_Property_Manager_ListView_Expand
{
public:
  PICML_Property_Manager_ListView_Expand (CListCtrl & parent, int index, int indent)
    : parent_ (parent)
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

    this->is_collection_ =
      !complex_type.is_nil () &&
       complex_type.meta () == "Collection";

    if (this->is_collection_)
    {
      this->index_counter_ = 0;
      this->last_location_.set (100, 0);
    }

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
    if (this->is_collection_)
    {
      GAME::Reference coll = GAME::Reference::_narrow (complex_type);
      this->insert_collection_footer (model, coll.refers_to ());
    }
  }

  //
  // insert_collection_footer
  //
  void insert_collection_footer (const GAME::Model & coll, const GAME::FCO & type)
  {
    // Insert the blank item into the listing. This will be used
    // to determine when the sequence is clicked.
    Data_Item * item = new New_Collection_Item (coll,
                                                type,
                                                this->item_.iIndent,
                                                this->item_.iItem,
                                                this->last_location_);

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

    Data_Item * item;

    if (metaname == "DataValue")
      item = new Data_Value_Item (value);
    else
      item = new Container_Data_Item (value);

    if (this->is_collection_)
    {
      item = new Collection_Item (item->get_item (),
                                  item,
                                  this->index_counter_ ++);

      GAME::utils::position ("DataValueAspect",
                             value,
                             this->last_location_);
    }

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

  bool is_collection_;

  size_t index_counter_;

  GAME::utils::Point last_location_;
};

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListCtrl

BEGIN_MESSAGE_MAP (PICML_Property_Manager_ListCtrl, CListCtrl)
  //ON_WM_CONTEXTMENU ()
  //ON_WM_INITMENUPOPUP ()
  ON_WM_HSCROLL ()
  ON_WM_LBUTTONDOWN ()
  ON_WM_VSCROLL ()

  //ON_COMMAND (ID_IDR_DELETEITEM, OnCommand_DeleteItem)
  //ON_COMMAND (ID_IDR_MOVEUP, OnCommand_MoveUp)
  //ON_COMMAND (ID_IDR_MOVEDOWN, OnCommand_MoveDown)
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

  // Determine what item in the list was selected. Also, we only
  // care about the 'value' column being clicked.
  //if (this->SubItemHitTest (&info) != -1 && info.iSubItem == 1)
  //{
  //  LVITEM lvitem;
  //  lvitem.mask     = LVIF_INDENT | LVIF_PARAM;
  //  lvitem.iItem    = info.iItem;
  //  lvitem.iSubItem = 0;

  //  // Get the information about the selected item.
  //  this->GetItem (&lvitem);
  //  int indent = lvitem.iIndent;

  //  // Extract the target value.
  //  Udm::ObjectImpl * impl = reinterpret_cast <Udm::ObjectImpl *> (lvitem.lParam);
  //  PICML::DataValueBase value_base (impl);

  //  // Determine if the value belongs to a sequence. This means
  //  // locating is parent, if it has one.
  //  do
  //  {
  //    -- lvitem.iItem;
  //  } while (this->GetItem (&lvitem) != 0 && lvitem.iIndent >= indent);

  //  // Get the data value from the item.
  //  PICML_Data_Value * value = reinterpret_cast <PICML_Data_Value *> (lvitem.lParam);

  //  if (typeid (*value) == typeid (PICML_Sequence_Data_Value))
  //  {
  //    // Convert the value into a sequence value.
  //    this->sequence_ =
  //      dynamic_cast <PICML_Sequence_Data_Value *> (value);

  //    // Save the item and index of the value to delete.
  //    this->parent_item_  = lvitem.iItem;
  //    this->target_item_  = info.iItem;

  //    // Load the main menu from the resources.
  //    CMenu menu;
  //    menu.LoadMenu (IDR_LISTCTRL_CTX);

  //    // Get the first submenu, which is our context menu.
  //    CMenu * popup = menu.GetSubMenu (0);

  //    if (popup != 0)
  //    {
  //      // Create it as a popup menu.
  //      popup->TrackPopupMenu (TPM_LEFTALIGN | TPM_LEFTBUTTON,
  //                             point.x,
  //                             point.y,
  //                             this);

  //      // We are going to return from here since we do not
  //      // need to perform any of the default operation(s).
  //      return;
  //    }
  //    else
  //    {
  //      ::AfxMessageBox ("Failed to create popup menu", MB_OK | MB_ICONEXCLAMATION);
  //    }
  //  }
  //}

  // Perform the default operation(s).
  CListCtrl::OnContextMenu (parent, point);
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
    Data_Item * data_item = reinterpret_cast <Data_Item *> (lvitem.lParam);
    GAME::FCO fco = data_item->get_item ();

    // Insert the child items into the control.
    GAME::Model container = GAME::Model::_narrow (data_item->get_item ());
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
  //if (index == 0 && this->sequence_ != 0)
  //{
  //  // Get the size of the sequence.
  //  size_t size = this->sequence_->size ();

  //  // Get the index of the target value in the sequence.
  //  size_t index;
  //  bool found = this->sequence_->get_index (this->target_value_, index);

  //  // Enable/disable the "Delete item..." command.
  //  UINT flags = MF_BYCOMMAND | (found ? MF_ENABLED : MF_GRAYED);
  //  popup->EnableMenuItem (ID_IDR_DELETEITEM, flags);

  //  // Enable/disable the "Move up" command.
  //  flags = MF_BYCOMMAND | (index != 0 ? MF_ENABLED : MF_GRAYED);
  //  popup->EnableMenuItem (ID_IDR_MOVEUP, flags);

  //  // Enable/disable the "Move down" command.
  //  flags = MF_BYCOMMAND | (index < size - 1 ? MF_ENABLED : MF_GRAYED);
  //  popup->EnableMenuItem (ID_IDR_MOVEDOWN, flags);
  //}
}

//
// OnCommand_MoveUp
//
void PICML_Property_Manager_ListCtrl::OnCommand_MoveUp (void)
{
  //// Move the value down in the sequence.
  //this->sequence_->move_up (this->target_value_);

  //// Find the next item in the control.
  //int prev_item = this->find_prev_item (this->target_item_);

  //// Swap the item's data in the control.
  //this->swap_item_data (this->target_item_, prev_item);

  //// Collapse and update the target.
  //this->collapse_item (this->target_item_);
  //this->Update (this->target_item_);

  //// Collapse and update the previous item.
  //this->collapse_item (prev_item);
  //this->Update (prev_item);

  //// Update the parent item.
  //this->Update (this->parent_item_);
}

//
// OnCommand_MoveDown
//
void PICML_Property_Manager_ListCtrl::OnCommand_MoveDown (void)
{
  //// Move the value down in the sequence.
  //this->sequence_->move_down (this->target_value_);

  //// Find the next item in the control.
  //int next_item = this->find_next_item (this->target_item_);

  //// Swap the item's data.
  //this->swap_item_data (this->target_item_, next_item);

  //// Collapse and update the next item.
  //this->collapse_item (next_item);
  //this->Update (next_item);

  //// Collapse and update the target item.
  //this->collapse_item (this->target_item_);
  //this->Update (this->target_item_);

  //// Update the parent item.
  //this->Update (this->parent_item_);
}

//
// OnCommand_DeleteItem
//
void PICML_Property_Manager_ListCtrl::OnCommand_DeleteItem (void)
{
  //// Collapse the item, if necessary, then delete it.
  //this->collapse_item (this->target_item_);
  //this->DeleteItem (this->target_item_);

  //// Delete the item from the sequence.
  //this->sequence_->remove (this->target_value_);

  //// Get the size of the sequence.
  //size_t size = this->sequence_->size ();

  //// Generate the "click here to insert new item" name.
  //std::ostrstream ostr;
  //ostr << "[" << size << "]" << std::ends;

  //// Update the "click here to insert new item" name and value.
  //int dummy = this->target_item_ + (size - this->target_index_);
  //this->SetItemText (dummy, 0, ostr.str ());

  //// Release our target sequence.
  //this->sequence_ = 0;

  //// Update the parent.
  //this->Update (this->parent_item_);
}

//
// find_prev_item
//
int PICML_Property_Manager_ListCtrl::find_prev_item (int item)
{
  return this->find_item_i (item, -1);
}

//
// find_next_item
//
int PICML_Property_Manager_ListCtrl::find_next_item (int item)
{
  return this->find_item_i (item, 1);
}

//
// find_next_item
//
int PICML_Property_Manager_ListCtrl::find_item_i (int item, int step)
{
  return -1;

  //LVITEM lvitem;
  //lvitem.mask     = LVIF_INDENT;
  //lvitem.iItem    = item;
  //lvitem.iSubItem = 0;

  //if (this->GetItem (&lvitem) == 0)
  //  return -1;

  //// Save the current indentation value. We need to find another
  //// item w/ the same indentation.
  //int indent = lvitem.iIndent;
  //int retval = 0;

  //do
  //{
  //  // Get the next item as long as it's indentation is greater
  //  // than the start item. This means that we are still one
  //  // looking at child items of parent we are searching for.
  //  lvitem.iItem += step;
  //  retval = this->GetItem (&lvitem);
  //} while (retval != 0 && lvitem.iIndent > indent);

  //return retval != 0 ? lvitem.iItem : -1;
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
  //DWORD_PTR temp = this->GetItemData (i);
  //this->SetItemData (i, this->GetItemData (j));
  //this->SetItemData (j, temp);
}
