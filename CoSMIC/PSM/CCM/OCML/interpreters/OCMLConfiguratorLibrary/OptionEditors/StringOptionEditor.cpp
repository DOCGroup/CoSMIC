#include "StringOptionEditor.hpp"

StringOptionEditor::StringOptionEditor(wxWindow* parent,
                                       StringOption* string_option)
  : OptionEditor(parent, string_option)
{
  editor_ = new StringEditControl(panel());
  if (option()->assigned())
    editor_->SetValue(string_option->get().c_str());
  else
    editor_->SetValue("");
  editor_->Show(true);
  editor_->add_focus_listener(this);
  panel()->GetSizer()->Add(editor_, 1, wxALL | wxADJUST_MINSIZE | wxEXPAND, 2);
    
  panel()->GetSizer()->SetSizeHints(panel());
}

StringOptionEditor::~StringOptionEditor()
{
}    

void
StringOptionEditor::add_focus_listener(StringOptionEditorFocusListener* l)
{
  focus_listeners_.push_back(l);
}
    
void
StringOptionEditor::string_edit_focus_gain(StringEditControl*)
{
  for (std::list<StringOptionEditorFocusListener*>::iterator
	 iter = focus_listeners_.begin();
       iter != focus_listeners_.end(); ++iter)
    (*iter)->string_editor_focused(this);
}

void
StringOptionEditor::string_edit_focus_lost(StringEditControl*)
{
  StringOption* string_option = (StringOption*) option();
  string_option->set((const char*) editor_->GetValue());
  button()->Enable(true);
}    

void
StringOptionEditor::clear_button_clicked(ClearButton*)
{
  option()->clear();
  button()->Enable(false);
  editor_->SetValue("");
}
