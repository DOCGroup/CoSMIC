// $Id$

#include "resource.h"

namespace GAME
{
namespace Dialogs
{
//
// Selection_List_Dialog
//
template <typename T>
Selection_List_Dialog <T>::
Selection_List_Dialog (const items_type & items, CWnd * parent)
: CDialog (IDD_GAME_SELECTION_LIST_DLG, parent),
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
  return this->items_[this->index_];
}

//
// OnInitDialog
//
template <typename T>
BOOL Selection_List_Dialog <T>::OnInitDialog (void)
{
  // Pass control to the base class first.
  CDialog::OnInitDialog ();

  // Insert each of the strings into the listbox. In the future, 
  // the client will be able to override the text value displayed
  // for each item using a callback class.
  std::for_each (this->items_.begin (),
                 this->items_.end (),
                 boost::bind (&CListBox::InsertString,
                              boost::ref (this->list_),
                              -1,
                              boost::bind (&std::string::c_str,
                                           boost::bind (&T::name, _1))));

  // Set the title of the dialog box.
  if (!this->title_.empty ())
    this->SetWindowText (this->title_.c_str ());

  return FALSE;
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

  // Get the string selection from the list box.
  DDX_LBIndex (pDX, IDC_GAME_SELECTION_LIST_DLG_STRING_LIST, this->index_);
}

}
}
