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
String_Selection_Dialog (const std::set <std::string> & strs,
                         CWnd * parent)
: CDialog (IDD_STRING_SELECTION_DLG, parent),
  strs_ (strs)
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
const char * String_Selection_Dialog::selection (void) const
{
  return this->selection_;
}

//
// OnInitDialog
//
BOOL String_Selection_Dialog::OnInitDialog (void)
{
  // Pass control to the base class first.
  CDialog::OnInitDialog ();

  // Insert each of the strings into the listbox
  std::for_each (this->strs_.begin (),
                 this->strs_.end (),
                 boost::bind (&String_Selection_Dialog::insert_string,
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
void String_Selection_Dialog::insert_string (const std::string & str)
{
  this->list_.InsertString (-1, str.c_str ());
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
