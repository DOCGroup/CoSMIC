// $Id$

#include "StdAfx.h"
#include "PropertyManager_Dialog.h"
#include "Resource.h"

#include "DT_Controls.h"
#include "PICML/Data_Value.h"
#include "PICML/Data_Value_Visitor.h"

#include "ace/Singleton.h"
#include "ace/Null_Mutex.h"

#include <memory>
#include <strstream>

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListView_Item

#define SELECT_DATA_VALUE_CONTROL(control, type) \
  control = ACE_Singleton <type, ACE_Null_Mutex>::instance ()

class PICML_Data_Value_Control_Selector :
  public PICML_Data_Value_Visitor
{
public:
  PICML_Data_Value_Control_Selector (PICML_Data_Value_Control * & control)
    : control_ (control)
  {
    this->control_ = 0;
  }

  /// Destructor.
  virtual ~PICML_Data_Value_Control_Selector (void)
  {

  }

  virtual void visit_PICML_Boolean_Data_Value (
    const PICML_Boolean_Data_Value & )
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Boolean_DT_Control);
  }

  virtual void visit_PICML_Char_Data_Value (
    const PICML_Char_Data_Value & value)
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Char_DT_Control);
  }

  virtual void visit_PICML_Enum_Data_Value (
    const PICML_Enum_Data_Value & )
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Enum_DT_Control);
  }

  virtual void visit_PICML_Long_Data_Value (
    const PICML_Long_Data_Value & )
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Long_DT_Control);
  }

  virtual void visit_PICML_Short_Data_Value (
    const PICML_Short_Data_Value & )
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_Short_DT_Control);
  }

  virtual void visit_PICML_String_Data_Value (
    const PICML_String_Data_Value & )
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_String_DT_Control);
  }

  virtual void visit_PICML_ULong_Data_Value (
    const PICML_ULong_Data_Value & )
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_ULong_DT_Control);
  }

  virtual void visit_PICML_UShort_Data_Value (
    const PICML_UShort_Data_Value & )
  {
    SELECT_DATA_VALUE_CONTROL (this->control_, PICML_UShort_DT_Control);
  }

private:
  /// The index of the image.
  PICML_Data_Value_Control * & control_;
};

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListView_Item

class PICML_Property_Manager_ListView_Image :
  public PICML_Data_Value_Visitor
{
public:
  PICML_Property_Manager_ListView_Image (int & image)
    : index_ (image)
  {

  }

  /// Destructor.
  virtual ~PICML_Property_Manager_ListView_Image (void)
  {

  }

  virtual void visit_PICML_Aggregate_Data_Value (
    const PICML_Aggregate_Data_Value &)
  {
    this->index_ = 1;
  }

  virtual void visit_PICML_Boolean_Data_Value (
    const PICML_Boolean_Data_Value &)
  {
    this->index_ = 0;
  }

  virtual void visit_PICML_Char_Data_Value (
    const PICML_Char_Data_Value &)
  {
    this->index_ = 0;
  }

  virtual void visit_PICML_Enum_Data_Value (
    const PICML_Enum_Data_Value &)
  {
    this->index_ = 0;
  }


  virtual void visit_PICML_Long_Data_Value (
    const PICML_Long_Data_Value &)
  {
    this->index_ = 0;
  }

  virtual void visit_PICML_Sequence_Data_Value (
    const PICML_Sequence_Data_Value &)
  {
    this->index_ = 1;
  }

  virtual void visit_PICML_Short_Data_Value (
    const PICML_Short_Data_Value &)
  {
    this->index_ = 0;
  }

  virtual void visit_PICML_String_Data_Value (
    const PICML_String_Data_Value &)
  {
    this->index_ = 0;
  }

  virtual void visit_PICML_ULong_Data_Value (
    const PICML_ULong_Data_Value &)
  {
    this->index_ = 0;
  }

  virtual void visit_PICML_UShort_Data_Value (
    const PICML_UShort_Data_Value & )
  {
    this->index_ = 0;
  }

private:
  /// The index of the image.
  int & index_;
};

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListView_Expand

class PICML_Property_Manager_ListView_Expand :
  public PICML_Data_Value_Visitor
{
public:
  PICML_Property_Manager_ListView_Expand (
    PICML_Property_Manager_ListCtrl & parent,
    LVITEM & item)
    : parent_ (parent),
      item_ (item),
      image_ (item_.iImage)
  {
    // Increment the index value. This should on be done
    // once during the lifetime fo the builder.
    ++ this->item_.iIndent;
  }

  virtual ~PICML_Property_Manager_ListView_Expand (void)
  {

  }

  virtual void visit_PICML_Aggregate_Data_Value (
    const PICML_Aggregate_Data_Value & value)
  {
    PICML_Aggregate_Data_Value::const_iterator
      iter = value.begin (),
      iter_end = value.end ();

    for ( ; iter != iter_end; iter ++)
      this->insert_item (*iter->second);
  }

  virtual void visit_PICML_Boolean_Data_Value (
    const PICML_Boolean_Data_Value & value)
  {
    this->insert_item (value);
  }

  virtual void visit_PICML_Char_Data_Value (
    const PICML_Char_Data_Value & value)
  {
    this->insert_item (value);
  }

  virtual void visit_PICML_Enum_Data_Value (
    const PICML_Enum_Data_Value & value)
  {
    this->insert_item (value);
  }


  virtual void visit_PICML_Long_Data_Value (
    const PICML_Long_Data_Value & value)
  {
    this->insert_item (value);
  }

  virtual void visit_PICML_Sequence_Data_Value (
    const PICML_Sequence_Data_Value & value)
  {
    PICML_Sequence_Data_Value::const_iterator
      iter = value.begin (),
      iter_end = value.end ();

    for ( ; iter != iter_end; iter ++)
      this->insert_item (*(*iter));

    std::ostrstream ostr;
    ostr << "[" << value.size () << "]" << std::ends;

    // Initialize the item's properties.
    this->item_.mask     = LVIF_PARAM | LVIF_TEXT | LVIF_INDENT;
    this->item_.pszText  = ostr.str ();
    this->item_.lParam   = 0;
    this->item_.iSubItem = 0;

    // Move to the next item in the list.
    ++ this->item_.iItem;

    // Insert the item into the listview control.
    if (this->parent_.InsertItem (&this->item_) != -1)
    {
      this->parent_.SetItemText (this->item_.iItem,
                                 1,
                                 "Click here to insert item...");
    }
  }

  virtual void visit_PICML_Short_Data_Value (
    const PICML_Short_Data_Value & value)
  {
    this->insert_item (value);
  }

  virtual void visit_PICML_String_Data_Value (
    const PICML_String_Data_Value & value)
  {
    this->insert_item (value);
  }

  virtual void visit_PICML_ULong_Data_Value (
    const PICML_ULong_Data_Value & value)
  {
    this->insert_item (value);
  }

  virtual void visit_PICML_UShort_Data_Value (
    const PICML_UShort_Data_Value & value)
  {
    this->insert_item (value);
  }

private:
  void insert_item (const PICML_Data_Value & value)
  {
    // Initialize the item's properties.
    this->item_.mask    = LVIF_PARAM | LVIF_INDENT | LVIF_IMAGE;
    this->item_.lParam  = reinterpret_cast <LPARAM> (&value);

    // Get the correct image for the value.
    value.accept (this->image_);

    // Move to the next item in the list.
    ++ this->item_.iItem;

    // Insert the item into the listview control.
    if (this->parent_.InsertItem (&this->item_) == -1)
      ::AfxMessageBox ("Failed to insert new item", MB_OK | MB_ICONEXCLAMATION);
  }

  /// Parent control of the item.
  PICML_Property_Manager_ListCtrl & parent_;

  /// Pointer to the target item.
  LVITEM & item_;

  /// The image selector.
  PICML_Property_Manager_ListView_Image image_;
};

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_ListCtrl

BEGIN_MESSAGE_MAP (PICML_Property_Manager_ListCtrl, CListCtrl)
  ON_WM_LBUTTONDOWN ()
  ON_WM_CONTEXTMENU ()
  ON_WM_HSCROLL ()
  ON_WM_VSCROLL ()
  ON_WM_INITMENUPOPUP ()

  ON_COMMAND (ID_IDR_DELETEITEM, OnCommand_DeleteItem)
  ON_COMMAND (ID_IDR_MOVEUP, OnCommand_MoveUp)
  ON_COMMAND (ID_IDR_MOVEDOWN, OnCommand_MoveDown)
END_MESSAGE_MAP ()

//
// PICML_Property_Manager_ListCtrl
//
PICML_Property_Manager_ListCtrl::
PICML_Property_Manager_ListCtrl (void)
: edit_control_ (0),
  sequence_ (0)
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
// SetDataValue
//
void PICML_Property_Manager_ListCtrl::
SetDataValue (PICML_Data_Value * value)
{
  // Initialize the list view item's properties.
  LVITEM lvitem;
  ZeroMemory (&lvitem, sizeof (LVITEM));

  lvitem.mask    = LVIF_PARAM | /*LVIF_TEXT |*/ LVIF_INDENT | LVIF_IMAGE;
  lvitem.lParam  = reinterpret_cast <LPARAM> (value);
  lvitem.iIndent = 0;

  // Select the correct image.
  PICML_Property_Manager_ListView_Image image (lvitem.iImage);
  value->accept (image);

  if (this->InsertItem (&lvitem) != -1)
  {
    // Insert the subitem, which is really the value.
    lvitem.mask = LVIF_TEXT;
    lvitem.iSubItem = 1;

    this->InsertItem (&lvitem);
  }
  else
  {
    ::AfxMessageBox ("Failed to create a new item", MB_OK | MB_ICONERROR);
  }
}

//
// DrawItem
//
void PICML_Property_Manager_ListCtrl::DrawItem (LPDRAWITEMSTRUCT item)
{
  int image = 0;
  std::string str_name, str_value;

  LVITEM lvitem;

  if (item->itemData != 0)
  {
    // Get the name and value from the data item.
    PICML_Data_Value * value =
      reinterpret_cast <PICML_Data_Value *> (item->itemData);

    str_name = value->name ();
    str_value = value->value ();

    // Get the image index for the item.
    lvitem.mask     = LVIF_IMAGE;
    lvitem.iItem    = item->itemID;
    lvitem.iSubItem = 0;

    if (this->GetItem (&lvitem) != 0)
      image = lvitem.iImage;
  }
  else
  {
    str_name  = this->GetItemText (item->itemID, 0).GetBuffer ();
    str_value = this->GetItemText (item->itemID, 1).GetBuffer ();
  }

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

  UINT format = DT_LEFT | DT_END_ELLIPSIS |
    DT_VCENTER | DT_SINGLELINE;

  if (!str_name.empty ())
  {
    // Draw the name of the value to the device.
    device.DrawText (str_name.c_str (),
                    str_name.length (),
                    rect_name,
                    format);
  }

  if (!str_value.empty ())
  {
    // Draw the actual value to the device.
    device.DrawText (str_value.c_str (),
                     str_value.length (),
                     rect_value,
                     format);
  }

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

  // We can only continue if we have really destroyed the edit
  // control. Otherwise, we need to leave it active.
  if (this->edit_control_ != 0)
    return;

  // Convert the screen coordinates to client coordinates.
  CPoint pt (point);
  this->ScreenToClient (&pt);

  // Prepare the hit test structure using the client coordinates.
  LVHITTESTINFO info;
  info.pt.x = pt.x;
  info.pt.y = pt.y;

  // Determine what item in the list was selected. Also, we only
  // care about the 'value' column being clicked.
  if (this->SubItemHitTest (&info) != -1 && info.iSubItem == 1)
  {
    LVITEM lvitem;
    lvitem.mask     = LVIF_INDENT | LVIF_PARAM;
    lvitem.iItem    = info.iItem;
    lvitem.iSubItem = 0;

    // Get the information about the selected item.
    this->GetItem (&lvitem);
    int indent = lvitem.iIndent;

    // Extract the target value.
    this->target_value_ =
      reinterpret_cast <PICML_Data_Value *> (lvitem.lParam);

    // Determine if the value belongs to a sequence. This means
    // locating is parent, if it has one.
    do
    {
      -- lvitem.iItem;
    } while (this->GetItem (&lvitem) != 0 && lvitem.iIndent >= indent);

    // Get the data value from the item.
    PICML_Data_Value * value =
      reinterpret_cast <PICML_Data_Value *> (lvitem.lParam);

    if (typeid (*value) == typeid (PICML_Sequence_Data_Value))
    {
      try
      {
        // Convert the value into a sequence value.
        this->sequence_ =
          dynamic_cast <PICML_Sequence_Data_Value *> (value);

        // Save the item and index of the value to delete.
        this->parent_item_  = lvitem.iItem;
        this->target_item_  = info.iItem;

        // Load the main menu from the resources.
        CMenu menu;
        menu.LoadMenu (IDR_LISTCTRL_CTX);

        // Get the first submenu, which is our context menu.
        CMenu * popup = menu.GetSubMenu (0);

        if (popup != 0)
        {
          // Create it as a popup menu.
          popup->TrackPopupMenu (TPM_LEFTALIGN | TPM_LEFTBUTTON,
                                 point.x,
                                 point.y,
                                 this);

          // We are going to return from here since we do not
          // need to perform any of the default operation(s).
          return;
        }
        else
        {
          ::AfxMessageBox ("Failed to create popup menu",
                           MB_OK | MB_ICONEXCLAMATION);
        }
      }
      catch (std::bad_cast &)
      {

      }
    }
  }

  // Perform the default operation(s).
  this->sequence_ = 0;
  CListCtrl::OnContextMenu (parent, point);
}

//
// OnLButtonDown
//
void PICML_Property_Manager_ListCtrl::
OnLButtonDown (UINT flags, CPoint point)
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
  if (this->SubItemHitTest (&info) != -1)
  {
    // Get the data associated with this item.
    if (info.iSubItem == 0)
    {
      if ((info.flags & LVHT_ONITEMICON))
      {
        // Get the appropriate information needed to toggle the
        // child items for this item, if applicable.
        LVITEM lvitem;
        lvitem.mask     = LVIF_IMAGE | LVIF_PARAM | LVIF_INDENT;
        lvitem.iItem    = info.iItem;
        lvitem.iSubItem = 0;

        if (this->GetItem (&lvitem) != 0)
        {
          if (lvitem.lParam != 0)
          {
            // Get the data value from the parameter.
            PICML_Data_Value * value =
              reinterpret_cast <PICML_Data_Value *> (lvitem.lParam);

            if (lvitem.iImage == 1)
            {
              // Set image to collapse image since we have expanded list.
              lvitem.iImage = 2;
              this->SetItem (&lvitem);

              // Insert the child items into the control.
              PICML_Property_Manager_ListView_Expand builder (*this, lvitem);
              value->accept (builder);
            }
            else if (lvitem.iImage == 2)
              this->collapse_item (lvitem.iItem);
          }
        }
        else
        {
          ::AfxMessageBox ("Failed to toggle selected item",
                           MB_OK | MB_ICONWARNING);
        }
      }
    }
    else if (info.iSubItem == 1)
    {
      // Get the data for the item.
      LVITEM lvitem;
      lvitem.mask     = LVIF_PARAM | LVIF_INDENT;
      lvitem.iItem    = info.iItem;
      lvitem.iSubItem = 0;

      if (this->GetItem (&lvitem) != 0)
      {
        if (lvitem.lParam != 0)
        {
          // Get the correct edit control to display for the item.
          PICML_Data_Value * value =
            reinterpret_cast <PICML_Data_Value *> (lvitem.lParam);

          PICML_Data_Value_Control_Selector selector (this->edit_control_);
          value->accept (selector);

          if (this->edit_control_ != 0)
          {
            // Get the dimensions of the subitem.
            CRect subitem_rect;
            this->GetSubItemRect (info.iItem,
                                  info.iSubItem,
                                  LVIR_BOUNDS,
                                  subitem_rect);

            // Shrink the height of the control so we do not draw it
            // over the horizontal borders.
            -- subitem_rect.bottom;

            // Initialize the control.
            this->edit_control_->InitControl (info.iItem, value);

            // Create the control.
            this->edit_control_->Create (0,
                                        subitem_rect,
                                        this,
                                        IDC_EDIT_CONTROL);
          }
        }
        else
        {
          // The user wants to insert a new item into a sequence. We
          // need to find the parent of this item. This will be the
          // item that's one indentation less than the current one.
          int item   = lvitem.iItem;
          int indent = lvitem.iIndent;

          lvitem.mask = LVIF_INDENT | LVIF_PARAM;

          do
          {
            // Get the previous item in the listing.
            -- lvitem.iItem;
            this->GetItem (&lvitem);

            // Check the indentation of this item.
          } while (lvitem.iIndent >= indent);

          if (lvitem.lParam != 0)
          {
            try
            {
              // Extract the sequence value.
              PICML_Data_Value * v =
                reinterpret_cast <PICML_Data_Value *> (lvitem.lParam);

              PICML_Sequence_Data_Value * sequence =
                dynamic_cast <PICML_Sequence_Data_Value *> (v);

              // Create a new element in the sequence.
              PICML_Data_Value * value = sequence->new_element ();

              lvitem.mask     = LVIF_IMAGE | LVIF_INDENT | LVIF_PARAM;
              lvitem.iItem    = item;
              lvitem.iSubItem = 0;
              lvitem.iIndent  = indent;
              lvitem.lParam   = reinterpret_cast <LPARAM> (value);

              // Select the correct image for the item.
              PICML_Property_Manager_ListView_Image image (lvitem.iImage);
              value->accept (image);

              // Insert the item into the list.
              if (this->InsertItem (&lvitem) != -1)
              {
                // Update the "insert" items name.
                std::ostrstream name;
                name << "[" << sequence->size () << "]" << std::ends;

                this->SetItemText (item + 1, 0, name.str ());
              }
              else
              {
                ::AfxMessageBox ("Failed to create new element in sequence",
                                 MB_OK | MB_ICONWARNING);
              }
            }
            catch (...)
            {
              ::AfxMessageBox ("Failed to extract sequence from item",
                               MB_OK | MB_ICONWARNING);
            }
          }
        }
      }
    }
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
// end_label_edit
//
void PICML_Property_Manager_ListCtrl::end_label_edit (void)
{
  if (this->edit_control_ == 0)
    return;

  // Destroy the window, but not the actual class.
  if (this->edit_control_->Destroy ())
  {
    // Update the list view item.
    this->Update (this->edit_control_->item ());

    // Reset the edit control.
    this->edit_control_ = 0;
  }

  // Force the entire window to redraw itself. This is kind
  // of overkill, but I'm crutched for time.
  this->InvalidateRect (0);
}

//
// OnInitMenuPopup
//
void PICML_Property_Manager_ListCtrl::
OnInitMenuPopup (CMenu * popup, UINT index, BOOL sysmenu)
{
  if (index == 0 && this->sequence_ != 0)
  {
    // Get the size of the sequence.
    size_t size = this->sequence_->size ();

    // Get the index of the target value in the sequence.
    size_t index;
    bool found = this->sequence_->get_index (this->target_value_, index);

    // Enable/disable the "Delete item..." command.
    UINT flags = MF_BYCOMMAND | (found ? MF_ENABLED : MF_GRAYED);
    popup->EnableMenuItem (ID_IDR_DELETEITEM, flags);

    // Enable/disable the "Move up" command.
    flags = MF_BYCOMMAND | (index != 0 ? MF_ENABLED : MF_GRAYED);
    popup->EnableMenuItem (ID_IDR_MOVEUP, flags);

    // Enable/disable the "Move down" command.
    flags = MF_BYCOMMAND | (index < size - 1 ? MF_ENABLED : MF_GRAYED);
    popup->EnableMenuItem (ID_IDR_MOVEDOWN, flags);
  }
}

//
// OnCommand_MoveUp
//
void PICML_Property_Manager_ListCtrl::OnCommand_MoveUp (void)
{
  // Move the value down in the sequence.
  this->sequence_->move_up (this->target_value_);

  // Find the next item in the control.
  int prev_item = this->find_prev_item (this->target_item_);

  // Swap the item's data in the control.
  this->swap_item_data (this->target_item_, prev_item);

  // Collapse and update the target.
  this->collapse_item (this->target_item_);
  this->Update (this->target_item_);

  // Collapse and update the previous item.
  this->collapse_item (prev_item);
  this->Update (prev_item);

  // Update the parent item.
  this->Update (this->parent_item_);
}

//
// OnCommand_MoveDown
//
void PICML_Property_Manager_ListCtrl::OnCommand_MoveDown (void)
{
  // Move the value down in the sequence.
  this->sequence_->move_down (this->target_value_);

  // Find the next item in the control.
  int next_item = this->find_next_item (this->target_item_);

  // Swap the item's data.
  this->swap_item_data (this->target_item_, next_item);

  // Collapse and update the next item.
  this->collapse_item (next_item);
  this->Update (next_item);

  // Collapse and update the target item.
  this->collapse_item (this->target_item_);
  this->Update (this->target_item_);

  // Update the parent item.
  this->Update (this->parent_item_);
}

//
// OnCommand_DeleteItem
//
void PICML_Property_Manager_ListCtrl::OnCommand_DeleteItem (void)
{
  // Collapse the item, if necessary, then delete it.
  this->collapse_item (this->target_item_);
  this->DeleteItem (this->target_item_);

  // Delete the item from the sequence.
  this->sequence_->remove (this->target_value_);

  // Get the size of the sequence.
  size_t size = this->sequence_->size ();

  // Generate the "click here to insert new item" name.
  std::ostrstream ostr;
  ostr << "[" << size << "]" << std::ends;

  // Update the "click here to insert new item" name and value.
  int dummy = this->target_item_ + (size - this->target_index_);
  this->SetItemText (dummy, 0, ostr.str ());

  // Release our target sequence.
  this->sequence_ = 0;

  // Update the parent.
  this->Update (this->parent_item_);
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
  LVITEM lvitem;
  lvitem.mask     = LVIF_INDENT;
  lvitem.iItem    = item;
  lvitem.iSubItem = 0;

  int retval = 0;

  if (this->GetItem (&lvitem) != 0)
  {
    // Save the current indentation value. We need to find another
    // item w/ the same indentation.
    int indent = lvitem.iIndent;

    do
    {
      // Get the next item as long as it's indentation is greater
      // than the start item. This means that we are still one
      // looking at child items of parent we are searching for.
      lvitem.iItem += step;
      retval = this->GetItem (&lvitem);
    } while (retval != 0 && lvitem.iIndent > indent);
  }

  return retval != 0 ? lvitem.iItem : -1;
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

  if (this->GetItem (&this->lvitem_) != 0)
  {
    // Save the parent item's indentation value.
    int indent = this->lvitem_.iIndent;

    // Move the next item. From this point forward, we do not
    // have to change this value.
    ++ this->lvitem_.iItem;

    // Delete all the items with a greater indentation value.
    while (this->GetItem (&this->lvitem_) != 0 &&
           this->lvitem_.iIndent > indent)
    {
      this->DeleteItem (this->lvitem_.iItem);
    }
  }
}

//
// swap_data_value
//
void PICML_Property_Manager_ListCtrl::
swap_item_data (int i, int j)
{
  DWORD_PTR temp = this->GetItemData (i);
  this->SetItemData (i, this->GetItemData (j));
  this->SetItemData (j, temp);
}

///////////////////////////////////////////////////////////////////////////////
// PICML_Property_Manager_Dialog

BEGIN_MESSAGE_MAP (PICML_Property_Manager_Dialog, CDialog)

END_MESSAGE_MAP ()

//
// PICML_Property_Manager_Dialog
//
PICML_Property_Manager_Dialog::
PICML_Property_Manager_Dialog (PICML_Data_Value * value, CWnd * parent)
: CDialog (IDD_DATAVALUE, parent),
  value_ (value)
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
void PICML_Property_Manager_Dialog::
DoDataExchange (CDataExchange * pDX)
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
  this->listview_.SetDataValue (this->value_);

  return TRUE;
}

