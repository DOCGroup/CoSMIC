#include "IntegerOptionEditor.hpp"

#include <sstream>

IntegerOptionEditor::IntegerOptionEditor(wxWindow* parent,
                                         IntegerOption* integer_option)
  : OptionEditor(parent, integer_option)
{
  editor_ = new IntegerEditControl(panel());

  if (option()->assigned())
    {
      std::ostringstream os;
      os << integer_option->get();
      editor_->SetValue(os.str().c_str());
    }
  else
    editor_->SetValue("");
  editor_->Show(true);
  editor_->add_focus_listener(this);
  panel()->GetSizer()->Add(editor_, 1, wxALL | wxADJUST_MINSIZE | wxEXPAND, 2);
    
  panel()->GetSizer()->SetSizeHints(panel());
}

IntegerOptionEditor::~IntegerOptionEditor()
{
}    

void
IntegerOptionEditor::add_focus_listener(IntegerOptionEditorFocusListener* l)
{
  focus_listeners_.push_back(l);
}
    
void
IntegerOptionEditor::integer_edit_focus_gain(IntegerEditControl*)
{
  for (std::list<IntegerOptionEditorFocusListener*>::iterator
	 iter = focus_listeners_.begin();
       iter != focus_listeners_.end(); ++iter)
    (*iter)->integer_editor_focused(this);
}

void
IntegerOptionEditor::integer_edit_focus_lost(IntegerEditControl*)
{
  IntegerOption* integer_option = (IntegerOption*) option();

  std::istringstream is((const char*) editor_->GetValue());
  int val;
  is >> val;
  integer_option->set(val);
  button()->Enable(true);
}    

void
IntegerOptionEditor::clear_button_clicked(ClearButton*)
{
  option()->clear();
  button()->Enable(false);
  editor_->SetValue("");
}

void
IntegerOptionEditor::unfocus()
{
  integer_edit_focus_lost(0);
}
