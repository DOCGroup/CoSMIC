// -*- C++ -*-

//=============================================================================
/**
 * @file        String_Selection_Dialog.h
 *
 * $Id$
 *
 * @author      James H. Hill
 */
//=============================================================================

#ifndef _STRING_SELECTION_DIALOG_H_
#define _STRING_SELECTION_DIALOG_H_

#include <string>
#include <set>

/**
 * @class String_Selection_Dialog
 *
 * Displays a simple dialog box for selecting a string from a
 * list of strings.
 */
class String_Selection_Dialog : public CDialog
{
public:
  /**
   * Initializing constructor.
   *
   * @param[in]     parent      Parent of the dialog
   */
  String_Selection_Dialog (const std::set <std::string> & strs,
                           CWnd * parent = 0);

  /// Destructor.
  virtual ~String_Selection_Dialog (void);

  /**
   * Get the selected string from the dialog.
   *
   * @return        The selected string value.
   */
  const char * selection (void) const;

  void title (const char * str);

protected:
  /**
   * Data exchange method for tranfering information to and from
   * the dialog box controls.
   *
   * @param[in]     pDX         Pointer to the data exchange.
   */
  virtual void DoDataExchange (CDataExchange * pDX);

  virtual BOOL OnInitDialog (void);

private:
  /**
   * @overload
   */
  void insert_string (const std::string & str);

  /// The selected string from the dialog.
  CString selection_;

  /// The list control for the dialog.
  CListBox list_;

  /// Collection of strings to display.
  const std::set <std::string> & strs_;

  /// Title of the dialog box.
  std::string title_;
};

#endif  // !defined _STRING_SELECTION_DIALOG_H_
