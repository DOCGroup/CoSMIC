// $Id$

#include "stdafx.h"
#include "resource.h"
#include "Property_Manager_Dialog.h"
#include "Data_Value_Controls.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include "boost/bind.hpp"
#include "Utils/UDM/Position_Sort_T.h"

#include <memory>
#include <strstream>
#include <algorithm>

#define SELECT_DATA_VALUE_CONTROL(control, type) \
  control = ACE_Singleton <type, ACE_Null_Mutex>::instance ()

#define PICML_DATA_TYPE_DISPATCHER \
  ACE_Singleton <PICML_Data_Type_Dispatcher, ACE_Null_Mutex>::instance ()

/**
 * @class DataValueBase_Dispatcher
 */
class DataValueBase_Dispatcher :
  public UDM_Abstract_Type_Dispatcher_T <PICML::Visitor>
{
public:
  DataValueBase_Dispatcher (void)
  {
    this->insert <PICML::DataValue> ();
    this->insert <PICML::DataValueContainer> ();
  }
};


/**
 * @class PICML_Data_Value_Control_Selector
 *
 * Helper class for selecting the correct control for data value.
 */
class PICML_Data_Value_Control_Selector :
  public PICML::Visitor
{
public:
  PICML_Data_Value_Control_Selector (void)
    : control_ (0)
  {

  }

  /// Destructor.
  virtual ~PICML_Data_Value_Control_Selector (void)
  {

  }

  virtual void Visit_Boolean (const PICML::Boolean & )
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Boolean_Data_Value_Control);
  }

  virtual void Visit_Char (const PICML::Char &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Char_Data_Value_Control);
  }

  virtual void Visit_WideChar (const PICML::WideChar &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Char_Data_Value_Control);
  }

  virtual void Visit_Enum (const PICML::Enum &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Enum_Data_Value_Control);
  }

  virtual void Visit_ShortInteger (const PICML::ShortInteger &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Short_Data_Value_Control);
  }

  virtual void Visit_UnsignedShortInteger (const PICML::UnsignedShortInteger &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_UShort_Data_Value_Control);
  }

  virtual void Visit_LongInteger (const PICML::LongInteger &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Long_Data_Value_Control);
  }

  virtual void Visit_UnsignedLongInteger (const PICML::UnsignedLongInteger &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_ULong_Data_Value_Control);
  }

  virtual void Visit_FloatNumber (const PICML::FloatNumber &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_String_Data_Value_Control);
  }

  virtual void Visit_DoubleNumber (const PICML::DoubleNumber &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_String_Data_Value_Control);
  }

  virtual void Visit_String (const PICML::String &)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_String_Data_Value_Control);
  }

  PICML_Data_Value_Control * control (void) const
  {
    return this->control_;
  }

private:
  /// The index of the image.
  PICML_Data_Value_Control * control_;
};

/**
 * @class PICML_Property_Manager_ListView_Item
 *
 * Select the image index for the data type. By default, the image
 * selected is IDI_NONE.
 */
class PICML_Property_Manager_ListView_Image :
  public PICML::Visitor
{
public:
  PICML_Property_Manager_ListView_Image (void)
    : index_ (0)
  {

  }

  /// Destructor.
  virtual ~PICML_Property_Manager_ListView_Image (void)
  {

  }

  virtual void Visit_Aggregate (const PICML::Aggregate &)
  {
    this->index_ = 1;
  }

  virtual void Visit_Collection (const PICML::Collection & c)
  {
    this->index_ = 1;
  }

  int index (void) const
  {
    return this->index_;
  }

private:
  /// The index of the image.
  int index_;
};

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListView_Expand

class PICML_Property_Manager_ListView_Expand :
  public PICML::Visitor
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

  virtual void Visit_Property (const PICML::Property & prop)
  {
    // We are going to make the assumption the elements contained
    // in the property are correct. This means that simple types
    // contain only a single DataValueBase element and complex types
    // contain [1..n] DataValueBase elements.
    typedef UDM_Position_Sort_T <PICML::DataValueBase, PS_Top_To_Bottom> sort_type;
    std::set <PICML::DataValueBase, sort_type> values = prop.DataValueBase_kind_children_sorted (sort_type ());

    std::for_each (values.begin (),
                   values.end (),
                   boost::bind (&PICML_Property_Manager_ListView_Expand::Visit_DataValueBase,
                                this,
                                _1));

    // We need to add a "blank" element to the end of the list
    // if this is a collection (i.e., a sequence). This will allow
    // the user to add new elements to the sequence.
    PICML::ComplexTypeReference type = prop.ComplexTypeReference_child ();

    if (type == Udm::null)
      return;

    // Get the complex type.
    PICML::ComplexType complex = type.ref ();

    if (complex != Udm::null && complex.type () == PICML::Collection::meta)
      this->insert_collection_footer ();
  }

  virtual void Visit_DataValueContainer (const PICML::DataValueContainer & c)
  {
    // We are going to make the assumption the elements contained
    // in the property are correct. This means that simple types
    // contain only a single DataValueBase element and complex types
    // contain [1..n] DataValueBase elements.
    typedef UDM_Position_Sort_T <PICML::DataValueBase, PS_Top_To_Bottom> sort_type;
    std::set <PICML::DataValueBase, sort_type> values = c.DataValueBase_kind_children_sorted (sort_type ());

    std::for_each (values.begin (),
                   values.end (),
                   boost::bind (&PICML_Property_Manager_ListView_Expand::Visit_DataValueBase,
                                this,
                                _1));

    // We need to add a "blank" element to the end of the list
    // if this is a collection (i.e., a sequence). This will allow
    // the user to add new elements to the sequence.
    PICML::ComplexTypeReference type = c.ComplexTypeReference_child ();

    if (type == Udm::null)
      return;

    // Get the complex type.
    PICML::ComplexType complex = type.ref ();

    if (complex != Udm::null && complex.type () == PICML::Collection::meta)
      this->insert_collection_footer ();
  }

private:
  void insert_collection_footer (void)
  {
    // Insert the blank item into the listing. This will be used
    // to determine when the sequence is clicked.
    this->item_.mask     = LVIF_INDENT | LVIF_IMAGE | LVIF_PARAM;
    this->item_.iImage   = 0;
    this->item_.iSubItem = 0;
    this->item_.lParam   = 0;

    this->parent_.InsertItem (&this->item_);
  }

  // Helper method for inserting items into the container.
  void Visit_DataValueBase (const PICML::DataValueBase & value)
  {
    const Uml::Class & type = value.type ();
    const bool expand = (type == PICML::DataValueContainer::meta);

    // Initialize the item's properties.
    this->item_.mask     = LVIF_PARAM | LVIF_INDENT | LVIF_IMAGE;
    this->item_.lParam   = reinterpret_cast <LPARAM> (value.__impl ()->clone ());
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
PICML_Property_Manager_ListCtrl::
PICML_Property_Manager_ListCtrl (void)
: edit_control_ (0)
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
void PICML_Property_Manager_ListCtrl::SetProperty (const PICML::Property & prop)
{
  // Initialize the control based on the property.
  PICML_Property_Manager_ListView_Expand expander (*this, 0, 0);
  PICML::Property (prop).Accept (expander);
  this->prop_ = prop;
}

//
// DrawItem
//
void PICML_Property_Manager_ListCtrl::DrawItem (LPDRAWITEMSTRUCT item)
{
  int image = 0;
  std::string name, value;

  // Get the name and value from the data item.
  if (item->itemData != 0)
  {
    Udm::ObjectImpl * impl = reinterpret_cast <Udm::ObjectImpl *> (item->itemData);
    Udm::Object obj (impl->clone ());

    // Save the name of the object/item.
    PICML::DataValueBase base = PICML::DataValueBase::Cast (obj);
    name = base.name ();

    if (base.type () == PICML::DataValue::meta)
      value = PICML::DataValue::Cast (base).Value ();
  }
  else
  {
    value = "Click to insert new item";
  }

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
  //this->end_label_edit ();

  // We can only continue if we have really destroyed the edit
  // control. Otherwise, we need to leave it active.
  //if (this->edit_control_ != 0)
  //  return;

  // Convert the screen coordinates to client coordinates.
  //CPoint pt (point);
  //this->ScreenToClient (&pt);

  // Prepare the hit test structure using the client coordinates.
  //LVHITTESTINFO info;
  //info.pt.x = pt.x;
  //info.pt.y = pt.y;

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

  //  this->target_value_ =       reinterpret_cast <PICML_Data_Value *> (lvitem.lParam);

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

  // We can only continue if we have really destroyed the edit
  // control. Otherwise, we need to leave it active.
  if (this->edit_control_ != 0)
    return;

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

  if (lvitem.iImage == 1 && lvitem.lParam != 0)
  {
    // Get the data value from the parameter.
    Udm::ObjectImpl * impl = reinterpret_cast <Udm::ObjectImpl *> (lvitem.lParam);
    PICML::DataValueContainer container (impl->clone ());

    // Set image to collapse image since we have expanded list.
    lvitem.iImage = 2;
    this->SetItem (&lvitem);

    // Insert the child items into the control.
    PICML_Property_Manager_ListView_Expand builder (*this, lvitem.iItem + 1, lvitem.iIndent + 1);
    container.Accept (builder);
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

  if (lvitem.lParam != 0)
  {
    // Get the correct edit control to display for the item.
    Udm::ObjectImpl * impl = reinterpret_cast <Udm::ObjectImpl *> (lvitem.lParam);
    PICML::DataValueBase value_base (impl->clone ());

    if (value_base.type () != PICML::DataValue::meta)
      return;

    // We need to select the correct editor based on the DataValue
    // elements data type.
    PICML::DataValue data_value = PICML::DataValue::Cast (value_base);
    PICML_Data_Value_Control_Selector selector;

    PICML_DATA_TYPE_DISPATCHER->dispatch (selector, data_value.ref ());
    this->edit_control_ = selector.control ();

    if (this->edit_control_ == 0)
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

    // Initialize the control.
    PICML::DataValue value = PICML::DataValue::Cast (value_base);
    this->edit_control_->InitControl (testinfo.iItem, value);

    // Create the control.
    this->edit_control_->Create (0,
                                 subitem_rect,
                                 this,
                                 IDC_EDIT_CONTROL);
  }
  else
  {
    // The user wants to insert a new item into a sequence. We
    // need to find the parent of this item. This will be the
    // item that's one indentation less than the current one.
    int item   = lvitem.iItem;
    int indent = lvitem.iIndent;

    lvitem.mask = LVIF_INDENT | LVIF_PARAM;

    // Get the infomration about the current item. We need to
    // locate the parent sequence container. If the container is
    // a property, then we need to
    this->GetItem (&lvitem);

    while (lvitem.iIndent >= indent && lvitem.iItem > 0)
    {
      -- lvitem.iItem;
      this->GetItem (&lvitem);
    }

    PICML::Collection source;
    Udm::Object parent;

    if (lvitem.lParam == 0)
    {
      // Save the container as the parent element. This will be needed
      // later when we create the new element in the sequence.
      parent = this->prop_;

      // We need to use the property, since we can assume the
      // sequence is actual the root.
      PICML::ComplexTypeReference ref = this->prop_.ComplexTypeReference_child ();
      source = PICML::Collection::Cast (ref.ref ());
    }
    else
    {
      Udm::ObjectImpl * impl = reinterpret_cast <Udm::ObjectImpl *> (lvitem.lParam);
      PICML::DataValueContainer container (impl->clone ());

      // Save the container as the parent element. This will be needed
      // later when we create the new element in the sequence.
      parent = container;

      PICML::ComplexTypeReference ref = this->prop_.ComplexTypeReference_child ();
      source = PICML::Collection::Cast (ref.ref ());
    }

    // Get the source's type. This will determine what kind of DataValueBase
    // element we need to create.
    PICML::DataValueBase value_base;
    PICML::MemberType member_type = source.ref ();
    const Uml::Class & cls = member_type.type ();

    if (Udm::IsDerivedFrom (cls, PICML::PredefinedType::meta) ||
        cls == PICML::Enum::meta)
    {
      // We need to create a DataValue element.
      PICML::DataValue value = PICML::DataValue::Create (parent);
      value.ref () = PICML::SimpleType::Cast (member_type);

      // Save the value for storage in the list control.
      value_base = value;
    }
    else
    {
      // We need to create a DataValueContainer element.
      PICML::DataValueContainer value = PICML::DataValueContainer::Create (parent);
      PICML::ComplexTypeReference ref = PICML::ComplexTypeReference::Create (value);
      ref.ref () = PICML::ComplexType::Cast (member_type);

      // Save the value for storage in the list control.
      value_base = value;
    }

    // Finally, add the element to the collection. This is done by
    // selecting all the elements in the container.


      // Add a new element to the collection to the DataValueContainer.

    lvitem.mask     = LVIF_IMAGE | LVIF_INDENT | LVIF_PARAM;
    lvitem.iItem    = item;
    lvitem.iSubItem = 0;
    lvitem.iIndent  = indent;
    lvitem.lParam   = reinterpret_cast <LPARAM> (value_base.__impl ());

      //// Select the correct image for the item.
      //PICML_Property_Manager_ListView_Image image (lvitem.iImage);
      //value->accept (image);

      //// Insert the item into the list.
      //if (this->InsertItem (&lvitem) != -1)
      //{
      //  // Update the "insert" items name.
      //  std::ostrstream name;
      //  name << "[" << sequence->size () << "]" << std::ends;

      //  this->SetItemText (item + 1, 0, name.str ());
      //}
  }
}

//
// end_label_edit
//
void PICML_Property_Manager_ListCtrl::end_label_edit (void)
{
  if (this->edit_control_ == 0)
    return;

  // Destroy the window, but not the actual class since there
  // is chance we will be using the class later one.
  if (this->edit_control_->Destroy ())
  {
    // Store the item and release the control.
    int item = this->edit_control_->item ();
    this->edit_control_ = 0;

    // Update the list view item.
    this->Update (item);
  }

  // Force the entire window to redraw itself. This is kind of
  // overkill, but and we should find a better way to just invalidate
  // the portion of the window that has changed.
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
  this->lvitem_.mask = LVIF_INDENT;

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
    this->DeleteItem (this->lvitem_.iItem);
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

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_Dialog

BEGIN_MESSAGE_MAP (PICML_Property_Manager_Dialog, CDialog)

END_MESSAGE_MAP ()

//
// PICML_Property_Manager_Dialog
//
PICML_Property_Manager_Dialog::
PICML_Property_Manager_Dialog (const PICML::Property & prop, CWnd * parent)
: CDialog (IDD_PROPERTY_MANAGER, parent),
  prop_ (prop)
{

}

//
// ~PICML_Property_Manager_Dialog
//
PICML_Property_Manager_Dialog::~PICML_Property_Manager_Dialog (void)
{

}

//
// DoDataExchange
//
void PICML_Property_Manager_Dialog::DoDataExchange (CDataExchange * pDX)
{
  CDialog::DoDataExchange (pDX);
  DDX_Control (pDX, IDC_DATAVALUE, this->listview_);
}

//
// OnInitDialog
//
BOOL PICML_Property_Manager_Dialog::OnInitDialog (void)
{
  // Pass control to the base class.
  CDialog::OnInitDialog ();

  // Set the data value of the list view.
  this->listview_.InitControl ();
  this->listview_.SetProperty (this->prop_);

  return TRUE;
}
