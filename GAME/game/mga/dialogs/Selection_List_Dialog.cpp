// $Id$

#include "stdafx.h"
#include "Selection_List_Dialog.h"
#include "Dialog_Display_Strategy.h"
#include "resource.h"

#include "boost/bind.hpp"

#include <algorithm>

namespace GAME
{
namespace Dialogs
{

//
// Selection_List_Dialog
//
Selection_List_Dialog::
Selection_List_Dialog (Dialog_Display_Strategy * strategy, CWnd * parent, int type)
: CDialog (IDD_GAME_SELECTION_LIST_DLG, parent),
  strategy_ (strategy),
  type_(type)
{

}

//
// ~Selection_List_Dialog
//
Selection_List_Dialog::~Selection_List_Dialog (void)
{

}

//
// selection
//
Mga::Object Selection_List_Dialog::selection (void)
{
  return this->selection_.get ();
}

//
// meta_selection
//
Mga::Meta::Base Selection_List_Dialog::meta_selection (void)
{
  return this->metaselection_.get ();
}

//
// string_selection
//
std::string Selection_List_Dialog::string_selection (void)
{
  return this->strselection_;
}

//
// OnInitDialog
//
BOOL Selection_List_Dialog::OnInitDialog (void)
{
  // Pass control to the base class first.
  CDialog::OnInitDialog ();

  // Set the title of the dialog box.
  if (!this->title_.empty ())
    this->SetWindowText (this->title_.c_str ());

  if (!this->directions_.empty ())
    this->directions_ctrl_.SetWindowTextA (this->directions_.c_str ());

  // Initialize the controls of the objects listing
  std::vector <Mga::Object>::iterator
    iter = this->items_.begin (), iter_end = this->items_.end ();

  // Initialize the controls of the meta-objects listing
  std::vector <Mga::Meta::Base>::iterator
    metaiter = this->metaitems_.begin (), metaiter_end = this->metaitems_.end ();

  // Initialize the controls of the strings listings
  std::vector <std::string>::iterator
    striter = this->strs_.begin (), striter_end = this->strs_.end ();

  if (0 == this->strategy_)
  {
    if (this->type_ == 0)
    {
      for (; iter != iter_end; ++ iter)
        this->insert_item (iter->get (), (*iter)->name ());
    }
    else if (this->type_ == 1)
    {
      for (; metaiter != metaiter_end; ++ metaiter)
        this->meta_insert_item (metaiter->get (), (*metaiter)->name ());
    }
    else if (this->type_ == 2)
    {
      for (; striter != striter_end; ++ striter)
        this->string_insert_item ((*striter));
    }
  }
  else
  {
    std::string display_name;

    if (this->type_ == 0)
    {
      for (; iter != iter_end; ++ iter)
      {
        if (this->strategy_->get_display_name (iter->get (), display_name))
          this->insert_item (iter->get (), display_name);
      }
    }
  }

  return FALSE;
}

//
// insert
//
void Selection_List_Dialog::insert (const Mga::Object_in obj)
{
  this->items_.push_back (obj);
}

//
// meta_insert
//
void Selection_List_Dialog::meta_insert (const GAME::Mga::Meta::Base_in metabase)
{
  this->metaitems_.push_back (metabase);
}

//
// string_insert
//
void Selection_List_Dialog::string_insert (const std::string str)
{
  this->strs_.push_back (str);
}

//
// insert
//
void Selection_List_Dialog::
insert (const std::vector <Mga::Object> & items)
{
  this->insert (items.begin (), items.end ());
}

//
// meta_insert
//
void Selection_List_Dialog::
meta_insert (const std::vector<GAME::Mga::Meta::Base> & metaitems)
{
  this->meta_insert (metaitems.begin (), metaitems.end ());
}

//
// string_insert
//
void Selection_List_Dialog::
string_insert (const std::vector<std::string> & str)
{
  this->string_insert (str.begin (), str.end ());
}

//
// insert
//
void Selection_List_Dialog::
insert (std::vector <Mga::Object>::const_iterator begin,
        std::vector <Mga::Object>::const_iterator end)
{
  std::for_each (begin,
                 end,
                 boost::bind (&std::vector <Mga::Object>::push_back,
                              boost::ref (this->items_),
                              _1));
}

//
// meta_insert
//
void Selection_List_Dialog::
meta_insert(std::vector<GAME::Mga::Meta::Base>::const_iterator begin,
            std::vector<GAME::Mga::Meta::Base>::const_iterator end)
{
  std::for_each (begin,
                 end,
                 boost::bind (&std::vector <GAME::Mga::Meta::Base>::push_back,
                              boost::ref (this->metaitems_),
                              _1));
}

//
// string_insert
//
void Selection_List_Dialog::
string_insert(std::vector<std::string>::const_iterator begin,
              std::vector<std::string>::const_iterator end)
{
  std::for_each (begin,
                 end,
                 boost::bind (&std::vector <std::string>::push_back,
                              boost::ref (this->strs_),
                              _1));
}


//
// insert_item
//
void Selection_List_Dialog::
insert_item (const Mga::Object_in & item, const std::string & display_name)
{
  int index = this->list_.InsertString (-1, display_name.c_str ());

  // Set the items data to this object implementation. This is just
  // in case the *display* order is not the same as the original
  // vector of items.
  if (-1 != index)
    this->list_.SetItemData (index, (DWORD_PTR)item->impl ());
}

//
// meta_insert_item
//
void Selection_List_Dialog::
meta_insert_item (const Mga::Meta::Base_in & item, const std::string & display_name)
{
  int index = this->list_.InsertString (-1, display_name.c_str ());

  // Set the items data to this object implementation. This is just
  // in case the *display* order is not the same as the original
  // vector of items.
  if (-1 != index)
    this->list_.SetItemData (index, (DWORD_PTR)item->impl ());
}

//
// string_insert_item
//
void Selection_List_Dialog::string_insert_item (const std::string & str)
{
  int index = this->list_.InsertString (-1, str.c_str ());

  // not handled for index is not -1
}


//
// title
//
void Selection_List_Dialog::title (const char * str)
{
  this->title_ = str;
}

//
// title
//
void Selection_List_Dialog::directions (const char * str)
{
  this->directions_ = str;
}

//
// DoDataExchange
//
void Selection_List_Dialog::DoDataExchange (CDataExchange * pDX)
{
  // First, let the base class handle its operations.
  CDialog::DoDataExchange (pDX);

  // Exchange the control data.
  DDX_Control (pDX, IDC_GAME_SELECTION_LIST_DLG_STRING_LIST, this->list_);
  DDX_Control (pDX, IDC_GAME_SELECTION_LIST_DLG_DIRECTIONS, this->directions_ctrl_);

  if (pDX->m_bSaveAndValidate)
  {
    // Get the selection from the list control.
    int index = 0;
    DDX_LBIndex (pDX, IDC_GAME_SELECTION_LIST_DLG_STRING_LIST, index);

    // Get the actual object based on the selection. We need to save
    // the item's data in the selection variable.
    DWORD_PTR item_data = this->list_.GetItemData (index);

    // Make sure we increment the reference count before attaching
    // the element. We don't want to cause any exceptions.

    if (this->type_ == 0)
      this->selection_ = reinterpret_cast <IMgaObject *> (item_data);
    else if (this->type_ == 1)
      this->metaselection_ = reinterpret_cast <IMgaMetaBase *> (item_data);
    else if (this->type_ == 2)
    {
      CString data;
      this->list_.GetText (index, data);
      std::string str((LPCTSTR)data) ;
      this->strselection_ = str;
    }
  }
}

}
}
