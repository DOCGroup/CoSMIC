/**
 * Definition of the integer edit control.
 *
 * @file IntegerEditControl.hpp
 * @author Emre Turkay <turkaye@dre.vanderbilt.edu>
 */

#ifndef INTEGER_EDIT_CONTROL_HPP
#define INTEGER_EDIT_CONTROL_HPP

#include <list>
#include <wx/wx.h>
#include "../extern_declarations.hpp"

class IntegerEditControl;

/// The classes which listens the focus gain/lost events should be derived
/// from this class.
class OCMLConfigurator_API IntegerEditControlFocusListener
{
public:
  /// When a focus gain event occurs this method is called.
  virtual void integer_edit_focus_gain(IntegerEditControl* control) = 0;
  /// When a focus lost event occurs this method is called.
  virtual void integer_edit_focus_lost(IntegerEditControl* control) = 0;
};

/**
 * Integer edit control is a single line text input widget which provides
 * focus listener interface. When a focus event occurs, calls the registered
 * listeners.
 */
class OCMLConfigurator_API IntegerEditControl: public wxTextCtrl
{
public:
  /// WXWindow focus gain event handler.
  void on_focus_gain(wxFocusEvent&);
  /// WXWindow focus lost event handler.
  void on_focus_lost(wxFocusEvent&);

public:
  /// Constructor.
  IntegerEditControl(wxWindow* parent);
    
  /// Registers the given FocusListener as a focus listener for this widget.
  void add_focus_listener(IntegerEditControlFocusListener* l);
    
private:
  /// The container for the focus listeners.
  std::list<IntegerEditControlFocusListener*> focus_listeners_;
    
  // Declares WXWindow event table.
  DECLARE_EVENT_TABLE()
};    

#endif // INTEGER_EDIT_CONTROL_HPP
