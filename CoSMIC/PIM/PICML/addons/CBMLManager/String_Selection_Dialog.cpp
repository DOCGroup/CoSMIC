// $Id$

#include "StdAfx.h"

#include "String_Selection_Dialog.h"
#include "Resource.h"
#include "boost/bind.hpp"
#include <algorithm>

//
// String_Selection_Dialog
//
String_Selection_Dialog::
String_Selection_Dialog (const items_type & items, CWnd * parent)
: CDialog (IDD_STRING_SELECTION_DLG, parent),
  items_ (items)
{

}

//
// ~String_Selection_Dialog
//
String_Selection_Dialog::~String_Selection_Dialog (void)
{

}

//
// selection
//
String_Selection_Dialog::items_type::const_iterator
String_Selection_Dialog::selection (void) const
{
  return this->items_.find (this->selection_.GetString ());
}

//
// OnInitDialog
//
BOOL String_Selection_Dialog::OnInitDialog (void)
{
  // Pass control to the base class first.
  CDialog::OnInitDialog ();

  // Insert each of the strings into the listbox
  std::for_each (this->items_.begin (),
                 this->items_.end (),
                 boost::bind (&String_Selection_Dialog::insert_item,
                              this,
                              _1));

  // Set the title of the dialog box.
  if (!this->title_.empty ())
    this->SetWindowText (this->title_.c_str ());

  return FALSE;
}

//
// title
//
void String_Selection_Dialog::title (const char * str)
{
  this->title_ = str;
}

//
// insert_string
//
void String_Selection_Dialog::
insert_item (const items_type::value_type & item)
{
  this->list_.InsertString (-1, item.first.c_str ());
}

//
// DoDataExchange
//
void String_Selection_Dialog::DoDataExchange (CDataExchange * pDX)
{
  // First, let the base class handle its operations.
  CDialog::DoDataExchange (pDX);

  // Exchange the control data.
  DDX_Control (pDX, IDC_STRING_LIST, this->list_);

  // Get the string selection from the list box.
  DDX_LBString (pDX, IDC_STRING_LIST, this->selection_);
}
