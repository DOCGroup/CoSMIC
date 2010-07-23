// $Id$

#include "resource.h"
#include "Dialog_Display_Strategy.h"

namespace GAME
{
namespace Dialogs
{
//
// Selection_List_Dialog
//
template <typename T>
Selection_List_Dialog <T>::
Selection_List_Dialog (const items_type & items,
                       Dialog_Display_Strategy * strategy,
                       CWnd * parent)
: CDialog (IDD_GAME_SELECTION_LIST_DLG, parent),
  strategy_ (strategy),
  items_ (items)
{

}

//
// ~Selection_List_Dialog
//
template <typename T>
Selection_List_Dialog <T>::~Selection_List_Dialog (void)
{

}

//
// selection
//
template <typename T>
T Selection_List_Dialog <T>::selection (void) const
{
  return this->selection_;
}

//
// OnInitDialog
//
template <typename T>
BOOL Selection_List_Dialog <T>::OnInitDialog (void)
{
  // Pass control to the base class first.
  CDialog::OnInitDialog ();

  if (0 == this->strategy_)
  {
    items_type::const_iterator
      iter = this->items_.begin (), iter_end = this->items_.end ();

    for (; iter != iter_end; ++ iter)
      this->insert_item (*iter, iter->name ());
  }
  else
  {
    items_type::const_iterator
      iter = this->items_.begin (), iter_end = this->items_.end ();

    std::string display_name;

    for (; iter != iter_end; ++ iter)
    {
      if (this->strategy_->get_display_name (*iter, display_name))
        this->insert_item (*iter, display_name);
    }
  }

  // Set the title of the dialog box.
  if (!this->title_.empty ())
    this->SetWindowText (this->title_.c_str ());

  return FALSE;
}

//
// insert_item
//
template <typename T>
void Selection_List_Dialog <T>::
insert_item (T item, const std::string & display_name)
{
  int index = this->list_.InsertString (-1, display_name.c_str ());

  // Set the items data to this object implementation. This is just
  // in case the *display* order is not the same as the original
  // vector of items.
  if (-1 != index)
    this->list_.SetItemData (index, (DWORD_PTR)item.impl ());
}

//
// title
//
template <typename T>
void Selection_List_Dialog <T>::title (const char * str)
{
  this->title_ = str;
}

//
// DoDataExchange
//
template <typename T>
void Selection_List_Dialog <T>::DoDataExchange (CDataExchange * pDX)
{
  // First, let the base class handle its operations.
  CDialog::DoDataExchange (pDX);

  // Exchange the control data.
  DDX_Control (pDX, IDC_GAME_SELECTION_LIST_DLG_STRING_LIST, this->list_);

  if (pDX->m_bSaveAndValidate)
  {
    // Get the selection from the list control.
    int index = 0;
    DDX_LBIndex (pDX, IDC_GAME_SELECTION_LIST_DLG_STRING_LIST, index);

    // Get the actual object based on the selection. We need to save
    // the item's data in the selection variable.
    DWORD_PTR item_data = this->list_.GetItemData (index);

    typedef typename T::interface_type interface_type;
    interface_type * impl = reinterpret_cast <interface_type *> (item_data);

    // Make sure we increment the reference count before attaching
    // the element. We don't want to cause any exceptions.
    impl->AddRef ();
    this->selection_.attach (impl);
  }
}

}
}
