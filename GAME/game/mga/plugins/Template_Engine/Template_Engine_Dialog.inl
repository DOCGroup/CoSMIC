//  -*- C++ -*-
// $Id$

//
// Template_Engine_Dialog
//
GAME_INLINE
Template_Engine_Dialog::Template_Engine_Dialog (CWnd * parent)
: CDialog (IDD_CUTE, parent),
  list_ (0),
  option_ (0)
{

}

//
// ~Template_Engine_Dialog
//
GAME_INLINE
Template_Engine_Dialog::~Template_Engine_Dialog (void)
{

}

//
// interpreter_list
//
GAME_INLINE
void Template_Engine_Dialog::interpreter_list (Interpreter_List * list)
{
  this->list_ = list;
}

//
// interpreter_list
//
GAME_INLINE
Interpreter_List * Template_Engine_Dialog::interpreter_list (void)
{
  return this->list_;
}

//
// selected_interpreter
//
GAME_INLINE
const CString & Template_Engine_Dialog::selected_interpreter (void) const
{
  return this->selected_interpeter_;
}

//
// configuation_filename
//
GAME_INLINE
const CString & Template_Engine_Dialog::configuration_filename (void) const
{
  return this->config_file_;
}

//
// parameters
//
GAME_INLINE
const CString & Template_Engine_Dialog::parameters (void) const
{
  return this->parameters_;
}

//
// option
//
GAME_INLINE
int Template_Engine_Dialog::option (void) const
{
  return this->option_;
}
