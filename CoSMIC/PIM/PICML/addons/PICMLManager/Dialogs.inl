// -*- C++ -*-
// $Id$

//
// ~Component_Name_Dialog
//
inline
Component_Name_Dialog::~Component_Name_Dialog (void)
{
}

//
// component_name
//
inline
const ACE_CString & Component_Name_Dialog::component_name (void) const
{
  return this->name_;
}

//
// component_name
//
inline
void Component_Name_Dialog::component_name (const ACE_CString & name)
{
  this->name_ = name;
}
